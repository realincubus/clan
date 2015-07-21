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

   #include <stdio.h>
   #include <stdlib.h>
   #include <string.h>
   #include <assert.h>
   #include <unistd.h>
   #include <termios.h>
   #include <execinfo.h>
   
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
   #include <clan/macros.h>
   #include <clan/vector.h>
   #include <clan/relation.h>
   #include <clan/relation_list.h>
   #include <clan/domain.h>
   #include <clan/scop.h>
   #include <clan/symbol.h>
   #include <clan/statement.h>
   #include <clan/options.h>

   #include <clang/AST/AST.h>
   #include <clang/ASTMatchers/ASTMatchers.h>
   #include <clang/ASTMatchers/ASTMatchFinder.h>
   #include <clang/Lex/Lexer.h>

   #define BACKWARD_HAS_DW 1
   //#define BACKWARD_HAS_BFD 1
   #include "backward.hpp"

   #include <string> 
   #include <iostream>

   #define CLAN_DEBUG 1

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
   void clan_parser_state_print(FILE*);
   int  clan_parser_is_loop_sane(osl_relation_list_p,osl_relation_list_p,int*);
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

   using namespace std;

void yyerror(char *s) {
  int i, line = 1;
  char c = 'C';
  FILE* file;
 
  CLAN_debug("parse error notified");

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
  parser_loop_depth++;
  if ((parser_loop_depth + parser_if_depth) > CLAN_MAX_DEPTH)
    CLAN_error("CLAN_MAX_DEPTH reached, recompile with a higher value");
}


