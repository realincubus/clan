cmake_minimum_required(VERSION 2.8)


set(PACKAGE_VERSION "0.7.1")
set(top_srcdir "${CMAKE_CURRENT_SOURCE_DIR}")

set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
SET(CMAKE_EXPORT_COMPILE_COMMANDS on)

# User's settings - C Flags

# 	set(release "TRUE")
	set(release "FALSE")

	# Release
	if (release)
	  set(CMAKE_C_FLAGS "-O3 -fPIC")
	  set(CMAKE_CXX_FLAGS "-O3 -std=c++14 -fno-rtti")
	# Debug # valgrind --show-reachable=yes --leak-check=full -v exe
	else()
	  set(CMAKE_C_FLAGS "-O0 -g3 -fPIC")
	  set(CMAKE_CXX_FLAGS "-O0 -std=c++14 -fPIC -fno-rtti")
	endif()

# User's settings - General C Flags
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -std=c99 -pedantic")


# Build doxygen
	find_package(Doxygen)
	if(DOXYGEN_FOUND)
		configure_file("doc/Doxyfile.in" "Doxyfile")
		add_custom_target(
			doxygen
			${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
			WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
			COMMENT "Generating API documentation with Doxygen" VERBATIM
		)
	else()
		message (STATUS "Doxygen not found :( API documentation can not be built")
	endif()

# Build documentation

	# doc
	find_program(texi2pdf_exe texi2pdf)
	if(texi2pdf_exe)
		add_custom_target(
			doc
			${texi2pdf_exe} ${CMAKE_CURRENT_SOURCE_DIR}/doc/clan.texi --output=${CMAKE_CURRENT_BINARY_DIR}/clan.pdf
			WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
			COMMENT "Generating documentation (pdf) (with texi2pdf)" VERBATIM
		)
	else()
		message (STATUS "texi2pdf not found :( Documentation can not be built")
	endif()

	# Reference card
	find_program(pdflatex_exe pdflatex)
	if(pdflatex_exe)
		file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/doc/reference_card DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
		add_custom_target(
			ref_card
			${pdflatex_exe} ${CMAKE_CURRENT_BINARY_DIR}/reference_card/reference_card.tex
			WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/reference_card"
			COMMENT "Generating Clan reference card (pdf) (with pdflatex)" VERBATIM
		)
	else()
		message (STATUS "pdflatex not found =( Clan reference card can not be built")
	endif()


# osl
	find_package(osl REQUIRED)

# Flex
	find_package(BISON REQUIRED)
	find_package(FLEX REQUIRED)
	BISON_TARGET(clan_parser source/parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.c)
	FLEX_TARGET(clan_scanner source/scanner.l ${CMAKE_CURRENT_BINARY_DIR}/scanner.c)
	ADD_FLEX_BISON_DEPENDENCY(clan_scanner clan_parser)
	include_directories(${CMAKE_CURRENT_BINARY_DIR})

# Include directories (to use #include <> instead of #include "")

	# include/clan/macros.h
	configure_file("include/clan/macros.h.in" "include/clan/macros.h")
	include_directories("${CMAKE_CURRENT_BINARY_DIR}/include")
	# clan
	include_directories("./include")

	add_subdirectory( backward-cpp)


# Compiler log
	message(STATUS "---")
	message(STATUS "C compiler = ${CMAKE_C_COMPILER}")
	if (release)
		message(STATUS "Mode Release")
	else()
		message(STATUS "Mode Debug")
	endif()
	message(STATUS "C flags    = ${CMAKE_C_FLAGS}")


# Library

	function ( add_libraries libname sources bison_files )
	message(STATUS "---")


	# Shared
	add_library(
		${libname}
		SHARED
		${sources}
		${bison_files}
		${FLEX_clan_scanner_OUTPUTS}
		${backward_ENABLE}
	)

        add_backward( ${libname} )
	target_link_libraries(${libname} ${OSL_LIBRARY})
	get_property(clan_lib_location TARGET ${libname} PROPERTY LOCATION)
	message(STATUS "Add ${libname} library (shared) ${clan_lib_location}")

	# Static
	add_library(
		${libname}_static
		STATIC
		${sources}
		${bison_files}
		${FLEX_clan_scanner_OUTPUTS}
		${backward_ENABLE}
	)

        add_backward( ${libname}_static )
	set_target_properties(${libname}_static PROPERTIES OUTPUT_NAME ${libname})
	target_link_libraries(${libname}_static ${OSL_LIBRARY})
	get_property(clan_static_lib_location TARGET ${libname}_static PROPERTY LOCATION)
	message(STATUS "Add ${libname} library (static) ${clan_static_lib_location}")
	endfunction( add_libraries )


	# files .c
	file(
		GLOB_RECURSE
		sources
		source/*
	)

	string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/source/clan.c;" "" sources "${sources}") # with ;
	string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/source/clan.c" "" sources "${sources}")  # without ;

	add_libraries( clan "${sources}" "${BISON_clan_parser_OUTPUTS}" )

	find_package(LLVM REQUIRED CONFIG)

	message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
	message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

	# Set your project compile flags.
	# E.g. if using the C++ header files
	# you will need to enable C++11 support
	# for your compiler.

	include_directories(${LLVM_INCLUDE_DIRS})
	add_definitions(${LLVM_DEFINITIONS})

	# Find the libraries that correspond to the LLVM components
	# that we wish to use
	llvm_map_components_to_libnames(llvm_libs support core irreader)

	add_libraries( clan-clang "${sources}" "clang-parser.cpp" )

	target_link_libraries(clan-clang clangASTMatchers clangDynamicASTMatchers )

# Executables & tests

	message(STATUS "---") # clan

	message(STATUS "Add executable clan")
	add_executable(clan_exe "source/clan.c" ${backward_ENABLE} )
	set_target_properties(clan_exe PROPERTIES OUTPUT_NAME "clan")
	target_link_libraries(clan_exe clan_static ${OSL_LIBRARY})

	# clan test
	find_package(PythonInterp)
	if (PYTHONINTERP_FOUND)
	
		message(STATUS "---")

		enable_testing()
		file(
			GLOB_RECURSE
			tests
			tests/*.c
		)

		foreach(test ${tests})
			message(STATUS "Add Test ${test}")
			if("${test}" MATCHES "autoscop")
				add_test(
					${test}
					"${CMAKE_CURRENT_SOURCE_DIR}/tests/check_source_result.py"
					"${test}"
					"${test}.scop"
					"${CMAKE_CURRENT_BINARY_DIR}/clan"
					"-autoscop"
				)
			else()
				add_test(
					${test}
					"${CMAKE_CURRENT_SOURCE_DIR}/tests/check_source_result.py"
					"${test}"
					"${test}.scop"
					"${CMAKE_CURRENT_BINARY_DIR}/clan"
				)
			endif()
			endforeach()

		message(STATUS "---")

	endif()


# Install

	install(TARGETS clan LIBRARY DESTINATION lib)
	install(TARGETS clan-clang LIBRARY DESTINATION lib)
	install(TARGETS clan_static ARCHIVE DESTINATION lib)
	install(TARGETS clan-clang_static ARCHIVE DESTINATION lib)
	install(DIRECTORY include/ DESTINATION include FILES_MATCHING PATTERN "*.h")
	install(DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/include/" DESTINATION include FILES_MATCHING PATTERN "*.h")
	install(FILES "${CMAKE_CURRENT_BINARY_DIR}/parser.h" DESTINATION include/clan)
	install(FILES clan-config.cmake DESTINATION lib/clan)
	install(TARGETS clan_exe RUNTIME DESTINATION bin)


# Little help

	message(STATUS "You can execute:")
	message(STATUS "    make          # To compile clan library & clan")
	if (PYTHONINTERP_FOUND)
		message(STATUS "    make test     # To execute tests")
	endif()
	message(STATUS "    make install  # To install library, include and CMake module")
	message(STATUS "                  # If you need root access:")
	message(STATUS "                  #     sudo make install")
	message(STATUS "                  #     su -c \"make install\"")
	if(DOXYGEN_FOUND)
		message(STATUS "    make doxygen  # To generate the Doxygen")
	endif()
	if(texi2pdf_exe)
		message(STATUS "    make doc      # To generate the documentation")
	endif()
	if(pdflatex_exe)
		message(STATUS "    make ref_card # To generate Clan reference card")
	endif()

	message(STATUS "---")
