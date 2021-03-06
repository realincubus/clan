/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1



/* Copy the first part of user declarations.  */
//#line 46 "source/parser.y" /* yacc.c:339  */

// C includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <termios.h>
#include <execinfo.h>

extern "C"{
#include <clan/macros.h>
#include <clan/vector.h>
#include <clan/relation.h>
#include <clan/relation_list.h>
#include <clan/domain.h>
#include <clan/scop.h>
#include <clan/symbol.h>
#include <clan/statement.h>
#include <clan/options.h>
}

// C++ includes 

#include <fstream>
#include <cstdio>
#include <osl/macros.h>
#include <osl/int.h>
#include <osl/vector.h>
#include <osl/relation.h>
#include <osl/statement.h>
#include <osl/strings.h>
#include <osl/generic.h>
#include <osl/body.h>
#include <osl/extensions/arrays.h>
#include <osl/extensions/extbody.h>
#include <osl/scop.h>
#include <clang/AST/AST.h>
#include <clang/Lex/Lexer.h>
#include "clang/AST/RecursiveASTVisitor.h"

#define BACKWARD_HAS_DW 1
//#define BACKWARD_HAS_BFD 1
//#include "backward.hpp"

#include <string> 
#include <iostream>

#define CLAN_DEBUG 1

#undef CLAN_debug 

std::ofstream logg;

#define logg cout 

#define CLAN_debug(x) \
         do {                                                              \
           if (CLAN_DEBUG)                                                 \
             logg << "[Clan] Debug: " << __PRETTY_FUNCTION__ <<  x << endl;    \
         } while (0)

#define YYABORT \
  do {\
  logg << "exiting at " << __FILE__ << " " << __LINE__ << " " << __PRETTY_FUNCTION__ << endl;\
  exit(-1);\
  }while(0)

using namespace std;
using namespace clang;


std::vector<std::pair<SourceRange, std::string>>* global_messages;
std::vector<std::string>* global_statement_texts;
std::map<osl_statement_p, const Stmt*>* global_osl_to_clang;

template <typename T>
void emit_message( const T * node, std::string message ){
  global_messages->push_back( make_pair ( SourceRange( node->getLocStart(), node->getLocEnd() ), std::string("CLAN_CLANG: ") + message ) );
}

template <typename T>
void emit_debug_message( const T * node, std::string message ){
  emit_message( node, std::string(" DEBUG: ") + message );
}