int clan_parser_is_loop_sane(osl_relation_list_p initialization,
                             osl_relation_list_p condition, int* stride) {
  int i, step;

  // Check there is the same number of elements in all for parts.
  if ((clan_relation_list_nb_elements(initialization) != parser_xfor_index) ||
      (clan_relation_list_nb_elements(condition) != parser_xfor_index)) {
    yyerror("not the same number of elements in all loop parts");
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
	yyerror("unsupported zero loop stride");
      else if (step > 0)
	yyerror("illegal min or floord in forward loop initialization");
      else
	yyerror("illegal max or ceild in backward loop initialization");
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


#if 0
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

auto print_stack_trace(){
  using namespace backward;
  StackTrace st; st.load_here(32);
  Printer p; p.print(st);
}

using namespace clang;
using namespace clang::ast_matchers;

#define YYABORT exit(-1)
const char* SCOP_ID = "scop";
const char* FOR_LOOP_ID = "for_loop";
const char* LOOP_ITERATOR_ID = "loop_iterator";
const char* LOOP_INITIALIZER_ID = "loop_initializer";
const char* LOOP_CONDITION_LIST_ID = "loop_condition_list";

const char* DECREMENT_ONE_ID = "decrement_one";
const char* INCREMENT_ONE_ID = "increment_one";

const char* CEILD_ID = "ceild";
const char* FLOORD_ID = "floord";

template <typename T>
inline std::string getString(const T *node, const SourceManager &SM) {
  SourceLocation expr_start = node->getLocStart();
  SourceLocation expr_end = node->getLocEnd();
  return Lexer::getSourceText(
      CharSourceRange::getTokenRange(SourceRange(expr_start, expr_end)), SM,
      LangOptions());
}

template <typename T>
string getString( const T* node, const MatchFinder::MatchResult &Result ){
  ASTContext& context = *Result.Context;
  SourceManager& SM = context.getSourceManager();
  return getString( node, SM ); 
}

SourceManager* global_SM = nullptr;

template <typename T>
string getString( const T* node ){
  SourceManager& SM = *global_SM;
  return getString( node, SM ); 
}

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

auto to_char_str( string str ) {
  char* ret;
  ret = (char*)malloc( str.length()+1 );
  strcpy( ret, str.c_str() );
  return ret;
}

auto handleInteger( const Expr* expr ){
  int* ret = nullptr;
  if ( auto integer_literal = dyn_cast_or_null<IntegerLiteral>( expr ) ){
    char* text = to_char_str( getString( integer_literal ) );
    ret = (int*)malloc( sizeof( int ) );
    *ret = atoi( text );
    free( text );
    return ret;
  } 
  return ret;
}

// has to work with standard char pointers
auto handleID( const Expr* expr ){
  cerr << __PRETTY_FUNCTION__ << endl;
  char* ret = nullptr;

  // ignore implicit casts
  const Expr* iic_expr = expr->IgnoreImpCasts();

  if ( auto decl_ref_expr = dyn_cast_or_null<DeclRefExpr>( iic_expr ) ) {
    ret = to_char_str( getString( decl_ref_expr ) );
    return ret; 
  }
  if ( auto call_expr = dyn_cast_or_null<CallExpr>( iic_expr ) ) {
    ret = to_char_str( getString( call_expr ) );
    return ret; 
  }
}

auto handleID( const NamedDecl* decl ){
  char* ret = nullptr;
  auto declaration_name = decl->getDeclName();
  auto name_str = declaration_name.getAsString();
  ret = to_char_str( name_str );
  return ret;
}

auto handleAffinePrimaryExpression( const Expr* expr ) {
  cerr << __PRETTY_FUNCTION__ << endl;
  osl_vector_p ret = nullptr;

  auto ID = handleID( expr );
  if ( ID ) {
    clan_symbol_p id;

    CLAN_debug("rule affine_primary_expression.1: id");
    id = clan_symbol_add(&parser_symbol, ID, CLAN_UNDEFINED);
    // An id in an affex can be either an iterator or a parameter. If it is
    // an unknown (embeds read-only variables), it is updated to a parameter.
    if (id->type == CLAN_UNDEFINED) {
      if ((parser_nb_parameters + 1) > CLAN_MAX_PARAMETERS)
	      CLAN_error("CLAN_MAX_PARAMETERS reached,"
			   "recompile with a higher value");
      id->type = CLAN_TYPE_PARAMETER;
      id->rank = ++parser_nb_parameters;
    }

    if ((id->type != CLAN_TYPE_ITERATOR) &&
	(id->type != CLAN_TYPE_PARAMETER)) {
      free(id);
      if (id->type == CLAN_TYPE_ARRAY)
	yyerror("variable or array reference in an affine expression");
      else
	yyerror("function call in an affine expression");
      YYABORT;
    }
    
    auto ret = clan_vector_term(parser_symbol, 1, ID, parser_options->precision);
    free(ID);
    CLAN_debug_call(osl_vector_dump(stderr, ret));
    return ret;
  }

  auto integer = handleInteger( expr );
  
  if ( integer ) {
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

  cerr << "no ID nor a declRefExpr " << endl;
  expr->dumpColor();
  return ret;

}


auto handleAffineUnaryExpression( const Expr* expr ) {
  cerr << __PRETTY_FUNCTION__ << endl;
  auto affine_primary_expression = handleAffinePrimaryExpression( expr );
  
  if ( affine_primary_expression ) {
      CLAN_debug("rule affine_unary_expression.1: affine_primary_expression");
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
    if ( !is_pos || !is_neg ) return (osl_vector_p)nullptr;

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
  cerr << __PRETTY_FUNCTION__ << endl;
  auto affine_unary_expression = handleAffineUnaryExpression( expr );
  if ( affine_unary_expression ){
      CLAN_debug("rule affine_multiplicative_expression.1: affine_unary_expression");
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
    if ( !is_mul || !is_div ) return (osl_vector_p)nullptr;

    auto affine_multiplicative_expression = handleAffineMultiplicativeExpression( binary_operator->getLHS() );
    auto affine_unary_expression = handleAffineUnaryExpression( binary_operator->getRHS() );

    if ( affine_multiplicative_expression && affine_unary_expression  && is_mul ) {
      int coef;
      
      CLAN_debug("rule affine_multiplicative_expression.2: affine_multiplicative_expression * affine_unary_expression");
      if (!osl_vector_is_scalar( affine_multiplicative_expression ) && !osl_vector_is_scalar(affine_unary_expression)) {
        osl_vector_free(affine_multiplicative_expression);
        osl_vector_free(affine_unary_expression);
        yyerror("non-affine expression");
	YYABORT;
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
        yyerror("non-affine expression");
	YYABORT;
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
  cerr << __PRETTY_FUNCTION__ << endl;
  auto affine_multiplicative_expression = handleAffineMultiplicativeExpression( expr );

  if ( affine_multiplicative_expression ) {
    CLAN_debug("rule affine_expression.1: affine_multiplicative_expression");
    auto ret = affine_multiplicative_expression;
    CLAN_debug_call(osl_vector_dump(stderr, ret));
    return ret;
  }

  auto binary_operator = dyn_cast_or_null<BinaryOperator>(expr);

  if ( binary_operator ) {

    // operator type has to be + or -
    string opcode = binary_operator->getOpcodeStr();
    bool is_add = false;
    bool is_sub = false;
    if ( opcode == "+" ) {
      is_add = true;
    } else if ( opcode == "-" ) {
      is_sub = true;
    }
    if ( !is_add || !is_sub ) return (osl_vector_p)nullptr;
    
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
  auto affine_expression = handleAffineExpression( expr );

  if ( affine_expression ) {
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

  // is either one of them
  auto affine_ceildfloord_expression = handleCeildFloordExpression( expr );
  
  if ( affine_ceildfloord_expression ){
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
  if ( auto decl_stmt = dyn_cast_or_null<DeclStmt>( stmt ) ){
    return decl_stmt;
  }
}

// TODO add the functionality to also allow assign statements
osl_relation_p handleLoopInitialization( const Stmt* stmt ){

  if( auto loop_declaration = handleLoopDeclaration( stmt ) ){
    auto loop_declaration_1 = dyn_cast_or_null<VarDecl>(loop_declaration->getSingleDecl());
    if ( loop_declaration_1 ) {
      auto ID = handleID( loop_declaration_1 );

      if ( ID ){
	cerr << "added new symbol " << ID << endl;
	if (!clan_symbol_new_iterator(&parser_symbol, parser_iterators, ID, parser_loop_depth)){
	    YYABORT;
	}
      }

      if ( loop_declaration_1->hasInit() ){
	auto affine_minmax_expression = handleAffineMinMaxExpression( loop_declaration_1->getInit() );
	if ( affine_minmax_expression ){
	  CLAN_debug("rule initialization: ID = <setex>");
	  parser_xfor_index++;
	  //free($2);
	  auto ret = affine_minmax_expression;
	  CLAN_debug_call(osl_relation_dump(stderr, ret));
	  return ret;
	}	
      }
    }
  }
}

// TODO make it also handle multiple initializations
osl_relation_list_p handleLoopInitializationList( const Stmt* stmt ){
  osl_relation_list_p ret = nullptr;

  auto loop_initialization = handleLoopInitialization( stmt );
  if ( loop_initialization ){
    CLAN_debug("rule initialization_list.2: initialization ;");
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
  cerr << __PRETTY_FUNCTION__ << endl;
  cerr << "handleAffineFloordExpression calling handleAffineExpression" << endl;
  auto affine_expression = handleAffineExpression( expr );
  cerr << "handleAffineFloordExpressio ndone calling handleAffineExpression" << endl;
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
  cerr << __PRETTY_FUNCTION__ << endl;
  cerr << "handleAffineCeildExpression calling handleAffineExpression" << endl;
  auto affine_expression = handleAffineExpression( expr );
  cerr << "handleAffineCeildExpression done calling handleAffineExpression" << endl;
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
  cerr << __PRETTY_FUNCTION__ << endl;
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
  cerr << __PRETTY_FUNCTION__ << endl;
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
  cerr << __PRETTY_FUNCTION__ << endl;

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
        cerr << "operator is less " << endl;
	cerr << "checking max expression" << endl;
	auto affine_max_expression = handleAffineMaxExpression( binary_operator->getLHS() );
	auto affine_min_expression = handleAffineMinExpression( binary_operator->getRHS() );

	cerr << affine_max_expression << " " << affine_min_expression << endl;
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
    cerr << "unary operator part" << endl;
    auto affine_condition = handleAffineCondition( unary_operator->getSubExpr() );
    if ( state_array[IS_NEGATION] && affine_condition ) {
      CLAN_debug("rule affine_relation.7: ! ( condition )");
      if (clan_relation_existential(affine_condition)) {
        osl_relation_free(affine_condition);
	yyerror("unsupported negation of a condition involving a modulo");
	YYABORT;
      }
      auto ret = clan_relation_not(affine_condition);
      osl_relation_free(affine_condition);
      CLAN_debug_call(osl_relation_dump(stderr, ret));
      return ret;
    }
  }


}

auto handleAffineLogicalAndExpression( const Expr* expr ){
  cerr << __PRETTY_FUNCTION__ << endl;
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
  cerr << __PRETTY_FUNCTION__ << endl;
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
  cerr << __PRETTY_FUNCTION__ << endl;
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
  cerr << __PRETTY_FUNCTION__ << endl;

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
  auto unary_operator = dyn_cast_or_null<UnaryOperator>( expr );
  if ( unary_operator ){

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

  auto binary_operator = dyn_cast_or_null<BinaryOperator>( expr );

  if ( binary_operator ) {
    auto decl_ref = dyn_cast_or_null<DeclRefExpr>(unary_operator->getSubExpr());
    if ( decl_ref ) {
      string opcode = unary_operator->getOpcodeStr(unary_operator->getOpcode());
      if ( opcode == "=" ){
	auto lhs = binary_operator->getLHS();
	auto rhs = binary_operator->getRHS();
	if ( auto decl_ref_lhs = dyn_cast_or_null<DeclRefExpr>( lhs ) ){
	  if ( auto binary_operator_rhs = dyn_cast_or_null<BinaryOperator>( rhs ) ){
	    // TODO add check : decl_ref_lhs and decl_ref have to reference the same variable
	    string opcode = binary_operator_rhs->getOpcodeStr(binary_operator_rhs->getOpcode());
	    auto integer = handleInteger( binary_operator_rhs->getRHS() );
	    if ( opcode == "+" ){
	      parser_xfor_index++; 
	      return *integer;
	    }
	    if ( opcode == "-" ) {
	      parser_xfor_index++; 
	      return - *integer;
	    }

	  }
	}
      }
    }
  }

  return 0;

}

// TODO handle multiple strides
auto handleLoopStrideList(const Expr* expr){

  auto loop_stride = handleLoopStride( expr );
  if ( loop_stride ) {
    auto ret = (int*)malloc(sizeof(int));
    ret[0] = loop_stride;
    return ret;
  }
}

auto handleIfStatement( const Stmt* stmt ){

  if ( auto if_stmt = dyn_cast_or_null<IfStmt>(stmt) ){
    return if_stmt;
  }
}

osl_statement_p handleStatement( const Stmt* stmt );

auto handleSelectionElseStatement( const Stmt* stmt ){
  if (!parser_valid_else[parser_if_depth]) {
    yyerror("unsupported negation of a condition involving a modulo");
    YYABORT;
  }
  auto statement = handleStatement( stmt );
  if ( statement ) {
      CLAN_debug("rule selection_else_statement.1: else <stmt>");
      auto ret = statement;
      CLAN_debug_call(osl_statement_dump(stderr, ret));
      return ret;
  } 
  return (osl_statement_p)nullptr;
}


auto handleSelectionStatement( const Stmt* stmt ){
  cerr << __PRETTY_FUNCTION__ << std::endl;
  if ( auto if_stmt = handleIfStatement( stmt ) ) {

    auto affine_condition = handleAffineCondition( if_stmt->getCond() );

    if ( affine_condition ) {
      CLAN_debug("rule selection_statement.1.1: if ( condition ) ...");
      clan_domain_dup(&parser_stack);
      clan_domain_and(parser_stack, affine_condition);
      parser_if_depth++;
      if ((parser_loop_depth + parser_if_depth) > CLAN_MAX_DEPTH)
	CLAN_error("CLAN_MAX_DEPTH reached, recompile with a higher value");

      auto statement = handleStatement( if_stmt->getThen() );
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

      auto selection_else_statement = handleSelectionElseStatement( if_stmt->getElse() );
      // TODO i dont understand whats returned it the if has no else branch there is no return statement or something like this
      CLAN_debug("rule selection_statement.1.3: if ( condition ) <stmt>"
	         "[else <stmt>]");
      clan_domain_drop(&parser_stack);
      auto ret = statement;
      osl_statement_add(&statement, selection_else_statement);
      parser_if_depth--;
      parser_nb_local_dims[parser_loop_depth + parser_if_depth] = 0;
      CLAN_debug_call(osl_statement_dump(stderr, ret));
      return ret;
    }

  }
}

osl_statement_p handleLoopBody( const Stmt* stmt );

auto handleFOR( const Stmt* stmt ){
  if ( auto for_stmt = dyn_cast_or_null<ForStmt>( stmt ) ){
    return for_stmt;
  }
}

auto handleIterationStatement( const Stmt* stmt ){
  cerr << __PRETTY_FUNCTION__ << endl;
  auto FOR = handleFOR( stmt );
  if ( FOR ) {
    auto loop_initialization_list = handleLoopInitializationList( FOR->getInit() );
    auto loop_condition_list = handleLoopConditionList( FOR->getCond() );
    auto loop_stride_list = handleLoopStrideList( FOR->getInc() );

    cerr << "loop stride is " << loop_stride_list[0] << endl;

    if ( loop_initialization_list && loop_condition_list && loop_stride_list ) {
      CLAN_debug("rule iteration_statement.2.1: for ( init cond stride ) ...");
      parser_xfor_labels[parser_loop_depth] = 0;
      clan_parser_increment_loop_depth();
     
      // Check there is only one element in each list
      if (parser_xfor_index != 1) {
	yyerror("unsupported element list in a for loop");
	osl_relation_list_free(loop_initialization_list);
        osl_relation_list_free(loop_condition_list);
	free(loop_stride_list);
        YYABORT;
      }

      // Check loop bounds and stride consistency and reset sanity sentinels.
      if (!clan_parser_is_loop_sane(loop_initialization_list, loop_condition_list, loop_stride_list))
        YYABORT;

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
    }
    
    auto loop_body = handleLoopBody( FOR->getBody() );
    if (loop_body ){
      CLAN_debug("rule iteration_statement.2.2: for ( init cond stride ) body");
      auto ret = loop_body;
      CLAN_debug_call(osl_statement_dump(stderr, ret));
      return ret;
    }
  } 
  // TODO add infinit loops
}


auto handleStatementList ( const Stmt* const* begin, const Stmt* const* end ){
  cerr << __PRETTY_FUNCTION__ << endl;

  // case 1: just one statement;
  if ( std::distance( begin, end ) == 1 ){
    auto ret = handleStatement( *begin );
    return ret;
  }

  // case 2: multiple statements
  for( auto i = begin, e = end; i != e; ++i ){
    auto statement_list = handleStatementList( i, (end - 1) );
    auto statement = handleStatement( *(end - 1) );
    osl_statement_add(&statement, statement);
    return statement;
  }
}

auto handleCompoundStatement( const Stmt* stmt ){
  cerr << __PRETTY_FUNCTION__ << endl;
  if ( auto compount_stmt = dyn_cast_or_null<CompoundStmt>( stmt ) ) {
    auto ret = handleStatementList( compount_stmt->body_begin(), compount_stmt->body_end() );
    return ret; 
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

auto handlePrimaryExpression( const Expr* expr ){
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
    auto ret = list;
    CLAN_debug_call(osl_relation_list_dump(stderr, ret));
    return list;
  }
  auto integer = handleInteger( expr );
  if ( integer ) {
    return (osl_relation_list_p)nullptr;
  }
  // TODO CONSTANT
  
  // TODO STRING_LITERAL
  
  // TODO parenthesis expression
}

osl_relation_list_p handleAssignmentExpression( const Expr* expr );

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
    osl_relation_list_add(&ret, assignment_expression);
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
    auto postfix_expression = handlePostfixExpression( subscript_expression->getLHS() );
    auto affine_expression = handleAffineExpression( subscript_expression->getRHS() );
    if ( affine_expression ){
      if (parser_options->extbody)
        parser_access_length = strlen(parser_record) - parser_access_start;

      CLAN_debug("rule postfix_expression.2: postfix_expression [ <affex> ]");
      if (!clan_symbol_update_type(parser_symbol, postfix_expression, CLAN_TYPE_ARRAY))
        YYABORT;
      clan_relation_new_output_vector(postfix_expression->elt, affine_expression);
      osl_vector_free(affine_expression);
      auto ret = postfix_expression;
      CLAN_debug_call(osl_relation_list_dump(stderr, ret));
      return ret;
    }
  }

  // NOTE the 3rd rule is a copy of the 2nd rule but handles arguemnts
  //      we can simply ignore this
  auto function_call = dyn_cast_or_null<CallExpr>( expr );
  if ( function_call ){

    auto postfix_expression = handlePostfixExpression( expr );

    if ( postfix_expression ){
      // don't save access name of a function
      if (parser_options->extbody) {
	parser_access_extbody->nb_access -= osl_relation_list_count(postfix_expression) - 1;
	parser_access_start = -1;
      }

      if (!clan_symbol_update_type(parser_symbol, postfix_expression, CLAN_TYPE_FUNCTION))
	YYABORT;
      osl_relation_list_free(postfix_expression);

      auto argument_expression_list = handleArgumentExpressionList( function_call->getArgs(), function_call->getNumArgs() );
      if ( argument_expression_list ) {
	return argument_expression_list;
      }

      auto ret = (osl_relation_list_p)nullptr;
      return ret;
    }
  }

  // TODO handle . and -> 
  auto member_access = dyn_cast_or_null<MemberExpr>( expr );
  if ( member_access ){

    auto postfix_expression = handlePostfixExpression( member_access->getBase() );
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
      if (!clan_symbol_update_type(parser_symbol, postfix_expression, CLAN_TYPE_ARRAY))
        YYABORT;
      list = postfix_expression;
      // The last reference in the list is also written.
      if (list != NULL) {
        while (list->next != NULL)
          list = list->next;
        list->next = osl_relation_list_node(list->elt);
        list->next->elt->type = OSL_TYPE_WRITE;
      }
      auto ret = postfix_expression;
      CLAN_debug_call(osl_relation_list_dump(stderr, ret));

      // add an empty line in the extbody
      if (parser_options->extbody) {
        osl_extbody_add(parser_access_extbody, -1, -1);
      }
      return ret;
    }
  }
}

osl_relation_list_p handleCastExpression( const Expr* expr );

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
      osl_relation_list_p list;

      CLAN_debug("rule unary_expression.2: unary_expression -> "
	         "++/-- unary_expression");
      if (!clan_symbol_update_type(parser_symbol, unary_expression, CLAN_TYPE_ARRAY))
        YYABORT;
      list = unary_expression;
      // The last reference in the list is also written.
      if (list != NULL) {
        while (list->next != NULL)
          list = list->next;
        list->next = osl_relation_list_node(list->elt);
        list->next->elt->type = OSL_TYPE_WRITE;
      }
      auto ret = unary_expression;
      CLAN_debug_call(osl_relation_list_dump(stderr, ret));

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

}

osl_relation_list_p handleCastExpression( const Expr* expr ){
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
	osl_relation_list_add(&ret, cast_expression);
	return ret;
      }
    }
  }
 
 

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
	osl_relation_list_add(&ret, multiplicative_expression);
	return ret;
      }
    }
  }
 

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
	osl_relation_list_add(&ret, additive_expression);
	return ret;
      }
    }
  }


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
	osl_relation_list_add(&ret, shift_expression);
	return ret;
      }
    }
  }
  
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
	osl_relation_list_add(&ret, relational_expression);
	return ret;
      }
    }
  }
  

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
	osl_relation_list_add(&ret, equality_expression);
	return ret;
      }
    }
  }
  
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
	osl_relation_list_add(&ret, and_expression);
	return ret;
      }
    }
  }
  
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
	osl_relation_list_add(&ret, exclusive_or_expression);
	return ret;
      }
    }
  }
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
	osl_relation_list_add(&ret, inclusive_or_expression);
	return ret;
      }
    }
  }
  
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
	osl_relation_list_add(&ret, logical_and_expression);
	return ret;
      }
    }
  }


}

