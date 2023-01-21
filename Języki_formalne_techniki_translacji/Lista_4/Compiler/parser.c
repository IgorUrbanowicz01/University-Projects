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
extern int yylineno;
//extern char *clean_string(char *string, char delim);
struct decl *ast;
struct decl *procedure;
struct decl *declere = NULL;
struct decl *parameters = NULL;


#line 96 "parser.c"

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
  YYSYMBOL_proc_head = 43,                 /* proc_head  */
  YYSYMBOL_proc_headSTMT = 44,             /* proc_headSTMT  */
  YYSYMBOL_declSTMT = 45,                  /* declSTMT  */
  YYSYMBOL_declH = 46,                     /* declH  */
  YYSYMBOL_decl = 47,                      /* decl  */
  YYSYMBOL_main = 48,                      /* main  */
  YYSYMBOL_stmt = 49,                      /* stmt  */
  YYSYMBOL_if_stmt = 50,                   /* if_stmt  */
  YYSYMBOL_read_stmt = 51,                 /* read_stmt  */
  YYSYMBOL_write_stmt = 52,                /* write_stmt  */
  YYSYMBOL_while_stmt = 53,                /* while_stmt  */
  YYSYMBOL_repeat_stmt = 54,               /* repeat_stmt  */
  YYSYMBOL_function_head_stmt = 55,        /* function_head_stmt  */
  YYSYMBOL_maybe_stmts = 56,               /* maybe_stmts  */
  YYSYMBOL_expr = 57,                      /* expr  */
  YYSYMBOL_expr6 = 58,                     /* expr6  */
  YYSYMBOL_expr5 = 59,                     /* expr5  */
  YYSYMBOL_expr4 = 60,                     /* expr4  */
  YYSYMBOL_expr3 = 61,                     /* expr3  */
  YYSYMBOL_expr1 = 62,                     /* expr1  */
  YYSYMBOL_atom = 63,                      /* atom  */
  YYSYMBOL_ident = 64,                     /* ident  */
  YYSYMBOL_identE = 65                     /* identE  */
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
#define YYLAST   100

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  53
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  114

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
       0,    83,    83,    88,    90,    93,    96,   100,   106,   108,
     111,   113,   117,   119,   127,   129,   135,   137,   139,   141,
     143,   145,   147,   152,   154,   158,   162,   166,   170,   173,
     178,   179,   186,   190,   192,   197,   199,   201,   203,   205,
     207,   209,   214,   216,   218,   223,   225,   227,   229,   234,
     239,   241,   245,   254
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
  "TOKEN_EOF", "$accept", "program", "procedures_decl", "proc_head",
  "proc_headSTMT", "declSTMT", "declH", "decl", "main", "stmt", "if_stmt",
  "read_stmt", "write_stmt", "while_stmt", "repeat_stmt",
  "function_head_stmt", "maybe_stmts", "expr", "expr6", "expr5", "expr4",
  "expr3", "expr1", "atom", "ident", "identE", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-45)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-53)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -45,     3,    11,   -45,    20,    67,   -45,   -45,   -15,    37,
      20,    68,    20,     2,    52,    51,    47,    19,    53,   -20,
     -20,     2,   -20,   -20,    58,   -45,     2,   -45,   -45,   -45,
     -45,   -45,   -45,    72,   -45,   -45,     4,    23,   -11,   -45,
     -45,    60,   -45,   -45,    20,    20,     2,     2,    20,   -45,
      65,    69,    64,    61,    62,   -45,   -45,   -20,   -20,   -20,
     -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,    20,
      66,   -45,    76,    77,    81,   -45,     2,     2,   -20,   -45,
     -45,    21,    23,    23,    23,    23,    23,    23,   -11,   -11,
     -45,   -45,   -45,    70,    71,   -45,     2,   -45,   -45,    55,
      74,    73,   -45,   -45,    20,    85,     2,   -45,   -45,   -45,
     -45,   -45,    83,   -45
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     0,     1,     0,     0,     2,    52,     0,     0,
       0,     0,     0,    30,     0,    11,     0,     0,    13,     0,
       0,    30,     0,     0,    53,    51,    30,    17,    18,    19,
      20,    21,    22,     0,    16,    32,    34,    41,    44,    48,
      49,     0,    50,     6,     0,     0,    30,    30,     0,    53,
       0,     0,     0,     0,     0,    31,    15,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,     0,     0,     0,    12,    30,    30,     0,    25,
      26,     0,    39,    40,    37,    35,    36,    38,    42,    43,
      45,    46,    47,     0,     9,    29,    30,     4,    14,     0,
       0,     0,    33,     7,     0,     0,    30,    24,    27,    28,
       8,     3,     0,    23
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -45,   -45,   -45,   -45,   -45,    -8,    49,   -44,   -45,   -45,
     -45,   -45,   -45,   -45,   -45,   -45,   -19,   -10,   -45,    41,
       1,     5,   -31,   -45,    -4,   -45
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,    11,    70,    93,    14,    17,     6,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
       8,    72,    52,     3,    75,    10,    15,    55,    18,    50,
      51,    19,    53,    54,     4,    20,    49,    25,    21,     5,
      22,    23,    66,    67,    68,    47,    57,    73,    74,    58,
      59,    60,    61,    62,    63,    90,    91,    92,    24,    25,
      15,    18,    12,    13,    18,   102,    58,    59,    60,    61,
      62,    63,    45,    46,    64,    65,     7,    99,   100,    82,
      83,    84,    85,    86,    87,    94,   106,   107,   101,    88,
      89,     9,    16,    43,    44,    76,    48,   105,   -52,    56,
      69,    78,    96,    77,    97,    79,    80,   112,    98,   108,
      95,   103,   111,    71,   104,   113,   110,   109,    81,     0,
      94
};