extern "C"{
   int  yylex(void);
   void yyerror(char*);
   void yyrestart(FILE*);
   void clan_scanner_initialize();
   void clan_scanner_reinitialize(int, int, int);
   void clan_scanner_free();

   void clan_parser_add_ld();
   int  clan_parser_nb_ld();
   void clan_parser_log(char*);
   void clan_parser_increment_loop_depth();
   void clan_parser_decrement_loop_depth();
   //void clan_parser_state_print(FILE*);
   int  clan_parser_is_loop_sane(osl_relation_list_p,osl_relation_list_p,int*, const Stmt* );
   void clan_parser_state_initialize(clan_options_p);
   osl_scop_p clan_parse(FILE*, clan_options_p);

   extern FILE*   yyin;                 /**< File to be read by Lex */
   extern int     scanner_parsing;      /**< Do we parse or not? */
   extern char*   scanner_latest_text;  /**< Latest text read by Lex */
   extern char*   scanner_clay;         /**< Data for the Clay software */
   extern int     scanner_line;         /**< Current scanned line */
   extern int     scanner_column;       /**< Scanned column (current) */
   extern int     scanner_column_LALR;  /**< Scanned column (before token) */
   extern int     scanner_scop_start;   /**< Scanned SCoP starting line */
   extern int     scanner_scop_end;     /**< Scanned SCoP ending line */
   extern int     scanner_pragma;       /**< Between SCoP pragmas or not? */

   // This is the "parser state", a collection of variables that vary
   // during the parsing and thanks to we can extract all SCoP informations.
   osl_scop_p     parser_scop;          /**< SCoP in construction */
   clan_symbol_p  parser_symbol;        /**< Top of the symbol table */
   int            parser_recording;     /**< Boolean: do we record or not? */
   char*          parser_record;        /**< What we record (statement body)*/
   int            parser_loop_depth;    /**< Current loop depth */
   int            parser_if_depth;      /**< Current if depth */
   int*           parser_scattering;    /**< Current statement scattering */
   clan_symbol_p* parser_iterators;     /**< Current iterator list */
   clan_domain_p  parser_stack;         /**< Iteration domain stack */
   int*           parser_nb_local_dims; /**< Nb of local dims per depth */
   int            parser_nb_parameters; /**< Nb of parameter symbols */
   int*           parser_valid_else;    /**< Boolean: OK for else per depth */
   int            parser_indent;        /**< SCoP indentation */
   int            parser_error;         /**< Boolean: parse error */

   int            parser_xfor_nb_nests; /**< Current number of xfor nests */
   int*           parser_xfor_depths;   /**< Current xfor nest depth list */
   int*           parser_xfor_labels;   /**< Current xfor label list */
   int            parser_xfor_index;    /**< Nb of current (x)for loop index */
   int*           parser_ceild;         /**< Booleans: ith index used ceild */
   int*           parser_floord;        /**< Booleans: ith index used floord */
   int*           parser_min;           /**< Booleans: ith index used min */
   int*           parser_max;           /**< Booleans: ith index used max */

   // Autoscop-relative variables.
   int            parser_autoscop;      /**< Boolean: autoscop in progress */
   int            parser_line_start;    /**< Autoscop start line, inclusive */
   int            parser_line_end;      /**< Autoscop end line, inclusive */
   int            parser_column_start;  /**< Autoscop start column, inclus. */
   int            parser_column_end;    /**< Autoscop end column, exclusive */

   // Ugly global variable to keep/read Clan options during parsing.
   clan_options_p parser_options;

   // Variables to generate the extbody
   osl_extbody_p  parser_access_extbody; /**< The extbody struct */
   int            parser_access_start;   /**< Start coordinates */
   int            parser_access_length;  /**< Length of the access string*/


/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
 int value;                      /**< An integer value */
         int* vecint;                    /**< A vector of integer values */
         char* symbol;                   /**< A string for identifiers */
         osl_vector_p affex;             /**< An affine expression */
         osl_relation_p setex;           /**< A set of affine expressions */
         osl_relation_list_p list;       /**< List of array accesses */
         osl_statement_p stmt;           /**< List of statements */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

YYSTYPE yylval;

void yyerror(char *s) {
  int i, line = 1;
  char c = 'C';
  FILE* file;
 
  CLAN_debug("parse error notified (yyerror)");

  //emit_message( nullptr, s );

  if (!parser_options->autoscop) {
    fprintf(stderr, "[Clan] Error: %s at line %d, column %d.\n", s,
        scanner_line, scanner_column - 1);

    // Print a message to show where is the problem.
    if ((parser_options != NULL) && (parser_options->name != NULL)) {
      file = fopen(parser_options->name, "r");
      if (file != NULL) {
        // Go to the right line.
        while (line != scanner_line) {
          c = fgetc(file);
          if (c == '\n')
            line++;
        }

        // Print the line.
        while (c != EOF) {
          c = fgetc(file);
          fprintf(stderr, "%c", c);
          if (c == '\n')
            break;
        }

        // Print the situation line.
        for (i = 0; i < scanner_column - 1; i++) {
          if (i < scanner_column - 5)
            fprintf(stderr, " ");
          else if (i < scanner_column - 2)
            fprintf(stderr, "~");
          else
            fprintf(stderr, "^\n");
        }
        fclose(file);
      } else {
        CLAN_warning("cannot open input file");
      }
    }
  }
  parser_error = CLAN_TRUE;
}

#if 0
/**
 * clan_parser_state_print function:
 * this function "pretty" prints the parser state to a file.
 */
void clan_parser_state_print(FILE* file) {
  int i;

  fprintf(file, "+-- clan parser state\n");
  fprintf(file, "|\t|\n");

  // SCoP.
  fprintf(file, "|\tparser_scop [SCoP in construction]\n");
  fprintf(file, "|\t|\t|\n");
  osl_scop_idump(file, parser_scop, 2);
  fprintf(file, "|\t|\n");

  // Symbol table.
  fprintf(file, "|\tparser_symbol [Symbol table]\n");
  fprintf(file, "|\t|\t|\n");
  clan_symbol_print_structure(file, parser_symbol, 2);
  fprintf(file, "|\t|\n");

  // Recording boolean.
  fprintf(file, "|\tparser_recording [Boolean: do we record or not?] = %d\n",
          parser_recording);
  fprintf(file, "|\t|\n");

  // Recorded body.
  fprintf(file, "|\tparser_record [Statement body] = ");
  if (parser_record == NULL)
    fprintf(file, "(NULL)\n");
  else
    fprintf(file, "%s\n", parser_record);
  fprintf(file, "|\t|\n");

  // Loop depth.
  fprintf(file, "|\tparser_loop_depth [Current loop depth] = %d\n",
          parser_loop_depth);
  fprintf(file, "|\t|\n");

  // If depth.
  fprintf(file, "|\tparser_if_depth [Current if depth] = %d\n",
          parser_if_depth);
  fprintf(file, "|\t|\n");

  // Scattering.
  fprintf(file, "|\tparser_scattering [Current statement scattering]\n");
  fprintf(file, "|\t|\t|\n");
  fprintf(file, "|\t|\t+-- ");
  for (i = 0; i < 2 * parser_loop_depth + 1; i++)
    printf("%d ", parser_scattering[i]);
  fprintf(file, "\n");
  fprintf(file, "|\t|\t|\n");
  fprintf(file, "|\t|\n");

  // Iterators.
  fprintf(file, "|\tparser_iterators [Current iterator list]\n");
  fprintf(file, "|\t|\t|\n");
  if (parser_loop_depth > 0) {
    for (i = 0; i < parser_loop_depth; i++) {
      fprintf(file, "|\t|\tparser_iterators[%d]\n", i);
      fprintf(file, "|\t|\t|\t|\n");
      clan_symbol_print_structure(file, parser_iterators[i], 3);
      if (i == parser_loop_depth - 1)
	fprintf(file, "|\t|\t|\n");
    }
  } else {
    fprintf(file, "|\t|\t+-- (none)\n");
    fprintf(file, "|\t|\t|\n");
  }
  fprintf(file, "|\t|\n");

  // Iteration domain stack.
  fprintf(file, "|\tparser_domain [Iteration domain stack]\n");
  fprintf(file, "|\t|\t|\n");
  clan_domain_idump(file, parser_stack, 2);
  fprintf(file, "|\t|\n");

  // Number of local dimensions per depth.
  fprintf(file, "|\tparser_nb_local_dims [Nb of local dims per depth]\n");
  fprintf(file, "|\t|\t|\n");
  fprintf(file, "|\t|\t+-- ");
  if (parser_loop_depth > 0) {
    for (i = 0; i < parser_loop_depth; i++)
      printf("%d ", parser_nb_local_dims[i]);
      fprintf(file, "\n");
    } else {
    fprintf(file, "(none)\n");
  }
  fprintf(file, "|\t|\t|\n");
  fprintf(file, "|\t|\n");

  // Number of parameters.
  fprintf(file, "|\tparser_nb_parameters [Nb of parameter symbols] = %d\n",
          parser_nb_parameters);
  fprintf(file, "|\t|\n");

  // Boolean valid else per if depth.
  fprintf(file, "|\tparser_valid_else [Boolean: OK for else per depth]\n");
  fprintf(file, "|\t|\t|\n");
  fprintf(file, "|\t|\t+-- ");
  if (parser_if_depth > 0) {
    for (i = 0; i < parser_if_depth; i++)
      printf("%d ", parser_valid_else[i]);
    fprintf(file, "\n");
  } else {
    fprintf(file, "(none)\n");
  }
  fprintf(file, "|\t|\t|\n");
  fprintf(file, "|\t|\n");

  // Indentation.
  fprintf(file, "|\tparser_indent [SCoP indentation] = %d\n", parser_indent);
  fprintf(file, "|\t|\n");

  // Parse error boolean.
  fprintf(file, "|\tparser_error [Boolean: parse error] = %d\n", parser_error);
  fprintf(file, "|\t|\n");

  // xfor number of nests, depths and labels.
  fprintf(file, "|\txfor management [nb of nests, depths and labels]\n");
  fprintf(file, "|\t|\t|\n");
  if (parser_xfor_nb_nests > 0) {
    fprintf(file, "|\t|\t|  nest | depth | label\n");
    for (i = 0; i < parser_xfor_nb_nests; i++) {
      printf("|\t|\t|   [%d] |     %d |     %d\n",
	     i, parser_xfor_depths[i], parser_xfor_labels[i]);
    }
  } else {
    fprintf(file, "|\t|\t|  (no xfor loop)\n");
  }
  fprintf(file, "|\t|\t|\n");
  fprintf(file, "|\t|\n");
  
  // loop sanity sentinels
  fprintf(file, "|\tloop sanity sentinels [booleans min/max/floord/ceild]\n");
  fprintf(file, "|\t|\t|\n");
  if (parser_xfor_index > 0) {
    fprintf(file, "|\t|\t|  index | min | max | floord | ceild\n");
    for (i = 0; i < parser_xfor_index; i++) {
      printf("|\t|\t|  [%d] |   %d |   %d |      %d |     %d\n",
	     i, parser_min[i], parser_max[i],
	     parser_floord[i], parser_ceild[i]);
    }
  } else {
    fprintf(file, "|\t|\t|  (no (x)for loop indices)\n");
  }
  fprintf(file, "|\t|\t|\n");
  fprintf(file, "|\t|\n");
  
  fprintf(file, "|\n");
}
#endif

// needed to find out whether a match was successful even if it returns null
struct match_wrapper {
  osl_relation_list_p result;
};

typedef match_wrapper* match_wrapper_p;

match_wrapper* match_successful( osl_relation_list_p _result ){
  match_wrapper* ret = (match_wrapper*)malloc(sizeof(match_wrapper));
  ret->result = _result;
  return ret;
}

match_wrapper* match_fail(){
  return nullptr;
}


void clan_parser_add_ld() {
  parser_nb_local_dims[parser_loop_depth + parser_if_depth]++;

  if (CLAN_DEBUG) {
    int i;
    CLAN_debug("parser_nb_local_dims updated");
    for (i = 0; i <= parser_loop_depth + parser_if_depth; i++)
      fprintf(stderr, "%d:%d ", i, parser_nb_local_dims[i]);
    fprintf(stderr, "\n");
  }
  
  if (clan_parser_nb_ld() > CLAN_MAX_LOCAL_DIMS)
    CLAN_error("CLAN_MAX_LOCAL_DIMS reached, recompile with a higher value");
}


int clan_parser_nb_ld() {
  int i, nb_ld = 0;

  for (i = 0; i <= parser_loop_depth + parser_if_depth; i++)
    nb_ld += parser_nb_local_dims[i]; 
  return nb_ld;
}


void clan_parser_increment_loop_depth() {
  logg << "incrementing parser_loop_depth " << endl;
  parser_loop_depth++;
  if ((parser_loop_depth + parser_if_depth) > CLAN_MAX_DEPTH)
    CLAN_error("CLAN_MAX_DEPTH reached, recompile with a higher value");
}

void clan_parser_decrement_loop_depth(){
  logg << "decrementing parser_loop_depth " << endl;
  parser_loop_depth--;
  if (parser_loop_depth < 0 )
    CLAN_error("loop depth is negative");
}


int clan_parser_is_loop_sane(osl_relation_list_p initialization,
                             osl_relation_list_p condition, int* stride, const Stmt* stmt) {
  int i, step;

  // Check there is the same number of elements in all for parts.
  if ((clan_relation_list_nb_elements(initialization) != parser_xfor_index) ||
      (clan_relation_list_nb_elements(condition) != parser_xfor_index)) {
    emit_message(stmt, "not the same number of elements in all loop parts");
    return 0;
  }

  // Check that all bounds and strides are consistent.
  for (i = 0; i < parser_xfor_index; i++) {
    step = stride[i];
    if ((step == 0) ||
	((step > 0) && parser_min[i])    ||
	((step > 0) && parser_floord[i]) ||
	((step < 0) && parser_max[i])    ||
	((step < 0) && parser_ceild[i])) {
      osl_relation_list_free(initialization);
      osl_relation_list_free(condition);
      free(stride);
      if (step == 0)
	emit_message( stmt, "unsupported zero loop stride");
      else if (step > 0)
	emit_message( stmt, "illegal min or floord in forward loop initialization");
      else
	emit_message( stmt, "illegal max or ceild in backward loop initialization");
      return 0;
    }
    parser_ceild[i]  = 0;
    parser_floord[i] = 0;
    parser_min[i]    = 0;
    parser_max[i]    = 0;
  }
  return 1;
}


/**
 * clan_parser_state_malloc function:
 * this function achieves the memory allocation for the "parser state".
 * \param[in] precision Precision of the integer elements.
 */
void clan_parser_state_malloc(int precision) {
  int nb_columns, depth;

  nb_columns        = CLAN_MAX_DEPTH + CLAN_MAX_LOCAL_DIMS +
                      CLAN_MAX_PARAMETERS + 2;
  depth             = CLAN_MAX_DEPTH;
  parser_stack      = clan_domain_malloc();
  parser_stack->constraints = osl_relation_list_malloc();
  parser_stack->constraints->elt = osl_relation_pmalloc(precision,
      0, nb_columns);
  CLAN_malloc(parser_nb_local_dims, int*, depth * sizeof(int));
  CLAN_malloc(parser_valid_else, int*, depth * sizeof(int));
  CLAN_malloc(parser_scattering, int*, (2 * depth + 1) * sizeof(int));
  CLAN_malloc(parser_iterators, clan_symbol_p*, depth * sizeof(clan_symbol_p));
  CLAN_malloc(parser_ceild,  int*, CLAN_MAX_XFOR_INDICES * sizeof(int));
  CLAN_malloc(parser_floord, int*, CLAN_MAX_XFOR_INDICES * sizeof(int));
  CLAN_malloc(parser_min,    int*, CLAN_MAX_XFOR_INDICES * sizeof(int));
  CLAN_malloc(parser_max,    int*, CLAN_MAX_XFOR_INDICES * sizeof(int));
  CLAN_malloc(parser_xfor_depths, int*, CLAN_MAX_DEPTH * sizeof(int));
  CLAN_malloc(parser_xfor_labels, int*, CLAN_MAX_DEPTH * sizeof(int));
}


/**
 * clan_parser_state_free function:
 * this function frees the memory allocated for the "parser state", with the
 * exception of the parser_scop.
 */
void clan_parser_state_free() {
  clan_symbol_free(parser_symbol);
  free(parser_scattering);
  free(parser_iterators);
  free(parser_nb_local_dims);
  free(parser_valid_else);
  free(parser_ceild);
  free(parser_floord);
  free(parser_min);
  free(parser_max);
  free(parser_xfor_depths);
  free(parser_xfor_labels);
  clan_domain_drop(&parser_stack);
}


/**
 * clan_parser_state_initialize function:
 * this function achieves the initialization of the "parser state", with
 * the exception of parser_scop.
 */
void clan_parser_state_initialize(clan_options_p options) {
  int i;

  parser_symbol        = NULL;
  parser_loop_depth    = 0;
  parser_options       = options;
  parser_recording     = CLAN_FALSE;
  parser_record        = NULL;
  parser_if_depth      = 0;
  parser_xfor_nb_nests = 0;
  parser_xfor_index    = 0;
  parser_indent        = CLAN_UNDEFINED;
  parser_error         = CLAN_FALSE;
  parser_autoscop      = CLAN_FALSE;
  parser_line_start    = 1;
  parser_line_end      = 1;
  parser_column_start  = 1;
  parser_column_end    = 1;
  parser_nb_parameters = 0;

  for (i = 0; i < CLAN_MAX_XFOR_INDICES; i++) {
    parser_ceild[i]  = 0;
    parser_floord[i] = 0;
    parser_min[i]    = 0;
    parser_max[i]    = 0;
  }

  for (i = 0; i < CLAN_MAX_DEPTH; i++) {
    parser_nb_local_dims[i] = 0;
    parser_valid_else[i] = 0;
    parser_iterators[i] = NULL;
    parser_xfor_depths[i] = 0;
    parser_xfor_labels[i] = CLAN_UNDEFINED;
  }

  for (i = 0; i < 2 * CLAN_MAX_DEPTH + 1; i++)
    parser_scattering[i] = 0;
}


/**
 * clan_parser_reinitialize function:
 * this function frees the temporary dynamic variables of the parser and
 * reset the variables to default values. It is meant to be used for a
 * clean restart after a parse error.
 */
void clan_parser_reinitialize() {
  int i;
  
  free(parser_record);
  clan_symbol_free(parser_symbol);
  for (i = 0; i < parser_loop_depth; i++)
    clan_symbol_free(parser_iterators[i]);
  while (parser_stack->next != NULL)
    clan_domain_drop(&parser_stack);
  osl_scop_free(parser_scop);
  clan_parser_state_initialize(parser_options);
}


void yyparse(){
}


#if 1
/**
 * clan_parser_autoscop function:
 * this functions performs the automatic extraction of SCoPs from the input
 * file. It leaves the SCoP pragmas already set by the user intact (note that
 * as a consequence, user-SCoPs cannot be inserted to a larger SCoP).
 * It writes a file (named by the CLAN_AUTOPRAGMA_FILE macro) with the input
 * code where new SCoP pragmas have been inserted. If the option -autoscop
 * is set, it puts the list of SCoPs (including automatically discovered
 * SCoPs and user-SCoPs) in parser_scop.
 */
void clan_parser_autoscop() {
  int new_scop, nb_scops = 0;
  int line, column, restart_line, restart_column;
  long position;
  char c;
  int coordinates[5][CLAN_MAX_SCOPS]; // 0, 1: line start, end
                                      // 2, 3: column start, end
				      // 4: autoscop or not
 
  while (1) {
    // For the automatic extraction, we parse everything except user-SCoPs.
    if (!scanner_pragma)
      scanner_parsing = CLAN_TRUE;
    yyparse();

    new_scop = (parser_line_end != 1) || (parser_column_end != 1);
    restart_line = (new_scop) ? parser_line_end : scanner_line;
    restart_column = (new_scop) ? parser_column_end : scanner_column;
    if (CLAN_DEBUG) {
      if (new_scop)
	fprintf(stderr, "[Clan] Debug: new autoscop, ");
      else
	fprintf(stderr, "[Clan] Debug: no autoscop, ");
      fprintf(stderr, "restart at line %d, column %d\n",
	      restart_line, restart_column);
    }
 
    if (parser_error || new_scop) {
      if (new_scop) {
        // If a new SCoP has been found, store its coordinates.
        if (nb_scops == CLAN_MAX_SCOPS)
          CLAN_error("too many SCoPs! Change CLAN_MAX_SCOPS and recompile.");
        coordinates[0][nb_scops] = parser_line_start;
        coordinates[1][nb_scops] = parser_line_end;
        coordinates[2][nb_scops] = parser_column_start;
        coordinates[3][nb_scops] = parser_column_end;
        coordinates[4][nb_scops] = CLAN_TRUE;
        if (CLAN_DEBUG) {
          fprintf(stderr, "[Clan] Debug: AutoSCoP [%d,%d -> %d,%d]\n",
                  coordinates[0][nb_scops], coordinates[2][nb_scops],
                  coordinates[1][nb_scops], coordinates[3][nb_scops] - 1);
        }
        // Let's go for the next SCoP.
        parser_autoscop = CLAN_FALSE;
        nb_scops++;
      } else if (scanner_scop_start != CLAN_UNDEFINED) {
        // If the start of a user-SCoP is detected, store its coordinate.
	coordinates[0][nb_scops] = scanner_scop_start;
      } else if (scanner_scop_end != CLAN_UNDEFINED) {
        // If the end of a user-SCoP is detected, store its coordinate.
	coordinates[1][nb_scops] = scanner_scop_end;
	coordinates[2][nb_scops] = 0;
	coordinates[3][nb_scops] = 0;
	coordinates[4][nb_scops] = CLAN_FALSE;
        if (CLAN_DEBUG) {
          fprintf(stderr, "[Clan] Debug: user-SCoP [%d,%d -> %d,%d]\n",
                  coordinates[0][nb_scops], coordinates[2][nb_scops],
                  coordinates[1][nb_scops], coordinates[3][nb_scops]);
        }
	nb_scops++;
      }

      // Restart after the SCoP or after the error.
      rewind(yyin);
      line = 1;
      column = 1;
      while ((line != restart_line) || (column != restart_column)) {
        c = fgetc(yyin);
        column++;
        if (c == '\n') {
          line++;
          column = 1;
        }
      }
    }

    // Reinitialize the scanner and the parser for a clean restart.
    clan_scanner_free();
    clan_scanner_reinitialize(scanner_pragma, restart_line, restart_column);
    clan_parser_reinitialize();
    yyrestart(yyin);

    // Check whether we reached the end of file or not.
    position = ftell(yyin);
    c = fgetc(yyin);
    if (fgetc(yyin) == EOF)
      break;
    else 
      fseek(yyin, position, SEEK_SET);
  }
 
  // Write the code with the inserted SCoP pragmas in CLAN_AUTOPRAGMA_FILE.
  rewind(yyin);
  clan_scop_print_autopragma(yyin, nb_scops, coordinates);

  // Use the temporary file for usual parsing.
  scanner_line = 1;
  scanner_column = 1;
  scanner_pragma = CLAN_FALSE;
  parser_options->autoscop = CLAN_FALSE;
  if ((yyin = fopen(CLAN_AUTOPRAGMA_FILE, "r")) == NULL)
    CLAN_error("cannot create the temporary file");
  yyparse();
  fclose(yyin);

  // Update the SCoP coordinates with those of the original file.
  clan_scop_update_coordinates(parser_scop, coordinates);
  parser_options->autoscop = CLAN_TRUE;
  
  if (remove(CLAN_AUTOPRAGMA_FILE))
    CLAN_warning("cannot delete temporary file");
}


/**
 * clan_parse function:
 * this function parses a file to extract a SCoP and returns, if successful,
 * a pointer to the osl_scop_t structure.
 * \param input   The file to parse (already open).
 * \param options Options for file parsing.
 */
osl_scop_p clan_parse(FILE* input, clan_options_p options) {
  osl_scop_p scop;
  yyin = input;

  clan_parser_state_malloc(options->precision);
  clan_parser_state_initialize(options);
  clan_scanner_initialize();
  yyrestart(yyin);  //restart scanning another file
  parser_scop = NULL;

  if (!options->autoscop)
    yyparse();
  else
    clan_parser_autoscop();

  CLAN_debug("parsing done");

  clan_scanner_free();
  
  if (!parser_error)
    scop = parser_scop;
  else
    scop = NULL;

  clan_parser_state_free();
  CLAN_debug("parser state successfully freed");

  return scop;
}
#endif
}

#if 0
auto print_stack_trace(){
  using namespace backward;
  StackTrace st; st.load_here(32);
  Printer p; p.print(st);
}
#endif


#if 0
const char* SCOP_ID = "scop";
const char* FOR_LOOP_ID = "for_loop";
const char* LOOP_ITERATOR_ID = "loop_iterator";
const char* LOOP_INITIALIZER_ID = "loop_initializer";
const char* LOOP_CONDITION_LIST_ID = "loop_condition_list";

const char* DECREMENT_ONE_ID = "decrement_one";
const char* INCREMENT_ONE_ID = "increment_one";

const char* CEILD_ID = "ceild";
const char* FLOORD_ID = "floord";
#endif
template <typename T>
inline std::string getString(const T *node, const SourceManager &SM) {
  cout << __PRETTY_FUNCTION__ << endl;
  SourceLocation expr_start = node->getLocStart();
  SourceLocation expr_end = node->getLocEnd();
  auto ret = Lexer::getSourceText(
      CharSourceRange::getTokenRange(SourceRange(expr_start, expr_end)), SM,
      LangOptions());
  return ret;
}