osl_relation_list_p handleExpression( const Expr* expr );

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
      osl_relation_list_add(&ret, expression);
      osl_relation_list_add(&ret, conditional_expression);
      return ret;
    }
  }
}


osl_relation_list_p handleAssignmentExpression( const Expr* expr ){
  auto conditional_expression = handleConditionalExpression( expr );
  if ( conditional_expression ){
    CLAN_debug("rule assignment_expression.1: conditional_expression;");
    auto ret = conditional_expression;
    clan_relation_list_define_type(ret, OSL_TYPE_READ);
    CLAN_debug_call(osl_relation_list_dump(stderr, ret));
    return ret;
  }
  
  auto assignment_operator = handleAssignmentOperator( expr );
  if ( assignment_operator ) {
    auto binary_operator = dyn_cast_or_null<BinaryOperator>( expr );
    auto unary_expression = handleUnaryExpression( binary_operator->getLHS() );
    auto assignment_expression = handleAssignmentExpression( binary_operator->getRHS() );
    if ( unary_expression && assignment_expression ) {
      osl_relation_list_p list;

      CLAN_debug("rule assignment_expression.2: unary_expression "
	         "assignment_operator assignment_expression;");
      if (!clan_symbol_update_type(parser_symbol, unary_expression, CLAN_TYPE_ARRAY))
        YYABORT;
      auto ret = unary_expression;
      // Accesses of $1 are READ except the last one which is a WRITE or both.
      clan_relation_list_define_type(ret, OSL_TYPE_READ);
      list = ret;
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
      osl_relation_list_add(&ret, assignment_expression);
      CLAN_debug_call(osl_relation_list_dump(stderr, ret));
      return ret;
    }
  }
}

