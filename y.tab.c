/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "tema.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "y.tab.h"
#include "functii.h"
#include "EvalAST.h"
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
int yylex();
int yyerror(char* s);
extern char tipData[50];
extern char parametri[50];
char listaVarClasa[256];
extern char lista_parametri[256];
extern char lista_parametri_apel[256];
char vectorType[256];
char lista_elemente_vector[256];
char lista_elemente_matrice[512];
char param[50];
char valoareStringChar[256];
char valoareStringChar2[256];
char valoareStringChar3[256];
char functieId[100];
int isBoolExpression;
int linii=0;

#line 100 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 229 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ASSIGN = 3,                     /* ASSIGN  */
  YYSYMBOL_MAIN = 4,                       /* MAIN  */
  YYSYMBOL_TIP = 5,                        /* TIP  */
  YYSYMBOL_TIP_BOOL = 6,                   /* TIP_BOOL  */
  YYSYMBOL_INT = 7,                        /* INT  */
  YYSYMBOL_FLOAT = 8,                      /* FLOAT  */
  YYSYMBOL_CHAR = 9,                       /* CHAR  */
  YYSYMBOL_BOOL = 10,                      /* BOOL  */
  YYSYMBOL_ID = 11,                        /* ID  */
  YYSYMBOL_STRING = 12,                    /* STRING  */
  YYSYMBOL_EVAL = 13,                      /* EVAL  */
  YYSYMBOL_TYPEOF = 14,                    /* TYPEOF  */
  YYSYMBOL_DOT = 15,                       /* DOT  */
  YYSYMBOL_ADD = 16,                       /* ADD  */
  YYSYMBOL_SUB = 17,                       /* SUB  */
  YYSYMBOL_MULT = 18,                      /* MULT  */
  YYSYMBOL_DIV = 19,                       /* DIV  */
  YYSYMBOL_AND = 20,                       /* AND  */
  YYSYMBOL_OR = 21,                        /* OR  */
  YYSYMBOL_GT = 22,                        /* GT  */
  YYSYMBOL_GEQ = 23,                       /* GEQ  */
  YYSYMBOL_LT = 24,                        /* LT  */
  YYSYMBOL_LEQ = 25,                       /* LEQ  */
  YYSYMBOL_EQQ = 26,                       /* EQQ  */
  YYSYMBOL_NEQ = 27,                       /* NEQ  */
  YYSYMBOL_IF = 28,                        /* IF  */
  YYSYMBOL_ELSE = 29,                      /* ELSE  */
  YYSYMBOL_WHILE = 30,                     /* WHILE  */
  YYSYMBOL_FOR = 31,                       /* FOR  */
  YYSYMBOL_DO = 32,                        /* DO  */
  YYSYMBOL_CONST = 33,                     /* CONST  */
  YYSYMBOL_CLASS = 34,                     /* CLASS  */
  YYSYMBOL_35_ = 35,                       /* ';'  */
  YYSYMBOL_36_ = 36,                       /* '['  */
  YYSYMBOL_37_ = 37,                       /* ']'  */
  YYSYMBOL_38_ = 38,                       /* '{'  */
  YYSYMBOL_39_ = 39,                       /* '}'  */
  YYSYMBOL_40_ = 40,                       /* '('  */
  YYSYMBOL_41_ = 41,                       /* ')'  */
  YYSYMBOL_42_ = 42,                       /* '|'  */
  YYSYMBOL_43_ = 43,                       /* ','  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_program = 45,                   /* program  */
  YYSYMBOL_global = 46,                    /* global  */
  YYSYMBOL_bloc_global = 47,               /* bloc_global  */
  YYSYMBOL_secventa_instructiuni_global = 48, /* secventa_instructiuni_global  */
  YYSYMBOL_declaratie_globala = 49,        /* declaratie_globala  */
  YYSYMBOL_clasa = 50,                     /* clasa  */
  YYSYMBOL_secventa_instructiuni_clasa = 51, /* secventa_instructiuni_clasa  */
  YYSYMBOL_declaratii_clasa = 52,          /* declaratii_clasa  */
  YYSYMBOL_declaratie_functie = 53,        /* declaratie_functie  */
  YYSYMBOL_parametri = 54,                 /* parametri  */
  YYSYMBOL_parametru = 55,                 /* parametru  */
  YYSYMBOL_bloc_functie = 56,              /* bloc_functie  */
  YYSYMBOL_secventa_instructiuni_functie = 57, /* secventa_instructiuni_functie  */
  YYSYMBOL_apel_functie = 58,              /* apel_functie  */
  YYSYMBOL_apel_functie_parametri = 59,    /* apel_functie_parametri  */
  YYSYMBOL_apel_functie_expr = 60,         /* apel_functie_expr  */
  YYSYMBOL_main = 61,                      /* main  */
  YYSYMBOL_bloc_main = 62,                 /* bloc_main  */
  YYSYMBOL_secventa_instructiuni_main = 63, /* secventa_instructiuni_main  */
  YYSYMBOL_declaratie_main = 64,           /* declaratie_main  */
  YYSYMBOL_matrice = 65,                   /* matrice  */
  YYSYMBOL_elemente_vector = 66,           /* elemente_vector  */
  YYSYMBOL_atribuire = 67,                 /* atribuire  */
  YYSYMBOL_expresie = 68,                  /* expresie  */
  YYSYMBOL_expresie_matematica = 69,       /* expresie_matematica  */
  YYSYMBOL_NUMAR_INT = 70,                 /* NUMAR_INT  */
  YYSYMBOL_NUMAR_FLOAT = 71,               /* NUMAR_FLOAT  */
  YYSYMBOL_expresie_bool = 72,             /* expresie_bool  */
  YYSYMBOL_expresie_bool_exclusiv = 73,    /* expresie_bool_exclusiv  */
  YYSYMBOL_instructiuni_control = 74,      /* instructiuni_control  */
  YYSYMBOL_control_if = 75,                /* control_if  */
  YYSYMBOL_control_while = 76,             /* control_while  */
  YYSYMBOL_control_for = 77,               /* control_for  */
  YYSYMBOL_78_1 = 78                       /* $@1  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  25
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   564

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  158
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  375

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      40,    41,     2,     2,    43,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    36,     2,    37,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,    42,    39,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    65,    65,    66,    71,    74,    77,    78,    79,    80,
      81,    82,    84,    91,   100,   109,   180,   204,   229,   230,
     263,   283,   305,   318,   331,   332,   333,   338,   360,   363,
     364,   367,   368,   380,   387,   394,   415,   441,   462,   484,
     485,   488,   490,   491,   492,   493,   495,   496,   497,   498,
     499,   500,   503,   510,   517,   518,   519,   520,   521,   522,
     523,   524,   526,   534,   544,   545,   548,   551,   552,   553,
     554,   555,   556,   557,   558,   561,   568,   576,   585,   662,
     687,   712,   745,   767,   788,   801,   815,   841,   863,   885,
     924,   925,   927,   943,   944,   945,   946,   964,   965,   967,
     968,   970,   971,   972,   973,   974,   975,   976,   977,   978,
     979,   982,  1017,  1018,  1040,  1062,  1088,  1108,  1109,  1112,
    1135,  1151,  1167,  1193,  1194,  1195,  1196,  1218,  1233,  1247,
    1258,  1260,  1266,  1278,  1290,  1302,  1314,  1326,  1338,  1339,
    1341,  1353,  1365,  1377,  1389,  1402,  1414,  1426,  1442,  1443,
    1444,  1446,  1447,  1448,  1449,  1451,  1452,  1454,  1454
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ASSIGN", "MAIN",
  "TIP", "TIP_BOOL", "INT", "FLOAT", "CHAR", "BOOL", "ID", "STRING",
  "EVAL", "TYPEOF", "DOT", "ADD", "SUB", "MULT", "DIV", "AND", "OR", "GT",
  "GEQ", "LT", "LEQ", "EQQ", "NEQ", "IF", "ELSE", "WHILE", "FOR", "DO",
  "CONST", "CLASS", "';'", "'['", "']'", "'{'", "'}'", "'('", "')'", "'|'",
  "','", "$accept", "program", "global", "bloc_global",
  "secventa_instructiuni_global", "declaratie_globala", "clasa",
  "secventa_instructiuni_clasa", "declaratii_clasa", "declaratie_functie",
  "parametri", "parametru", "bloc_functie",
  "secventa_instructiuni_functie", "apel_functie",
  "apel_functie_parametri", "apel_functie_expr", "main", "bloc_main",
  "secventa_instructiuni_main", "declaratie_main", "matrice",
  "elemente_vector", "atribuire", "expresie", "expresie_matematica",
  "NUMAR_INT", "NUMAR_FLOAT", "expresie_bool", "expresie_bool_exclusiv",
  "instructiuni_control", "control_if", "control_while", "control_for",
  "$@1", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-313)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-146)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     305,    -7,    23,    41,    59,    18,    57,    83,   135,  -313,
     289,  -313,  -313,  -313,  -313,  -313,   314,   112,  -313,     9,
      88,   201,   148,   159,   199,  -313,  -313,  -313,  -313,  -313,
     188,   229,     7,   202,   208,   211,   223,   258,   264,  -313,
     116,  -313,  -313,  -313,  -313,  -313,  -313,   270,   238,  -313,
     317,    12,   311,  -313,  -313,  -313,   301,   302,    -8,   308,
       8,  -313,   365,   448,  -313,  -313,  -313,   306,  -313,    99,
     348,    36,   117,   194,   325,   355,    29,   367,   213,     8,
       8,   442,   451,  -313,  -313,  -313,  -313,  -313,  -313,   433,
     434,   372,   435,   459,   436,    48,  -313,   438,  -313,  -313,
     464,    73,  -313,   421,   332,   157,   175,     8,     8,     8,
       8,     8,     8,  -313,   134,   134,   134,   134,   253,  -313,
     465,    22,  -313,   219,  -313,   468,   467,  -313,   439,  -313,
      10,  -313,    37,  -313,   445,  -313,   127,   421,   437,   440,
     441,   444,   345,   197,   215,   234,   276,   480,   481,  -313,
    -313,  -313,    40,  -313,   324,   450,   482,  -313,   452,  -313,
     140,  -313,     8,     8,  -313,     8,     8,  -313,  -313,  -313,
    -313,  -313,  -313,  -313,   134,    60,    60,    60,    60,   455,
     456,   379,    11,   457,  -313,   458,   460,   446,   386,   461,
     462,   484,   259,   124,  -313,   466,   265,   469,   470,   471,
     472,   473,   270,   270,   477,   478,   134,   272,   474,  -313,
     487,   488,   489,    87,  -313,  -313,   324,  -313,   475,  -313,
     293,  -313,   320,  -313,   342,  -313,   344,  -313,   332,  -313,
    -313,  -313,   278,  -313,    25,  -313,  -313,  -313,   490,  -313,
      51,  -313,   476,   479,   483,   393,   445,   146,  -313,  -313,
    -313,  -313,   421,  -313,  -313,  -313,  -313,  -313,   486,   491,
     270,   270,   358,   492,   493,   400,   443,   485,   137,   151,
    -313,  -313,  -313,   132,   496,   494,   495,   407,   497,   290,
     498,   499,  -313,   506,   501,  -313,  -313,  -313,   466,   270,
     270,  -313,  -313,     8,  -313,  -313,  -313,  -313,  -313,  -313,
    -313,  -313,    85,   155,   295,  -313,   509,  -313,  -313,   503,
    -313,  -313,  -313,   324,   500,   507,   443,   504,  -313,  -313,
    -313,   508,   510,   449,   511,  -313,   512,   513,   414,   515,
    -313,   145,   324,  -313,   190,   158,   505,  -313,  -313,  -313,
    -313,  -313,  -313,   514,  -313,  -313,  -313,  -313,  -313,   161,
     516,   517,  -313,   518,   443,   249,  -313,  -313,   514,   134,
     339,   519,   520,   341,   340,  -313,  -313,   443,   521,  -313,
     420,  -313,   270,  -313,  -313
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
       5,     7,    10,    26,     3,     9,     0,     0,    65,     0,
       0,     0,     0,     0,     0,     1,     2,     6,    11,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    73,
       0,    69,    70,    72,   148,   149,   150,     0,     0,    12,
       0,     0,     0,    13,   130,   131,     0,     0,   126,     0,
       0,   129,   112,   117,   124,   125,   118,     0,   116,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    66,    74,    67,    68,    71,    64,     0,
       0,     0,     0,     0,     0,     0,    39,     0,   114,   115,
       0,     0,   113,     0,   117,   118,     0,     0,     0,     0,
       0,     0,     0,   111,     0,     0,     0,     0,     0,    18,
       0,     0,    30,     0,    75,     0,     0,    76,     0,    96,
       0,    55,   126,    56,     0,    60,     0,    54,     0,     0,
       0,     0,     0,   118,     0,   118,     0,     0,     0,    16,
      17,    15,     0,    41,     0,     0,     0,    14,     0,    62,
       0,   123,     0,     0,   138,     0,     0,   139,   132,   136,
     133,   137,   134,   135,     0,   119,   120,   121,   122,     0,
       0,     0,     0,    28,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
       0,     0,     0,     0,    43,    44,     0,    40,   127,    63,
     118,   147,   118,   146,   118,   142,   118,   143,     0,    21,
      20,    19,     0,    31,     0,    27,    80,    79,     0,    78,
       0,    77,     0,     0,     0,     0,    62,     0,    53,    57,
      58,    61,    59,    89,    95,    94,    93,    92,   151,   152,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,    42,    45,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    84,     0,     0,    87,    88,    86,    63,     0,
       0,   155,   156,     0,    82,    83,    81,   102,   104,   106,
     110,   108,     0,     0,     0,    46,     0,    48,    37,     0,
      33,    34,    32,     0,     0,     0,     0,     0,    91,   153,
     154,   118,     0,     0,     0,    23,     0,     0,     0,     0,
     128,     0,     0,    90,     0,     0,     0,    24,   101,   103,
     105,   109,   107,     0,    51,    50,    47,    49,    36,     0,
       0,     0,    85,     0,     0,     0,    35,    97,     0,     0,
       0,     0,     0,     0,     0,    99,    25,     0,     0,   157,
       0,    98,     0,   100,   158
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -313,  -313,  -313,  -313,  -313,   522,   523,  -313,   402,  -313,
     291,   368,  -213,  -206,   -11,   -92,  -313,   526,   -46,  -313,
     524,   168,  -312,   242,   -13,   -58,  -313,  -313,   -54,   -59,
     -16,  -313,  -313,  -313,  -313
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     7,     8,     9,    10,    11,    12,   121,   122,    13,
      95,    96,   213,   214,   135,   136,    61,    14,    18,    40,
      41,   355,   302,    15,   103,    63,    64,    65,    66,   106,
     215,    44,    45,    46,   372
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,    88,   104,   273,   334,    39,   105,   271,    62,   160,
      73,    68,    48,   192,   232,    54,    55,    93,    74,    58,
     144,   146,    75,    23,    87,   143,   145,   120,   100,    84,
      93,    16,   101,    17,    19,    91,    54,    55,   131,   123,
     132,   133,   360,   208,    49,    50,   233,    76,    60,    51,
      76,   234,    20,    94,   281,   370,   175,   176,   177,   178,
      62,   183,    21,   137,    68,   142,   278,   271,    24,    60,
     134,   124,   125,   100,    22,   209,   210,   193,   116,   117,
      54,    55,   131,    25,   132,   133,   282,   283,   137,   155,
     156,    52,   211,   212,   168,   169,   170,   171,   172,   173,
     331,   247,   118,   221,   223,   181,   225,   227,   220,   222,
     188,   224,   226,    60,   159,    35,   228,    36,    37,   349,
     126,    30,    31,    53,   322,   271,   270,    32,   323,    33,
      34,    54,    55,   131,   119,   132,   133,   211,   212,     1,
     304,    54,    55,   271,    35,    58,    36,    37,   262,    38,
     211,   212,   127,    47,   306,    83,   258,   259,   324,    67,
      35,   351,    36,    37,    60,   246,   211,   212,   195,   196,
      69,   308,   305,    35,   174,    36,    37,   162,   163,   245,
     137,   219,   196,   252,   348,   251,   307,   288,   196,    35,
     325,    36,    37,   352,   265,   165,   166,   272,   164,    71,
     356,    54,    55,    56,    57,    58,    59,   128,    54,    55,
      56,    57,    58,    59,   291,   292,   167,   162,   163,   277,
      54,    55,   139,   140,    58,   141,    54,    55,   185,   350,
      58,   186,   187,   323,    60,   165,   166,    70,   202,   321,
      72,    60,    77,   319,   320,    54,    55,    89,    78,    58,
      90,    79,    29,    60,   162,   163,   203,   272,    42,    60,
      54,    55,   179,    80,    58,   180,    54,    55,   243,    82,
      58,   244,    54,    55,   249,   204,   132,   250,    60,    54,
      55,   263,    86,    58,   264,    54,    55,   275,   361,    58,
     276,   328,   362,    60,     2,     3,   165,   166,    81,    60,
       4,   364,    54,    55,   326,    60,    58,   327,    16,     1,
       2,     3,    60,  -140,  -140,   272,     4,   205,    60,    30,
      31,    97,     5,     6,    92,    32,   374,    33,    34,   211,
     212,   314,   156,   272,  -140,    60,    98,    99,     5,     6,
    -141,  -141,    35,   102,    36,    37,    76,    38,   114,   115,
     116,   117,    35,   120,    36,    37,   114,   115,   116,   117,
     129,  -141,  -145,  -145,  -144,  -144,   130,   107,   108,   109,
     110,   111,   112,   161,   114,   115,   116,   117,   365,   138,
     368,   369,   323,  -145,   362,  -144,   201,   107,   108,   109,
     110,   111,   112,   293,   107,   108,   109,   110,   111,   112,
     113,   107,   108,   109,   110,   111,   112,   151,   107,   108,
     109,   110,   111,   112,   231,   107,   108,   109,   110,   111,
     112,   239,   107,   108,   109,   110,   111,   112,   287,   107,
     108,   109,   110,   111,   112,   296,   107,   108,   109,   110,
     111,   112,   312,   107,   108,   109,   110,   111,   112,   346,
     297,   298,   299,   147,   300,   301,   338,   339,   340,   373,
     341,   342,   148,   323,   114,   115,   116,   117,   149,   150,
     153,   158,   152,   157,   154,   189,   182,   190,   197,   191,
     194,   198,   199,   206,   207,   200,   238,    93,   216,   218,
     229,   230,   235,   236,   267,   237,   242,   241,   240,   268,
     269,   248,   280,   309,   253,   254,   255,   256,   257,   260,
     261,   274,   266,   317,   285,   289,   353,   284,   286,   329,
     290,   359,   303,   184,   217,   279,   363,   294,   295,   310,
     311,     0,    27,    28,    26,   313,   318,   316,   332,   315,
     330,   335,   333,   336,     0,   337,     0,   344,   345,   343,
     347,   357,   354,     0,   366,   358,   371,     0,   367,     0,
       0,     0,     0,     0,    85
};

static const yytype_int16 yycheck[] =
{
      16,    47,    60,   216,   316,    16,    60,   213,    21,   101,
       3,    22,     3,     3,     3,     7,     8,     5,    11,    11,
      79,    80,    15,     5,    40,    79,    80,     5,    36,    40,
       5,    38,    40,    40,    11,    48,     7,     8,     9,     3,
      11,    12,   354,     3,    35,    36,    35,    40,    40,    40,
      40,    40,    11,    41,     3,   367,   114,   115,   116,   117,
      73,    39,     3,    76,    75,    78,    41,   273,    11,    40,
      41,    35,    36,    36,    15,    35,    36,    40,    18,    19,
       7,     8,     9,     0,    11,    12,    35,    36,   101,    41,
      42,     3,     5,     6,   107,   108,   109,   110,   111,   112,
     313,   193,     3,   162,   163,   118,   165,   166,   162,   163,
     123,   165,   166,    40,    41,    28,   174,    30,    31,   332,
       3,     5,     6,    35,    39,   331,    39,    11,    43,    13,
      14,     7,     8,     9,    35,    11,    12,     5,     6,     4,
       3,     7,     8,   349,    28,    11,    30,    31,   206,    33,
       5,     6,    35,    41,     3,    39,   202,   203,     3,    11,
      28,     3,    30,    31,    40,    41,     5,     6,    41,    42,
      11,    39,    35,    28,    40,    30,    31,    20,    21,   192,
     193,    41,    42,   196,    39,   196,    35,    41,    42,    28,
      35,    30,    31,    35,   207,    20,    21,   213,    41,    11,
      39,     7,     8,     9,    10,    11,    12,    13,     7,     8,
       9,    10,    11,    12,   260,   261,    41,    20,    21,   232,
       7,     8,     9,    10,    11,    12,     7,     8,     9,    39,
      11,    12,    13,    43,    40,    20,    21,    38,    41,   293,
      11,    40,    40,   289,   290,     7,     8,     9,    40,    11,
      12,    40,    10,    40,    20,    21,    41,   273,    16,    40,
       7,     8,     9,    40,    11,    12,     7,     8,     9,     5,
      11,    12,     7,     8,     9,    41,    11,    12,    40,     7,
       8,     9,    40,    11,    12,     7,     8,     9,    39,    11,
      12,   304,    43,    40,     5,     6,    20,    21,    40,    40,
      11,   359,     7,     8,     9,    40,    11,    12,    38,     4,
       5,     6,    40,    20,    21,   331,    11,    41,    40,     5,
       6,    10,    33,    34,     7,    11,   372,    13,    14,     5,
       6,    41,    42,   349,    41,    40,    35,    35,    33,    34,
      20,    21,    28,    35,    30,    31,    40,    33,    16,    17,
      18,    19,    28,     5,    30,    31,    16,    17,    18,    19,
      35,    41,    20,    21,    20,    21,    11,    22,    23,    24,
      25,    26,    27,    41,    16,    17,    18,    19,    39,    12,
      39,    41,    43,    41,    43,    41,    41,    22,    23,    24,
      25,    26,    27,    35,    22,    23,    24,    25,    26,    27,
      35,    22,    23,    24,    25,    26,    27,    35,    22,    23,
      24,    25,    26,    27,    35,    22,    23,    24,    25,    26,
      27,    35,    22,    23,    24,    25,    26,    27,    35,    22,
      23,    24,    25,    26,    27,    35,    22,    23,    24,    25,
      26,    27,    35,    22,    23,    24,    25,    26,    27,    35,
       7,     8,     9,    11,    11,    12,     7,     8,     9,    39,
      11,    12,    11,    43,    16,    17,    18,    19,    35,    35,
      11,     7,    37,    35,    38,     7,    11,    10,    41,    40,
      35,    41,    41,     3,     3,    41,    40,     5,    38,    37,
      35,    35,    35,    35,     7,    35,    12,    35,    37,    11,
      11,    35,    12,     7,    35,    35,    35,    35,    35,    32,
      32,    36,    38,     7,    35,    29,    11,    41,    35,    10,
      29,     3,    37,   121,   156,   234,   358,    35,    35,    35,
      35,    -1,    10,    10,     8,    38,    35,    38,    38,    41,
      37,    37,    35,    35,    -1,    35,    -1,    35,    35,    38,
      35,    35,    38,    -1,    35,    38,    35,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    40
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,     6,    11,    33,    34,    45,    46,    47,
      48,    49,    50,    53,    61,    67,    38,    40,    62,    11,
      11,     3,    15,     5,    11,     0,    61,    49,    50,    67,
       5,     6,    11,    13,    14,    28,    30,    31,    33,    58,
      63,    64,    67,    74,    75,    76,    77,    41,     3,    35,
      36,    40,     3,    35,     7,     8,     9,    10,    11,    12,
      40,    60,    68,    69,    70,    71,    72,    11,    58,    11,
      38,    11,    11,     3,    11,    15,    40,    40,    40,    40,
      40,    40,     5,    39,    58,    64,    67,    74,    62,     9,
      12,    68,     7,     5,    41,    54,    55,    10,    35,    35,
      36,    40,    35,    68,    69,    72,    73,    22,    23,    24,
      25,    26,    27,    35,    16,    17,    18,    19,     3,    35,
       5,    51,    52,     3,    35,    36,     3,    35,    13,    35,
      11,     9,    11,    12,    41,    58,    59,    68,    12,     9,
      10,    12,    68,    72,    73,    72,    73,    11,    11,    35,
      35,    35,    37,    11,    38,    41,    42,    35,     7,    41,
      59,    41,    20,    21,    41,    20,    21,    41,    68,    68,
      68,    68,    68,    68,    40,    69,    69,    69,    69,     9,
      12,    68,    11,    39,    52,     9,    12,    13,    68,     7,
      10,    40,     3,    40,    35,    41,    42,    41,    41,    41,
      41,    41,    41,    41,    41,    41,     3,     3,     3,    35,
      36,     5,     6,    56,    57,    74,    38,    55,    37,    41,
      72,    73,    72,    73,    72,    73,    72,    73,    69,    35,
      35,    35,     3,    35,    40,    35,    35,    35,    40,    35,
      37,    35,    12,     9,    12,    68,    41,    59,    35,     9,
      12,    58,    68,    35,    35,    35,    35,    35,    62,    62,
      32,    32,    69,     9,    12,    68,    38,     7,    11,    11,
      39,    57,    74,    56,    36,     9,    12,    68,    41,    54,
      12,     3,    35,    36,    41,    35,    35,    35,    41,    29,
      29,    62,    62,    35,    35,    35,    35,     7,     8,     9,
      11,    12,    66,    37,     3,    35,     3,    35,    39,     7,
      35,    35,    35,    38,    41,    41,    38,     7,    35,    62,
      62,    72,    39,    43,     3,    35,     9,    12,    68,    10,
      37,    56,    38,    35,    66,    37,    35,    35,     7,     8,
       9,    11,    12,    38,    35,    35,    35,    35,    39,    56,
      39,     3,    35,    11,    38,    65,    39,    35,    38,     3,
      66,    39,    43,    65,    69,    39,    35,    38,    39,    41,
      66,    35,    78,    39,    62
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    45,    46,    47,    48,    48,    48,    48,
      48,    48,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    50,    50,    51,
      51,    52,    52,    52,    52,    52,    52,    53,    53,    54,
      54,    55,    56,    56,    56,    56,    57,    57,    57,    57,
      57,    57,    58,    58,    59,    59,    59,    59,    59,    59,
      59,    59,    60,    60,    61,    61,    62,    63,    63,    63,
      63,    63,    63,    63,    63,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    65,
      65,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    67,    67,    67,    67,    67,    67,    68,    68,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      70,    71,    72,    72,    72,    72,    72,    72,    72,    72,
      73,    73,    73,    73,    73,    73,    73,    73,    74,    74,
      74,    75,    75,    75,    75,    76,    76,    78,    77
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     2,     1,     2,     1,
       1,     2,     3,     3,     5,     5,     5,     5,     4,     6,
       6,     6,     6,     9,    10,    13,     1,     6,     5,     2,
       1,     3,     5,     5,     5,     8,     7,     8,     7,     1,
       3,     2,     2,     1,     1,     2,     3,     5,     3,     5,
       5,     5,     4,     5,     1,     1,     1,     3,     3,     3,
       1,     3,     3,     4,     4,     2,     3,     2,     2,     1,
       1,     2,     1,     1,     2,     3,     3,     5,     5,     5,
       5,     6,     6,     6,     6,     9,     6,     6,     6,     5,
       8,     7,     5,     5,     5,     5,     3,    10,    13,     3,
       5,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     4,     3,     4,     4,     4,     3,     1,     1,     3,
       3,     3,     3,     3,     1,     1,     1,     4,     7,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     5,     5,     7,     7,     6,     6,     0,    14
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 12: /* declaratie_globala: TIP ID ';'  */
#line 84 "tema.y"
                                {if(verificareExistenta((yyvsp[-1].strVal),"global") == 0) declarareId((yyvsp[-2].strVal),(yyvsp[-1].strVal),"global",0,0);
                              else if(verificareExistenta((yyvsp[-1].strVal),"global") == 3)
                               {printf("[Linia %d] Exista o functie cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);}
                              else if(verificareExistenta((yyvsp[-1].strVal),"global") == 4)
                               {printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);}
                              else {printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);}
                             }