const Stmt* get_predecessor( const CompoundStmt* c, const Stmt* stmt ){
  cout << __PRETTY_FUNCTION__ << endl;
  c->dumpColor();
  cerr << "------------" << endl;
  stmt->dumpColor();
  for( auto I = c->body_begin(), E = c->body_end(); I != E ; I++ ){
    // search yourself
    if ( *I == stmt ){
      std::cout << "found myself" << std::endl;
      // dont work with begin statements
      if ( I == c->body_begin() ) return nullptr;
      // get the predecessor 
      decltype(I) prev = I - 1;
      // otherwise
      std::cout << "returning something" << std::endl;
      return *prev;
    }
  }
  assert( 0 && "this should never occur" );
  return nullptr;
}


auto ignoreImplicitCastExpressions( const Expr* expr ){
  return expr->IgnoreParenImpCasts();
}

const Stmt* get_succesessor( const CompoundStmt* c, const Stmt* stmt ){
  cout << __PRETTY_FUNCTION__ << endl;
  for( auto I = c->body_begin(), E = c->body_end(); I != E ; I++ ){
    // search yourself
    if ( *I == stmt ){
      std::cout << "found myself" << std::endl;
      // get the successor
      decltype(I) next = I + 1;
      // if the statement is the first in the list
      if ( next == c->body_end() ) return nullptr;
      // otherwise
      return *next;
    }
  }
  assert( 0 && "this should never occur" );
  return nullptr;
}

class DeclRefVisitor
  : public clang::RecursiveASTVisitor<DeclRefVisitor> {
public:

  DeclRefVisitor( std::vector<std::string>& _iterators ):
    iterators(_iterators)
  {

  }

  bool VisitDeclRefExpr( const DeclRefExpr* declRefExpr ) {
    std::cout << "visited a node" << std::endl;
    for( auto i = 0 ; i < iterators.size() ; i++ ){
      auto& iterator = iterators[i];
      if ( declRefExpr->getDecl()->getNameAsString() == iterator ) {
	// push_this occurence to the list of excludes for this iterator
	exclude_ranges.push_back( make_pair( declRefExpr->getSourceRange(), to_string(i)) );
	return true;
      }
    }
    
    // everything that is not an iterator passes this point
    return true;
  }
  std::vector<std::pair<SourceRange,std::string>> exclude_ranges;
private:
  std::vector<std::string>& iterators;
};

// TODO this currently just works for compound_statements 
template <typename T>
inline std::string getStringWithComments(const T *node, const T* parent, const SourceManager &SM, std::vector<std::string>& iterators) {
  cout << __PRETTY_FUNCTION__ << endl;

  SourceLocation expr_start = node->getLocStart();
  SourceLocation expr_end = node->getLocEnd();
  std::string comment = "";
  int skip_start = 0;
  int skip_end = 0;

  // compound stmt 
  if ( auto compound_stmt = dyn_cast_or_null<CompoundStmt>( parent ) ) {
    if ( auto pre = get_predecessor( compound_stmt, node ) ) {
      expr_start = pre->getLocEnd();
      // now go down by one line 
      auto FID = SM.getFileID( expr_start );
      auto line = SM.getSpellingLineNumber( expr_start ); // TODO something is wrong here. does not seam to be critical but still wrong
      auto column = 0; // start to read from line begin
      expr_start = SM.translateLineCol( FID, line, column );
    }else{
      // no predecessor 
      expr_start = compound_stmt->getLBracLoc();
      skip_start = 1;
    }


    if ( auto suc = get_succesessor( compound_stmt, node ) ) {
      // find where the successor is 
      auto comment_start = node->getLocEnd();
      auto comment_end = suc->getLocStart();
      std::string ret = Lexer::getSourceText(
	  CharSourceRange::getTokenRange(SourceRange(comment_start, comment_end)), SM,
	  LangOptions());


      // get the string but throw away everything after the first \n character
      std::cout << "text till next statemenet: " << ret.substr( 1 ) << std::endl;
      comment = ret.substr( 1, ret.find("\n") );
    }else{
      // if there is no successor because its the last statement 
      // read until the end but skip the 
      expr_end = compound_stmt->getRBracLoc();
      skip_end = 1;
    }
  }


  {
    DeclRefVisitor visitor(iterators);
    visitor.TraverseStmt( (Stmt*)node );

    std::string lexer_result;

    auto starts_with = expr_start;

    for ( auto& exclude : visitor.exclude_ranges){

      std::string ret = Lexer::getSourceText(
	CharSourceRange::getCharRange(
	  SourceRange(
	    Lexer::getLocForEndOfToken(starts_with,0,SM,LangOptions()), 
	    exclude.first.getBegin()
	  )
	), 
	SM,
	LangOptions()
      );

      std::cout << "parsed: " << ret << std::endl;

      lexer_result += ret;
      lexer_result += "..."s + exclude.second + "..."s;
      
      starts_with = exclude.first.getEnd();
    }

    std::string ret = Lexer::getSourceText(
      CharSourceRange::getTokenRange(
	SourceRange(
	  Lexer::getLocForEndOfToken(starts_with,0,SM,LangOptions()), 
	  expr_end
	)
      ), 
      SM,
      LangOptions()
    );

    std::cout << "parsed: " << ret << std::endl;

    lexer_result += ret;
    // to skip the closing bracket if its present
    if ( skip_end ) {
      lexer_result = lexer_result.substr( 0, lexer_result.size()-1);
    }
    lexer_result += comment; // the comment include the ";"

    std::cout << "lexer_result: " << lexer_result << std::endl;

    return lexer_result;
  }

}

SourceManager* global_SM = nullptr;

template <typename T>
string getString( const T* node ){
  SourceManager& SM = *global_SM;
  return getString( node, SM ); 
}

template <typename T>
string getStringWithComments( const T* node, const T* parent, std::vector<std::string>& iterators ){
  SourceManager& SM = *global_SM;
  return getStringWithComments( node, parent, SM, iterators ); 
}



#if 0
void handleSCoP(  const MatchFinder::MatchResult &Result ){

  
  int nb_parameters;
  osl_scop_p scop;
  osl_generic_p arrays;

  CLAN_debug("rule scop.1: statement_list IGNORE");
  scop = osl_scop_malloc();
  CLAN_strdup(scop->language, "C");

  // TODO fill parameters 
  // Build the SCoP context.
#if 0
  nb_parameters = clan_symbol_nb_of_type(parser_symbol,
      CLAN_TYPE_PARAMETER);
  scop->parameters = clan_symbol_to_strings(parser_symbol,
      CLAN_TYPE_PARAMETER);
  scop->context = clan_relation_build_context(nb_parameters,
					      parser_options);
#endif
  
  // TODO get the statements from the id
  // Set the statements.
  //scop->statement = $1;

  // Compact the SCoP relations.
  if (CLAN_DEBUG) {
    CLAN_debug("SCoP before compaction:");
    osl_scop_dump(stderr, scop);
  }
  clan_scop_compact(scop);
  if (CLAN_DEBUG) {
    CLAN_debug("SCoP after compaction:");
    osl_scop_dump(stderr, scop);
  }

  // Simplify the SCoP iteration domains.
  if (!parser_options->nosimplify)
    clan_scop_simplify(scop);

#if 0
  // Add extensions.
  scop->registry = osl_interface_get_default_registry();
  clan_scop_generate_scatnames(scop);
  arrays = clan_symbol_to_arrays(parser_symbol);
  osl_generic_add(&scop->extension, arrays);
  clan_scop_generate_coordinates(scop, parser_options->name);
  clan_scop_generate_clay(scop, scanner_clay);
#endif

#if 0
  // Add the SCoP to parser_scop and prepare the state for the next SCoP.
  osl_scop_add(&parser_scop, scop);
  clan_symbol_free(parser_symbol);
  clan_parser_state_initialize(parser_options);
  CLAN_debug_call(osl_scop_dump(stderr, scop));
#endif
}
#endif


auto to_char_str( string str ) {
  char* ret;
  ret = (char*)malloc( sizeof(char)*(str.length()+1) );
  printf("new char ptr %d\n", ret);
  cout << "content: " << str << endl;
  strcpy( ret, str.c_str() );
  cout << ret[0] << " " << ret[1] << " " << ret[2] << endl;
  ret[str.length()] = '\0';
  cout << "returing from " << __PRETTY_FUNCTION__ << endl;
  return ret;
}

auto handleInteger( const Expr* expr ){
  logg << __PRETTY_FUNCTION__ << endl;
  int* ret = nullptr;
  auto ignore_paren_impl_casts = expr->IgnoreParenImpCasts();
  if ( auto integer_literal = dyn_cast_or_null<IntegerLiteral>( ignore_paren_impl_casts ) ){
    char* text = to_char_str( getString( integer_literal ) );
    cout << "integer literal number: " << text << endl;
    ret = (int*)malloc( sizeof( int ) );
    *ret = atoi( text );
    cout << "integer literal number (cvted): " << ret << endl;
    free( text );
    return ret;
  } 
  logg << "not an integer literal" << endl;
  return ret;
}


// a statement is save to use if all variables which are pointers or references have a restrict qualifier
// TODO is this really needed for high level parallelization ?
auto restrict_qualified( const Stmt* stmt ) {
  
  // TODO find all declrefs 
  // TODO get their types 
  // TODO get their qualtypes
  // TODO are they restric qualified ?
  //

}

// TODO check that:
// a function is save to call if it has the pure or const attribute 
auto is_save_to_call( const Decl* decl ) {
  if ( auto function_decl = dyn_cast_or_null<FunctionDecl>( decl ) ){
    for( auto i = function_decl->attr_begin(), e = function_decl->attr_end(); i != e; ++i ){
      if ( isa<ConstAttr>(*i) ) return true;
      if ( isa<PureAttr>(*i) ) return true;
    }
    return false;
  }
  assert( 0 && "not implemented" );
  return false;
}

// has to work with standard char pointers
auto handleID( const Expr* expr ){
  logg << __PRETTY_FUNCTION__ << endl;

  expr->dumpColor();
  char* ret = nullptr;

  // ignore implicit casts
  const Expr* iic_expr = expr->IgnoreParenImpCasts();

  if ( auto decl_ref_expr = dyn_cast_or_null<DeclRefExpr>( iic_expr ) ) {
    logg << "leaving via decl_ref " << __PRETTY_FUNCTION__ << endl;
    ret = to_char_str( getString( decl_ref_expr ) );
    return ret; 
  }
  if ( auto call_expr = dyn_cast_or_null<CallExpr>( iic_expr ) ) {
    if ( !is_save_to_call ( call_expr->getCalleeDecl() ) ) {
      emit_message( call_expr , "Assuming function call has no side effects" );
    }
    ret = to_char_str( getString( call_expr ) );
    logg << "leaving via call expr " << __PRETTY_FUNCTION__ << endl;
    return ret; 
  }
  logg << "leaving with nullptr" << __PRETTY_FUNCTION__ << endl;
  return (char*)nullptr;
}

auto handleID( const NamedDecl* decl ){
  logg << __PRETTY_FUNCTION__ << endl;
  decl->dumpColor();
  char* ret = nullptr;
  auto declaration_name = decl->getDeclName();
  auto name_str = declaration_name.getAsString();
  ret = to_char_str( name_str );
  cout << "declaration_name (as char*)" << ret << endl;
  logg << "leaving " << __PRETTY_FUNCTION__ << endl;
  return ret;
}

auto handleAffinePrimaryExpression( const Expr* expr ) {
  logg << __PRETTY_FUNCTION__ << endl;
  osl_vector_p ret = nullptr;

  auto ID = handleID( expr );
  if ( ID ) {
    clan_symbol_p id;

    CLAN_debug("rule affine_primary_expression.1: id");
    id = clan_symbol_add(&parser_symbol, ID, CLAN_UNDEFINED);
    // An id in an affex can be either an iterator or a parameter. If it is
    // an unknown (embeds read-only variables), it is updated to a parameter.
    if (id->type == CLAN_UNDEFINED) {
      std::cout << "clan undefined" << std::endl;
      if ((parser_nb_parameters + 1) > CLAN_MAX_PARAMETERS)
	      CLAN_error("CLAN_MAX_PARAMETERS reached,"
			   "recompile with a higher value");
      id->type = CLAN_TYPE_PARAMETER;
      id->rank = ++parser_nb_parameters;
    }

    if ((id->type != CLAN_TYPE_ITERATOR) &&
	(id->type != CLAN_TYPE_PARAMETER)) {
      std::cout << "not an iterator or a parameter" << std::endl;
      free(id);
      if (id->type == CLAN_TYPE_ARRAY){
	emit_message( expr, "variable or array reference in an affine expression");
      }else{
	emit_message( expr, "function call in an affine expression");
      }
      return ret;
    }
    
    auto ret = clan_vector_term(parser_symbol, 1, ID, parser_options->precision);
    free(ID);
    CLAN_debug_call(osl_vector_dump(stderr, ret));
    return ret;
  }

  auto integer = handleInteger( expr );
  if ( integer ) {
    //expr->dumpColor();
    CLAN_debug("rule affine_primary_expression.2: INTEGER");
    auto ret = clan_vector_term(parser_symbol, *integer, NULL, parser_options->precision);
    CLAN_debug_call(osl_vector_dump(stderr, ret));
    return ret;
  }

  // TODO handle the case that an affine expression is wrapped in parenthesis
#if 0 
  if ( affine_expression ) {
    auto affine_expression = handleAffineExpression( expr );
  }
#endif

  logg << "no ID nor a declRefExpr " << endl;
  return ret;

}


