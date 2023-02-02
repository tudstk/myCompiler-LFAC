/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ASSIGN = 258,                  /* ASSIGN  */
    MAIN = 259,                    /* MAIN  */
    TIP = 260,                     /* TIP  */
    TIP_BOOL = 261,                /* TIP_BOOL  */
    INT = 262,                     /* INT  */
    FLOAT = 263,                   /* FLOAT  */
    CHAR = 264,                    /* CHAR  */
    BOOL = 265,                    /* BOOL  */
    ID = 266,                      /* ID  */
    STRING = 267,                  /* STRING  */
    EVAL = 268,                    /* EVAL  */
    TYPEOF = 269,                  /* TYPEOF  */
    DOT = 270,                     /* DOT  */
    ADD = 271,                     /* ADD  */
    SUB = 272,                     /* SUB  */
    MULT = 273,                    /* MULT  */
    DIV = 274,                     /* DIV  */
    AND = 275,                     /* AND  */
    OR = 276,                      /* OR  */
    GT = 277,                      /* GT  */
    GEQ = 278,                     /* GEQ  */
    LT = 279,                      /* LT  */
    LEQ = 280,                     /* LEQ  */
    EQQ = 281,                     /* EQQ  */
    NEQ = 282,                     /* NEQ  */
    IF = 283,                      /* IF  */
    ELSE = 284,                    /* ELSE  */
    WHILE = 285,                   /* WHILE  */
    FOR = 286,                     /* FOR  */
    DO = 287,                      /* DO  */
    CONST = 288,                   /* CONST  */
    CLASS = 289                    /* CLASS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ASSIGN 258
#define MAIN 259
#define TIP 260
#define TIP_BOOL 261
#define INT 262
#define FLOAT 263
#define CHAR 264
#define BOOL 265
#define ID 266
#define STRING 267
#define EVAL 268
#define TYPEOF 269
#define DOT 270
#define ADD 271
#define SUB 272
#define MULT 273
#define DIV 274
#define AND 275
#define OR 276
#define GT 277
#define GEQ 278
#define LT 279
#define LEQ 280
#define EQQ 281
#define NEQ 282
#define IF 283
#define ELSE 284
#define WHILE 285
#define FOR 286
#define DO 287
#define CONST 288
#define CLASS 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 30 "tema.y"

  int intVal;
  char* strVal;
  float floatVal;
  char charVal;
  int boolVal;

#line 143 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