#line 1569 "y.tab.c"
    break;

  case 13: /* declaratie_globala: TIP_BOOL ID ';'  */
#line 92 "tema.y"
                                   {
                                        if(verificareExistenta((yyvsp[-1].strVal),"global") == 0) declarareId((yyvsp[-2].strVal),(yyvsp[-1].strVal),"global",0,0);
                                        else if(verificareExistenta((yyvsp[-1].strVal),"global") == 3)
                                        {printf("[Linia %d] Exista o functie cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);}
                                        else if(verificareExistenta((yyvsp[-1].strVal),"global") == 4)
                                        {printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);}
                                        else {printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);}
                                   }
#line 1582 "y.tab.c"
    break;

  case 14: /* declaratie_globala: TIP_BOOL ID ASSIGN BOOL ';'  */
#line 100 "tema.y"
                                                  {
                                        if(verificareExistenta((yyvsp[-3].strVal),"global") == 0) declarareIdVal((yyvsp[-4].strVal),(yyvsp[-3].strVal),itoa((yyvsp[-1].boolVal)), "global",0,0);
                                        else if(verificareExistenta((yyvsp[-3].strVal),"global") == 3)
                                        {printf("[Linia %d] Exista o functie cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);}
                                        else if(verificareExistenta((yyvsp[-3].strVal),"global") == 4)
                                        {printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);}
                                        else {printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);}
                                   }