auto handleAffineUnaryExpression( const Expr* expr ) {
  logg << __PRETTY_FUNCTION__ << endl;
  auto affine_primary_expression = handleAffinePrimaryExpression( expr );
  if ( affine_primary_expression ) {
      CLAN_debug("rule affine_unary_expression.1: affine_primary_expression");
      //expr->dumpColor();
      auto ret = affine_primary_expression;
      CLAN_debug_call(osl_vector_dump(stderr, ret));
      return ret;
  }

  auto unary_operator = dyn_cast_or_null<UnaryOperator>( expr );
  if ( unary_operator ) {
    string opcode = unary_operator->getOpcodeStr( unary_operator->getOpcode() );
    bool is_pos = false;
    bool is_neg = false;
    if ( opcode == "+" ) {
      is_pos = true;
    } else if ( opcode == "-" ) {
      is_neg = true;
    }
    if ( !is_pos && !is_neg ) return (osl_vector_p)nullptr;

    auto affine_primary_expression = handleAffinePrimaryExpression( unary_operator->getSubExpr() );

    if ( is_pos && affine_primary_expression ) {
      CLAN_debug("rule affine_unary_expression.2: +affine_primary_expression");
      auto ret = affine_primary_expression;
      CLAN_debug_call(osl_vector_dump(stderr, ret));
      return ret;
    }

    if ( is_neg && affine_primary_expression ){
      CLAN_debug("rule affine_unary_expression.2: -affine_primary_expression");
      auto ret = osl_vector_mul_scalar(affine_primary_expression, -1);
      osl_vector_free(affine_primary_expression);
      CLAN_debug_call(osl_vector_dump(stderr, ret));
      return ret;
    }
  }

}

auto handleAffineMultiplicativeExpression( const Expr* expr ) {
  logg << __PRETTY_FUNCTION__ << endl;
  auto affine_unary_expression = handleAffineUnaryExpression( expr );
  if ( affine_unary_expression ){
      CLAN_debug("rule affine_multiplicative_expression.1: affine_unary_expression");
      //expr->dumpColor();
      auto ret = affine_unary_expression;
      CLAN_debug_call(osl_vector_dump(stderr, ret));
      return ret;
  }

  auto binary_operator = dyn_cast_or_null<BinaryOperator>(expr);

  if ( binary_operator ) {

    string opcode = binary_operator->getOpcodeStr();
    bool is_mul = false;
    bool is_div = false;
    if ( opcode == "*" ) {
      is_mul = true;
    } else if ( opcode == "/" ) {
      is_div = true;
    }
    if ( !is_mul && !is_div ) return (osl_vector_p)nullptr;

    auto affine_multiplicative_expression = handleAffineMultiplicativeExpression( binary_operator->getLHS() );
    auto affine_unary_expression = handleAffineUnaryExpression( binary_operator->getRHS() );

    if ( affine_multiplicative_expression && affine_unary_expression  && is_mul ) {
      int coef;
      
      CLAN_debug("rule affine_multiplicative_expression.2: affine_multiplicative_expression * affine_unary_expression");
      if (!osl_vector_is_scalar( affine_multiplicative_expression ) && !osl_vector_is_scalar(affine_unary_expression)) {
        osl_vector_free(affine_multiplicative_expression);
        osl_vector_free(affine_unary_expression);
        emit_message( expr ,"non-affine expression");
	return (osl_vector_p)nullptr;
      }

      osl_vector_p ret = nullptr;
      if (osl_vector_is_scalar(affine_multiplicative_expression)) {
        coef = osl_int_get_si(affine_multiplicative_expression->precision, affine_multiplicative_expression->v[affine_multiplicative_expression->size - 1]);
        ret = osl_vector_mul_scalar(affine_unary_expression, coef);
      } else {
        coef = osl_int_get_si(affine_unary_expression->precision, affine_unary_expression->v[affine_unary_expression->size - 1]);
        ret = osl_vector_mul_scalar(affine_multiplicative_expression, coef);
      }
      osl_vector_free(affine_multiplicative_expression);
      osl_vector_free(affine_unary_expression);
      CLAN_debug_call(osl_vector_dump(stderr, ret));
      return ret;
    }

    if ( affine_multiplicative_expression && affine_unary_expression  && is_div ) {
      int val1, val2;
      
      CLAN_debug("rule affine_multiplicative_expression.3: affine_multiplicative_expression / affine_unary_expression");
      if (!osl_vector_is_scalar(affine_multiplicative_expression) || !osl_vector_is_scalar(affine_unary_expression)) {
        osl_vector_free(affine_multiplicative_expression);
        osl_vector_free(affine_unary_expression);
        emit_message(expr, "non-affine expression");
	return (osl_vector_p)nullptr;
      }
      val1 = osl_int_get_si(affine_multiplicative_expression->precision, affine_multiplicative_expression->v[affine_multiplicative_expression->size - 1]);
      val2 = osl_int_get_si(affine_unary_expression->precision, affine_unary_expression->v[affine_unary_expression->size - 1]);
      auto ret = clan_vector_term(parser_symbol, val1 / val2, NULL,
                            parser_options->precision);
      osl_vector_free(affine_multiplicative_expression);
      osl_vector_free(affine_unary_expression);
      CLAN_debug_call(osl_vector_dump(stderr, ret));
      return ret;
    }
  }
  
}

auto handleAffineExpression( const Expr* expr ){
  logg << __PRETTY_FUNCTION__ << endl;
  auto affine_multiplicative_expression = handleAffineMultiplicativeExpression( expr );

  if ( affine_multiplicative_expression ) {
    //expr->dumpColor();
    CLAN_debug("rule affine_expression.1: affine_multiplicative_expression");
    auto ret = affine_multiplicative_expression;
    CLAN_debug_call(osl_vector_dump(stderr, ret));
    return ret;
  }

  logg << "in " << __PRETTY_FUNCTION__ << endl;
  //expr->dumpColor();

  auto binary_operator = dyn_cast_or_null<BinaryOperator>(expr);
  if ( binary_operator ) {
    CLAN_debug( "rule affine_expression.2.0.1: is binary operator" );
    // operator type has to be + or -
    string opcode = binary_operator->getOpcodeStr();
    bool is_add = false;
    bool is_sub = false;
    if ( opcode == "+" ) {
      is_add = true;
    } else if ( opcode == "-" ) {
      is_sub = true;
    }
    if ( is_add == false && is_sub == false ) return (osl_vector_p)nullptr;
    CLAN_debug( "rule affine_expression.2.0.2: there is an operator + or -" );
    
    auto affine_expression = handleAffineExpression( binary_operator->getLHS() );
    auto affine_multiplicative_expression = handleAffineMultiplicativeExpression( binary_operator->getRHS() );

    if ( affine_expression && affine_multiplicative_expression && is_add ) {
      CLAN_debug("rule affine_expression.2: affine_expression + affine_multiplicative_expression");
      auto ret = osl_vector_add(affine_expression, affine_multiplicative_expression);
      osl_vector_free(affine_expression);
      osl_vector_free(affine_multiplicative_expression);
      CLAN_debug_call(osl_vector_dump(stderr, ret));
      return ret;
    }
    if ( affine_expression && affine_multiplicative_expression  && is_sub ) {
      CLAN_debug("rule affine_expression.3: affine_expression - affine_multiplicative_expression");
      auto ret = osl_vector_sub(affine_expression, affine_multiplicative_expression);
      osl_vector_free(affine_expression);
      osl_vector_free(affine_multiplicative_expression);
      CLAN_debug_call(osl_vector_dump(stderr, ret));
      return ret;
    }
  }
   
  return (osl_vector_p)nullptr;
}

auto handleCeildFloord( Expr* expr ) {
  const auto* ceild  = dyn_cast_or_null<CallExpr>(expr);
  if ( ceild ){
    auto* callee_decl = ceild->getCalleeDecl();
    auto* named_decl = dyn_cast_or_null<NamedDecl>(callee_decl);
    auto qname = named_decl->getQualifiedNameAsString();
    if ( qname.compare( "ceild" ) ==  0 ) {
      parser_ceild[parser_xfor_index]  = 1;
      return true;
    }
  }
  const auto* floord = dyn_cast_or_null<CallExpr>(expr);
  if ( floord ) {
    auto* callee_decl = ceild->getCalleeDecl();
    auto* named_decl = dyn_cast_or_null<NamedDecl>(callee_decl);
    auto qname = named_decl->getQualifiedNameAsString();
    if ( qname.compare( "floord" ) ==  0 ) {
      parser_floord[parser_xfor_index] = 1;
      return true;
    }
  }
  std::cout << "no ceild or floord" << std::endl;
  return false;
}

auto handleCeildFloordExpression( const Expr* expr ){
  logg << __PRETTY_FUNCTION__ << endl;
  auto affine_expression = handleAffineExpression( expr );
  if ( affine_expression ) {
    //expr->dumpColor();
    CLAN_debug("affine_ceildloord_expression.1: affine_expression");
    auto ret = affine_expression;
    CLAN_debug_call(osl_vector_dump(stderr, ret));
    return ret;
  }

#if 0
  auto ceildfloord = handleCeildFloord( expr );

  if ( ceildfloord ) {
   
    // TODO handle the arguments of the function 
    CLAN_debug("affine_ceildfloord_expression.2: "
	       "ceildfloord ( affine_expression , INTEGER )");
    osl_int_set_si(parser_options->precision, &($3->v[0]), $5);
    auto ret = $3;
    CLAN_debug_call(osl_vector_dump(stderr, $$));
  }
#endif
}

osl_relation_p handleAffineMinMaxExpression( const Expr* expr ){
  logg << __PRETTY_FUNCTION__ << endl;

  // is either one of them
  auto affine_ceildfloord_expression = handleCeildFloordExpression( expr );
  if ( affine_ceildfloord_expression ){
      //expr->dumpColor();
      CLAN_debug("rule affine_minmax_expression.1: <affex>");
      auto ret = osl_relation_from_vector(affine_ceildfloord_expression);
      osl_vector_free(affine_ceildfloord_expression);
      CLAN_debug_call(osl_relation_dump(stderr, ret));
      return ret;
  }

#if 0
  auto minmax = handleMinMax( expr );

  if ( minmax ) {

    // TODO handleAffineMinMaxExpression for argument 1 and argument 2 

    CLAN_debug("rule affine_minmax_expression.2: "
	       "MAX (affine_minmaxexpression , affine_minmax_expression )");
    auto ret = osl_relation_concat_constraints( ,  );
    osl_relation_free($3);
    osl_relation_free($5);
    CLAN_debug_call(osl_relation_dump(stderr, $$));
  }
#endif

}

auto handleLoopDeclaration( const Stmt* stmt ) {
  logg << __PRETTY_FUNCTION__ << endl;
  if ( auto decl_stmt = dyn_cast_or_null<DeclStmt>( stmt ) ){
    return decl_stmt;
  }
  logg << "leaving " << __PRETTY_FUNCTION__ << endl;
}

auto handleLoopInitializersInitialization( const Expr * expr ) {
  logg << __PRETTY_FUNCTION__ << endl;
  auto affine_minmax_expression = handleAffineMinMaxExpression( expr );
  if ( affine_minmax_expression ){
    //expr->dumpColor();
    CLAN_debug("rule initialization: ID = <setex>");
    parser_xfor_index++;
    //free($2);
    auto ret = affine_minmax_expression;
    CLAN_debug_call(osl_relation_dump(stderr, ret));
    return ret;
  }
}

osl_relation_p handleLoopInitialization( const Stmt* stmt ){
  logg << __PRETTY_FUNCTION__ << endl;

  // initialized with a declaration
  if( auto loop_declaration = handleLoopDeclaration( stmt ) ){
    auto loop_declaration_1 = dyn_cast_or_null<VarDecl>(loop_declaration->getSingleDecl());
    if ( loop_declaration_1 ) {
      auto ID = handleID( loop_declaration_1 );

      if ( ID ){
	if (!clan_symbol_new_iterator(&parser_symbol, parser_iterators, ID, parser_loop_depth)){
	    emit_message( stmt, "a loop iterator was previously used for something else");
	    return nullptr; 
	}
      }

      logg << "has init" <<endl;
      if ( loop_declaration_1->hasInit() ){
	return handleLoopInitializersInitialization( loop_declaration_1->getInit() );	
      }
      logg << "no it does not" << endl;
    }
  }

  // initialized with a assign operation
  auto expr = dyn_cast_or_null<Expr>( stmt );
  if ( expr ){
    auto binary_operator = dyn_cast_or_null<BinaryOperator>( expr );
    if ( binary_operator ) {
      CLAN_debug("rule loop initialization.2: assign operation");
      //binary_operator->dumpColor();
      auto ID = handleID( binary_operator->getLHS() );
      logg << "get string" << endl;
      auto opcode = binary_operator->getOpcodeStr();
      logg << "done get string " << endl;
      if ( opcode == "=" ) {
	if ( ID ) {
	  logg << "added new symbol " << ID << endl;
	  if (!clan_symbol_new_iterator(&parser_symbol, parser_iterators, ID, parser_loop_depth)){
	    emit_message( expr, "a loop iterator was previously used for something else");
	    return nullptr;
	  }
	}
	logg << "rhs of the assign operator " << endl;
	binary_operator->getRHS()->dumpColor();
	logg << "done rhs of the assign operator " << endl;

	return handleLoopInitializersInitialization( binary_operator->getRHS() );
      }
    }
  }

}

// TODO make it also handle multiple initializations
osl_relation_list_p handleLoopInitializationList( const Stmt* stmt ){
  logg << __PRETTY_FUNCTION__ << endl;
  osl_relation_list_p ret = nullptr;

  auto loop_initialization = handleLoopInitialization( stmt );
  if ( loop_initialization ){
    CLAN_debug("rule initialization_list.2: initialization ;");
    //stmt->dumpColor();
    parser_xfor_index = 0;
    ret = osl_relation_list_malloc();
    ret->elt = loop_initialization;
  }
  return ret;
}

auto is_call_to_function ( const Expr* expr, string name, int arg_count ) {
  if ( auto call_to_function = dyn_cast_or_null<CallExpr>(expr) ){
    // check name
    auto* callee_decl = call_to_function->getCalleeDecl();
    auto* named_decl = dyn_cast_or_null<NamedDecl>(callee_decl);
    auto qname = named_decl->getQualifiedNameAsString();
    if ( qname != name ) return (const CallExpr*)nullptr;

    // check arg count
    auto nargs = call_to_function->getNumArgs();
    if ( nargs != arg_count ) return (const CallExpr*)nullptr;

    return call_to_function;
  }
  return (const CallExpr*)nullptr;
}