osl_relation_list_p handleExpression( const Expr* expr ){
  auto assignment_expression = handleAssignmentExpression( expr );
  if ( assignment_expression ) {
    return assignment_expression;
  }

  // TODO handle expression , assign 
}

auto handleExpressionStatement( const Stmt* stmt ){
  cerr << __PRETTY_FUNCTION__ << endl;

  if (parser_options->extbody) {
    parser_access_start = -1;
    parser_access_extbody = osl_extbody_malloc();
  }

  auto statement_str = getString( stmt );
  statement_str += ";";
  CLAN_strdup(parser_record, statement_str.c_str());
  parser_recording = CLAN_TRUE;

  auto expression = handleExpression( dyn_cast_or_null<Expr>(stmt) );
  if ( expression ) {
    osl_statement_p statement;
    osl_body_p body;
    osl_generic_p gen;
    
    CLAN_debug("rule expression_statement.2: expression ;");
    statement = osl_statement_malloc();

    // - 1. Domain
    if (clan_relation_list_nb_elements(parser_stack->constraints) != 1) {
      yyerror("missing label on a statement inside an xfor loop");
      YYABORT;
    }
    statement->domain = osl_relation_clone(parser_stack->constraints->elt);
    osl_relation_set_type(statement->domain, OSL_TYPE_DOMAIN);
    osl_relation_set_attributes(statement->domain, parser_loop_depth, 0,
				clan_parser_nb_ld(), CLAN_MAX_PARAMETERS);

    // - 2. Scattering
    statement->scattering = clan_relation_scattering(parser_scattering,
	parser_loop_depth, parser_options->precision);

    // - 3. Array accesses
    statement->access = expression;

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

    parser_recording = CLAN_FALSE;
    parser_record = NULL;
    
    parser_scattering[2*parser_loop_depth]++;

    auto ret = statement;
    CLAN_debug_call(osl_statement_dump(stderr, ret));
    return ret;
  }
}