static const yytype_int8 yycheck[] =
{
       4,    45,    21,     0,    48,    20,    10,    26,    12,    19,
      20,     9,    22,    23,     3,    13,    36,    37,    16,     8,
      18,    19,    33,    34,    35,     6,    22,    46,    47,    25,
      26,    27,    28,    29,    30,    66,    67,    68,    36,    37,
      44,    45,     5,     6,    48,    24,    25,    26,    27,    28,
      29,    30,     5,     6,    31,    32,    36,    76,    77,    58,
      59,    60,    61,    62,    63,    69,    11,    12,    78,    64,
      65,     4,     4,    21,    23,    10,    23,    96,    20,     7,
      20,    17,     6,    14,     7,    24,    24,   106,     7,    15,
      24,    21,     7,    44,    23,    12,   104,    24,    57,    -1,
     104
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    41,    42,     0,     3,     8,    48,    36,    64,     4,
      20,    43,     5,     6,    46,    64,     4,    47,    64,     9,
      13,    16,    18,    19,    36,    37,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    21,    23,     5,     6,     6,    23,    36,
      57,    57,    56,    57,    57,    56,     7,    22,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    20,
      44,    46,    47,    56,    56,    47,    10,    14,    17,    24,
      24,    59,    60,    60,    60,    60,    60,    60,    61,    61,
      62,    62,    62,    45,    64,    24,     6,     7,     7,    56,
      56,    57,    24,    21,    23,    56,    11,    12,    15,    24,
      45,     7,    56,    12
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    42,    42,    42,    43,    44,    45,    45,
      46,    46,    47,    47,    48,    48,    49,    49,    49,    49,
      49,    49,    49,    50,    50,    51,    52,    53,    54,    55,
      56,    56,    57,    58,    58,    59,    59,    59,    59,    59,
      59,    59,    60,    60,    60,    61,    61,    61,    61,    62,
      63,    63,    64,    65
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,    10,     8,     0,     3,     3,     3,     1,
       3,     1,     3,     1,     7,     5,     1,     1,     1,     1,
       1,     1,     1,     7,     5,     3,     3,     5,     5,     3,
       0,     2,     1,     4,     1,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     1,
       1,     1,     1,     1
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
#line 84 "parser.bison"
        {procedure = (yyvsp[-1].decl); ast = (yyvsp[0].decl); return 1; }
#line 1218 "parser.c"
    break;

  case 3: /* procedures_decl: procedures_decl PROCEDURE ident proc_head IS VAR decl X_BEGIN maybe_stmts END  */
#line 89 "parser.bison"
            {  (yyval.decl) = decl_create((yyvsp[-7].ident), (yyvsp[-6].type), (yyvsp[-1].stmt), (yyvsp[-3].decl), (yyvsp[-9].decl)); }
#line 1224 "parser.c"
    break;

  case 4: /* procedures_decl: procedures_decl PROCEDURE ident proc_head IS X_BEGIN maybe_stmts END  */
#line 91 "parser.bison"
            { (yyval.decl) = decl_create((yyvsp[-5].ident), (yyvsp[-4].type), (yyvsp[-1].stmt), NULL, (yyvsp[-7].decl)); }
#line 1230 "parser.c"
    break;

  case 5: /* procedures_decl: %empty  */
#line 93 "parser.bison"
            { (yyval.decl) = NULL; }
#line 1236 "parser.c"
    break;

  case 6: /* proc_head: LPR declH RPR  */
#line 97 "parser.bison"
            { (yyval.type) = type_create(TYPE_FUNCTION, (yyvsp[-1].decl)); }
#line 1242 "parser.c"
    break;

  case 7: /* proc_headSTMT: LPR declSTMT RPR  */
#line 101 "parser.bison"
            { (yyval.type) = type_create(TYPE_FUNCTION, (yyvsp[-1].decl)); }
#line 1248 "parser.c"
    break;

  case 8: /* declSTMT: ident COMMA declSTMT  */
#line 107 "parser.bison"
      { (yyval.decl)  = decl_create((yyvsp[-2].ident), type_create(TYPE_INTEGER, NULL), NULL, NULL, NULL); (yyval.decl)->next = (yyvsp[0].decl);}
#line 1254 "parser.c"
    break;

  case 9: /* declSTMT: ident  */
#line 109 "parser.bison"
      { (yyval.decl)  = decl_create((yyvsp[0].ident), type_create(TYPE_INTEGER, NULL), NULL, NULL, NULL);}
#line 1260 "parser.c"
    break;

  case 10: /* declH: ident COMMA declH  */
#line 112 "parser.bison"
      { (yyval.decl)  = decl_create((yyvsp[-2].ident), type_create(TYPE_INTEGER, NULL), NULL, NULL, NULL); (yyval.decl)->next = (yyvsp[0].decl); parameters = (yyval.decl); }
#line 1266 "parser.c"
    break;

  case 11: /* declH: ident  */
#line 114 "parser.bison"
      { (yyval.decl)  = decl_create((yyvsp[0].ident), type_create(TYPE_INTEGER, NULL), NULL, NULL, NULL); parameters = (yyval.decl);}
#line 1272 "parser.c"
    break;

  case 12: /* decl: ident COMMA decl  */
#line 118 "parser.bison"
      { (yyval.decl)  = decl_create((yyvsp[-2].ident), type_create(TYPE_INTEGER, NULL), NULL, NULL, NULL); (yyval.decl)->next = (yyvsp[0].decl); declere = (yyval.decl); }
#line 1278 "parser.c"
    break;

  case 13: /* decl: ident  */
#line 120 "parser.bison"
      { (yyval.decl)  = decl_create((yyvsp[0].ident), type_create(TYPE_INTEGER, NULL), NULL, NULL, NULL); declere = (yyval.decl);}
#line 1284 "parser.c"
    break;

  case 14: /* main: PROGRAM IS VAR decl X_BEGIN maybe_stmts END  */
#line 128 "parser.bison"
      {(yyval.decl) = decl_create("MAIN", type_create(TYPE_FUNCTION, NULL), (yyvsp[-1].stmt), (yyvsp[-3].decl), NULL);}
#line 1290 "parser.c"
    break;

  case 15: /* main: PROGRAM IS X_BEGIN maybe_stmts END  */
#line 130 "parser.bison"
      {(yyval.decl) = decl_create("MAIN", type_create(TYPE_FUNCTION, NULL), (yyvsp[-1].stmt), NULL, NULL);}
#line 1296 "parser.c"
    break;

  case 16: /* stmt: expr  */
#line 136 "parser.bison"
      { (yyval.stmt) = stmt_create(STMT_EXPR, NULL, (yyvsp[0].expr), NULL, NULL); }
#line 1302 "parser.c"
    break;

  case 17: /* stmt: if_stmt  */
#line 138 "parser.bison"
      { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1308 "parser.c"
    break;

  case 18: /* stmt: read_stmt  */
#line 140 "parser.bison"
      { (yyval.stmt) = (yyvsp[0].expr); }
#line 1314 "parser.c"
    break;

  case 19: /* stmt: write_stmt  */
#line 142 "parser.bison"
      { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1320 "parser.c"
    break;

  case 20: /* stmt: while_stmt  */
#line 144 "parser.bison"
      { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1326 "parser.c"
    break;

  case 21: /* stmt: repeat_stmt  */
#line 146 "parser.bison"
      { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1332 "parser.c"
    break;

  case 22: /* stmt: function_head_stmt  */
#line 148 "parser.bison"
      { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1338 "parser.c"
    break;

  case 23: /* if_stmt: IF expr THEN maybe_stmts ELSE maybe_stmts ENDIF  */
#line 153 "parser.bison"
        { (yyvsp[-3].stmt)->next = (yyvsp[-1].stmt); (yyval.stmt) = stmt_create(STMT_IF_ELSE, NULL, (yyvsp[-5].expr), (yyvsp[-3].stmt), (yyvsp[-1].stmt)); }
#line 1344 "parser.c"
    break;

  case 24: /* if_stmt: IF expr THEN maybe_stmts ENDIF  */
#line 155 "parser.bison"
        { (yyval.stmt) = stmt_create(STMT_IF_ELSE, NULL, (yyvsp[-3].expr), (yyvsp[-1].stmt), NULL); }
#line 1350 "parser.c"
    break;

  case 25: /* read_stmt: READ expr SEMICOLON  */
#line 159 "parser.bison"
      { (yyval.expr) = stmt_create(STMT_READ, NULL, (yyvsp[-1].expr), NULL, NULL);}
#line 1356 "parser.c"
    break;

  case 26: /* write_stmt: WRITE expr SEMICOLON  */
#line 163 "parser.bison"
      { (yyval.stmt) = stmt_create(STMT_WRITE, NULL, (yyvsp[-1].expr), NULL, NULL);}
#line 1362 "parser.c"
    break;

  case 27: /* while_stmt: WHILE expr DO maybe_stmts ENDWHILE  */
#line 167 "parser.bison"
      { (yyval.stmt) = stmt_create(STMT_WHILE, NULL, (yyvsp[-3].expr), (yyvsp[-1].stmt), NULL);}
#line 1368 "parser.c"
    break;

  case 28: /* repeat_stmt: REPEAT maybe_stmts UNTIL expr SEMICOLON  */
#line 171 "parser.bison"
      { (yyval.stmt) = stmt_create(STMT_REPEAT, NULL, (yyvsp[-1].expr), (yyvsp[-3].stmt), NULL);}
#line 1374 "parser.c"
    break;

  case 29: /* function_head_stmt: ident proc_headSTMT SEMICOLON  */
#line 174 "parser.bison"
      { (yyval.stmt) = stmt_create(STMT_HEAD, decl_create((yyvsp[-2].ident), (yyvsp[-1].type), NULL, NULL, NULL), NULL, NULL, NULL);}
#line 1380 "parser.c"
    break;

  case 30: /* maybe_stmts: %empty  */
#line 178 "parser.bison"
            { (yyval.stmt) = NULL; }
#line 1386 "parser.c"
    break;

  case 31: /* maybe_stmts: stmt maybe_stmts  */
#line 180 "parser.bison"
            { (yyvsp[-1].stmt)->next = (yyvsp[0].stmt); (yyval.stmt) = (yyvsp[-1].stmt); }
#line 1392 "parser.c"
    break;

  case 32: /* expr: expr6  */
#line 187 "parser.bison"
     { (yyval.expr) = (yyvsp[0].expr); }
#line 1398 "parser.c"
    break;

  case 33: /* expr6: expr5 ASSIGN expr5 SEMICOLON  */
#line 191 "parser.bison"
      { (yyval.expr) = expr_create_oper(EXPR_ASGN, (yyvsp[-3].expr), (yyvsp[-1].expr));}
#line 1404 "parser.c"
    break;

  case 34: /* expr6: expr5  */
#line 193 "parser.bison"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 1410 "parser.c"
    break;

  case 35: /* expr5: expr5 LT expr4  */
#line 198 "parser.bison"
      { (yyval.expr) = expr_create_oper(EXPR_LT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1416 "parser.c"
    break;

  case 36: /* expr5: expr5 LEQ expr4  */
#line 200 "parser.bison"
      { (yyval.expr) = expr_create_oper(EXPR_LT_EQ, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1422 "parser.c"
    break;

  case 37: /* expr5: expr5 GT expr4  */
#line 202 "parser.bison"
      { (yyval.expr) = expr_create_oper(EXPR_GT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1428 "parser.c"
    break;

  case 38: /* expr5: expr5 GEQ expr4  */
#line 204 "parser.bison"
      { (yyval.expr) = expr_create_oper(EXPR_GT_EQ, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1434 "parser.c"
    break;

  case 39: /* expr5: expr5 EQ expr4  */
#line 206 "parser.bison"
      { (yyval.expr) = expr_create_oper(EXPR_EQ, (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1440 "parser.c"
    break;

  case 40: /* expr5: expr5 NEQ expr4  */
#line 208 "parser.bison"
      { (yyval.expr) = expr_create_oper(EXPR_NOT_EQ, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1446 "parser.c"
    break;

  case 41: /* expr5: expr4  */
#line 210 "parser.bison"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 1452 "parser.c"
    break;

  case 42: /* expr4: expr4 ADD expr3  */
#line 215 "parser.bison"
      { (yyval.expr) = expr_create_oper(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1458 "parser.c"
    break;

  case 43: /* expr4: expr4 SUB expr3  */
#line 217 "parser.bison"
      { (yyval.expr) = expr_create_oper(EXPR_SUB, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1464 "parser.c"
    break;

  case 44: /* expr4: expr3  */
#line 219 "parser.bison"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 1470 "parser.c"
    break;

  case 45: /* expr3: expr3 MUL expr1  */
#line 224 "parser.bison"
      { (yyval.expr) = expr_create_oper(EXPR_MUL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1476 "parser.c"
    break;

  case 46: /* expr3: expr3 DIV expr1  */
#line 226 "parser.bison"
      { (yyval.expr) = expr_create_oper(EXPR_DIV, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1482 "parser.c"
    break;

  case 47: /* expr3: expr3 MOD expr1  */
#line 228 "parser.bison"
      { (yyval.expr) = expr_create_oper(EXPR_MOD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1488 "parser.c"
    break;

  case 48: /* expr3: expr1  */
#line 230 "parser.bison"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 1494 "parser.c"
    break;

  case 49: /* expr1: atom  */
#line 235 "parser.bison"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 1500 "parser.c"
    break;

  case 50: /* atom: identE  */
#line 240 "parser.bison"
     { (yyval.expr) = expr_create_identifier((yyvsp[0].ident)); /*printf("%s <-- \n", $1);*/ }
#line 1506 "parser.c"
    break;

  case 51: /* atom: INT_LIT  */
#line 242 "parser.bison"
     { (yyval.expr) = expr_create_integer_literal(last_int_literal); /*printf("%d <-- \n", last_int_literal);*/}
#line 1512 "parser.c"
    break;

  case 52: /* ident: IDENT  */
#line 246 "parser.bison"
     { char *s = strdup((yyvsp[0].ident));
       if (!s){
           fprintf(stdout, "[ERROR|internal] Failed to allocate space for duping identifier.\n");
           exit(EXIT_FAILURE);
       }
       (yyval.ident) = s;
     }
#line 1524 "parser.c"
    break;

  case 53: /* identE: IDENT  */
#line 255 "parser.bison"
     { char *s = strdup((yyvsp[0].ident));
       if (!s){
           fprintf(stdout, "[ERROR|internal] Failed to allocate space for duping identifier.\n");
           exit(EXIT_FAILURE);
       }
       if(decl_find(declere, s) || decl_find(parameters, s))
            (yyval.ident) = s;
       else{
            fprintf(stdout, "[ERROR|identifire] Failed to find decleared varible %s at line: %d \n", s, yylineno);
            exit(EXIT_FAILURE);
      }

     }
#line 1542 "parser.c"
    break;


#line 1546 "parser.c"

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

#line 271 "parser.bison"


int yyerror( char *str )
{
      fprintf(stderr, "Error at line: %d\n%s\n", yylineno, str);
    return 0;
}