auto handleMAX( const Expr* expr ) {
  return is_call_to_function( expr, "max", 2 );
}

auto handleMIN( const Expr* expr ) {
  return is_call_to_function( expr, "min", 2 );
}

auto handleFLOORD( const Expr* expr ){
  return is_call_to_function( expr, "floord", 2 );
}

auto handleCEILD( const Expr* expr ){
  return is_call_to_function( expr, "ceild", 2 );
}

auto handleAffineFloordExpression( const Expr* expr ){
  logg << __PRETTY_FUNCTION__ << endl;
  logg << "handleAffineFloordExpression calling handleAffineExpression" << endl;
  auto affine_expression = handleAffineExpression( expr );
  logg << "handleAffineFloordExpressio ndone calling handleAffineExpression" << endl;
  if ( affine_expression ) {
      CLAN_debug("affine_floor_expression.1: affine_expression");
      auto ret = affine_expression;
      CLAN_debug_call(osl_vector_dump(stderr, ret));
      return ret;
  }
  if ( auto FLOORD = handleFLOORD( expr ) ){
    auto affine_expression = handleAffineExpression( FLOORD->getArg(0) );
    auto integer = handleInteger( FLOORD->getArg(1) );

    if ( affine_expression && integer ) {
      CLAN_debug("affine_floor_expression.2: FLOORD ( affine_expression , INTEGER )");
      osl_int_set_si(parser_options->precision, &(affine_expression->v[0]), *integer);
      auto ret = affine_expression;
      CLAN_debug_call(osl_vector_dump(stderr, ret));
      return ret;
    }
  }
}

auto handleAffineCeildExpression( const Expr* expr ){
  logg << __PRETTY_FUNCTION__ << endl;
  logg << "handleAffineCeildExpression calling handleAffineExpression" << endl;
  auto affine_expression = handleAffineExpression( expr );
  logg << "handleAffineCeildExpression done calling handleAffineExpression" << endl;
  if ( affine_expression ) {
    CLAN_debug("affine_ceil_expression.1: affine_expression");
    auto ret = affine_expression;
    CLAN_debug_call(osl_vector_dump(stderr, ret));
    return ret;
  }
  if ( auto CEILD = handleCEILD( expr ) ){
    auto affine_expression = handleAffineExpression( CEILD->getArg(0) );
    auto integer = handleInteger( CEILD->getArg(1) );

    if ( affine_expression && integer ) {
      CLAN_debug("affine_ceil_expression.2: CEILD ( affine_expression , INTEGER )");
      osl_int_set_si(parser_options->precision, &(affine_expression->v[0]), *integer);
      auto ret = affine_expression;
      CLAN_debug_call(osl_vector_dump(stderr, ret));
      return ret;
    }
  }
}

auto handleAffineMinExpression( const Expr* expr ) {
  logg << __PRETTY_FUNCTION__ << endl;
  auto affine_floord_expression = handleAffineFloordExpression( expr );
  
  if (affine_floord_expression){
    CLAN_debug("rule affine_min_expression.1: <affex>");
    auto ret = osl_relation_from_vector(affine_floord_expression);
    osl_vector_free(affine_floord_expression);
    CLAN_debug_call(osl_relation_dump(stderr, ret));
    return ret;
  }

  if ( auto MIN = handleMIN( expr ) ) {

    auto affine_min_expression_1 = handleAffineMinExpression( MIN->getArg(0) ); 
    auto affine_min_expression_2 = handleAffineMinExpression( MIN->getArg(1) ); 
    if ( affine_min_expression_1 && affine_min_expression_2 ){
      CLAN_debug("rule affine_min_expression.2: MIN ( affine_min_expression , affine_min_expression )");
      auto ret = osl_relation_concat_constraints(affine_min_expression_1, affine_min_expression_2);
      osl_relation_free(affine_min_expression_1);
      osl_relation_free(affine_min_expression_2);
      CLAN_debug_call(osl_relation_dump(stderr, ret));
      return ret;
    }
  }
  return (osl_relation_p)nullptr;
}

osl_relation_p handleAffineCondition( const Expr* expr );

auto handleAffineMaxExpression( const Expr* expr ) {
  logg << __PRETTY_FUNCTION__ << endl;
  auto affine_ceild_expression = handleAffineCeildExpression( expr );
  
  if (affine_ceild_expression){
    CLAN_debug("rule affine_max_expression.1: <affex>");
    auto ret = osl_relation_from_vector(affine_ceild_expression);
    osl_vector_free(affine_ceild_expression);
    CLAN_debug_call(osl_relation_dump(stderr, ret));
    return ret;
  }

  if ( auto MAX = handleMAX( expr ) ) {

    auto affine_max_expression_1 = handleAffineMaxExpression( MAX->getArg(0) ); 
    auto affine_max_expression_2 = handleAffineMaxExpression( MAX->getArg(1) ); 
    if ( affine_max_expression_1 && affine_max_expression_2 ){
      CLAN_debug("rule affine_max_expression.2: MAX ( affine_max_expression , affine_max_expression )");
      auto ret = osl_relation_concat_constraints(affine_max_expression_1, affine_max_expression_2);
      osl_relation_free(affine_max_expression_1);
      osl_relation_free(affine_max_expression_2);
      CLAN_debug_call(osl_relation_dump(stderr, ret));
      return ret;
    }
  }
  return (osl_relation_p)nullptr;
}

auto handleAffineRelation( const Expr* expr ){
  logg << __PRETTY_FUNCTION__ << endl;

  enum STATES{
    IS_LESS,
    IS_LESS_EQUAL,
    IS_GREATER,
    IS_GREATER_EQUAL,
    IS_EQUAL,
    IS_MODULO,
    IS_NEGATION,
    IS_PARENTHESIS,
    MAX_STATES
  };
  bool state_array[MAX_STATES];
  for( auto&& element : state_array ){
      element = false;
  }

  auto binary_operator = dyn_cast_or_null<BinaryOperator>(expr);
  if ( binary_operator ) {

    string opcode = binary_operator->getOpcodeStr();
    if ( opcode == "<" ) {
      state_array[IS_LESS] = true;      
    }else if ( opcode == "<=" ) {
      state_array[IS_LESS_EQUAL] = true;
    }else if ( opcode == ">" ){
      state_array[IS_GREATER] = true;
    }else if ( opcode == ">=" ){
      state_array[IS_GREATER_EQUAL] = true;
    }else if ( opcode == "==" ){
      state_array[IS_EQUAL] = true;
    }else if ( opcode == "%" ){
      state_array[IS_MODULO] = true;
    }
  }

  auto unary_operator = dyn_cast_or_null<UnaryOperator>(expr);
  if ( unary_operator ) {
    string opcode = unary_operator->getOpcodeStr( unary_operator->getOpcode() );
    if ( opcode == "!" ) {
      state_array[IS_NEGATION] = true;
    }
  }

  bool is_one_true = false;
  for( auto&& element : state_array ){
    if ( element ) {
      is_one_true = true;
      break;
    }
  }
  if ( !is_one_true ) return (osl_relation_p)nullptr;
  
  if ( binary_operator ) {
    // Operations like < <= > >=

    if ( state_array[IS_LESS] ) {
        logg << "operator is less " << endl;
	logg << "checking max expression" << endl;
	auto affine_max_expression = handleAffineMaxExpression( binary_operator->getLHS() );
	auto affine_min_expression = handleAffineMinExpression( binary_operator->getRHS() );

	logg << affine_max_expression << " " << affine_min_expression << endl;
	if ( affine_max_expression && affine_min_expression ) {
	  CLAN_debug("rule affine_relation.1: max_affex < min_affex");
	  auto ret = clan_relation_greater(affine_min_expression, affine_max_expression, 1);
	  osl_relation_free(affine_max_expression);
	  osl_relation_free(affine_min_expression);
	  CLAN_debug_call(osl_relation_dump(stderr, ret));
	  return ret;
	}
    }

    if ( state_array[IS_GREATER] ) {
	auto affine_min_expression = handleAffineMinExpression( binary_operator->getLHS() );
	auto affine_max_expression = handleAffineMaxExpression( binary_operator->getRHS() );

	if ( affine_max_expression && affine_min_expression ) {
	  CLAN_debug("rule affine_relation.2: min_affex > max_affex");
	  auto ret = clan_relation_greater(affine_min_expression, affine_max_expression, 1);
	  osl_relation_free(affine_min_expression);
	  osl_relation_free(affine_max_expression);
	  CLAN_debug_call(osl_relation_dump(stderr, ret));
	  return ret;
	}
    }

    if ( state_array[IS_LESS_EQUAL]  ) {
	auto affine_max_expression = handleAffineMaxExpression( binary_operator->getLHS() );
	auto affine_min_expression = handleAffineMinExpression( binary_operator->getRHS() );

	if ( affine_max_expression && affine_min_expression ) {
	  CLAN_debug("rule affine_relation.3: max_affex <= min_affex");
	  auto ret = clan_relation_greater(affine_min_expression, affine_max_expression, 0);
	  osl_relation_free(affine_max_expression);
	  osl_relation_free(affine_min_expression);
	  CLAN_debug_call(osl_relation_dump(stderr, ret));
	  return ret;
	}
    }

    if ( state_array[IS_GREATER_EQUAL]  ) {
	auto affine_max_expression = handleAffineMaxExpression( binary_operator->getLHS() );
	auto affine_min_expression = handleAffineMinExpression( binary_operator->getRHS() );

	if ( affine_max_expression && affine_min_expression ) {
	  CLAN_debug("rule affine_relation.4: min_affex >= max_affex");
	  auto ret = clan_relation_greater( affine_min_expression, affine_max_expression, 0);
	  osl_relation_free(affine_min_expression);
	  osl_relation_free(affine_max_expression);
	  CLAN_debug_call(osl_relation_dump(stderr, ret));
	  return ret;
	}
    }

    auto affine_expression_lhs = handleAffineExpression( binary_operator->getLHS() );
    auto affine_expression_rhs = handleAffineExpression( binary_operator->getRHS() );
    if ( state_array[IS_EQUAL] && affine_expression_lhs && affine_expression_rhs ) {
      // a==b translates to a-b==0.
      osl_vector_p res;

      CLAN_debug("rule affine_relation.5: <affex> == <affex>");
      // Warning: cases like ceild(M,32) == ceild(N,32) are not handled.
      // Assert if we encounter such a case.
      assert ((osl_int_zero(parser_options->precision, affine_expression_lhs->v[0]) ||
	       osl_int_one(parser_options->precision,  affine_expression_lhs->v[0])) &&
	      (osl_int_zero(parser_options->precision, affine_expression_rhs->v[0]) ||
	       osl_int_one(parser_options->precision,  affine_expression_rhs->v[0])));
      res = osl_vector_sub(affine_expression_lhs, affine_expression_rhs);
      osl_vector_tag_equality(res);
      auto ret = osl_relation_from_vector(res);
      osl_vector_free(res);
      osl_vector_free(affine_expression_lhs);
      osl_vector_free(affine_expression_rhs);
      CLAN_debug_call(osl_relation_dump(stderr, ret));
      return ret;
    }
  }

  // USE ignoreparenimplicitcast from ASTMatchers;
  // TODO handle the parenthesis case
  //  {
  //    CLAN_debug("rule affine_relation.6: ( condition )");
  //    $$ = $2;
  //    CLAN_debug_call(osl_relation_dump(stderr, $$));
  //  }
  
  if ( unary_operator ) {
    logg << "unary operator part" << endl;
    auto affine_condition = handleAffineCondition( unary_operator->getSubExpr() );
    if ( state_array[IS_NEGATION] && affine_condition ) {
      CLAN_debug("rule affine_relation.7: ! ( condition )");
      if (clan_relation_existential(affine_condition)) {
        osl_relation_free(affine_condition);
	emit_message(unary_operator, "unsupported negation of a condition involving a modulo");
	return (osl_relation_p)nullptr;
      }
      auto ret = clan_relation_not(affine_condition);
      osl_relation_free(affine_condition);
      CLAN_debug_call(osl_relation_dump(stderr, ret));
      return ret;
    }
  }


}

auto handleAffineLogicalAndExpression( const Expr* expr ){
  logg << __PRETTY_FUNCTION__ << endl;
  auto affine_relation = handleAffineRelation( expr );
  if ( affine_relation ) {
    CLAN_debug("rule affine_logical_and_expression.1: affine_relation");
    auto ret = affine_relation;
    CLAN_debug_call(osl_relation_dump(stderr, ret));
    return ret;
  }

  auto binary_operator = dyn_cast_or_null<BinaryOperator>( expr );
  
  if ( binary_operator ) {

    string opcode = binary_operator->getOpcodeStr();
    // TODO add cast
    if ( !(opcode == "&&") ) return (osl_relation_p)nullptr;
    
    auto affine_logical_and_expression = handleAffineLogicalAndExpression( binary_operator->getLHS() );
    auto affine_relation = handleAffineRelation( binary_operator->getRHS() );

    if ( affine_logical_and_expression && affine_relation ) {
      CLAN_debug("rule affine_logical_and_expression.2: "
	         "affine_logical_and_expression && affine_relation");
      clan_relation_and(affine_logical_and_expression, affine_relation);
      auto ret = affine_logical_and_expression;
      osl_relation_free(affine_relation);
      CLAN_debug_call(osl_relation_dump(stderr, ret));
      return ret;
    }

  }

}


osl_relation_p handleAffineCondition( const Expr* expr ){
  logg << __PRETTY_FUNCTION__ << endl;
  auto affine_logical_and_expression = handleAffineLogicalAndExpression( expr );
  if ( affine_logical_and_expression ) {
    CLAN_debug("rule affine_condition.1: affine_logical_and_expression");
    auto ret = affine_logical_and_expression;
    CLAN_debug_call(osl_relation_dump(stderr, ret));
    return ret;
  }

  auto binary_operator = dyn_cast_or_null<BinaryOperator>( expr );

  if ( binary_operator ) {
    
    string opcode = binary_operator->getOpcodeStr();
    // TODO add cast
    if ( !(opcode == "||") ) return (osl_relation_p)nullptr;
    
    auto affine_condition = handleAffineCondition( binary_operator->getLHS() );
    auto affine_logical_and_expression = handleAffineLogicalAndExpression( binary_operator->getRHS() );

    if ( affine_condition && affine_logical_and_expression ){
      CLAN_debug("rule affine_condition.2: "
	         "affine_condition || affine_logical_and_expression");
      osl_relation_add(&affine_condition, affine_logical_and_expression);
      auto ret = affine_condition;
      CLAN_debug_call(osl_relation_dump(stderr, ret));
      return ret;
    }

  } 

}