// TODO continue there is a lot more about statements
osl_statement_p handleStatement( const Stmt* stmt ){
  cerr << __PRETTY_FUNCTION__ << endl;

#if 0
  auto labeled_statement = handleLabeledStatement( stmt );
  if ( labeled_statement ) {
    return labeled_statement;
  }

  auto expression_statement = handleExpressionStatement( stmt );
  if ( expression_statement ) {
    return expression_statement;
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

  auto expression_statement = handleExpressionStatement( stmt );
  if ( expression_statement ) {
    return expression_statement;
  }

  return (osl_statement_p)nullptr;
}

osl_statement_p handleLoopBody( const Stmt* stmt ){
  cerr << __PRETTY_FUNCTION__ << endl;
  osl_statement_p ret = nullptr;
  auto statement = handleStatement( stmt );
  if ( statement ) {
    CLAN_debug("rule loop_body.1: <stmt>");
    parser_loop_depth--;
    clan_symbol_free(parser_iterators[parser_loop_depth]);
    parser_iterators[parser_loop_depth] = NULL;
    clan_domain_drop(&parser_stack);
    ret = statement;
    parser_scattering[2*parser_loop_depth]++;
    parser_nb_local_dims[parser_loop_depth + parser_if_depth] = 0;
    CLAN_debug_call(osl_statement_dump(stderr, ret));
    return ret;
  }
  return ret;
}

void handleForLoop( const MatchFinder::MatchResult &Result ){

  static bool once = true;
  if ( once ) {
    clan_options_p options;
    int argc = 2;
    char* argv[argc] = { "clan", "non_exist.c" };
    char **input_files = NULL;
    FILE* output;
    options = clan_options_read( argc, argv, &input_files, &output);
    clan_parser_state_malloc(options->precision);
    clan_parser_state_initialize(options);
    ASTContext& context = *Result.Context;
    global_SM = (SourceManager*)&context.getSourceManager();
    once = false;
  }

  cout << "got the hook into clan-clang" << __PRETTY_FUNCTION__ << endl;


  const auto* for_loop = Result.Nodes.getNodeAs<ForStmt>(FOR_LOOP_ID);
  auto iteration_statement = handleIterationStatement( for_loop ) ; 

  if ( iteration_statement ) {
    cout << "hurray: found an iteration statement !!!!!!!!!!!!!!!" << endl;
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
    FILE* output = fopen("test.scop", "w");
    clan_scop_print(output, scop, parser_options);
    fclose( output );
  }
}

// TODO make it ignore parens
StatementMatcher makePrimaryExpressionMatcher(){
  return anyOf(
    integerLiteral(),
    declRefExpr()
  );
}

StatementMatcher makePostfixExpressionMatcher(){
  return anyOf( 
      makePrimaryExpressionMatcher(),
      arraySubscriptExpr()
  );
}

StatementMatcher makeUnaryIncrementOperatorMatcher(){
  return anyOf( 
      unaryOperator( hasOperatorName("++") ),
      unaryOperator( hasOperatorName("--") )
    );
}

StatementMatcher makeUnaryExpressionMatcher(){
  return anyOf( 
      makePostfixExpressionMatcher(),
      makeUnaryIncrementOperatorMatcher()
  );
}

StatementMatcher makeConditionalExpressionMatcher() {
  return stmt();
}

StatementMatcher makeAssignmentExpressionMatcher(){
  return anyOf( 
      makeUnaryExpressionMatcher(),
      makeConditionalExpressionMatcher()
  );
}

StatementMatcher makeExpressionStatementMatcher(){
  return makeAssignmentExpressionMatcher();
}

StatementMatcher inSingleLineCompoundStmt(StatementMatcher innerMatcher) {
  return anyOf(
	  compoundStmt(statementCountIs(1), hasAnySubstatement(innerMatcher)),
	  innerMatcher
  );
}

// TODO make it support more than one variable 
StatementMatcher makeLoopInitializationMatcher(){
  return inSingleLineCompoundStmt(
      declStmt(
	hasSingleDecl(
	  varDecl(
	    //hasName("int"), // TODO extend for all integer types
	    hasInitializer(
	      ignoringParenImpCasts(
		integerLiteral().bind(LOOP_INITIALIZER_ID)
		)
	      )
	    ).bind(LOOP_ITERATOR_ID)
	  )
	)
      );
}

// TODO very complicated part with affine expressions ...
StatementMatcher makeLoopConditionMatcher(){
  return expr().bind(LOOP_CONDITION_LIST_ID);
}

StatementMatcher makeIncrementMatcher(){
  return anyOf( 
     unaryOperator( hasOperatorName("++") ).bind(INCREMENT_ONE_ID) ,
     binaryOperator( 
       hasOperatorName("+="),
       hasRHS(
	 integerLiteral(equals(1))
       )
     ).bind(INCREMENT_ONE_ID),
     binaryOperator( 
       hasOperatorName("="),
       hasLHS( declRefExpr() ),
       hasRHS( 
	 binaryOperator( 
	   hasOperatorName("+"),
	   hasLHS( declRefExpr() )
	   //hasRHS(  )
	)
      )
     ).bind(INCREMENT_ONE_ID) 
  );
}

StatementMatcher makeDecrementMatcher(){
  return anyOf( 
     unaryOperator( hasOperatorName("--") ).bind(DECREMENT_ONE_ID),
     binaryOperator( 
       hasOperatorName("-="),
       hasRHS(
	 integerLiteral(equals(1))
       )
     ).bind(DECREMENT_ONE_ID),
     binaryOperator( 
       hasOperatorName("="),
       hasLHS( declRefExpr() ),
       hasRHS( 
	 binaryOperator( 
	   hasOperatorName("-"),
	   hasLHS( declRefExpr() )
	   //hasRHS( anything() )
	)
      )
     ).bind(DECREMENT_ONE_ID) 
  );
}

StatementMatcher makeLoopStrideMatcher(){
  return anyOf( 
     makeIncrementMatcher(),
     makeDecrementMatcher()
  );
}

StatementMatcher makeIterationStmtMatcher(){
  return forStmt( 
#if 0
      hasLoopInit(
	makeLoopInitializationMatcher()
      ),
#endif
      hasCondition(
	makeLoopConditionMatcher()
      ),
#if 1
      hasIncrement(
	makeLoopStrideMatcher()
      )
#endif
  ).bind(FOR_LOOP_ID); 
}

StatementMatcher makeStatementMatcher() {
  return anyOf( 
      compoundStmt(),
      ifStmt(),
      //makeIterationStmtMatcher(),
      makeExpressionStatementMatcher()
  );
}

// TODO make it match multiple statements
StatementMatcher makeStatementListMatcher(){
  return makeStatementMatcher();
}

StatementMatcher makeSCoPMatcher(){
  return makeStatementListMatcher();  
}


















