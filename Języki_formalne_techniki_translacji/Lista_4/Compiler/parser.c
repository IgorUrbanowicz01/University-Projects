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
#line 2 "parser.bison"

#include <stdio.h>
#include "decl.h"
#include "stmt.h"
#include "expr.h"
//#include "param_list.h"
#include "type.h"
#include <stdlib.h>
#include <string.h>

//#define YYSTYPE struct decl *

extern char *yytext;
extern int last_int_literal;
extern int yylex();
extern int yyerror( char *str );
//extern char *clean_string(char *string, char delim);
struct decl *ast;


#line 92 "parser.c"

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

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PROCEDURE = 3,                  /* PROCEDURE  */
  YYSYMBOL_IS = 4,                         /* IS  */
  YYSYMBOL_VAR = 5,                        /* VAR  */
  YYSYMBOL_X_BEGIN = 6,                    /* X_BEGIN  */
  YYSYMBOL_END = 7,                        /* END  */
  YYSYMBOL_PROGRAM = 8,                    /* PROGRAM  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_THEN = 10,                      /* THEN  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_ENDIF = 12,                     /* ENDIF  */
  YYSYMBOL_WHILE = 13,                     /* WHILE  */
  YYSYMBOL_DO = 14,                        /* DO  */
  YYSYMBOL_ENDWHILE = 15,                  /* ENDWHILE  */
  YYSYMBOL_REPEAT = 16,                    /* REPEAT  */
  YYSYMBOL_UNTIL = 17,                     /* UNTIL  */
  YYSYMBOL_READ = 18,                      /* READ  */
  YYSYMBOL_WRITE = 19,                     /* WRITE  */
  YYSYMBOL_LPR = 20,                       /* LPR  */
  YYSYMBOL_RPR = 21,                       /* RPR  */
  YYSYMBOL_ASSIGN = 22,                    /* ASSIGN  */
  YYSYMBOL_COMMA = 23,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 24,                 /* SEMICOLON  */
  YYSYMBOL_EQ = 25,                        /* EQ  */
  YYSYMBOL_NEQ = 26,                       /* NEQ  */
  YYSYMBOL_GT = 27,                        /* GT  */
  YYSYMBOL_LT = 28,                        /* LT  */
  YYSYMBOL_LEQ = 29,                       /* LEQ  */
  YYSYMBOL_GEQ = 30,                       /* GEQ  */
  YYSYMBOL_ADD = 31,                       /* ADD  */
  YYSYMBOL_SUB = 32,                       /* SUB  */
  YYSYMBOL_MUL = 33,                       /* MUL  */
  YYSYMBOL_DIV = 34,                       /* DIV  */
  YYSYMBOL_MOD = 35,                       /* MOD  */
  YYSYMBOL_IDENT = 36,                     /* IDENT  */
  YYSYMBOL_INT_LIT = 37,                   /* INT_LIT  */
  YYSYMBOL_SCAN_ERR = 38,                  /* SCAN_ERR  */
  YYSYMBOL_TOKEN_EOF = 39,                 /* TOKEN_EOF  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_program = 41,                   /* program  */
  YYSYMBOL_procedures_decl = 42,           /* procedures_decl  */
  YYSYMBOL_param_comma_list = 43,          /* param_comma_list  */
  YYSYMBOL_decl = 44,                      /* decl  */
  YYSYMBOL_main = 45,                      /* main  */
  YYSYMBOL_stmt = 46,                      /* stmt  */
  YYSYMBOL_if_stmt = 47,                   /* if_stmt  */
  YYSYMBOL_read_stmt = 48,                 /* read_stmt  */
  YYSYMBOL_write_stmt = 49,                /* write_stmt  */
  YYSYMBOL_while_stmt = 50,                /* while_stmt  */
  YYSYMBOL_repeat_stmt = 51,               /* repeat_stmt  */
  YYSYMBOL_maybe_stmts = 52,               /* maybe_stmts  */
  YYSYMBOL_expr = 53,                      /* expr  */
  YYSYMBOL_expr6 = 54,                     /* expr6  */
  YYSYMBOL_expr5 = 55,                     /* expr5  */
  YYSYMBOL_expr4 = 56,                     /* expr4  */
  YYSYMBOL_expr3 = 57,                     /* expr3  */
  YYSYMBOL_expr1 = 58,                     /* expr1  */
  YYSYMBOL_atom = 59,                      /* atom  */
  YYSYMBOL_ident = 60,                     /* ident  */
  YYSYMBOL_func_call = 61,                 /* func_call  */
  YYSYMBOL_expr_commdecla_list = 62        /* expr_commdecla_list  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   91

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  50
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  107

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    79,    79,    84,    86,    89,    92,    94,   101,   103,
     111,   113,   119,   121,   123,   125,   127,   129,   134,   136,
     140,   144,   148,   152,   158,   159,   166,   171,   173,   178,
     180,   182,   184,   186,   188,   190,   195,   197,   199,   204,
     206,   208,   210,   215,   217,   222,   224,   228,   241,   246,
     248
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
  "\"end of file\"", "error", "\"invalid token\"", "PROCEDURE", "IS",
  "VAR", "X_BEGIN", "END", "PROGRAM", "IF", "THEN", "ELSE", "ENDIF",
  "WHILE", "DO", "ENDWHILE", "REPEAT", "UNTIL", "READ", "WRITE", "LPR",
  "RPR", "ASSIGN", "COMMA", "SEMICOLON", "EQ", "NEQ", "GT", "LT", "LEQ",
  "GEQ", "ADD", "SUB", "MUL", "DIV", "MOD", "IDENT", "INT_LIT", "SCAN_ERR",
  "TOKEN_EOF", "$accept", "program", "procedures_decl", "param_comma_list",
  "decl", "main", "stmt", "if_stmt", "read_stmt", "write_stmt",
  "while_stmt", "repeat_stmt", "maybe_stmts", "expr", "expr6", "expr5",
  "expr4", "expr3", "expr1", "atom", "ident", "func_call",
  "expr_commdecla_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-66)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -66,     3,    38,   -66,     6,    35,   -66,   -66,    25,     0,
       6,     6,     7,    26,     6,     1,   -66,    13,    13,     7,
      13,    13,   -66,     7,   -66,   -66,   -66,   -66,   -66,    51,
     -66,   -66,     8,    20,   -16,    49,   -66,   -66,   -66,    64,
     -66,     7,     6,    60,    57,    55,    50,    52,   -66,   -66,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    48,    66,   -66,     7,     7,    13,   -66,
     -66,    53,    20,    20,    20,    20,    20,    20,   -16,   -16,
      49,    49,    49,    56,    54,     6,     7,   -66,    45,    63,
      62,   -66,    13,   -66,     9,    73,     7,   -66,   -66,   -66,
     -66,     7,   -66,    69,    77,   -66,   -66
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     0,     1,     0,     0,     2,    47,     0,     0,
       0,     0,    24,     0,     6,     0,     9,     0,     0,    24,
       0,     0,    46,    24,    13,    14,    15,    16,    17,     0,
      12,    26,    28,    35,    38,    42,    44,    45,    43,     0,
       7,    24,     0,     0,     0,     0,     0,     0,    25,    11,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     8,     0,    24,     0,    20,
      21,     0,    33,    34,    31,    29,    30,    32,    36,    37,
      39,    40,    41,    49,     0,     0,     0,    10,     0,     0,
       0,    27,     0,    48,     0,     0,     0,    19,    22,    23,
      50,    24,     4,     0,     0,    18,     3
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -66,   -66,   -66,    74,     4,   -66,   -65,   -66,   -66,   -66,
     -66,   -66,   -19,    -7,    37,   -66,    11,     2,   -32,   -66,
      -2,   -66,    -1
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,    13,    15,     6,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    84
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      45,    88,     8,     3,    48,    11,    12,    41,    14,    16,
      43,    44,    14,    46,    47,   101,    17,    59,    60,    61,
      18,    95,    64,    19,    42,    20,    21,    80,    81,    82,
      50,   103,    42,    51,    52,    53,    54,    55,    56,     9,
      65,     4,     7,     7,    22,    10,     5,    39,    89,     7,
      22,    57,    58,    85,    86,    83,    96,    97,    49,    78,
      79,    90,    72,    73,    74,    75,    76,    77,    63,    62,
      66,    67,    68,    87,    69,    93,    70,    91,    98,    92,
     102,   105,   104,    16,   106,    83,    99,    71,    40,    94,
       0,   100
};

static const yytype_int8 yycheck[] =
{
      19,    66,     4,     0,    23,     5,     6,     6,    10,    11,
      17,    18,    14,    20,    21,     6,     9,    33,    34,    35,
      13,    86,    41,    16,    23,    18,    19,    59,    60,    61,
      22,    96,    23,    25,    26,    27,    28,    29,    30,     4,
      42,     3,    36,    36,    37,    20,     8,    21,    67,    36,
      37,    31,    32,     5,     6,    62,    11,    12,     7,    57,
      58,    68,    51,    52,    53,    54,    55,    56,     4,    20,
      10,    14,    17,     7,    24,    21,    24,    24,    15,    23,
       7,    12,   101,    85,     7,    92,    24,    50,    14,    85,
      -1,    92
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    41,    42,     0,     3,     8,    45,    36,    60,     4,
      20,     5,     6,    43,    60,    44,    60,     9,    13,    16,
      18,    19,    37,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    21,
      43,     6,    23,    53,    53,    52,    53,    53,    52,     7,
      22,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    20,     4,    52,    60,    10,    14,    17,    24,
      24,    54,    56,    56,    56,    56,    56,    56,    57,    57,
      58,    58,    58,    53,    62,     5,     6,     7,    46,    52,
      53,    24,    23,    21,    44,    46,    11,    12,    15,    24,
      62,     6,     7,    46,    52,    12,     7
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    42,    42,    42,    43,    43,    44,    44,
      45,    45,    46,    46,    46,    46,    46,    46,    47,    47,
      48,    49,    50,    51,    52,    52,    53,    54,    54,    55,
      55,    55,    55,    55,    55,    55,    56,    56,    56,    57,
      57,    57,    57,    58,    58,    59,    59,    60,    61,    62,
      62
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,    12,    10,     0,     1,     2,     3,     1,
       7,     5,     1,     1,     1,     1,     1,     1,     7,     5,
       3,     3,     5,     5,     0,     2,     1,     4,     1,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     4,     1,
       3
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
  case 2: /* program: procedures_decl main  */