auto handleLoopCondition( const Expr* expr ){
  logg << __PRETTY_FUNCTION__ << endl;
  auto affine_condition = handleAffineCondition( expr );

  if ( affine_condition ) {
    CLAN_debug("rule condition.1: <setex>");
    parser_xfor_index++;
    auto ret = affine_condition;
    CLAN_debug_call(osl_relation_dump(stderr, ret));
    return ret;
  }

}

// TODO make it work with multiple conditions
osl_relation_list_p handleLoopConditionList( const Expr* expr ){
  logg << __PRETTY_FUNCTION__ << endl;

  osl_relation_list_p ret = nullptr;
  auto loop_condition = handleLoopCondition( expr );

  if ( loop_condition ) {
      parser_xfor_index = 0;
      ret = osl_relation_list_malloc();
      ret->elt = loop_condition;
      return ret;
  }

  return ret;
}


// TODO make it ignore parenthesis
auto handleLoopStride( const Expr* expr ){
  std::cout << __PRETTY_FUNCTION__ << std::endl;

  if ( auto unary_operator = dyn_cast_or_null<UnaryOperator>( expr ) ) {
    auto decl_ref = dyn_cast_or_null<DeclRefExpr>(unary_operator->getSubExpr());
    if ( decl_ref ) {
      string opcode = unary_operator->getOpcodeStr(unary_operator->getOpcode());
      if ( opcode == "++" ) {
	parser_xfor_index++; 
	return  1;  
      }
      if ( opcode == "--" ) {
	parser_xfor_index++; 
	return -1;  
      }
    }
  }


  if ( auto binary_operator = dyn_cast_or_null<BinaryOperator>( expr ) ) {
    std::cout << "is a binary operator " << std::endl;
    auto decl_ref = ignoreImplicitCastExpressions(dyn_cast_or_null<DeclRefExpr>(binary_operator->getLHS()));
    if ( decl_ref ) {
      string opcode = binary_operator->getOpcodeStr(binary_operator->getOpcode());
      if ( opcode == "=" ){
	std::cout << "has opcode = " << std::endl;
	auto lhs = ignoreImplicitCastExpressions(binary_operator->getLHS());
	auto rhs = ignoreImplicitCastExpressions(binary_operator->getRHS());
	if ( auto decl_ref_lhs = dyn_cast_or_null<DeclRefExpr>( lhs ) ){
	  if ( auto binary_operator_rhs = dyn_cast_or_null<BinaryOperator>( rhs ) ){
	    // TODO add check : decl_ref_lhs and decl_ref have to reference the same variable
	    string opcode = binary_operator_rhs->getOpcodeStr(binary_operator_rhs->getOpcode());
	    if( auto integer = handleInteger( binary_operator_rhs->getRHS() ) ){
	      if ( opcode == "+" ){
		parser_xfor_index++; 
		return *integer; // TODO i see a memory leak here !?!?!
	      }
	      if ( opcode == "-" ) {
		parser_xfor_index++; 
		return - *integer;
	      }
	    }
	  }
	}
      }
      if ( opcode == "+=" || opcode == "-=" ){
	std::cout << "is a plus/minus equal operator" << std::endl;
	auto lhs = ignoreImplicitCastExpressions(binary_operator->getLHS());
	auto rhs = ignoreImplicitCastExpressions(binary_operator->getRHS());
	if ( auto decl_ref_lhs = dyn_cast_or_null<DeclRefExpr>( lhs ) ){
	  if( auto integer = handleInteger( rhs ) ){
	    if ( opcode == "+=" ) {
	      parser_xfor_index++;  // i have no idea why this is needed
	      return *integer;
	    } 
	    if ( opcode == "-=" ) {
	      parser_xfor_index++; 
	      return -*integer;
	    }
	  }
	}
      }
      // perhaps calls to advance for iterators are interesting
    }
  }

  return 0;

}

// TODO handle multiple strides
auto handleLoopStrideList(const Expr* expr){
  std::cout << __PRETTY_FUNCTION__ << std::endl;

  auto loop_stride = handleLoopStride( expr );
  if ( loop_stride ) {
    auto ret = (int*)malloc(sizeof(int));
    ret[0] = loop_stride;
    return ret;
  }
  return (int*)nullptr;
}

auto handleIfStatement( const Stmt* stmt ){

  if ( auto if_stmt = dyn_cast_or_null<IfStmt>(stmt) ){
    return if_stmt;
  }
}

osl_statement_p handleStatement( const Stmt* stmt, const Stmt* parent );

auto handleSelectionElseStatement( const Stmt* stmt, const Stmt* parent ){
  if (!parser_valid_else[parser_if_depth]) {
    emit_message( stmt, "unsupported negation of a condition involving a modulo");
    return (osl_statement_p)nullptr;
  }
  auto statement = handleStatement( stmt, parent );
  if ( statement ) {
      CLAN_debug("rule selection_else_statement.1: else <stmt>");
      auto ret = statement;
      CLAN_debug_call(osl_statement_dump(stderr, ret));
      return ret;
  } 
  return (osl_statement_p)nullptr;
}


// TODO why does it just work for if statements with an else branch ?
auto handleSelectionStatement( const Stmt* stmt ){
  logg << __PRETTY_FUNCTION__ << std::endl;
  if ( auto if_stmt = handleIfStatement( stmt ) ) {
    auto affine_condition = handleAffineCondition( if_stmt->getCond() );
    if ( affine_condition ) {
      CLAN_debug("rule selection_statement.1.1: if ( condition ) ...");
      clan_domain_dup(&parser_stack);
      clan_domain_and(parser_stack, affine_condition);
      parser_if_depth++;
      if ((parser_loop_depth + parser_if_depth) > CLAN_MAX_DEPTH)
	CLAN_error("CLAN_MAX_DEPTH reached, recompile with a higher value");

      if( auto statement = handleStatement( if_stmt->getThen(), if_stmt ) ){
	osl_relation_p not_if;
	
	CLAN_debug("rule selection_statement.1.2: if ( condition ) <stmt> ...");
	clan_domain_drop(&parser_stack);
	clan_domain_dup(&parser_stack);
	if (!clan_relation_existential(affine_condition)) {
	  not_if = clan_relation_not(affine_condition);
	  clan_domain_and(parser_stack, not_if);
	  osl_relation_free(not_if);
	  parser_valid_else[parser_if_depth] = 1;
	} else {
	  parser_valid_else[parser_if_depth] = 0;
	}
	osl_relation_free(affine_condition);

	if ( auto selection_else_statement = handleSelectionElseStatement( if_stmt->getElse(), if_stmt ) ) {
	  CLAN_debug("rule selection_statement.1.3: if ( condition ) <stmt>"
		     "[else <stmt>]");
	  clan_domain_drop(&parser_stack);
	  auto ret = statement;
	  osl_statement_add(&ret, selection_else_statement);
	  parser_if_depth--;
	  parser_nb_local_dims[parser_loop_depth + parser_if_depth] = 0;
	  CLAN_debug_call(osl_statement_dump(stderr, ret));
	  return ret;
	}
      }
    }
  }
  return (osl_statement_p)nullptr;
}

osl_statement_p handleLoopBody( const Stmt* stmt, const Stmt* parent );

auto handleFOR( const Stmt* stmt ){
  if ( auto for_stmt = dyn_cast_or_null<ForStmt>( stmt ) ){
    return for_stmt;
  }
}

// TODO add infinit loops
auto handleIterationStatement( const Stmt* stmt ){
  logg << __PRETTY_FUNCTION__ << endl;

  osl_statement_p ret = nullptr;
  auto FOR = handleFOR( stmt );
  if ( FOR ) {
    auto loop_initialization_list = handleLoopInitializationList( FOR->getInit() );
    std::cout << "fished loop initialization list" << std::endl;
    if ( loop_initialization_list ) {
      auto loop_condition_list = handleLoopConditionList( FOR->getCond() );
      std::cout << "finished loop condition list" << std::endl;
      if ( loop_condition_list ) {
	cout << "calling loop stride list" << endl;
	auto loop_stride_list = handleLoopStrideList( FOR->getInc() );
	if ( loop_stride_list ) {
	  CLAN_debug("rule iteration_statement.2.1: for ( init cond stride ) ...");
	  parser_xfor_labels[parser_loop_depth] = 0;
	  clan_parser_increment_loop_depth();
	 
	  // Check there is only one element in each list
	  if (parser_xfor_index != 1) {
	    emit_message( stmt, "unsupported element list in a for loop");
	    osl_relation_list_free(loop_initialization_list);
	    osl_relation_list_free(loop_condition_list);
	    free(loop_stride_list);
	    return ret;
	  }

	  // Check loop bounds and stride consistency and reset sanity sentinels.
	  if (!clan_parser_is_loop_sane(loop_initialization_list, loop_condition_list, loop_stride_list, stmt)){
	    return ret;
	  }

	  // Add the constraints contributed by the for loop to the domain stack.
	  clan_domain_dup(&parser_stack);
	  clan_domain_for(parser_stack, parser_loop_depth, parser_symbol,
			  loop_initialization_list->elt, loop_condition_list->elt, loop_stride_list[0], parser_options);

	  parser_xfor_index = 0;
	  osl_relation_list_free(loop_initialization_list);
	  osl_relation_list_free(loop_condition_list);
	  loop_initialization_list = NULL; // To avoid conflicts with the destructor TODO: avoid that.
	  loop_condition_list = NULL;
	  parser_scattering[2*parser_loop_depth-1] = (loop_stride_list[0] > 0) ? 1 : -1;
	  parser_scattering[2*parser_loop_depth] = 0;
	  free(loop_stride_list);
	
	  auto loop_body = handleLoopBody( FOR->getBody(), FOR );
	  if (loop_body ){
	    CLAN_debug("rule iteration_statement.2.2: for ( init cond stride ) body");
	    ret = loop_body;
	    CLAN_debug_call(osl_statement_dump(stderr, ret));
	    return ret;
	  }
	}
      }
    }
  } 
  return ret;
}


auto handleStatementList ( const Stmt* const* begin, const Stmt* const* end, const Stmt* parent ){
  logg << __PRETTY_FUNCTION__ << endl;

  // case 1: just one statement;
  if ( std::distance( begin, end ) == 1 ){
    auto ret = handleStatement( *begin, parent );
    return ret;
  }

  // case 2: multiple statements
  auto statement_list = handleStatementList( begin, end - 1, parent );
  auto statement = handleStatement( *(end - 1), parent );
  osl_statement_add(&statement_list, statement);
  return statement_list;
}

auto handleCompoundStatement( const Stmt* stmt ){
  logg << __PRETTY_FUNCTION__ << endl;
  if ( auto compound_stmt = dyn_cast_or_null<CompoundStmt>( stmt ) ) {
    if ( compound_stmt->size() > 0 ) {
      auto ret = handleStatementList( compound_stmt->body_begin(), compound_stmt->body_end(), compound_stmt );
      return ret; 
    }
  }
}

auto handleAssignmentOperator( const Expr* expr ){
  if ( auto binary_operator = dyn_cast_or_null<BinaryOperator> ( expr ) ){
    auto opcode = binary_operator->getOpcodeStr();
    if ( opcode == "=" ) {
      return CLAN_TYPE_WRITE;
    }

    // the rest are read-write operators 
    if (  opcode == "*=" ||
	  opcode == "/=" ||
	  opcode == "%=" ||
	  opcode == "+=" ||
	  opcode == "-=" ||
	  opcode == "<<=" ||
	  opcode == ">>=" ||
	  opcode == "&=" ||
	  opcode == "|=" ||
	  opcode == "^="
	){
      return CLAN_TYPE_RDWR;
    }
  }
  return 0;
}

// TODO this is actually not wrong. the content from the integer or other things is simply a nullptr 
// i have no idea why
auto handlePrimaryExpression( const Expr* expr ){
  logg << __PRETTY_FUNCTION__ << endl;
  match_wrapper* ret = nullptr;
  auto ID = handleID( expr );
  if ( ID ) {
    int nb_columns;
    osl_relation_p id;
    osl_relation_list_p list;
    clan_symbol_p symbol;

    CLAN_debug("rule primary_expression.1: ID");
    symbol = clan_symbol_add(&parser_symbol, ID, CLAN_UNDEFINED);
    nb_columns = CLAN_MAX_DEPTH + CLAN_MAX_LOCAL_DIMS +
		       CLAN_MAX_PARAMETERS + 2;
    id = osl_relation_pmalloc(parser_options->precision, 0, nb_columns);
    osl_relation_set_attributes(id, 0, parser_loop_depth, 0,
				CLAN_MAX_PARAMETERS);
    clan_relation_tag_array(id, symbol->key);
    list = osl_relation_list_malloc();
    list->elt = id;

    // add the id to the extbody
    if (parser_options->extbody) {
      if (parser_access_start != -1) {
	osl_extbody_add(parser_access_extbody,
			parser_access_start,
			parser_access_length);
      }

      int len = strlen(parser_record);
      parser_access_start = len - strlen(ID);
      parser_access_length = len - parser_access_start;
    }

    free(ID);
    ret = match_successful(list);
    CLAN_debug_call(osl_relation_list_dump(stderr, ret->result));
    return ret;
  }
  // TODO i think all of this can be removed
  auto integer = handleInteger( expr );
  if ( integer ) {
    return match_successful(nullptr);
  }
  // TODO CONSTANT
  
  // TODO STRING_LITERAL
  logg << "was not recognized as something usefull" << endl;
  return match_fail();
}

match_wrapper_p handleAssignmentExpression( const Expr* expr );