#line 1595 "y.tab.c"
    break;

  case 15: /* declaratie_globala: TIP ID ASSIGN expresie ';'  */
#line 109 "tema.y"
                                                {
                                             if(verificareExistenta((yyvsp[-3].strVal),"global") == 0) 
                                                            {
                                                                 if(isBoolExpression == 1)
                                                                      {
                                                                           isBoolExpression = 0;
                                                                           if(checkAssign(verificareTip((yyvsp[-3].strVal),"main"),"bool")==1)
                                                                           {
                                                                                asignare((yyvsp[-3].strVal), (yyvsp[-1].strVal), "main");
                                                                           }
                                                                           else
                                                                           {
                                                                                printf("[Linia %d] Nu pot exista atribuiri intre tipuri de date diferite.\n", yylineno);
                                                                                exit(1);
                                                                           }
                                                                      }
                                                                 else if(strcmp((yyvsp[-4].strVal),"string")==0)
                                                                 {
                                                                      if(strcmp((yyvsp[-1].strVal),"string")==0)
                                                                      {
                                                                           bzero(valoareStringChar2,256);
                                                                           strcpy(valoareStringChar2,valoareStringChar);
                                                                           declarareIdVal((yyvsp[-4].strVal),(yyvsp[-3].strVal),valoareStringChar2,"main",0,0);
                                                                      }
                                                                      else
                                                                      {
                                                                           printf("[Linia %d] Nu pot exista atribuiri intre tipuri de date diferite.\n", yylineno);
                                                                           exit(1);
                                                                      }
                                                                 }
                                                                 else if(strcmp((yyvsp[-4].strVal),"char")==0)
                                                                 {
                                                                      if(strcmp((yyvsp[-1].strVal),"char")==0)
                                                                      {
                                                                           strcpy(valoareStringChar3,valoareStringChar);
                                                                           declarareIdVal((yyvsp[-4].strVal),(yyvsp[-3].strVal),valoareStringChar3,"main",0,0);
                                                                      }
}
                                                                      else
                                                                      {
                                                                           int tip1=0;
                                                                           if(strcmp((yyvsp[-4].strVal),"int")==0)
                                                                                tip1 = 1;
                                                                           else if(strcmp((yyvsp[-4].strVal),"float")==0)
                                                                                tip1 = 0;
                                                                           int tip2 = verificareTipInt((yyvsp[-1].strVal));
                                                                           if (tip1 != tip2) 
                                                                           {
                                                                                printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                                                                exit(1);
                                                                           }
                                                                      
                                                                 else
                                                                 { 
                                                                      declarareIdVal((yyvsp[-4].strVal),(yyvsp[-3].strVal),(yyvsp[-1].strVal),"global",0,0);
                                                                 }
                                                                      }
                                                            }
                                                            else if(verificareExistenta((yyvsp[-3].strVal),"global") == 3)
                                                            {
                                                                 printf("[Linia %d] Exista o functie cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                                            }
                                                            else if(verificareExistenta((yyvsp[-3].strVal),"global") == 4)
                                                            {
                                                                 printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                                            }
                                                            else 
                                                            {
                                                                 printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);
                                                            }
                                                       }
#line 1671 "y.tab.c"
    break;

  case 16: /* declaratie_globala: TIP ID ASSIGN CHAR ';'  */
#line 180 "tema.y"
                                               {
                                             if(verificareExistenta((yyvsp[-3].strVal),"global") == 0) 
                                             {    
                                                  if(checkAssign((yyvsp[-4].strVal),"char")==1)
                                                  {
                                                       declarareIdVal((yyvsp[-4].strVal),(yyvsp[-3].strVal),ctoa((yyvsp[-1].charVal)),"global",0,0);
                                                  }
                                                  else 
                                                  {
                                                       printf("[Linia %d] Nu pot exista asignari intre tipuri de date diferite.\n",yylineno); exit(1);
                                                  }
                                             }
                                             else if(verificareExistenta((yyvsp[-3].strVal),"global") == 3)
                                             {
                                                  printf("[Linia %d] Exista o functie cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                             }
                                             else if(verificareExistenta((yyvsp[-3].strVal),"global") == 4)
                                             {
                                                  printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                             }
                                             else 
                                             {
                                                  printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);}
                                             }
#line 1700 "y.tab.c"
    break;

  case 17: /* declaratie_globala: TIP ID ASSIGN STRING ';'  */
#line 204 "tema.y"
                                              {if(verificareExistenta((yyvsp[-3].strVal),"global") == 0) 
                                             {    
                                                  if(checkAssign((yyvsp[-4].strVal),"string")==1)
                                                  {
                                                       declarareIdVal((yyvsp[-4].strVal),(yyvsp[-3].strVal),(yyvsp[-1].strVal),"global",0,0);
                                                  }
                                                  else 
                                                  {
                                                       printf("[Linia %d] Nu pot exista asignari intre tipuri de date diferite.\n",yylineno); exit(1);
                                                  }
                                             }
                                             else if(verificareExistenta((yyvsp[-3].strVal),"global") == 3)
                                             {
                                                  printf("[Linia %d] Exista o functie cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                             }
                                             else if(verificareExistenta((yyvsp[-3].strVal),"global") == 4)
                                             {
                                                  printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                             }
                                             else 
                                             {
                                                  printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);
                                             }
                                             
                                           }
#line 1730 "y.tab.c"
    break;

  case 18: /* declaratie_globala: CONST TIP ID ';'  */
#line 229 "tema.y"
                                      {printf("[Linia %d] Unei variabile declarata const trebuie sa-i fie asociata o valoare.\n",yylineno); exit(1);}
#line 1736 "y.tab.c"
    break;

  case 19: /* declaratie_globala: CONST TIP ID ASSIGN expresie ';'  */
#line 230 "tema.y"
                                                     {    
                                                                 if(verificareExistenta((yyvsp[-3].strVal),"global") == 0) 
                                                                 {
                                                                      int tip1=0;
                                                                      if(strcmp((yyvsp[-4].strVal),"int")==0)
                                                                           tip1 = 1;
                                                                      else if(strcmp((yyvsp[-4].strVal),"float")==0)
                                                                           tip1 = 0;
                                                                      int tip2 = verificareTipInt((yyvsp[-1].strVal));
                                                                      if (tip1 != tip2) 
                                                                      {
                                                                           printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                                                           exit(1);
                                                                      }
                                                                      else
                                                                      { 
                                                                           declarareIdVal((yyvsp[-4].strVal),(yyvsp[-3].strVal),(yyvsp[-1].strVal),"global",1,0);
                                                                      }
                                                                 }
                                                                 else if(verificareExistenta((yyvsp[-3].strVal),"global") == 3)
                                                                 {
                                                                      printf("[Linia %d] Exista o functie cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                                                 }
                                                                 else if(verificareExistenta((yyvsp[-3].strVal),"global") == 4)
                                                                 {
                                                                      printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                                                 }
                                                                 else 
                                                                 {
                                                                      printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno);
                                                                      exit(1);
                                                                 }
                                                  }
#line 1774 "y.tab.c"
    break;

  case 20: /* declaratie_globala: CONST TIP ID ASSIGN STRING ';'  */
#line 263 "tema.y"
                                                   {if(verificareExistenta((yyvsp[-3].strVal),"global") == 0)
                                                  {if(checkAssign((yyvsp[-4].strVal),"string")==1)
                                                  {
                                                        declarareIdVal((yyvsp[-4].strVal),(yyvsp[-3].strVal),(yyvsp[-1].strVal),"global",1,0);
                                                  }
                                                  else 
                                                  {
                                                            printf("[Linia %d] Nu pot exista asignari intre tipuri de date diferite.\n",yylineno); exit(1);
                                                  }
                                                  } 
                                                  else if(verificareExistenta((yyvsp[-3].strVal),"global") == 3)
                                                  {
                                                       printf("[Linia %d] Exista o functie cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                                  }
                                                  else if(verificareExistenta((yyvsp[-3].strVal),"global") == 4)
                                                  {
                                                       printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                                  }                                                             
                                           else {printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);}
                                           }
#line 1799 "y.tab.c"
    break;

  case 21: /* declaratie_globala: CONST TIP ID ASSIGN CHAR ';'  */
#line 283 "tema.y"
                                                    {
                                                  if(verificareExistenta((yyvsp[-3].strVal),"global") == 0) 
                                             {    
                                                  if(checkAssign((yyvsp[-4].strVal),"char")==1)
                                                  {
                                                       declarareIdVal((yyvsp[-4].strVal),(yyvsp[-3].strVal),ctoa((yyvsp[-1].charVal)),"global",1,0);
                                                  }
                                                  else 
                                                       {
                                                            printf("[Linia %d] Nu pot exista asignari intre tipuri de date diferite.\n",yylineno); exit(1);
                                                       }
                                             }
                                             else if(verificareExistenta((yyvsp[-3].strVal),"global") == 3)
                                             {
                                                  printf("[Linia %d] Exista o functie cu acleasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                             }
                                             else if(verificareExistenta((yyvsp[-3].strVal),"global") == 4)
                                             {
                                                  printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                             }
                                             else {printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);}
                                           }
#line 1826 "y.tab.c"
    break;

  case 22: /* declaratie_globala: TIP ID '[' INT ']' ';'  */
#line 305 "tema.y"
                                                {if(verificareExistenta((yyvsp[-4].strVal),"global") == 0) declara_vector((yyvsp[-4].strVal),(yyvsp[-5].strVal),(yyvsp[-2].intVal),lista_elemente_vector,"global",0,1);
                                              else if(verificareExistenta((yyvsp[-4].strVal),"global") == 3)
                                             {
                                                  printf("[Linia %d] Exista o functie cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno);
                                                  exit(1);
                                             }
                                             else if(verificareExistenta((yyvsp[-4].strVal),"global") == 4)
                                             {
                                                  printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno);
                                                  exit(1);
                                             }
                                              else {printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);} 
                                             }
#line 1844 "y.tab.c"
    break;

  case 23: /* declaratie_globala: TIP ID '[' INT ']' '[' INT ']' ';'  */
#line 318 "tema.y"
                                                    {if(verificareExistenta((yyvsp[-7].strVal),"global") == 0) declara_matrice((yyvsp[-7].strVal),(yyvsp[-8].strVal),(yyvsp[-5].intVal),(yyvsp[-2].intVal),lista_elemente_matrice,"global",0,2);
                                              else if(verificareExistenta((yyvsp[-7].strVal),"global") == 3)
                                             {
                                                  printf("[Linia %d] Exista o functie cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno);
                                                  exit(1);
                                             }
                                              else if(verificareExistenta((yyvsp[-7].strVal),"global") == 4)
                                             {
                                                  printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno);
                                                  exit(1);
                                             }
                                              else {printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);} 
                                             }
#line 1862 "y.tab.c"
    break;

  case 24: /* declaratie_globala: TIP ID '[' INT ']' ASSIGN '{' elemente_vector '}' ';'  */
#line 331 "tema.y"
                                                                         {declara_vector((yyvsp[-8].strVal),(yyvsp[-9].strVal),(yyvsp[-6].intVal),lista_elemente_vector,"main",0,1); lista_elemente_vector[0]='\0';}
#line 1868 "y.tab.c"
    break;

  case 25: /* declaratie_globala: TIP ID '[' INT ']' '[' INT ']' ASSIGN '{' matrice '}' ';'  */
#line 332 "tema.y"
                                                                              {declara_matrice((yyvsp[-11].strVal),(yyvsp[-12].strVal),(yyvsp[-9].intVal),(yyvsp[-6].intVal),lista_elemente_matrice,"main",0,2); linii=0;lista_elemente_matrice[0]='\0';}
#line 1874 "y.tab.c"
    break;

  case 27: /* clasa: CLASS ID '{' secventa_instructiuni_clasa '}' ';'  */
#line 338 "tema.y"
                                                         {  
                                                                      if(verificareExistenta((yyvsp[-4].strVal),"main") == 0)
                                                                      { 
                                                                           declara_clasa((yyvsp[-4].strVal),listaVarClasa);  
                                                                           bzero(listaVarClasa,256);
                                                                      }
                                                                      else if(verificareExistenta((yyvsp[-4].strVal),"main") == 3)
                                                                      {
                                                                           printf("[Linia %d] O functie cu acest nume a fost declarata anterior.\n", yylineno);
                                                                           exit(1);
                                                                      }
                                                                      else if(verificareExistenta((yyvsp[-4].strVal),"main") == 4)
                                                                      {
                                                                           printf("[Linia %d] O clasa cu acest nume a fost declarata anterior.\n", yylineno);
                                                                           exit(1);
                                                                      }
                                                                      else
                                                                      {
                                                                           printf("[Linia %d] O variabila cu acest nume a fost declarata anterior.\n", yylineno);
                                                                           exit(1);
                                                                      }
                                                                 }
#line 1901 "y.tab.c"
    break;

  case 28: /* clasa: CLASS ID '{' secventa_instructiuni_clasa '}'  */
#line 360 "tema.y"
                                                      {printf("[Linia %d] Lipseste ';' la finalul clasei!\n",yylineno); exit(1);}
#line 1907 "y.tab.c"
    break;

  case 31: /* declaratii_clasa: TIP ID ';'  */
#line 367 "tema.y"
                              {strcat(listaVarClasa,(yyvsp[-2].strVal));strcat(listaVarClasa," ");strcat(listaVarClasa,(yyvsp[-1].strVal));strcat(listaVarClasa," ");strcat(listaVarClasa,"$ ");}
#line 1913 "y.tab.c"
    break;

  case 32: /* declaratii_clasa: TIP ID ASSIGN expresie ';'  */
#line 368 "tema.y"
                                             {int tip1=0;
                                             if(strcmp((yyvsp[-4].strVal),"int")==0)
                                             tip1 = 1;
                                             else if(strcmp((yyvsp[-4].strVal),"float")==0)
                                             tip1 = 0;
                                             int tip2 = verificareTipInt((yyvsp[-1].strVal));
                                             if (tip1 != tip2) 
                                             {
                                             printf("[Linia %d] Nu pot exista asignari intre tipuri de date diferite.\n", yylineno);
                                             exit(1);
                                             }
                                             strcat(listaVarClasa,(yyvsp[-4].strVal));strcat(listaVarClasa," ");strcat(listaVarClasa,(yyvsp[-3].strVal));strcat(listaVarClasa," ");strcat(listaVarClasa,(yyvsp[-1].strVal));strcat(listaVarClasa," ");}
#line 1930 "y.tab.c"
    break;

  case 33: /* declaratii_clasa: TIP ID ASSIGN CHAR ';'  */
#line 380 "tema.y"
                                         {
                                             if (strcmp((yyvsp[-4].strVal),"char")!=0) 
                                             {
                                             printf("[Linia %d] Nu pot exista asignari intre tipuri de date diferite.\n", yylineno);
                                             exit(1);
                                             }
                                             strcat(listaVarClasa,(yyvsp[-4].strVal));strcat(listaVarClasa," ");strcat(listaVarClasa,(yyvsp[-3].strVal));strcat(listaVarClasa," ");strcat(listaVarClasa,itoa((yyvsp[-1].charVal)));strcat(listaVarClasa," ");}
#line 1942 "y.tab.c"
    break;

  case 34: /* declaratii_clasa: TIP ID ASSIGN STRING ';'  */
#line 387 "tema.y"
                                           {
                                             if (strcmp((yyvsp[-4].strVal),"string")!=0) 
                                             {
                                             printf("[Linia %d] Nu pot exista asignari intre tipuri de date diferite.\n", yylineno);
                                             exit(1);
                                             }
                                             strcat(listaVarClasa,(yyvsp[-4].strVal));strcat(listaVarClasa," ");strcat(listaVarClasa,(yyvsp[-3].strVal));strcat(listaVarClasa," ");strcat(listaVarClasa,(yyvsp[-1].strVal));strcat(listaVarClasa," ");}
#line 1954 "y.tab.c"
    break;

  case 35: /* declaratii_clasa: TIP ID '(' parametri ')' '{' bloc_functie '}'  */
#line 394 "tema.y"
                                                                 {
                                                                      if(verificareExistenta((yyvsp[-6].strVal),"main") == 0)
                                                                      {
                                                                           if(verificaDuplicat_functie((yyvsp[-6].strVal)) == 0)
                                                                      {    
                                                                           
                                                                           declara_functie((yyvsp[-7].strVal), (yyvsp[-6].strVal), 1);  
                                                                           lista_parametri[0] = '\0';   
                                                                      }
                                                                      }
                                                                      else if(verificareExistenta((yyvsp[-6].strVal),"main") == 3)
                                                                      {
                                                                           printf("[Linia %d] O functie cu acest nume a fost declarata anterior.\n", yylineno);
                                                                           exit(1);
                                                                      }
                                                                      else
                                                                      {
                                                                           printf("[Linia %d] O variabila cu acest nume a fost declarata anterior.\n", yylineno);
                                                                           exit(1);
                                                                      }
                                                                 }
#line 1980 "y.tab.c"
    break;

  case 36: /* declaratii_clasa: TIP ID '(' ')' '{' bloc_functie '}'  */
#line 415 "tema.y"
                                                                 {
                                                                      if(verificareExistenta((yyvsp[-5].strVal),"main") == 0)
                                                                      {
                                                                           if(verificaDuplicat_functie((yyvsp[-5].strVal)) == 0)
                                                                      {    
                                                                           lista_parametri[0] = '\0'; 
                                                                           declara_functie((yyvsp[-6].strVal), (yyvsp[-5].strVal), 1);  
                                                                           lista_parametri[0] = '\0';   
                                                                      }
                                                                      }
                                                                      else if(verificareExistenta((yyvsp[-5].strVal),"main") == 3)
                                                                      {
                                                                           printf("[Linia %d] O functie cu acest nume a fost declarata anterior.\n", yylineno);
                                                                           exit(1);
                                                                      }
                                                                      else
                                                                      {
                                                                           printf("[Linia %d] O variabila cu acest nume a fost declarata anterior.\n", yylineno);
                                                                           exit(1);
                                                                      }
                                                                 }
#line 2006 "y.tab.c"
    break;

  case 37: /* declaratie_functie: TIP ID '(' parametri ')' '{' bloc_functie '}'  */
#line 441 "tema.y"
                                                                    {
                                                                      if(verificareExistenta((yyvsp[-6].strVal),"main") == 0)
                                                                      {
                                                                           if(verificaDuplicat_functie((yyvsp[-6].strVal)) == 0)
                                                                      {    
                                                                           
                                                                           declara_functie((yyvsp[-7].strVal), (yyvsp[-6].strVal), 0);  
                                                                           lista_parametri[0] = '\0';   
                                                                      }
                                                                      }
                                                                      else if(verificareExistenta((yyvsp[-6].strVal),"main") == 3)
                                                                      {
                                                                           printf("[Linia %d] O functie cu acest nume a fost declarata anterior.\n", yylineno);
                                                                           exit(1);
                                                                      }
                                                                      else
                                                                      {
                                                                           printf("[Linia %d] O variabila cu acest nume a fost declarata anterior.\n", yylineno);
                                                                           exit(1);
                                                                      }
                                                                 }
#line 2032 "y.tab.c"
    break;

  case 38: /* declaratie_functie: TIP ID '(' ')' '{' bloc_functie '}'  */
#line 462 "tema.y"
                                                                 {
                                                                      if(verificareExistenta((yyvsp[-5].strVal),"main") == 0)
                                                                      {
                                                                           if(verificaDuplicat_functie((yyvsp[-5].strVal)) == 0)
                                                                      {    
                                                                           lista_parametri[0] = '\0'; 
                                                                           declara_functie((yyvsp[-6].strVal), (yyvsp[-5].strVal), 0);  
                                                                           lista_parametri[0] = '\0';   
                                                                      }
                                                                      }
                                                                      else if(verificareExistenta((yyvsp[-5].strVal),"main") == 3)
                                                                      {
                                                                           printf("[Linia %d] O functie cu acest nume a fost declarata anterior.\n", yylineno);
                                                                           exit(1);
                                                                      }
                                                                      else
                                                                      {
                                                                           printf("[Linia %d] O variabila cu acest nume a fost declarata anterior.\n", yylineno);
                                                                           exit(1);
                                                                      }
                                                                 }
#line 2058 "y.tab.c"
    break;

  case 39: /* parametri: parametru  */
#line 484 "tema.y"
                      {strcpy(lista_parametri,param);(yyval.strVal)=lista_parametri;}
#line 2064 "y.tab.c"
    break;

  case 40: /* parametri: parametri '|' parametru  */
#line 485 "tema.y"
                                     {strcat(lista_parametri," ");strcat(lista_parametri,param);(yyval.strVal)=lista_parametri;}
#line 2070 "y.tab.c"
    break;

  case 41: /* parametru: TIP ID  */
#line 488 "tema.y"
                   {strcpy(param,(yyvsp[-1].strVal));strcat(param," ");strcat(param,(yyvsp[0].strVal));}
#line 2076 "y.tab.c"
    break;

  case 52: /* apel_functie: ID '(' ')' ';'  */
#line 503 "tema.y"
                              {                        strcpy(functieId, (yyvsp[-3].strVal));
                                                       lista_parametri_apel[0]='\0';
                                                       if(vericareAntetApelFunctie((yyvsp[-3].strVal),lista_parametri_apel)==0)
                                                        {printf("[Linia %d]Pentru a putea apela o functie, aceasta trebuie sa fi fost declarata!\n", yylineno);
    exit(1);}
                                   lista_parametri_apel[0]='\0';
                                                     }
#line 2088 "y.tab.c"
    break;

  case 53: /* apel_functie: ID '(' apel_functie_parametri ')' ';'  */
#line 510 "tema.y"
                                                     { strcpy(functieId, (yyvsp[-4].strVal));
                                                       if(vericareAntetApelFunctie((yyvsp[-4].strVal),lista_parametri_apel)==0)
                                                       {printf("[Linia %d]Pentru a putea apela o functie, aceasta trebuie sa fi fost declarata!\n", yylineno);
    exit(1);}
                                                       lista_parametri_apel[0]='\0';
                                                     }
#line 2099 "y.tab.c"
    break;

  case 54: /* apel_functie_parametri: expresie  */
#line 517 "tema.y"
                                  {strcpy(lista_parametri_apel,determinareTip((yyvsp[0].strVal))); strcat(lista_parametri_apel," ");(yyval.strVal)=lista_parametri_apel;}
#line 2105 "y.tab.c"
    break;

  case 55: /* apel_functie_parametri: CHAR  */
#line 518 "tema.y"
                                  {strcpy(lista_parametri_apel,"char");             strcat(lista_parametri_apel," ");(yyval.strVal)=lista_parametri_apel;}
#line 2111 "y.tab.c"
    break;

  case 56: /* apel_functie_parametri: STRING  */
#line 519 "tema.y"
                                  {strcpy(lista_parametri_apel,"string");           strcat(lista_parametri_apel," ");(yyval.strVal)=lista_parametri_apel; }
#line 2117 "y.tab.c"
    break;

  case 57: /* apel_functie_parametri: apel_functie_parametri '|' CHAR  */
#line 520 "tema.y"
                                                             {strcat(lista_parametri_apel,"char");             strcat(lista_parametri_apel," ");(yyval.strVal)=lista_parametri_apel;}
#line 2123 "y.tab.c"
    break;

  case 58: /* apel_functie_parametri: apel_functie_parametri '|' STRING  */
#line 521 "tema.y"
                                                             {strcat(lista_parametri_apel,"string");           strcat(lista_parametri_apel," ");(yyval.strVal)=lista_parametri_apel;}
#line 2129 "y.tab.c"
    break;

  case 59: /* apel_functie_parametri: apel_functie_parametri '|' expresie  */
#line 522 "tema.y"
                                                             {strcat(lista_parametri_apel,determinareTip((yyvsp[0].strVal))); strcat(lista_parametri_apel," ");(yyval.strVal)=lista_parametri_apel;}
#line 2135 "y.tab.c"
    break;

  case 62: /* apel_functie_expr: ID '(' ')'  */
#line 526 "tema.y"
                                {    
                                                      lista_parametri_apel[0]='\0';
                                                       if(vericareAntetApelFunctie((yyvsp[-2].strVal),lista_parametri_apel)==0)
                                                        {printf("[Linia %d]Pentru a putea apela o functie, aceasta trebuie sa fi fost declarata!\n", yylineno);
    exit(1);}
                                   lista_parametri_apel[0]='\0';
                                                        (yyval.strVal)=(yyvsp[-2].strVal);
                                                     }
#line 2148 "y.tab.c"
    break;

  case 63: /* apel_functie_expr: ID '(' apel_functie_parametri ')'  */
#line 534 "tema.y"
                                                   { 
                                                       if(vericareAntetApelFunctie((yyvsp[-3].strVal),lista_parametri_apel)==0)
                                                       {printf("[Linia %d]Pentru a putea apela o functie, aceasta trebuie sa fi fost declarata!\n", yylineno);
    exit(1);}
                                                       lista_parametri_apel[0]='\0';
                                                       (yyval.strVal)=(yyvsp[-3].strVal);
                                                     }
#line 2160 "y.tab.c"
    break;

  case 65: /* main: MAIN bloc_main  */
#line 545 "tema.y"
                      {printf("[Linia %d]Eroare lipsesc ().\n",yylineno);exit(1);}
#line 2166 "y.tab.c"
    break;

  case 75: /* declaratie_main: TIP ID ';'  */
#line 561 "tema.y"
                             {if(verificareExistenta((yyvsp[-1].strVal),"main") == 0) declarareId((yyvsp[-2].strVal),(yyvsp[-1].strVal),"main",0,0);
                              else if(verificareExistenta((yyvsp[-1].strVal),"main") == 3)
                               {printf("[Linia %d] Exista o functie cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);}
                              else if(verificareExistenta((yyvsp[-1].strVal),"main") == 4)
                               {printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);}
                              else {printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);}
                             }
#line 2178 "y.tab.c"
    break;

  case 76: /* declaratie_main: TIP_BOOL ID ';'  */
#line 568 "tema.y"
                                  {
                                   if(verificareExistenta((yyvsp[-1].strVal),"main") == 0) declarareId((yyvsp[-2].strVal),(yyvsp[-1].strVal),"main",0,0);
                                   else if(verificareExistenta((yyvsp[-1].strVal),"main") == 3)
                                   {printf("[Linia %d] Exista o functie cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);}
                                   else if(verificareExistenta((yyvsp[-1].strVal),"main") == 4)
                                   {printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);}
                                   else {printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);}
                                   }
#line 2191 "y.tab.c"
    break;

  case 77: /* declaratie_main: TIP_BOOL ID ASSIGN BOOL ';'  */
#line 577 "tema.y"
                                   {
                                   if(verificareExistenta((yyvsp[-3].strVal),"main") == 0) declarareIdVal((yyvsp[-4].strVal),(yyvsp[-3].strVal),itoa((yyvsp[-1].boolVal)),"main",0,0);
                                   else if(verificareExistenta((yyvsp[-3].strVal),"main") == 3)
                                   {printf("[Linia %d] Exista o functie cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);}
                                   else if(verificareExistenta((yyvsp[-3].strVal),"main") == 4)
                                   {printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);}
                                   else {printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);}
                                   }
#line 2204 "y.tab.c"
    break;

  case 78: /* declaratie_main: TIP ID ASSIGN expresie ';'  */
#line 585 "tema.y"
                                             {    
                                                            if(verificareExistenta((yyvsp[-3].strVal),"main") == 0) 
                                                            {
                                                                 if(isBoolExpression == 1)
                                                                      {
                                                                           isBoolExpression = 0;
                                                                           char idType[69];
                                                                           if(checkAssign(verificareTip((yyvsp[-3].strVal),"main"),"bool")==1)
                                                                           {
                                                                                asignare((yyvsp[-3].strVal), (yyvsp[-1].strVal), "main");
                                                                           }
                                                                           else
                                                                           {
                                                                                printf("[Linia %d] Nu pot exista atribuiri intre tipuri de date diferite.\n", yylineno);
                                                                                exit(1);
                                                                           }
                                                                      }
                                                                 else if(strcmp((yyvsp[-4].strVal),"string")==0)
                                                                 {
                                                                      if(strcmp((yyvsp[-1].strVal),"string")==0)
                                                                      {
                                                                           bzero(valoareStringChar2,256);
                                                                           strcpy(valoareStringChar2,valoareStringChar);
                                                                           declarareIdVal((yyvsp[-4].strVal),(yyvsp[-3].strVal),valoareStringChar2,"main",0,0);
                                                                      }
                                                                      else
                                                                      {
                                                                           printf("[Linia %d] Nu pot exista atribuiri intre tipuri de date diferite.\n", yylineno);
                                                                           exit(1);
                                                                      }
                                                                 }
                                                                 else if(strcmp((yyvsp[-4].strVal),"char")==0)
                                                                 {
                                                                      if(strcmp((yyvsp[-1].strVal),"char")==0)
                                                                      {
                                                                           strcpy(valoareStringChar3,valoareStringChar);
                                                                           declarareIdVal((yyvsp[-4].strVal),(yyvsp[-3].strVal),valoareStringChar3,"main",0,0);
                                                                      }
                                                                      else
                                                                      {
                                                                           printf("[Linia %d] Nu pot exista atribuiri intre tipuri de date diferite.\n", yylineno);
                                                                           exit(1);
                                                                      }
                                                                 }
                                                                 else
                                                                 {
                                                                 int tip1=0;
                                                                 if(strcmp((yyvsp[-4].strVal),"int")==0)
                                                                      tip1 = 1;
                                                                 else if(strcmp((yyvsp[-4].strVal),"float")==0)
                                                                      tip1 = 0;
                                                                 int tip2 = verificareTipInt((yyvsp[-1].strVal));
                                                                 if (tip1 != tip2) 
                                                                 {
                                                                      printf("[Linia %d] Nu pot exista atribuiri intre tipuri de date diferite.\n", yylineno);
                                                                      exit(1);
                                                                 }
                                                                 else
                                                                 { 
                                                                      declarareIdVal((yyvsp[-4].strVal),(yyvsp[-3].strVal),(yyvsp[-1].strVal),"main",0,0);
                                                                 }
                                                                 }
                                                            }
                                                            else if(verificareExistenta((yyvsp[-3].strVal),"main") == 3)
                                                            {
                                                                 printf("[Linia %d] Exista o functie cu acleasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                                            }
                                                            else if(verificareExistenta((yyvsp[-3].strVal),"main") == 4)
                                                            {
                                                                 printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                                            }   
                                                            else 
                                                            {
                                                                 printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);}
                                                            }
#line 2284 "y.tab.c"
    break;

  case 79: /* declaratie_main: TIP ID ASSIGN STRING ';'  */
#line 662 "tema.y"
                                           {
                                             if(verificareExistenta((yyvsp[-3].strVal),"main") == 0) 
                                             {    
                                                  if(checkAssign((yyvsp[-4].strVal),"string")==1)
                                                  {
                                                       declarareIdVal((yyvsp[-4].strVal),(yyvsp[-3].strVal),(yyvsp[-1].strVal),"main",0,0);
                                                  }
                                                  else 
                                                  {
                                                       printf("[Linia %d] Nu pot exista asignari intre tipuri de date diferite.\n",yylineno); exit(1);
                                                  }
                                             }
                                             else if(verificareExistenta((yyvsp[-3].strVal),"main") == 3)
                                             {
                                                  printf("[Linia %d] Exista o functie cu acleasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                             }
                                             else if(verificareExistenta((yyvsp[-3].strVal),"main") == 4)
                                             {
                                                  printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                             }
                                             else 
                                             {
                                                  printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);
                                             }
                                           }
#line 2314 "y.tab.c"
    break;

  case 80: /* declaratie_main: TIP ID ASSIGN CHAR ';'  */
#line 687 "tema.y"
                                         {
                                             if(verificareExistenta((yyvsp[-3].strVal),"main") == 0) 
                                             {    
                                                  if(checkAssign((yyvsp[-4].strVal),"char")==1)
                                                  {
                                                       declarareIdVal((yyvsp[-4].strVal),(yyvsp[-3].strVal),ctoa((yyvsp[-1].charVal)),"main",0,0);
                                                  }
                                                  else 
                                                  {
                                                       printf("[Linia %d] Nu pot exista asignari intre tipuri de date diferite.\n",yylineno); exit(1);
                                                  }
                                             }
                                             else if(verificareExistenta((yyvsp[-3].strVal),"main") == 3)
                                             {
                                                  printf("[Linia %d] Exista o functie cu acleasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                             }
                                             else if(verificareExistenta((yyvsp[-3].strVal),"main") == 4)
                                             {
                                                  printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                             }
                                             else 
                                             {
                                                  printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);
                                             }
                                           }
#line 2344 "y.tab.c"
    break;

  case 81: /* declaratie_main: CONST TIP ID ASSIGN expresie ';'  */
#line 712 "tema.y"
                                                     {    
                                                                 if(verificareExistenta((yyvsp[-3].strVal),"main") == 0) 
                                                                 {
                                                                      int tip1=0;
                                                                      if(strcmp((yyvsp[-4].strVal),"int")==0)
                                                                           tip1 = 1;
                                                                      else if(strcmp((yyvsp[-4].strVal),"float")==0)
                                                                           tip1 = 0;
                                                                      int tip2 = verificareTipInt((yyvsp[-1].strVal));
                                                                      if (tip1 != tip2) 
                                                                      {
                                                                           printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                                                           exit(1);
                                                                      }
                                                                      else
                                                                      { 
                                                                           declarareIdVal((yyvsp[-4].strVal),(yyvsp[-3].strVal),(yyvsp[-1].strVal),"main",1,0);
                                                                      }
                                                                 }
                                                                 else if(verificareExistenta((yyvsp[-3].strVal),"main") == 3)
                                                                 {
                                                                      printf("[Linia %d] Exista o functie cu acleasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                                                 }
                                                                 else if(verificareExistenta((yyvsp[-3].strVal),"main") == 4)
                                                                 {
                                                                      printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                                                 }
                                                                 else 
                                                                 {
                                                                      printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno);
                                                                      exit(1);
                                                                 }
                                                  }
#line 2382 "y.tab.c"
    break;

  case 82: /* declaratie_main: CONST TIP ID ASSIGN CHAR ';'  */
#line 745 "tema.y"
                                                 {
                                                  if(verificareExistenta((yyvsp[-3].strVal),"main") == 0) 
                                             {    
                                                  if(checkAssign((yyvsp[-4].strVal),"char")==1)
                                                  {
                                                       declarareIdVal((yyvsp[-4].strVal),(yyvsp[-3].strVal),ctoa((yyvsp[-1].charVal)),"main",1,0);
                                                  }
                                                  else 
                                                       {
                                                            printf("[Linia %d] Nu pot exista asignari intre tipuri de date diferite.\n",yylineno); exit(1);
                                                       }
                                             }
                                             else if(verificareExistenta((yyvsp[-3].strVal),"main") == 3)
                                             {
                                                  printf("[Linia %d] Exista o functie cu acleasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                             }
                                             else if(verificareExistenta((yyvsp[-3].strVal),"main") == 4)
                                             {
                                                  printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                             }
                                             else {printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);}
                                           }
#line 2409 "y.tab.c"
    break;

  case 83: /* declaratie_main: CONST TIP ID ASSIGN STRING ';'  */
#line 767 "tema.y"
                                                {if(verificareExistenta((yyvsp[-3].strVal),"main") == 0)
                                                  {if(checkAssign((yyvsp[-4].strVal),"string")==1)
                                                  {
                                                        declarareIdVal((yyvsp[-4].strVal),(yyvsp[-3].strVal),(yyvsp[-1].strVal),"main",1,0);
                                                  }
                                                  else 
                                                  {
                                                            printf("[Linia %d] Nu pot exista asignari intre tipuri de date diferite.\n",yylineno); exit(1);
                                                  }

                                                  } 
                                                  else if(verificareExistenta((yyvsp[-3].strVal),"main") == 3)
                                                  {
                                                       printf("[Linia %d] Exista o functie cu acleasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                                  }
                                                  else if(verificareExistenta((yyvsp[-3].strVal),"main") == 4)
                                                  {
                                                       printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                                  }            
                                           else {printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);}
                                           }
#line 2435 "y.tab.c"
    break;

  case 84: /* declaratie_main: TIP ID '[' INT ']' ';'  */
#line 788 "tema.y"
                                             {if(verificareExistenta((yyvsp[-4].strVal),"main") == 0) declara_vector((yyvsp[-4].strVal),(yyvsp[-5].strVal),(yyvsp[-2].intVal),lista_elemente_matrice,"main",0,1);
                                              else if(verificareExistenta((yyvsp[-4].strVal),"main") == 3)
                                             {
                                                  printf("[Linia %d] Exista o functie cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno);
                                                  exit(1);
                                             }
                                             else if(verificareExistenta((yyvsp[-4].strVal),"main") == 4)
                                             {
                                                  printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno);
                                                  exit(1);
                                             }
                                              else {printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);} 
                                             }
#line 2453 "y.tab.c"
    break;

  case 85: /* declaratie_main: TIP ID '[' INT ']' '[' INT ']' ';'  */
#line 801 "tema.y"
                                                     { 
                                                       if(verificareExistenta((yyvsp[-7].strVal),"main") == 0) declara_matrice((yyvsp[-7].strVal),(yyvsp[-8].strVal),(yyvsp[-5].intVal),(yyvsp[-2].intVal),lista_elemente_matrice,"main",0,2);
                                                       else if(verificareExistenta((yyvsp[-7].strVal),"main") == 3)
                                                       {
                                                            printf("[Linia %d] Exista o functie cu acleasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); 
                                                            exit(1);
                                                       }
                                                       else if(verificareExistenta((yyvsp[-7].strVal),"main") == 4)
                                                       {
                                                            printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno);
                                                            exit(1);
                                                       }
                                                       else {printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);} 
                                                     }
#line 2472 "y.tab.c"
    break;

  case 86: /* declaratie_main: ID DOT ID ASSIGN expresie ';'  */
#line 815 "tema.y"
                                                            {
                                                                 if(verificareExistenta((yyvsp[-5].strVal), "main") == 1 || verificareExistenta((yyvsp[-5].strVal), "main") == 2)
                                                                 {    
                                                                       int tip_expr = verificareTipInt((yyvsp[-1].strVal));
                                                                           char *tip;
                                                                           if(tip_expr==0)
                                                                                tip = "float";
                                                                           else
                                                                                tip = "int";
                                                                       if(verificaCamp_clasa((yyvsp[-5].strVal), (yyvsp[-3].strVal),tip) == -1)
                                                                      {
                                                                           printf("[Linia %d] Tipul campului %s caruia incercati sa-i asignati o valoare este diferit de tipul valorii!\n",yylineno, (yyvsp[-3].strVal));
                                                                           exit(1);
                                                                      }
                                                                      else if(verificaCamp_clasa((yyvsp[-5].strVal), (yyvsp[-3].strVal),tip) == 0)
                                                                      {
                                                                           printf("[Linia %d] Nu se poate realiza accesarea campului %s deoarece acesta nu exista in clasa!\n",yylineno, (yyvsp[-3].strVal));
                                                                           exit(1);
                                                                      }
                                                                 }
                                                                 else
                                                                 {
                                                                      printf("[Linia %d] Nu exista o variabila declarata cu id-ul %s.\n", yylineno, (yyvsp[-5].strVal)); 
                                                                      exit(1);
                                                                 }
                                                            }
#line 2503 "y.tab.c"
    break;

  case 87: /* declaratie_main: ID DOT ID ASSIGN CHAR ';'  */
#line 841 "tema.y"
                                                        {
                                                                 if(verificareExistenta((yyvsp[-5].strVal), "main") == 1 || verificareExistenta((yyvsp[-5].strVal), "main") == 2)
                                                                 {    
                                                                           char *tip;
                                                                           tip = "char";
                                                                       if(verificaCamp_clasa((yyvsp[-5].strVal), (yyvsp[-3].strVal),tip) == -1)
                                                                      {
                                                                           printf("[Linia %d] Tipul campului %s caruia incercati sa-i asignati o valoare este diferit de tipul valorii!\n",yylineno, (yyvsp[-3].strVal));
                                                                           exit(1);
                                                                      }
                                                                      else if(verificaCamp_clasa((yyvsp[-5].strVal), (yyvsp[-3].strVal),tip) == 0)
                                                                      {
                                                                           printf("[Linia %d] Nu se poate realiza accesarea campului %s deoarece acesta nu exista in clasa!\n",yylineno, (yyvsp[-3].strVal));
                                                                           exit(1);
                                                                      }
                                                                 }
                                                                 else
                                                                 {
                                                                      printf("[Linia %d] Nu exista o variabila declarata cu id-ul %s.\n", yylineno, (yyvsp[-5].strVal)); 
                                                                      exit(1);
                                                                 }
                                                            }
#line 2530 "y.tab.c"
    break;

  case 88: /* declaratie_main: ID DOT ID ASSIGN STRING ';'  */
#line 863 "tema.y"
                                                          {
                                                                 if(verificareExistenta((yyvsp[-5].strVal), "main") == 1 || verificareExistenta((yyvsp[-5].strVal), "main") == 2)
                                                                 {    
                                                                           char *tip;
                                                                           tip = "string";
                                                                       if(verificaCamp_clasa((yyvsp[-5].strVal), (yyvsp[-3].strVal),tip) == -1)
                                                                      {
                                                                           printf("[Linia %d] Tipul campului %s caruia incercati sa-i asignati o valoare este diferit de tipul valorii!\n",yylineno, (yyvsp[-3].strVal));
                                                                           exit(1);
                                                                      }
                                                                      else if(verificaCamp_clasa((yyvsp[-5].strVal), (yyvsp[-3].strVal),tip) == 0)
                                                                      {
                                                                           printf("[Linia %d] Nu se poate realiza accesarea campului %s deoarece acesta nu exista in clasa!\n",yylineno, (yyvsp[-3].strVal));
                                                                           exit(1);
                                                                      }
                                                                 }
                                                                 else
                                                                 {
                                                                      printf("[Linia %d] Nu exista o variabila declarata cu id-ul %s.\n", yylineno, (yyvsp[-5].strVal)); 
                                                                      exit(1);
                                                                 }
                                                            }
#line 2557 "y.tab.c"
    break;

  case 89: /* declaratie_main: EVAL '(' STRING ')' ';'  */
#line 885 "tema.y"
                                            {   int g=0;
                                                char EvalVerificare[256];
                                                strcpy(EvalVerificare,(yyvsp[-2].strVal));
                                                
                                                for(int i = 0; i<strlen(EvalVerificare);i++)
                                                  if(strchr(".",EvalVerificare[i]) && strchr("+-/*",EvalVerificare[i])!=0)
                                                  {
                                                       printf("[Linia %d]Eval poate evalua doar expresii de tip int, in cazul de fata aveti o valoare de tip float in expresie\n",yylineno);
                                                       exit(1);
                                                  }
                                                  else if(strchr(".",EvalVerificare[i]) && strchr("+-/*",EvalVerificare[i])==0)
                                                  {
                                                       printf("Eval (%s) este : %s\n",(yyvsp[-2].strVal),(yyvsp[-2].strVal));
                                                       g=1;
                                                  }
                                                
                                                for(int i = 0; i<strlen(EvalVerificare);i++)
                                                    if(strchr("''",EvalVerificare[i]))
                                                {printf("[Linia %d]Eval poate evalua doar expresii de tip int, in cazul de fata aveti o valoare de tip char in expresie\n",yylineno);
                                                 exit(1);}
                                                for(int i = 0; i<strlen(EvalVerificare);i++)
                                                    if(strchr("""",EvalVerificare[i]))
                                                {printf("[Linia %d]Eval poate evalua doar expresii de tip int, in cazul de fata aveti o valoare de tip string in expresie\n",yylineno);
                                                 exit(1);}
                                                
                                                for(int i = 0; i<strlen(EvalVerificare);i++)
                                                    if(strchr("+-/*",EvalVerificare[i]))
                                                        {AST((yyvsp[-2].strVal));g=1;break;}
                                                    if(g==0)
                                                    {   
                                                        char *val;      
                                                        val=valoareId(EvalVerificare);
                                                        printf("Eval (%s) este : %s\n",EvalVerificare,val);                                         
                                                    }
        
                                                
                                                
        
                                            }
#line 2601 "y.tab.c"
    break;

  case 92: /* declaratie_main: TYPEOF '(' expresie ')' ';'  */
#line 927 "tema.y"
                                              {   char type[256];
                                                                                if(strcmp((yyvsp[-2].strVal),"string")==0)
                                                                                    strcpy(type,"string");
                                                                                else if(strcmp((yyvsp[-2].strVal),"char")==0)
                                                                                    strcpy(type,"char");
                                                                                else
                                                                            {
                                                                                int tipNr;
                                                                                tipNr = verificareTipInt((yyvsp[-2].strVal));
                                                                                if(tipNr==0)
                                                                                    strcpy(type,"float");
                                                                                else if(tipNr==1)
                                                                                    strcpy(type,"int");
                                                                            }
                                                                                printf("TypeOf la linia %d = %s\n",yylineno,type);
                                                                                }
#line 2622 "y.tab.c"
    break;

  case 93: /* declaratie_main: TYPEOF '(' STRING ')' ';'  */
#line 943 "tema.y"
                                            {printf("TypeOf la linia %d = string\n",yylineno);}
#line 2628 "y.tab.c"
    break;

  case 94: /* declaratie_main: TYPEOF '(' BOOL ')' ';'  */
#line 944 "tema.y"
                                          {printf("TypeOf la linia %d = bool\n",yylineno);}
#line 2634 "y.tab.c"
    break;

  case 95: /* declaratie_main: TYPEOF '(' CHAR ')' ';'  */
#line 945 "tema.y"
                                          {printf("TypeOf la linia %d = char\n",yylineno);}
#line 2640 "y.tab.c"
    break;

  case 96: /* declaratie_main: ID ID ';'  */
#line 946 "tema.y"
                                                            {
                                                                 if(verificaClasa((yyvsp[-2].strVal)) == 1)
                                                                 {
                                                                      if(verificareExistenta((yyvsp[-1].strVal), "main") == 0)
                                                                      {
                                                                           declarareId((yyvsp[-2].strVal), (yyvsp[-1].strVal), "main", 0,0);
                                                                      }
                                                                      else
                                                                      {
                                                                           printf("[Linia %d] Numele acestei variabile este deja folosit in program!\n",yylineno);
                                                                           exit(1);
                                                                      }
                                                                 }
                                                                 else
                                                                 {
                                                                     printf("[Linia %d] Nu exista o clasa cu acest nume: %s\n",yylineno, (yyvsp[-2].strVal));exit(1);
                                                                 }
                                                            }
#line 2663 "y.tab.c"
    break;

  case 97: /* declaratie_main: TIP ID '[' INT ']' ASSIGN '{' elemente_vector '}' ';'  */
#line 964 "tema.y"
                                                                        {declara_vector((yyvsp[-8].strVal),(yyvsp[-9].strVal),(yyvsp[-6].intVal),lista_elemente_vector,"main",0,1); lista_elemente_vector[0]='\0';}
#line 2669 "y.tab.c"
    break;

  case 98: /* declaratie_main: TIP ID '[' INT ']' '[' INT ']' ASSIGN '{' matrice '}' ';'  */
#line 965 "tema.y"
                                                                             {declara_matrice((yyvsp[-11].strVal),(yyvsp[-12].strVal),(yyvsp[-9].intVal),(yyvsp[-6].intVal),lista_elemente_matrice,"main",0,2); linii=0;lista_elemente_matrice[0]='\0';}
#line 2675 "y.tab.c"
    break;

  case 99: /* matrice: '{' elemente_vector '}'  */
#line 967 "tema.y"
                                  {strcpy(lista_elemente_matrice,lista_elemente_vector);strcat(lista_elemente_matrice,itoa(linii)); strcat(lista_elemente_matrice," ");linii++; }
#line 2681 "y.tab.c"
    break;

  case 100: /* matrice: matrice ',' '{' elemente_vector '}'  */
#line 968 "tema.y"
                                              {strcat(lista_elemente_matrice,lista_elemente_vector); strcat(lista_elemente_matrice,itoa(linii));strcat(lista_elemente_matrice," ");linii++; }
#line 2687 "y.tab.c"
    break;

  case 101: /* elemente_vector: elemente_vector ',' INT  */
#line 970 "tema.y"
                                              {strcat(lista_elemente_vector,"int");strcat(lista_elemente_vector," ");strcat(lista_elemente_vector,itoa((yyvsp[0].intVal)));strcat(lista_elemente_vector," ");}
#line 2693 "y.tab.c"
    break;

  case 102: /* elemente_vector: INT  */
#line 971 "tema.y"
                                              {strcpy(lista_elemente_vector,"int");strcat(lista_elemente_vector," ");strcat(lista_elemente_vector,itoa((yyvsp[0].intVal)));strcat(lista_elemente_vector," ");}
#line 2699 "y.tab.c"
    break;

  case 103: /* elemente_vector: elemente_vector ',' FLOAT  */
#line 972 "tema.y"
                                              {strcat(lista_elemente_vector,"float");strcat(lista_elemente_vector," ");strcat(lista_elemente_vector,ftoa((yyvsp[0].floatVal)));strcat(lista_elemente_vector," ");}
#line 2705 "y.tab.c"
    break;

  case 104: /* elemente_vector: FLOAT  */
#line 973 "tema.y"
                                              {strcpy(lista_elemente_vector,"float");strcat(lista_elemente_vector," ");strcat(lista_elemente_vector,ftoa((yyvsp[0].floatVal)));strcat(lista_elemente_vector," ");}
#line 2711 "y.tab.c"
    break;

  case 105: /* elemente_vector: elemente_vector ',' CHAR  */
#line 974 "tema.y"
                                              {strcat(lista_elemente_vector,"char");strcat(lista_elemente_vector," ");strcat(lista_elemente_vector,ctoa((yyvsp[0].charVal)));strcat(lista_elemente_vector," ");}
#line 2717 "y.tab.c"
    break;

  case 106: /* elemente_vector: CHAR  */
#line 975 "tema.y"
                                              {strcpy(lista_elemente_vector,"char");strcat(lista_elemente_vector," ");strcat(lista_elemente_vector,ctoa((yyvsp[0].charVal)));strcat(lista_elemente_vector," ");}
#line 2723 "y.tab.c"
    break;

  case 107: /* elemente_vector: elemente_vector ',' STRING  */
#line 976 "tema.y"
                                              {strcat(lista_elemente_vector,"string");strcat(lista_elemente_vector," ");strcat(lista_elemente_vector,(yyvsp[0].strVal));strcat(lista_elemente_vector," ");}
#line 2729 "y.tab.c"
    break;

  case 108: /* elemente_vector: STRING  */
#line 977 "tema.y"
                                              {strcpy(lista_elemente_vector,"string");strcat(lista_elemente_vector," ");strcat(lista_elemente_vector,(yyvsp[0].strVal));strcat(lista_elemente_vector," ");}
#line 2735 "y.tab.c"
    break;

  case 109: /* elemente_vector: elemente_vector ',' ID  */
#line 978 "tema.y"
                                              {strcat(lista_elemente_vector,tipId((yyvsp[0].strVal)));strcat(lista_elemente_vector," ");strcat(lista_elemente_vector,valoareId((yyvsp[0].strVal)));strcat(lista_elemente_vector," ");}
#line 2741 "y.tab.c"
    break;

  case 110: /* elemente_vector: ID  */
#line 979 "tema.y"
                                              {strcpy(lista_elemente_vector,tipId((yyvsp[0].strVal)));strcat(lista_elemente_vector," ");strcat(lista_elemente_vector,valoareId((yyvsp[0].strVal)));strcat(lista_elemente_vector," ");}
#line 2747 "y.tab.c"
    break;

  case 111: /* atribuire: ID ASSIGN expresie ';'  */
#line 982 "tema.y"
                                   {                                  if(getScope((yyvsp[-3].strVal))!=-1)
                                                                      {
                                                                      if(isBoolExpression == 1)
                                                                      {
                                                                           isBoolExpression = 0;
                                                                           if(checkAssign(verificareTip((yyvsp[-3].strVal),"main"),"bool")==1)
                                                                           {
                                                                                asignare((yyvsp[-3].strVal), (yyvsp[-1].strVal), "main");
                                                                           }
                                                                           else
                                                                           {
                                                                                printf("[Linia %d] Nu pot exista atribuiri intre tipuri de date diferite.\n", yylineno);
                                                                                exit(1);
                                                                           }
                                                                      }
                                                                      else{
                                                                      int tip1 = verificareTipIntId((yyvsp[-3].strVal),getScope((yyvsp[-3].strVal)));
                                                                      int tip2 = verificareTipInt((yyvsp[-1].strVal));
                                                                      if (tip1 != tip2) {
                                                                      printf("[Linia %d] Nu pot exista atribuiri intre tipuri de date diferite.\n", yylineno);
                                                                      exit(1);
                                                                      }
                                                                      else
                                                                      {    if(getScope((yyvsp[-3].strVal)) == 0)
                                                                           asignare((yyvsp[-3].strVal),(yyvsp[-1].strVal),"global");
                                                                           else if(getScope((yyvsp[-3].strVal)) == 1)
                                                                           asignare((yyvsp[-3].strVal),(yyvsp[-1].strVal),"main");
                                                                      }
                                                                      }
                                                                      }
                                                                      else 
                                                                      {
                                                                           printf("[Linia %d] Variabila nu a fost declarata.\n",yylineno); exit(1);
                                                                      } 
                                   }
#line 2787 "y.tab.c"
    break;

  case 112: /* atribuire: ID ASSIGN expresie  */
#line 1017 "tema.y"
                               {printf("[Linia %d] Lipseste ';' de la finalul expresiei\n",yylineno);exit(1);}
#line 2793 "y.tab.c"
    break;

  case 113: /* atribuire: ID ASSIGN STRING ';'  */
#line 1018 "tema.y"
                                {if(verificareExistenta((yyvsp[-3].strVal),"main") == 1) 
                                    {if(checkAssign(verificareTip((yyvsp[-3].strVal),"main"),"string")==1) //daca imi gaseste variabila declarata in main
                                        asignare((yyvsp[-3].strVal),(yyvsp[-1].strVal),"main");
                                        else
                                        {
                                             printf("[Linia %d] Nu pot exista asignari intre tipuri de date diferite.\n",yylineno); exit(1);
                                        }
                                    }
                                    else if(verificareExistenta((yyvsp[-3].strVal),"main") == 2) 
                                   {
                                        if(checkAssign(verificareTip((yyvsp[-3].strVal),"global"),"string")==1) //daca imi gaseste variabila declarata global
                                             asignare((yyvsp[-3].strVal),(yyvsp[-1].strVal),"global");
                                        else
                                        {
                                             printf("[Linia %d] Nu pot exista asignari intre tipuri de date diferite.\n",yylineno); exit(1);
                                        }
                                   } 
                                   else
                                   {
                                        printf("[Linia %d] Variabila careia incercati sa-i atribuiti o valoare nu a fost declarata.\n",yylineno);exit(1);
                                   }
                                   }
#line 2820 "y.tab.c"
    break;

  case 114: /* atribuire: ID ASSIGN CHAR ';'  */
#line 1040 "tema.y"
                              {if(verificareExistenta((yyvsp[-3].strVal),"main") == 1) 
                                    {if(checkAssign(verificareTip((yyvsp[-3].strVal),"main"),"char")==1) //daca imi gaseste variabila declarata in main
                                        asignare((yyvsp[-3].strVal),ctoa((yyvsp[-1].charVal)),"main");
                                        else
                                        {
                                             printf("[Linia %d] Nu pot exista asignari intre tipuri de date diferite.\n",yylineno); exit(1);
                                        }
                                    }
                                    else if(verificareExistenta((yyvsp[-3].strVal),"main") == 2) 
                                   {
                                        if(checkAssign(verificareTip((yyvsp[-3].strVal),"global"),"char")==1) //daca imi gaseste variabila declarata global
                                             asignare((yyvsp[-3].strVal),ctoa((yyvsp[-1].charVal)),"global");
                                        else
                                        {
                                             printf("[Linia %d] Nu pot exista asignari intre tipuri de date diferite.\n",yylineno); exit(1);
                                        }
                                   } 
                                   else
                                   {
                                        printf("[Linia %d] Variabila careia incercati sa-i atribuiti o valoare nu a fost declarata.\n",yylineno);exit(1);
                                   }
                                   }
#line 2847 "y.tab.c"
    break;

  case 115: /* atribuire: ID ASSIGN BOOL ';'  */
#line 1062 "tema.y"
                              {if(verificareExistenta((yyvsp[-3].strVal),"main") == 1) 
                                    {if(checkAssign(verificareTip((yyvsp[-3].strVal),"main"),"bool") == 1) //daca imi gaseste variabila declarata in main
                                        asignare((yyvsp[-3].strVal),itoa((yyvsp[-1].boolVal)),"main");
                                        else
                                        {
                                             printf("[Linia %d] Nu pot exista asignari intre tipuri de date diferite.\n",yylineno); exit(1);
                                        }
                                    }
                                    else if(verificareExistenta((yyvsp[-3].strVal),"main") == 2) 
                                   {
                                        if(checkAssign(verificareTip((yyvsp[-3].strVal),"global"),"bool")==1)
                                        {
                                             //daca imi gaseste variabila declarata global
                                             printf("itoa drc: %s\n", itoa((yyvsp[-1].boolVal)));
                                             asignare((yyvsp[-3].strVal),itoa((yyvsp[-1].boolVal)),"global");
                                        } 
                                        else
                                        {
                                             printf("[Linia %d] Nu pot exista asignari intre tipuri de date diferite.\n",yylineno); exit(1);
                                        }
                                   } 
                                   else
                                   {
                                        printf("[Linia %d] Variabila careia incercati sa-i atribuiti o valoare nu a fost declarata.\n",yylineno);exit(1);
                                   }
                                   }
#line 2878 "y.tab.c"
    break;

  case 116: /* atribuire: ID DOT apel_functie  */
#line 1088 "tema.y"
                                             {
                                                  
                                                  if(verificareExistenta((yyvsp[-2].strVal),"main") == 1) 
                                                  {
                                                       if(isInClass(functieId) == 0)
                                                       {
                                                            printf("[Linia %d] Functia pe care incercati sa o accesati nu face parte din clasa.\n",yylineno);
                                                       }

                                                  }
                                                  else
                                                  {
                                                       printf("[Linia %d] Variabila %s nu a fost declarata.\n",yylineno, (yyvsp[-2].strVal));
                                                  }

                                             }
#line 2899 "y.tab.c"
    break;

  case 117: /* expresie: expresie_matematica  */
#line 1108 "tema.y"
                               {(yyval.strVal)=(yyvsp[0].strVal);}
#line 2905 "y.tab.c"
    break;

  case 118: /* expresie: expresie_bool  */
#line 1109 "tema.y"
                         {isBoolExpression = 1; (yyval.strVal)=(yyvsp[0].strVal);}
#line 2911 "y.tab.c"
    break;

  case 119: /* expresie_matematica: expresie_matematica ADD expresie_matematica  */
#line 1112 "tema.y"
                                                                   {
                                                                      int tip1 = verificareTipInt((yyvsp[-2].strVal));
                                                                      int tip2 = verificareTipInt((yyvsp[0].strVal));
                                                                      
                                                                      if (tip1 != tip2) {
                                                                      printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                                                      exit(1);
                                                                      }
                                                                      if (tip1 == 1) { //dacă ambele valori sunt întregi, efectuăm operația întreagă
                                                                           sprintf((yyvsp[-2].strVal), "%d", atoi((yyvsp[-2].strVal)) + atoi((yyvsp[0].strVal)));
                                                                           (yyval.strVal) = (yyvsp[-2].strVal);
                                                                      }
                                                                      else if (tip1 == 0) { //dacă ambele valori sunt zecimale, efectuăm operația zecimală
                                                                           sprintf((yyvsp[-2].strVal), "%f", atof((yyvsp[-2].strVal)) + atof((yyvsp[0].strVal)));
                                                                           (yyval.strVal) = (yyvsp[-2].strVal);
                                                                      }
                                                                      else if(strcmp((yyvsp[-2].strVal),(yyvsp[0].strVal))!=0)
                                                                      {
                                                                           printf("[Linia %d] Eroare semantica, nu pot exista operatii intre tipuri de caractere diferite!\n",yylineno);
                                                                           exit(1);
                                                                      }
                                                                   
                                                                 }
#line 2939 "y.tab.c"
    break;

  case 120: /* expresie_matematica: expresie_matematica SUB expresie_matematica  */
#line 1135 "tema.y"
                                                                   {
                                                                      int tip1 = verificareTipInt((yyvsp[-2].strVal));
                                                                      int tip2 = verificareTipInt((yyvsp[0].strVal));
                                                                      if (tip1 != tip2) {
                                                                           printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                                                           exit(1);
                                                                      }
                                                                      if (tip1 == 1) { //dacă ambele valori sunt întregi, efectuăm operația întreagă
                                                                           sprintf((yyvsp[-2].strVal), "%d", atoi((yyvsp[-2].strVal)) - atoi((yyvsp[0].strVal)));
                                                                           (yyval.strVal) = (yyvsp[-2].strVal);
                                                                      }
                                                                      if (tip1 == 0) { //dacă ambele valori sunt zecimale, efectuăm operația zecimală
                                                                           sprintf((yyvsp[-2].strVal), "%f", atof((yyvsp[-2].strVal)) - atof((yyvsp[0].strVal)));
                                                                           (yyval.strVal) = (yyvsp[-2].strVal);
                                                                      }
                                                                    }
#line 2960 "y.tab.c"
    break;

  case 121: /* expresie_matematica: expresie_matematica MULT expresie_matematica  */
#line 1151 "tema.y"
                                                                   {
                                                                      int tip1 = verificareTipInt((yyvsp[-2].strVal));
                                                                      int tip2 = verificareTipInt((yyvsp[0].strVal));
                                                                      if (tip1 != tip2) {
                                                                           printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                                                           exit(1);
                                                                      }
                                                                      if (tip1 == 1) { //dacă ambele valori sunt întregi, efectuăm operația întreagă
                                                                           sprintf((yyvsp[-2].strVal), "%d", atoi((yyvsp[-2].strVal)) * atoi((yyvsp[0].strVal)));
                                                                           (yyval.strVal) = (yyvsp[-2].strVal);
                                                                      }
                                                                      if (tip1 == 0) { //dacă ambele valori sunt zecimale, efectuăm operația zecimală
                                                                           sprintf((yyvsp[-2].strVal), "%f", atof((yyvsp[-2].strVal)) * atof((yyvsp[0].strVal)));
                                                                           (yyval.strVal) = (yyvsp[-2].strVal);
                                                                      }
                                                                   }
#line 2981 "y.tab.c"
    break;

  case 122: /* expresie_matematica: expresie_matematica DIV expresie_matematica  */
#line 1167 "tema.y"
                                                                  {
                                                                      int tip1 = verificareTipInt((yyvsp[-2].strVal));
                                                                      int tip2 = verificareTipInt((yyvsp[0].strVal));
                                                                      if (tip1 != tip2) {
                                                                           printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                                                           exit(1);
                                                                      }
                                                                      if (tip1 == 1) { //dacă ambele valori sunt întregi, efectuăm operația întreagă
                                                                           if (atoi((yyvsp[0].strVal)) == 0) { //verificăm dacă divizorul este diferit de 0
                                                                                printf("[Linia %d] Impartire la 0.\n", yylineno);
                                                                                exit(1);
                                                                           }
                                                                           sprintf((yyvsp[-2].strVal), "%d", atoi((yyvsp[-2].strVal)) / atoi((yyvsp[0].strVal)));
                                                                           (yyval.strVal) = (yyvsp[-2].strVal);
                                                                      }
                                                                      if (tip1 == 0) { //dacă ambele valori sunt zecimale, efectuăm operația zecimală
                                                                           if (atof((yyvsp[0].strVal)) == 0.0) { //verificăm dacă divizorul este diferit de 0.0
                                                                                printf("[Linia %d] Impartire la 0.\n", yylineno);
                                                                                exit(1);
                                                                           }
                                                                           sprintf((yyvsp[-2].strVal), "%f", atof((yyvsp[-2].strVal)) / atof((yyvsp[0].strVal)));
                                                                           (yyval.strVal) = (yyvsp[-2].strVal);
                                                                      }
                                                                   }
#line 3010 "y.tab.c"
    break;

  case 123: /* expresie_matematica: '(' expresie_matematica ')'  */
#line 1193 "tema.y"
                                                  {(yyval.strVal) = (yyvsp[-1].strVal);}
#line 3016 "y.tab.c"
    break;

  case 124: /* expresie_matematica: NUMAR_INT  */
#line 1194 "tema.y"
                                {(yyval.strVal) = (yyvsp[0].strVal);}
#line 3022 "y.tab.c"
    break;

  case 125: /* expresie_matematica: NUMAR_FLOAT  */
#line 1195 "tema.y"
                                  {(yyval.strVal) = (yyvsp[0].strVal);}
#line 3028 "y.tab.c"
    break;

  case 126: /* expresie_matematica: ID  */
#line 1196 "tema.y"
                         {
                         
                         if (verificareExistenta((yyvsp[0].strVal), "main") == 1 ){
                         if(isVector((yyvsp[0].strVal))==1)
                              {printf("[Linia %d] Utilizarea gresita a unui vector, formatul este id[size]!\n",yylineno);exit(1);}
                         if(isVector((yyvsp[0].strVal))==2)
                              {printf("[Linia %d] Utilizarea gresita a unei matrici, formatul este id[size][size]!\n",yylineno);exit(1);}
                         char* returnVal;
                         returnVal = returnValue((yyvsp[0].strVal),"main",0,0);
                         
                         strcpy(valoareStringChar,returnValStringChar((yyvsp[0].strVal)));
                    
                         strcpy((yyval.strVal),returnVal);
                         } 
                         else if(verificareExistenta((yyvsp[0].strVal), "main") == 2 )
                         {
                            char* returnVal;
                              returnVal = returnValue((yyvsp[0].strVal),"global",0,0);
                              strcpy(valoareStringChar,returnValStringChar((yyvsp[0].strVal)));  
                              strcpy((yyval.strVal),returnVal);  
                         }
                         else {printf("[Linia %d]Variabila %s nu a fost declarata\n",yylineno,(yyvsp[0].strVal));exit(1);}}
#line 3055 "y.tab.c"
    break;

  case 127: /* expresie_matematica: ID '[' INT ']'  */
#line 1218 "tema.y"
                                     {if (verificareExistenta((yyvsp[-3].strVal), "main") == 1 ){

                         if(isVector((yyvsp[-3].strVal))==0)
                              {printf("[Linia %d] Aceasta variabila nu este un vector!\n",yylineno);exit(1);}
                         if(isVector((yyvsp[-3].strVal))==2)
                              {printf("[Linia %d] Utilizarea gresita a unei matrici, formatul este id[size][size]!\n",yylineno);exit(1);}
                         char* returnVal;
                         returnVal = returnValue((yyvsp[-3].strVal),"main",(yyvsp[-1].intVal),0);
                         strcpy((yyval.strVal),returnVal);} 
                         else if(verificareExistenta((yyvsp[-3].strVal), "main") == 2 ){
                            char* returnVal;
                         returnVal = returnValue((yyvsp[-3].strVal),"global",(yyvsp[-1].intVal),0);
                         strcpy((yyval.strVal),returnVal);  
                         }
                         else {printf("[Linia %d]Vectorul %s nu a fost declarata\n",yylineno,(yyvsp[-3].strVal));exit(1);}}
#line 3075 "y.tab.c"
    break;

  case 128: /* expresie_matematica: ID '[' INT ']' '[' INT ']'  */
#line 1233 "tema.y"
                                                 {if (verificareExistenta((yyvsp[-6].strVal), "main") == 1 ){
                         if(isVector((yyvsp[-6].strVal))==0)
                              {printf("[Linia %d] Aceasta variabila nu este o matrice!\n",yylineno);exit(1);}
                         if(isVector((yyvsp[-6].strVal))==1)
                              {printf("[Linia %d] Utilizarea gresita a unui vector, formatul este id[size]!\n",yylineno);exit(1);}
                         char* returnVal;
                         returnVal = returnValue((yyvsp[-6].strVal),"main",(yyvsp[-4].intVal),(yyvsp[-1].intVal));
                         strcpy((yyval.strVal),returnVal);} 
                         else if(verificareExistenta((yyvsp[-6].strVal), "main") == 2 ){
                            char* returnVal;
                         returnVal = returnValue((yyvsp[-6].strVal),"global",(yyvsp[-4].intVal),(yyvsp[-1].intVal));
                         strcpy((yyval.strVal),returnVal);  
                         }
                         else {printf("[Linia %d]Vectorul %s nu a fost declarata\n",yylineno,(yyvsp[-6].strVal));exit(1);}}
#line 3094 "y.tab.c"
    break;

  case 129: /* expresie_matematica: apel_functie_expr  */
#line 1247 "tema.y"
                                         {
                                          if(getTipFunctie((yyvsp[0].strVal))==1)strcpy((yyval.strVal),"0.0");
                                          else if(getTipFunctie((yyvsp[0].strVal))==2)strcpy((yyval.strVal),"0");
                                          else if(getTipFunctie((yyvsp[0].strVal))==3)strcpy((yyval.strVal),"char");
                                          else if(getTipFunctie((yyvsp[0].strVal))==4)strcpy((yyval.strVal),"string");
                                         }
#line 3105 "y.tab.c"
    break;

  case 130: /* NUMAR_INT: INT  */
#line 1258 "tema.y"
                {(yyval.strVal)=itoa((yyvsp[0].intVal));}
#line 3111 "y.tab.c"
    break;

  case 131: /* NUMAR_FLOAT: FLOAT  */
#line 1260 "tema.y"
                    {(yyval.strVal)=ftoa((yyvsp[0].floatVal));}
#line 3117 "y.tab.c"
    break;

  case 132: /* expresie_bool: expresie GT expresie  */
#line 1266 "tema.y"
                                      { 
                                        int tip1 = verificareTipInt((yyvsp[-2].strVal));
                                        int tip2 = verificareTipInt((yyvsp[0].strVal));
                                        if (tip1 != tip2) {
                                              printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                              exit(1);
                                                          }
                                        if(tip1 == 1)
                                        {(yyval.strVal)= itoa(atoi((yyvsp[-2].strVal)) > atoi((yyvsp[0].strVal)));}
                                        else if(tip1 == 0)
                                        {(yyval.strVal)= ftoa(atof((yyvsp[-2].strVal)) > atof((yyvsp[0].strVal)));}
                                       }
#line 3134 "y.tab.c"
    break;

  case 133: /* expresie_bool: expresie LT expresie  */
#line 1278 "tema.y"
                                      { 
                                        int tip1 = verificareTipInt((yyvsp[-2].strVal));
                                        int tip2 = verificareTipInt((yyvsp[0].strVal));
                                        if (tip1 != tip2) {
                                              printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                              exit(1);
                                                          }
                                        if(tip1 == 1)
                                        {(yyval.strVal)= itoa(atoi((yyvsp[-2].strVal)) < atoi((yyvsp[0].strVal)));}
                                        else if(tip1 == 0)
                                        {(yyval.strVal)= ftoa(atof((yyvsp[-2].strVal)) < atof((yyvsp[0].strVal)));}
                                       }
#line 3151 "y.tab.c"
    break;

  case 134: /* expresie_bool: expresie EQQ expresie  */
#line 1290 "tema.y"
                                      { 
                                        int tip1 = verificareTipInt((yyvsp[-2].strVal));
                                        int tip2 = verificareTipInt((yyvsp[0].strVal));
                                        if (tip1 != tip2) {
                                              printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                              exit(1);
                                                          }
                                        if(tip1 == 1)
                                        {(yyval.strVal)= itoa(atoi((yyvsp[-2].strVal)) == atoi((yyvsp[0].strVal)));}
                                        else if(tip1 == 0)
                                        {(yyval.strVal)= ftoa(atof((yyvsp[-2].strVal)) == atof((yyvsp[0].strVal)));}
                                       }
#line 3168 "y.tab.c"
    break;

  case 135: /* expresie_bool: expresie NEQ expresie  */
#line 1302 "tema.y"
                                      { 
                                        int tip1 = verificareTipInt((yyvsp[-2].strVal));
                                        int tip2 = verificareTipInt((yyvsp[0].strVal));
                                        if (tip1 != tip2) {
                                              printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                              exit(1);
                                                          }
                                        if(tip1 == 1)
                                        {(yyval.strVal)= itoa(atoi((yyvsp[-2].strVal)) != atoi((yyvsp[0].strVal)));}
                                        else if(tip1 == 0)
                                        {(yyval.strVal)= ftoa(atof((yyvsp[-2].strVal)) != atof((yyvsp[0].strVal)));}
                                       }
#line 3185 "y.tab.c"
    break;

  case 136: /* expresie_bool: expresie GEQ expresie  */
#line 1314 "tema.y"
                                      { 
                                        int tip1 = verificareTipInt((yyvsp[-2].strVal));
                                        int tip2 = verificareTipInt((yyvsp[0].strVal));
                                        if (tip1 != tip2) {
                                              printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                              exit(1);
                                                          }
                                        if(tip1 == 1)
                                        {(yyval.strVal)= itoa(atoi((yyvsp[-2].strVal)) >= atoi((yyvsp[0].strVal)));}
                                        else if(tip1 == 0)
                                        {(yyval.strVal)= ftoa(atof((yyvsp[-2].strVal)) >= atof((yyvsp[0].strVal)));}
                                       }
#line 3202 "y.tab.c"
    break;

  case 137: /* expresie_bool: expresie LEQ expresie  */
#line 1326 "tema.y"
                                      { 
                                        int tip1 = verificareTipInt((yyvsp[-2].strVal));
                                        int tip2 = verificareTipInt((yyvsp[0].strVal));
                                        if (tip1 != tip2) {
                                              printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                              exit(1);
                                                          }
                                        if(tip1 == 1)
                                        {(yyval.strVal)= itoa(atoi((yyvsp[-2].strVal))  <= atoi((yyvsp[0].strVal)));}
                                        else if(tip1 == 0)
                                        {(yyval.strVal)= ftoa(atof((yyvsp[-2].strVal)) <= atof((yyvsp[0].strVal)));}
                                       }
#line 3219 "y.tab.c"
    break;

  case 138: /* expresie_bool: '(' expresie_bool ')'  */
#line 1338 "tema.y"
                                      {(yyval.strVal)=(yyvsp[-1].strVal);}
#line 3225 "y.tab.c"
    break;

  case 139: /* expresie_bool: '(' expresie_bool_exclusiv ')'  */
#line 1339 "tema.y"
                                               {(yyval.strVal)=(yyvsp[-1].strVal);}
#line 3231 "y.tab.c"
    break;

  case 140: /* expresie_bool_exclusiv: expresie_bool AND expresie_bool  */
#line 1341 "tema.y"
                                                         { 
                                        int tip1 = verificareTipInt((yyvsp[-2].strVal));
                                        int tip2 = verificareTipInt((yyvsp[0].strVal));
                                        if (tip1 != tip2) {
                                              printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                              exit(1);
                                                          }
                                        if(tip1 == 1)
                                        {(yyval.strVal)= itoa(atoi((yyvsp[-2].strVal)) && atoi((yyvsp[0].strVal)));}
                                        else if(tip1 == 0)
                                        {(yyval.strVal)= ftoa(atof((yyvsp[-2].strVal)) && atof((yyvsp[0].strVal)));}
                                       }
#line 3248 "y.tab.c"
    break;

  case 141: /* expresie_bool_exclusiv: expresie_bool OR expresie_bool  */
#line 1353 "tema.y"
                                                         { 
                                        int tip1 = verificareTipInt((yyvsp[-2].strVal));
                                        int tip2 = verificareTipInt((yyvsp[0].strVal));
                                        if (tip1 != tip2) {
                                              printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                              exit(1);
                                                          }
                                        if(tip1 == 1)
                                        {(yyval.strVal)= itoa(atoi((yyvsp[-2].strVal)) || atoi((yyvsp[0].strVal)));}
                                        else if(tip1 == 0)
                                        {(yyval.strVal)= ftoa(atof((yyvsp[-2].strVal)) || atof((yyvsp[0].strVal)));}
                                       }
#line 3265 "y.tab.c"
    break;

  case 142: /* expresie_bool_exclusiv: expresie_bool_exclusiv AND expresie_bool_exclusiv  */
#line 1365 "tema.y"
                                                                            { 
                                        int tip1 = verificareTipInt((yyvsp[-2].strVal));
                                        int tip2 = verificareTipInt((yyvsp[0].strVal));
                                        if (tip1 != tip2) {
                                              printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                              exit(1);
                                                          }
                                        if(tip1 == 1)
                                        {(yyval.strVal)= itoa(atoi((yyvsp[-2].strVal)) && atoi((yyvsp[0].strVal)));}
                                        else if(tip1 == 0)
                                        {(yyval.strVal)= ftoa(atof((yyvsp[-2].strVal)) && atof((yyvsp[0].strVal)));}
                                       }
#line 3282 "y.tab.c"
    break;

  case 143: /* expresie_bool_exclusiv: expresie_bool_exclusiv OR expresie_bool_exclusiv  */
#line 1377 "tema.y"
                                                                          { 
                                        int tip1 = verificareTipInt((yyvsp[-2].strVal));
                                        int tip2 = verificareTipInt((yyvsp[0].strVal));
                                        if (tip1 != tip2) {
                                              printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                              exit(1);
                                                          }
                                        if(tip1 == 1)
                                        {(yyval.strVal)= itoa(atoi((yyvsp[-2].strVal)) || atoi((yyvsp[0].strVal)));}
                                        else if(tip1 == 0)
                                        {(yyval.strVal)= ftoa(atof((yyvsp[-2].strVal)) || atof((yyvsp[0].strVal)));}
                                       }
#line 3299 "y.tab.c"
    break;

  case 144: /* expresie_bool_exclusiv: expresie_bool_exclusiv OR expresie_bool  */
#line 1389 "tema.y"
                                                                { 
                                        int tip1 = verificareTipInt((yyvsp[-2].strVal));
                                        int tip2 = verificareTipInt((yyvsp[0].strVal));
                                        if (tip1 != tip2) {
                                              printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                              exit(1);
                                                          }
                                        if(tip1 == 1)
                                        {(yyval.strVal)= itoa(atoi((yyvsp[-2].strVal)) || atoi((yyvsp[0].strVal)));}
                                        else if(tip1 == 0)
                                        {(yyval.strVal)= ftoa(atof((yyvsp[-2].strVal)) || atof((yyvsp[0].strVal)));}
                                       }
#line 3316 "y.tab.c"
    break;

  case 145: /* expresie_bool_exclusiv: expresie_bool_exclusiv AND expresie_bool  */
#line 1402 "tema.y"
                                                                 { 
                                        int tip1 = verificareTipInt((yyvsp[-2].strVal));
                                        int tip2 = verificareTipInt((yyvsp[0].strVal));
                                        if (tip1 != tip2) {
                                              printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                              exit(1);
                                                          }
                                       if(tip1 == 1)
                                        {(yyval.strVal)= itoa(atoi((yyvsp[-2].strVal)) && atoi((yyvsp[0].strVal)));}
                                        else if(tip1 == 0)
                                        {(yyval.strVal)= ftoa(atof((yyvsp[-2].strVal)) && atof((yyvsp[0].strVal)));}
                                       }
#line 3333 "y.tab.c"
    break;

  case 146: /* expresie_bool_exclusiv: expresie_bool OR expresie_bool_exclusiv  */
#line 1414 "tema.y"
                                                                { 
                                        int tip1 = verificareTipInt((yyvsp[-2].strVal));
                                        int tip2 = verificareTipInt((yyvsp[0].strVal));
                                        if (tip1 != tip2) {
                                              printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                              exit(1);
                                                          }
                                        if(tip1 == 1)
                                        {(yyval.strVal)= itoa(atoi((yyvsp[-2].strVal)) || atoi((yyvsp[0].strVal)));}
                                        else if(tip1 == 0)
                                        {(yyval.strVal)= ftoa(atof((yyvsp[-2].strVal)) || atof((yyvsp[0].strVal)));}
                                       }
#line 3350 "y.tab.c"
    break;

  case 147: /* expresie_bool_exclusiv: expresie_bool AND expresie_bool_exclusiv  */
#line 1426 "tema.y"
                                                                 { 
                                        int tip1 = verificareTipInt((yyvsp[-2].strVal));
                                        int tip2 = verificareTipInt((yyvsp[0].strVal));
                                        if (tip1 != tip2) {
                                              printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                              exit(1);
                                                          }
                                        if(tip1 == 1)
                                        {(yyval.strVal)= itoa(atoi((yyvsp[-2].strVal)) && atoi((yyvsp[0].strVal)));}
                                        else if(tip1 == 0)
                                        {(yyval.strVal)= ftoa(atof((yyvsp[-2].strVal)) && atof((yyvsp[0].strVal)));}
                                       }
#line 3367 "y.tab.c"
    break;

  case 157: /* $@1: %empty  */
#line 1454 "tema.y"
                                                                                                             {
                                                       if(verificareExistenta((yyvsp[-9].strVal),"main") == 0)
                                                            {printf("[Linia %d] Variabila %s din for nu a fost declarata.\n",yylineno,(yyvsp[-9].strVal));exit(1);}
                                                       }
#line 3376 "y.tab.c"
    break;


#line 3380 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1461 "tema.y"

int erori=0;
int yyerror(char * s){
     erori++;
     printf("eroare: %s la linia:%d\n",s,yylineno);
}
int main(int argc, char** argv){
     yyin=fopen(argv[1],"r");
     yyparse();
     if(erori==0)
     {
          printf("Programul este corect sintatic!\n\n");
          afisare();
          afisare_functii();
          //afisare_vector();
          //afisare_matrice();
 
     }
     else
     {printf("Programul nu este corect sintatic!\n\n");}
     
     
}