#line 80 "parser.bison"
        { ast = (yyvsp[0].decl); return 0; }
#line 1206 "parser.c"
    break;

  case 3: /* procedures_decl: procedures_decl PROCEDURE ident LPR param_comma_list RPR IS VAR decl X_BEGIN maybe_stmts END  */
#line 85 "parser.bison"
            { (yyval.decl) = decl_create((yyvsp[-9].ident), type_create(TYPE_FUNCTION, NULL, (yyvsp[-7].decl)), NULL, (yyvsp[-1].stmt), (yyvsp[-3].decl)); }
#line 1212 "parser.c"
    break;

  case 4: /* procedures_decl: procedures_decl PROCEDURE ident LPR param_comma_list RPR IS X_BEGIN stmt END  */
#line 87 "parser.bison"
            { (yyval.decl) = decl_create((yyvsp[-7].ident), type_create(TYPE_FUNCTION, NULL, (yyvsp[-5].decl)), NULL, (yyvsp[-1].stmt), NULL); }
#line 1218 "parser.c"
    break;

  case 5: /* procedures_decl: %empty  */
#line 89 "parser.bison"
            { (yyval.decl) = NULL; }
#line 1224 "parser.c"
    break;

  case 6: /* param_comma_list: ident  */
#line 93 "parser.bison"
      { (yyval.decl) = decl_create((yyvsp[0].ident), type_create(TYPE_INTEGER, NULL, NULL), NULL, NULL, NULL); }