auto handleArgumentExpressionList( const Expr* const* expressions, int n_expressions ){
  if ( n_expressions == 1 ) {
    auto assignment_expression = handleAssignmentExpression( expressions[0] ) ;
    if ( assignment_expression ) {
      return assignment_expression ;
    }
  } 
  auto argument_expression_list = handleArgumentExpressionList( expressions, n_expressions - 1 );
  auto assignment_expression = handleAssignmentExpression( expressions[n_expressions-1] );
  if ( argument_expression_list && assignment_expression ) {
    auto ret = argument_expression_list;
    osl_relation_list_add(&ret->result, assignment_expression->result);
    return ret;
  }
}


auto handlePostfixExpression( const Expr* expr ){
  auto primary_expression = handlePrimaryExpression( expr );
  if ( primary_expression ) {
    return primary_expression;
  }

  // TODO also handle a[4] and 4[a]
  auto subscript_expression = dyn_cast_or_null<ArraySubscriptExpr>( expr );
  if ( subscript_expression ){
    auto postfix_expression = handlePostfixExpression( ignoreImplicitCastExpressions( subscript_expression->getLHS() ) );
    auto affine_expression = handleAffineExpression(   ignoreImplicitCastExpressions( subscript_expression->getRHS() ) );
    if ( affine_expression ){
      if (parser_options->extbody)
        parser_access_length = strlen(parser_record) - parser_access_start;

      CLAN_debug("rule postfix_expression.2: postfix_expression [ <affex> ]");
      if (!clan_symbol_update_type(parser_symbol, postfix_expression->result, CLAN_TYPE_ARRAY)){
	emit_message( subscript_expression ,"illegal use of an iterator (update or reference) in a statement");
        return match_fail();
      }
      clan_relation_new_output_vector(postfix_expression->result->elt, affine_expression);
      osl_vector_free(affine_expression);
      auto ret = postfix_expression;
      CLAN_debug_call(osl_relation_list_dump(stderr, ret->result));
      return ret;
    }
  }

  // NOTE the 3rd rule is a copy of the 2nd rule but handles arguemnts
  //      we can simply ignore this
  auto function_call = dyn_cast_or_null<CallExpr>( expr );
  if ( function_call ){

    //emit_message( function_call, "Assuming this function has no side effects" );
    auto postfix_expression = handlePostfixExpression( expr );

    if ( postfix_expression ){
      // don't save access name of a function
      if (parser_options->extbody) {
	parser_access_extbody->nb_access -= osl_relation_list_count(postfix_expression->result) - 1;
	parser_access_start = -1;
      }

      if (!clan_symbol_update_type(parser_symbol, postfix_expression->result, CLAN_TYPE_FUNCTION)){
	emit_message( function_call ,"illegal use of an iterator (update or reference) in a statement");
        return match_fail();
      }
      osl_relation_list_free(postfix_expression->result);

      auto argument_expression_list = handleArgumentExpressionList( function_call->getArgs(), function_call->getNumArgs() );
      if ( argument_expression_list ) {
	return argument_expression_list;
      }

      return match_fail();
    }
  }

  // TODO handle . and -> 
  auto member_access = dyn_cast_or_null<MemberExpr>( expr );
  if ( member_access ){

    auto postfix_expression = handlePostfixExpression( member_access->getBase() );
    emit_message( member_access, "member access is currently not implemented" );
    return match_fail();
    // TODO needs custom implementation of ID handling
#if 0
    auto ID = handleID( member_access );

    if ( postfix_expression ){
      if (parser_options->extbody)
        parser_access_length = strlen(parser_record) - parser_access_start;

      clan_symbol_p symbol;

      CLAN_debug("rule postfix_expression.4: postfix_expression . ID");
      if (!clan_symbol_update_type(parser_symbol, postfix_expression, CLAN_TYPE_ARRAY))
        YYABORT;
      symbol = clan_symbol_add(&parser_symbol, $3, CLAN_TYPE_FIELD);
      clan_relation_new_output_scalar($1->elt, symbol->key);
      free($3);
      $$ = $1;
      CLAN_debug_call(osl_relation_list_dump(stderr, $$));
    }
#endif
  } 

  auto unary_operator = dyn_cast_or_null<UnaryOperator> ( expr );
  if ( unary_operator ){
    auto postfix_expression = handlePostfixExpression( unary_operator->getSubExpr() );
    auto opcode = unary_operator->getOpcodeStr(unary_operator->getOpcode());
    if ( (opcode == "++" || opcode == "--") && unary_operator->isPostfix() && postfix_expression ){
      osl_relation_list_p list;

      CLAN_debug("rule postfix_expression.6: postfix_expression -> "
	         "postfix_expression ++/--");
      if (!clan_symbol_update_type(parser_symbol, postfix_expression->result, CLAN_TYPE_ARRAY)){
	emit_message(unary_operator ,"illegal use of an iterator (update or reference) in a statement");
        return match_fail();
      }

      list = postfix_expression->result;
      // The last reference in the list is also written.
      if (list != NULL) {
        while (list->next != NULL)
          list = list->next;
        list->next = osl_relation_list_node(list->elt);
        list->next->elt->type = OSL_TYPE_WRITE;
      }
      auto ret = postfix_expression;
      CLAN_debug_call(osl_relation_list_dump(stderr, ret->result));

      // add an empty line in the extbody
      if (parser_options->extbody) {
        osl_extbody_add(parser_access_extbody, -1, -1);
      }
      return ret;
    }
  }
  return match_fail();
}

match_wrapper_p handleCastExpression( const Expr* expr );

auto handleUnaryExpression( const Expr* expr ){
  auto postfix_expression = handlePostfixExpression( expr );
  if ( postfix_expression ) {
    return postfix_expression;
  }
  
  auto unary_operator = dyn_cast_or_null<UnaryOperator>( expr );
  if ( unary_operator ) {
    auto opcode = unary_operator->getOpcodeStr( unary_operator->getOpcode() );
    if ( opcode == "++" && unary_operator->isPrefix() ) {
      auto unary_expression = handleUnaryExpression( unary_operator->getSubExpr() );

      CLAN_debug("rule unary_expression.2: unary_expression -> "
	         "++/-- unary_expression");
      if (!clan_symbol_update_type(parser_symbol, unary_expression->result, CLAN_TYPE_ARRAY)){
	emit_message( unary_operator, "illegal use of an iterator (update or reference) in a statement");
	return match_fail();
      }
      auto list = unary_expression->result;
      // The last reference in the list is also written.
      if (list != NULL) {
        while (list->next != NULL)
          list = list->next;
        list->next = osl_relation_list_node(list->elt);
        list->next->elt->type = OSL_TYPE_WRITE;
      }
      auto ret = unary_expression;
      CLAN_debug_call(osl_relation_list_dump(stderr, ret->result));

      // add an empty line in the extbody
      if (parser_options->extbody) {
        osl_extbody_add(parser_access_extbody, -1, -1);
      }
      return ret;
    }

    std::vector<string> operators { "+", "-", "*", "!", "~", "&" };
    for( auto&& element : operators ){
      if ( opcode == element ) {
	auto cast_expression = handleCastExpression( unary_operator->getSubExpr() );
	return cast_expression;
      }
    }
  }

  auto sizeof_expression = dyn_cast_or_null<UnaryExprOrTypeTraitExpr>( expr );
  if( sizeof_expression ) {
    assert( 0 && "add the check whether this is really a sizeof_expression" );
    return handleUnaryExpression( sizeof_expression->getArgumentExpr() );
  }
  return match_fail();

}

match_wrapper_p handleCastExpression( const Expr* expr ){
  auto unary_expression = handleUnaryExpression( expr );
  if ( unary_expression ) {
    return unary_expression;
  }

  auto cast_expression = dyn_cast_or_null<CastExpr>( expr );
  if ( cast_expression ) {
    auto cast_expression_subexpr = handleCastExpression( cast_expression->getSubExpr() );
    if ( cast_expression_subexpr ) {
      return cast_expression_subexpr;
    }
  }
  return match_fail();

}

auto handleMultiplicativeExpression( const Expr* expr ){
  auto cast_expression = handleCastExpression( expr );
  if ( cast_expression ){
    return cast_expression;
  }
 
  auto binary_operator = dyn_cast_or_null<BinaryOperator>( expr );
  if ( binary_operator ) {
    auto opcode = binary_operator->getOpcodeStr();
    if ( opcode == "*" || opcode == "/" || opcode == "%=" ) {
      auto multiplicative_expression = handleMultiplicativeExpression( binary_operator->getLHS() );
      auto cast_expression = handleCastExpression( binary_operator->getRHS() );

      if ( multiplicative_expression && cast_expression ) {
	auto ret = multiplicative_expression;
	osl_relation_list_add(&ret->result, cast_expression->result);
	return ret;
      }
    }
  }
 
  return match_fail();
}

auto handleAdditiveExpression( const Expr* expr ){
  auto multiplicative_expression = handleMultiplicativeExpression ( expr );
  if ( multiplicative_expression ) {
    return multiplicative_expression;
  }

  auto binary_operator = dyn_cast_or_null<BinaryOperator>( expr );
  if ( binary_operator ) {
    auto opcode = binary_operator->getOpcodeStr();
    if ( opcode == "+" || opcode == "-"  ) {
      auto additive_expression = handleAdditiveExpression( binary_operator->getLHS() );
      auto multiplicative_expression = handleMultiplicativeExpression( binary_operator->getRHS() );

      if ( additive_expression && multiplicative_expression ) {
	auto ret = additive_expression;
	osl_relation_list_add(&ret->result, multiplicative_expression->result);
	return ret;
      }
    }
  }
 
  return match_fail();
}

auto handleShiftExpression( const Expr* expr ){
  auto additive_expression = handleAdditiveExpression( expr );
  if ( additive_expression ) {
    return additive_expression;
  }

  auto binary_operator = dyn_cast_or_null<BinaryOperator>( expr );
  if ( binary_operator ) {
    auto opcode = binary_operator->getOpcodeStr();
    if ( opcode == "<<" || opcode == ">>"  ) {
      auto shift_expression = handleShiftExpression( binary_operator->getLHS() );
      auto additive_expression = handleAdditiveExpression( binary_operator->getRHS() );

      if ( shift_expression && additive_expression ) {
	auto ret = shift_expression;
	osl_relation_list_add(&ret->result, additive_expression->result);
	return ret;
      }
    }
  }


  return match_fail();
}

auto handleRelationalExpression( const Expr* expr ){
  auto shift_expression = handleShiftExpression ( expr );
  if ( shift_expression ) {
    return shift_expression;
  }
  
  auto binary_operator = dyn_cast_or_null<BinaryOperator>( expr );
  if ( binary_operator ) {
    auto opcode = binary_operator->getOpcodeStr();
    if ( opcode == "<" || opcode == "<=" || opcode == ">" || opcode == ">=" ) {
      auto relational_expression = handleRelationalExpression( binary_operator->getLHS() );
      auto shift_expression = handleShiftExpression( binary_operator->getRHS() );

      if ( relational_expression && shift_expression ) {
	auto ret = relational_expression;
	osl_relation_list_add(&ret->result, shift_expression->result);
	return ret;
      }
    }
  }
  
  return match_fail();
}

auto handleEqualityExpression( const Expr* expr ){
  auto relational_expression = handleRelationalExpression( expr );
  if ( relational_expression ) {
    return relational_expression;
  }

  auto binary_operator = dyn_cast_or_null<BinaryOperator>( expr );
  if ( binary_operator ) {
    auto opcode = binary_operator->getOpcodeStr();
    if ( opcode == "==" || opcode == "!=" ) {
      auto equality_expression = handleEqualityExpression( binary_operator->getLHS() );
      auto relational_expression = handleRelationalExpression( binary_operator->getRHS() );

      if ( equality_expression && relational_expression ) {
	auto ret = equality_expression;
	osl_relation_list_add(&ret->result, relational_expression->result);
	return ret;
      }
    }
  }
  

  return match_fail();
}

auto handleAndExpression( const Expr* expr ){
  auto equality_expression = handleEqualityExpression( expr );
  if ( equality_expression ) {
    return equality_expression;
  }

  auto binary_operator = dyn_cast_or_null<BinaryOperator>( expr );
  if ( binary_operator ) {
    auto opcode = binary_operator->getOpcodeStr();
    if ( opcode == "&" ) {
      auto and_expression = handleAndExpression( binary_operator->getLHS() );
      auto equality_expression = handleEqualityExpression( binary_operator->getRHS() );

      if ( and_expression && equality_expression ) {
	auto ret = and_expression;
	osl_relation_list_add(&ret->result, equality_expression->result);
	return ret;
      }
    }
  }
  
  return match_fail();
}

auto handleExclusiveOrExpression( const Expr* expr ){
  if( auto and_expression = handleAndExpression( expr ) ){
    return and_expression;
  }

  auto binary_operator = dyn_cast_or_null<BinaryOperator>( expr );
  if ( binary_operator ) {
    auto opcode = binary_operator->getOpcodeStr();
    if ( opcode == "^" ) {
      auto exclusive_or_expression = handleExclusiveOrExpression( binary_operator->getLHS() );
      auto and_expression = handleAndExpression( binary_operator->getRHS() );

      if ( exclusive_or_expression && and_expression ) {
	auto ret = exclusive_or_expression;
	osl_relation_list_add(&ret->result, and_expression->result);
	return ret;
      }
    }
  }
  
  return match_fail();
}

auto handleInclusiveOrExpression( const Expr* expr ){
  auto exclusive_or_expression = handleExclusiveOrExpression( expr );
  if ( exclusive_or_expression ) {
    return exclusive_or_expression;
  }

  auto binary_operator = dyn_cast_or_null<BinaryOperator>( expr );
  if ( binary_operator ) {
    auto opcode = binary_operator->getOpcodeStr();
    if ( opcode == "|" ) {
      auto inclusive_or_expression = handleInclusiveOrExpression( binary_operator->getLHS() );
      auto exclusive_or_expression = handleExclusiveOrExpression( binary_operator->getRHS() );

      if ( inclusive_or_expression && exclusive_or_expression ) {
	auto ret = inclusive_or_expression;
	osl_relation_list_add(&ret->result, exclusive_or_expression->result);
	return ret;
      }
    }
  }
  return match_fail();
}

auto handleLogicalAndExpression( const Expr* expr ){
  auto inclusive_or_expression = handleInclusiveOrExpression ( expr );
  if ( inclusive_or_expression ){
    return inclusive_or_expression;
  } 

  auto binary_operator = dyn_cast_or_null<BinaryOperator>( expr );
  if ( binary_operator ) {
    auto opcode = binary_operator->getOpcodeStr();
    if ( opcode == "&&" ) {
      auto logical_and_expression = handleLogicalAndExpression( binary_operator->getLHS() );
      auto inclusive_or_expression = handleInclusiveOrExpression( binary_operator->getRHS() );
      if ( logical_and_expression && inclusive_or_expression ) {
	auto ret = logical_and_expression;
	osl_relation_list_add(&ret->result, inclusive_or_expression->result);
	return ret;
      }
    }
  }
  
  return match_fail();
}

auto handleLogicalOrExpression( const Expr* expr ){
  auto logical_and_expression = handleLogicalAndExpression( expr );
  if ( logical_and_expression ){
    return logical_and_expression;
  }
  
  auto binary_operator = dyn_cast_or_null<BinaryOperator>( expr );
  if ( binary_operator ) {
    auto opcode = binary_operator->getOpcodeStr();
    if ( opcode == "||" ) {
      auto logical_or_expression = handleLogicalOrExpression( binary_operator->getLHS() );
      auto logical_and_expression = handleLogicalAndExpression( binary_operator->getRHS() );
      if ( logical_or_expression && logical_and_expression ) {
	auto ret = logical_or_expression;
	osl_relation_list_add(&ret->result, logical_and_expression->result);
	return ret;
      }
    }
  }


  return match_fail();
}

match_wrapper_p handleExpression( const Expr* expr );

auto handleConditionalExpression( const Expr* expr ){
  auto logical_or_expression = handleLogicalOrExpression( expr );
  if ( logical_or_expression ) {
    return logical_or_expression;
  }
  
  // ConditionalOperator
  
  auto conditional_operator = dyn_cast_or_null<ConditionalOperator>( expr );
  if ( conditional_operator ){

    auto logical_or_expression = handleLogicalOrExpression(conditional_operator->getCond());
    auto expression = handleExpression( conditional_operator->getTrueExpr() );
    auto conditional_expression = handleConditionalExpression( conditional_operator->getFalseExpr() );

    if ( logical_or_expression && expression && conditional_expression ) {
      auto ret = logical_or_expression;
      osl_relation_list_add(&ret->result, expression->result);
      osl_relation_list_add(&ret->result, conditional_expression->result);
      return ret;
    }
  }
  return match_fail();
}


// TODO i believe the problem is that the return value of some of these functions can be nullptr 
// eaven if it matches the expression
// since my assumption was that a match should return something except nullptr 
// nothing works anymore
match_wrapper_p handleAssignmentExpression( const Expr* expr ){
  auto conditional_expression = handleConditionalExpression( expr );
  if ( conditional_expression ){
    CLAN_debug("rule assignment_expression.1: conditional_expression;");
    auto ret = conditional_expression;
    clan_relation_list_define_type(ret->result, OSL_TYPE_READ);
    CLAN_debug_call(osl_relation_list_dump(stderr, ret->result));
    return ret;
  }
  
  auto assignment_operator = handleAssignmentOperator( expr );
  if ( assignment_operator ) {
    auto binary_operator = dyn_cast_or_null<BinaryOperator>( expr );
    auto unary_expression = handleUnaryExpression( binary_operator->getLHS() );
    auto assignment_expression = handleAssignmentExpression( binary_operator->getRHS() );

    if ( unary_expression && assignment_expression ) {

      CLAN_debug("rule assignment_expression.2: unary_expression "
	         "assignment_operator assignment_expression;");
      if (!clan_symbol_update_type(parser_symbol, unary_expression->result, CLAN_TYPE_ARRAY)){
	emit_message( expr, "illegal use of an iterator (update or reference) in a statement");
        return match_fail();
      }
      auto ret = unary_expression;
      // Accesses of $1 are READ except the last one which is a WRITE or both.
      clan_relation_list_define_type(ret->result, OSL_TYPE_READ);
      auto list = ret->result;
      while (list->next != NULL)
        list = list->next;
      if (assignment_operator == CLAN_TYPE_RDWR) {
        list->next = osl_relation_list_node(list->elt);
        list = list->next;

        // add an empty line in the extbody
        if (parser_options->extbody) {
          osl_extbody_add(parser_access_extbody, -1, -1);
        }
      }
      osl_relation_set_type(list->elt, OSL_TYPE_WRITE);
      osl_relation_list_add(&ret->result, assignment_expression->result);
      CLAN_debug_call(osl_relation_list_dump(stderr, ret->result));
      return ret;
    }
  }
  return match_fail();
}

match_wrapper_p handleExpression( const Expr* expr ){
  auto assignment_expression = handleAssignmentExpression( expr );
  if ( assignment_expression ) {
    return assignment_expression;
  }

  // TODO handle expression , assign 
  return match_fail();
}

osl_statement_p handleExpressionStatement( const Stmt* stmt, const Stmt* parent ){
  logg << __PRETTY_FUNCTION__ << endl;
  osl_statement_p ret = nullptr;

  if (parser_options->extbody) {
    parser_access_start = -1;
    parser_access_extbody = osl_extbody_malloc();
  }

  // This is where the statements string is recorded into the openscop structure
  // TODO in addition to the osl statement store the pointer to the ast node 
  auto statement_str = getString( stmt );
  statement_str += ";";
  CLAN_strdup(parser_record, statement_str.c_str());
  parser_recording = CLAN_TRUE;

  auto expr = dyn_cast_or_null<Expr>(stmt);
  if ( expr ) {
    auto expression = handleExpression( expr );
    if ( expression ) {
      osl_statement_p statement;
      osl_body_p body;
      osl_generic_p gen;
      
      CLAN_debug("rule expression_statement.2: expression ;");
      statement = osl_statement_malloc();

      // - 1. Domain
      if (clan_relation_list_nb_elements(parser_stack->constraints) != 1) {
	emit_message( stmt, "missing label on a statement inside an xfor loop");
	return ret;
      }
      statement->domain = osl_relation_clone(parser_stack->constraints->elt);
      osl_relation_set_type(statement->domain, OSL_TYPE_DOMAIN);
      osl_relation_set_attributes(statement->domain, parser_loop_depth, 0,
				  clan_parser_nb_ld(), CLAN_MAX_PARAMETERS);

      // - 2. Scattering
      statement->scattering = clan_relation_scattering(parser_scattering,
	  parser_loop_depth, parser_options->precision);

      // - 3. Array accesses
      statement->access = expression->result;

      // - 4. Body.
      body = osl_body_malloc();
      body->iterators = clan_symbol_array_to_strings(parser_iterators,
	  parser_loop_depth, parser_xfor_depths, parser_xfor_labels);
      body->expression = osl_strings_encapsulate(parser_record);
      gen = osl_generic_shell(body, osl_body_interface());
      osl_generic_add(&statement->extension, gen);

      if (parser_options->extbody) {
	// Extended body

	// add the last access
	if (parser_access_start != -1) {
	  osl_extbody_add(parser_access_extbody,
			  parser_access_start,
			  parser_access_length);
	}

	parser_access_extbody->body = osl_body_clone(body);
	gen = osl_generic_shell(parser_access_extbody, osl_extbody_interface());
	osl_generic_add(&statement->extension, gen);

      }

      std::vector<std::string> iterators;
      int idx = 0;
      // TODO generate a vector of strings
      while( body->iterators->string[idx] ){
	cout << body->iterators->string[idx] << endl;
	iterators.push_back(body->iterators->string[idx]);
	idx++;
      }

#if 1
      auto statement_str_with_comments = getStringWithComments( stmt, parent, iterators );
      global_statement_texts->push_back( statement_str_with_comments );

#endif

#if 1
      (*global_osl_to_clang)[statement] = stmt;
      std::cout << "mapping " << statement << " to " << stmt << std::endl;
#endif

      parser_recording = CLAN_FALSE;
      parser_record = NULL;
      
      parser_scattering[2*parser_loop_depth]++;

      ret = statement;
      CLAN_debug_call(osl_statement_dump(stderr, ret));
      return ret;
    }
  }
  return ret;
}

// TODO continue there is a lot more about statements
osl_statement_p handleStatement( const Stmt* stmt, const Stmt* parent ){
  logg << __PRETTY_FUNCTION__ << endl;

#if 0
  auto labeled_statement = handleLabeledStatement( stmt );
  if ( labeled_statement ) {
    return labeled_statement;
  }
#endif

  auto compound_statement = handleCompoundStatement( stmt );
  if( compound_statement ) {
    return compound_statement;
  }

  auto selection_statement = handleSelectionStatement( stmt );
  if ( selection_statement ) {
    return selection_statement;
  }

  auto iteration_statement = handleIterationStatement( stmt );
  if ( iteration_statement ) {
    return iteration_statement;
  }

  auto expression_statement = handleExpressionStatement( stmt, parent );
  if ( expression_statement ) {
    return expression_statement;
  }

  emit_message( stmt, "could not understand this statement" );
  // TODO if it can not handle the statement. 
  // throw an exception or some how emit an error message 
  return (osl_statement_p)nullptr;
}

osl_statement_p handleLoopBody( const Stmt* stmt, const Stmt* parent ){
  logg << __PRETTY_FUNCTION__ << endl;
  osl_statement_p ret = nullptr;
  auto statement = handleStatement( stmt, parent );
  if ( statement ) {
    CLAN_debug("rule loop_body.1: <stmt>");
    clan_parser_decrement_loop_depth();
    assert( parser_loop_depth >= 0 && "parser_loop_depth negative" );
    clan_symbol_free(parser_iterators[parser_loop_depth]);
    parser_iterators[parser_loop_depth] = NULL;
    clan_domain_drop(&parser_stack);
    ret = statement;
    parser_scattering[2*parser_loop_depth]++;
    assert( parser_loop_depth + parser_if_depth >= 0 && "expr negative" );
    parser_nb_local_dims[parser_loop_depth + parser_if_depth] = 0;
    CLAN_debug_call(osl_statement_dump(stderr, ret));
    return ret;
  }
  return ret;
}

osl_scop_p handleForLoop( const ForStmt* for_loop, const SourceManager& SM, string filename, std::vector<std::pair<SourceRange,std::string>>& messages, vector<std::string>& statement_texts, std::map<osl_statement_p,const Stmt*>& osl_to_clang ){

  static bool once = true;
  if ( once ) {
    // reopen stdout and stderr
    std::freopen("/home/incubus/log/clan_redir_stdout.log", "w", stdout);
    std::freopen("/home/incubus/log/clan_redir_stderr.log", "w", stderr);
    // set buffering to Line buffering like on normal terminals 
    setvbuf ( stdout , NULL , _IOLBF , 1024 );
    setvbuf ( stderr , NULL , _IOLBF , 1024 );
    once = false;
  }

  global_statement_texts = &statement_texts;
  global_SM = (SourceManager*)&SM;
  global_messages = &messages;
  global_osl_to_clang = &osl_to_clang;

  clan_options_p options;
  int argc = 2;
  char* argv[argc] = { "clan", "non_exist.c" };
  char **input_files = NULL;
  FILE* output;
  options = clan_options_read( argc, argv, &input_files, &output);
  clan_parser_state_malloc(options->precision);
  clan_parser_state_initialize(options);

  logg << "got the hook into clan-clang " << __PRETTY_FUNCTION__ << endl;

  cerr << "handleForLoop" << __LINE__ << endl;
  for_loop->dumpColor();

  logg << "is this an iteration statement" << endl;
  //const auto* for_loop = Result.Nodes.getNodeAs<ForStmt>(FOR_LOOP_ID);
  auto iteration_statement = handleIterationStatement( for_loop ) ; 
  logg << "lets test its" << endl;

  if ( iteration_statement ) {
    logg << "hurray: found an iteration statement !!!!!!!!!!!!!!!" << endl;
    printf("building a scop\n");
    int nb_parameters;
    osl_scop_p scop;
    osl_generic_p arrays;

    CLAN_debug("rule scop.1: statement_list IGNORE");
    scop = osl_scop_malloc();
    CLAN_strdup(scop->language, "C");

    // Build the SCoP context.
    nb_parameters = clan_symbol_nb_of_type(parser_symbol,
	CLAN_TYPE_PARAMETER);
    scop->parameters = clan_symbol_to_strings(parser_symbol,
	CLAN_TYPE_PARAMETER);
    scop->context = clan_relation_build_context(nb_parameters,
						parser_options);
    
    // Set the statements.
    scop->statement = iteration_statement;

    // Compact the SCoP relations.
    if (CLAN_DEBUG) {
      CLAN_debug("SCoP before compaction:");
      osl_scop_dump(stderr, scop);
    }
    clan_scop_compact(scop);
    if (CLAN_DEBUG) {
      CLAN_debug("SCoP after compaction:");
      osl_scop_dump(stderr, scop);
    }

    // Simplify the SCoP iteration domains.
    if (!parser_options->nosimplify)
      clan_scop_simplify(scop);

    // Add extensions.
    scop->registry = osl_interface_get_default_registry();
    clan_scop_generate_scatnames(scop);
    arrays = clan_symbol_to_arrays(parser_symbol);
    osl_generic_add(&scop->extension, arrays);
    clan_scop_generate_coordinates(scop, parser_options->name);
    clan_scop_generate_clay(scop, scanner_clay);

    // Add the SCoP to parser_scop and prepare the state for the next SCoP.
    osl_scop_add(&parser_scop, scop);
    clan_symbol_free(parser_symbol);
    clan_parser_state_initialize(parser_options);
    CLAN_debug_call(osl_scop_dump(stderr, scop));
    FILE* output = fopen(filename.c_str(), "w");
    clan_scop_print(output, scop, parser_options);
    fclose( output );
    logg << "returning a scop " << endl;
    return scop;
  }
  return nullptr;
}