#line 1230 "parser.c"
    break;

  case 7: /* param_comma_list: ident param_comma_list  */
#line 95 "parser.bison"
      { (yyval.decl) = decl_create((yyvsp[-1].ident), type_create(TYPE_INTEGER, NULL, NULL), NULL, NULL, NULL); (yyval.decl)->next = (yyvsp[0].decl); }
#line 1236 "parser.c"
    break;

  case 8: /* decl: decl COMMA ident  */
#line 102 "parser.bison"
      { (yyval.decl)  = decl_create((yyvsp[0].ident), type_create(TYPE_INTEGER, NULL, NULL), NULL, NULL, NULL); (yyval.decl)->next = (yyvsp[-2].decl); }
#line 1242 "parser.c"
    break;

  case 9: /* decl: ident  */
#line 104 "parser.bison"
      { (yyval.decl)  = decl_create((yyvsp[0].ident), type_create(TYPE_INTEGER, NULL, NULL), NULL, NULL, NULL); }
#line 1248 "parser.c"
    break;

  case 10: /* main: PROGRAM IS VAR decl X_BEGIN maybe_stmts END  */
#line 112 "parser.bison"
      {(yyval.decl) = decl_create(NULL, type_create(TYPE_FUNCTION,  NULL, NULL), NULL, (yyvsp[-1].stmt), (yyvsp[-3].decl));}
#line 1254 "parser.c"
    break;

  case 11: /* main: PROGRAM IS X_BEGIN maybe_stmts END  */
#line 114 "parser.bison"
      {(yyval.decl) = decl_create(NULL, type_create(TYPE_FUNCTION,  NULL, NULL), NULL, (yyvsp[-1].stmt), NULL);}
#line 1260 "parser.c"
    break;

  case 12: /* stmt: expr  */
#line 120 "parser.bison"
      { (yyval.stmt) = stmt_create(STMT_EXPR, NULL, (yyvsp[0].expr), NULL, NULL); }
#line 1266 "parser.c"
    break;

  case 13: /* stmt: if_stmt  */
#line 122 "parser.bison"
      { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1272 "parser.c"
    break;

  case 14: /* stmt: read_stmt  */
#line 124 "parser.bison"
      { (yyval.stmt) = (yyvsp[0].expr); }
#line 1278 "parser.c"
    break;

  case 15: /* stmt: write_stmt  */
#line 126 "parser.bison"
      { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1284 "parser.c"
    break;

  case 16: /* stmt: while_stmt  */
#line 128 "parser.bison"
      { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1290 "parser.c"
    break;

  case 17: /* stmt: repeat_stmt  */
#line 130 "parser.bison"
      { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1296 "parser.c"
    break;

  case 18: /* if_stmt: IF expr THEN stmt ELSE stmt ENDIF  */
#line 135 "parser.bison"
        { (yyvsp[-3].stmt)->next = (yyvsp[-1].stmt); (yyval.stmt) = stmt_create(STMT_IF_ELSE, NULL, (yyvsp[-5].expr), (yyvsp[-3].stmt), (yyvsp[-1].stmt)); }
#line 1302 "parser.c"
    break;

  case 19: /* if_stmt: IF expr THEN stmt ENDIF  */
#line 137 "parser.bison"
        { (yyval.stmt) = stmt_create(STMT_IF_ELSE, NULL, (yyvsp[-3].expr), (yyvsp[-1].stmt), NULL); }
#line 1308 "parser.c"
    break;

  case 20: /* read_stmt: READ expr SEMICOLON  */
#line 141 "parser.bison"
      { (yyval.expr) = stmt_create(STMT_READ, NULL, (yyvsp[-1].expr), NULL, NULL);}
#line 1314 "parser.c"
    break;

  case 21: /* write_stmt: WRITE expr SEMICOLON  */
#line 145 "parser.bison"
      { (yyval.stmt) = stmt_create(STMT_WRITE, NULL, (yyvsp[-1].expr), NULL, NULL);}
#line 1320 "parser.c"
    break;

  case 22: /* while_stmt: WHILE expr DO maybe_stmts ENDWHILE  */
#line 149 "parser.bison"
      { (yyval.stmt) = stmt_create(STMT_WHILE, NULL, (yyvsp[-3].expr), (yyvsp[-1].stmt), NULL);}
#line 1326 "parser.c"
    break;

  case 23: /* repeat_stmt: REPEAT maybe_stmts UNTIL expr SEMICOLON  */
#line 153 "parser.bison"
      { (yyval.stmt) = stmt_create(STMT_REPEAT, NULL, (yyvsp[-1].expr), (yyvsp[-3].stmt), NULL);}
#line 1332 "parser.c"
    break;

  case 24: /* maybe_stmts: %empty  */
#line 158 "parser.bison"
            { (yyval.stmt) = NULL; }
#line 1338 "parser.c"
    break;

  case 25: /* maybe_stmts: stmt maybe_stmts  */
#line 160 "parser.bison"
            { (yyvsp[-1].stmt)->next = (yyvsp[0].stmt); (yyval.stmt) = (yyvsp[-1].stmt); }
#line 1344 "parser.c"
    break;

  case 26: /* expr: expr6  */
#line 167 "parser.bison"
     { (yyval.expr) = (yyvsp[0].expr); }
#line 1350 "parser.c"
    break;

  case 27: /* expr6: expr5 ASSIGN expr6 SEMICOLON  */
#line 172 "parser.bison"
      { (yyval.expr) = expr_create_oper(EXPR_ASGN, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 1356 "parser.c"
    break;

  case 28: /* expr6: expr5  */
#line 174 "parser.bison"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 1362 "parser.c"
    break;

  case 29: /* expr5: expr5 LT expr4  */
#line 179 "parser.bison"
      { (yyval.expr) = expr_create_oper(EXPR_LT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1368 "parser.c"
    break;

  case 30: /* expr5: expr5 LEQ expr4  */
#line 181 "parser.bison"
      { (yyval.expr) = expr_create_oper(EXPR_LT_EQ, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1374 "parser.c"
    break;

  case 31: /* expr5: expr5 GT expr4  */
#line 183 "parser.bison"
      { (yyval.expr) = expr_create_oper(EXPR_GT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1380 "parser.c"
    break;

  case 32: /* expr5: expr5 GEQ expr4  */
#line 185 "parser.bison"
      { (yyval.expr) = expr_create_oper(EXPR_GT_EQ, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1386 "parser.c"
    break;

  case 33: /* expr5: expr5 EQ expr4  */
#line 187 "parser.bison"
      { (yyval.expr) = expr_create_oper(EXPR_EQ, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1392 "parser.c"
    break;

  case 34: /* expr5: expr5 NEQ expr4  */
#line 189 "parser.bison"
      { (yyval.expr) = expr_create_oper(EXPR_NOT_EQ, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1398 "parser.c"
    break;

  case 35: /* expr5: expr4  */
#line 191 "parser.bison"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 1404 "parser.c"
    break;

  case 36: /* expr4: expr4 ADD expr3  */
#line 196 "parser.bison"
      { (yyval.expr) = expr_create_oper(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1410 "parser.c"
    break;

  case 37: /* expr4: expr4 SUB expr3  */
#line 198 "parser.bison"
      { (yyval.expr) = expr_create_oper(EXPR_SUB, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1416 "parser.c"
    break;

  case 38: /* expr4: expr3  */
#line 200 "parser.bison"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 1422 "parser.c"
    break;

  case 39: /* expr3: expr3 MUL expr1  */
#line 205 "parser.bison"
      { (yyval.expr) = expr_create_oper(EXPR_MUL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1428 "parser.c"
    break;

  case 40: /* expr3: expr3 DIV expr1  */
#line 207 "parser.bison"
      { (yyval.expr) = expr_create_oper(EXPR_DIV, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1434 "parser.c"
    break;

  case 41: /* expr3: expr3 MOD expr1  */
#line 209 "parser.bison"
      { (yyval.expr) = expr_create_oper(EXPR_MOD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1440 "parser.c"
    break;

  case 42: /* expr3: expr1  */
#line 211 "parser.bison"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 1446 "parser.c"
    break;

  case 43: /* expr1: func_call  */
#line 216 "parser.bison"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 1452 "parser.c"
    break;

  case 44: /* expr1: atom  */
#line 218 "parser.bison"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 1458 "parser.c"
    break;

  case 45: /* atom: ident  */
#line 223 "parser.bison"
     { (yyval.expr) = expr_create_identifier((yyvsp[0].ident)); }
#line 1464 "parser.c"
    break;

  case 46: /* atom: INT_LIT  */
#line 225 "parser.bison"
     { (yyval.expr) = expr_create_integer_literal(last_int_literal); }
#line 1470 "parser.c"
    break;

  case 47: /* ident: IDENT  */
#line 229 "parser.bison"
     { char *s = strdup(yytext);
       if (!s){
           fprintf(stdout, "[ERROR|internal] Failed to allocate space for duping identifier.\n");
           exit(EXIT_FAILURE);
       }
       (yyval.ident) = s;
     }
#line 1482 "parser.c"
    break;

  case 48: /* func_call: expr1 LPR expr_commdecla_list RPR  */
#line 242 "parser.bison"
         { (yyval.expr) = expr_create_function_call((yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 1488 "parser.c"
    break;

  case 49: /* expr_commdecla_list: expr  */
#line 247 "parser.bison"
               { (yyval.expr) = (yyvsp[0].expr); }
#line 1494 "parser.c"
    break;

  case 50: /* expr_commdecla_list: expr COMMA expr_commdecla_list  */
#line 249 "parser.bison"
               { (yyvsp[-2].expr)->next = (yyvsp[0].expr); (yyval.expr) = (yyvsp[-2].expr); }
#line 1500 "parser.c"
    break;


#line 1504 "parser.c"

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

#line 251 "parser.bison"


int yyerror( char *str )
{
    printf("parse error: %s\n",str);
    return 0;
}
