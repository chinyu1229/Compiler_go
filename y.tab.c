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
#line 2 "compiler_hw3.y" /* yacc.c:339  */

    #include "common.h" //Extern variables that communicate with lex
    #include <stdio.h>
    // #define YYDEBUG 1
    // int yydebug = 1;
    struct symtab{
	    char name[20];
	    char type[20];
            int addr;
            int line;
            char element_type[20];
	};
    int scope=0;
    int address=0;
    int addr_=0;
    int scopes_index[1000];
    int scopes_index_[1000];
    int print_type=0;
    int conversion_t=0;
    int flag=0;
    int local_num=0;
    int integer=0;
    int cmp=0;
    int cmp2=0;
    int cmp3=0;
    float float_num=0;
    char str[100];
    int b;
    int array_t=0;
    char store_ID[100];
    int left_right=0;
    int left_arr=0;
    int c=0;
    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;
    struct symtab symtable[10][20];
    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    /* Symbol table function - you can add new function if needed. */
    static void create_symbol(int s);
    static void insert_symbol(char* t,int type,int scope);
    int lookup_symbol(char *a);
    int lookup_type();
    static void dump_symbol(int s);
   

#line 117 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VAR = 258,
    INT = 259,
    FLOAT = 260,
    BOOL = 261,
    STRING = 262,
    INC = 263,
    DEC = 264,
    GEQ = 265,
    LEQ = 266,
    EQL = 267,
    NEQ = 268,
    ADD_ASSIGN = 269,
    SUB_ASSIGN = 270,
    MUL_ASSIGN = 271,
    QUO_ASSIGN = 272,
    REM_ASSIGN = 273,
    LAND = 274,
    LOR = 275,
    NEWLINE = 276,
    PRINT = 277,
    PRINTLN = 278,
    IF = 279,
    ELSE = 280,
    FOR = 281,
    TRUE = 282,
    FALSE = 283,
    INT_LIT = 284,
    FLOAT_LIT = 285,
    STRING_LIT = 286,
    BOOL_LIT = 287,
    ID = 288
  };
#endif
/* Tokens.  */
#define VAR 258
#define INT 259
#define FLOAT 260
#define BOOL 261
#define STRING 262
#define INC 263
#define DEC 264
#define GEQ 265
#define LEQ 266
#define EQL 267
#define NEQ 268
#define ADD_ASSIGN 269
#define SUB_ASSIGN 270
#define MUL_ASSIGN 271
#define QUO_ASSIGN 272
#define REM_ASSIGN 273
#define LAND 274
#define LOR 275
#define NEWLINE 276
#define PRINT 277
#define PRINTLN 278
#define IF 279
#define ELSE 280
#define FOR 281
#define TRUE 282
#define FALSE 283
#define INT_LIT 284
#define FLOAT_LIT 285
#define STRING_LIT 286
#define BOOL_LIT 287
#define ID 288

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 58 "compiler_hw3.y" /* yacc.c:355  */

    int i_val;
    float f_val;
    char *s_val;
    char str[50];
    /* ... */

#line 231 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 248 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  68
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   297

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  146

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,    50,     2,     2,    48,     2,     2,
      40,    41,    46,    44,     2,    45,     2,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
      42,    14,    43,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    35,     2,    36,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    96,    96,   102,   103,   106,   107,   108,   109,   110,
     110,   111,   112,   115,   116,   117,   120,   149,   191,   316,
     356,   357,   358,   359,   360,   361,   365,   368,   389,   412,
     413,   416,   417,   418,   419,   422,   422,   433,   433,   436,
     442,   450,   450,   462,   470,   471,   474,   477,   480,   483,
     525,   525,   568,   573,   577,   583,   587,   694,   697,   708,
     711,   722,   726,   727,   747,   748,   749,   750,   751,   752,
     755,   756,   759,   760,   761,   764,   765,   766,   769,   770,
     771,   774,   775,   794,   795,   800,   808,   823,   837,   852,
     867,   878
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VAR", "INT", "FLOAT", "BOOL", "STRING",
  "INC", "DEC", "GEQ", "LEQ", "EQL", "NEQ", "'='", "ADD_ASSIGN",
  "SUB_ASSIGN", "MUL_ASSIGN", "QUO_ASSIGN", "REM_ASSIGN", "LAND", "LOR",
  "NEWLINE", "PRINT", "PRINTLN", "IF", "ELSE", "FOR", "TRUE", "FALSE",
  "INT_LIT", "FLOAT_LIT", "STRING_LIT", "BOOL_LIT", "ID", "'['", "']'",
  "'{'", "'}'", "';'", "'('", "')'", "'<'", "'>'", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'!'", "'\"'", "$accept", "Program", "StatementList",
  "Statement", "$@1", "SimpleStmt", "DeclarationStmt", "AssignmentStmt",
  "assign_op", "ExpressionStmt", "IncDecStmt", "Type", "TypeName",
  "ArrayType", "$@2", "Block", "$@3", "IfStmt", "$@4", "Condition",
  "ForStmt", "ForClause", "InitStmt", "PostStmt", "PrintStmt", "$@5",
  "Expression", "AExpression", "BExpr", "CExpr", "DExpr", "UnaryExpr",
  "cmp_op", "add_op", "mul_op", "unary_op", "PrimaryExpr", "Oprand",
  "Literal", "IndexExpr", "ConversionExpr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,    61,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,    91,    93,   123,   125,    59,
      40,    41,    60,    62,    43,    45,    42,    47,    37,    33,
      34
};
# endif

#define YYPACT_NINF -66

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-66)))

#define YYTABLE_NINF -44

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     192,   -28,   -66,   -66,   -66,   -66,   -66,   -31,   -66,   239,
     -66,   -66,   -66,   -66,   -66,    11,   -66,   -66,   239,   -66,
     -66,   -66,   -21,    20,    96,   -66,    -4,    18,    19,   -66,
     -66,   -66,     6,   -66,   -66,    27,    29,    30,    26,    16,
       2,    -6,   -15,   -66,   239,     7,   -66,   -66,   -66,   -66,
      12,   239,     8,   -66,    17,   -66,    25,   -66,   -66,   -66,
     -66,   -66,   -66,   239,   239,   192,    22,     3,   -66,   -66,
     247,    39,   -66,   -66,   239,   -66,   -66,   -66,   -66,   -66,
     239,   239,   -66,   -66,   -66,   -66,   -66,   -66,   239,   -66,
     -66,   239,   -66,   -66,   -66,   239,   -66,   239,    50,    28,
     239,    42,   239,   -66,    35,   144,   -66,   -66,   -66,    17,
      17,    33,    13,   -66,    32,     2,    54,    -6,   -15,   -66,
      40,   239,   -66,    34,    53,    44,    12,   -66,   -66,   -66,
     239,   -66,    11,   -66,   -66,   -66,    17,   -66,   -66,    43,
     239,   -66,   247,   -66,   -66,   -66
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       9,     0,    31,    32,    34,    33,    12,     0,    50,     0,
      84,    85,    86,    87,    88,    82,    35,    37,     0,    75,
      76,    77,     0,     0,     2,     4,     0,     0,     0,    13,
      14,    15,     0,    29,    30,     0,     0,     0,    26,    53,
      55,    57,    59,    61,     0,    62,    78,    81,    79,    80,
       0,     0,     0,    82,     0,    43,    62,    20,    21,    22,
      23,    24,    25,     0,     0,     9,     0,     0,     1,     3,
       0,     0,     6,     5,     0,     7,     8,    11,    27,    28,
       0,     0,    69,    67,    64,    65,    66,    68,     0,    70,
      71,     0,    72,    73,    74,     0,    63,     0,    16,     0,
       0,    39,     0,    18,     0,     9,    83,    89,    47,     0,
       0,     0,    26,    10,     0,    54,    52,    56,    58,    60,
       0,     0,    49,     0,    41,     0,     0,    38,    44,    45,
       0,    91,    90,    17,    51,    40,     0,    90,    36,     0,
       0,    42,     0,    19,    48,    46
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -66,   -66,    21,   -20,   -66,   -65,   -66,   -66,   -51,   -66,
     -66,   -47,   -66,   -66,   -66,   -52,   -66,   -41,   -66,   -63,
     -66,   -66,   -66,   -66,   -66,   -66,    -8,     9,    15,    -1,
      -3,   -36,   -66,   -66,   -66,   -66,     0,   -66,   -66,   -66,
     -66
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    23,    24,    25,    26,    27,    28,    29,    63,    30,
      31,    32,    33,    34,    64,    35,    65,    36,   136,    54,
      71,   110,   111,   145,    37,    52,    38,    39,    40,    41,
      42,    43,    88,    91,    95,    44,    56,    46,    47,    48,
      49
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    55,   101,    98,    69,   108,    50,   109,    96,    51,
      66,    67,    82,    83,    84,    85,     2,     3,     4,     5,
      68,    78,    79,    70,    45,    57,    58,    59,    60,    61,
      62,    92,    93,    94,    78,    79,    80,    81,    89,    90,
      72,    73,    97,    99,    86,    87,    74,    16,   100,    75,
     -43,    76,    77,   107,    17,   103,   104,   128,   129,   119,
     102,   113,   112,   106,   121,    45,   114,   139,   124,   122,
      45,   126,   130,   131,    80,   134,   132,   144,     9,   138,
     137,   140,   142,   135,   141,    69,   105,   117,   118,   120,
     116,     0,   123,     0,   125,   115,     0,     0,     0,     1,
       2,     3,     4,     5,     0,    45,     0,     0,     0,     0,
       0,     0,     0,   133,     0,     0,     0,     0,     6,     7,
       8,     9,    55,    -9,    10,    11,    12,    13,     0,    14,
      15,    16,   143,    17,     0,     0,    18,     0,     0,     0,
      19,    20,    45,     0,     0,    21,    22,     1,     2,     3,
       4,     5,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     6,     7,     8,     9,
       0,     0,    10,    11,    12,    13,     0,    14,    15,    16,
       0,    17,   127,     0,    18,     0,     0,     0,    19,    20,
       0,     0,     0,    21,    22,     1,     2,     3,     4,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     7,     8,     9,     0,     0,
      10,    11,    12,    13,     0,    14,    15,    16,     0,    17,
       0,     0,    18,     0,     0,     0,    19,    20,     0,     0,
       0,    21,    22,     2,     3,     4,     5,     0,     0,     0,
       0,     2,     3,     4,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,    12,
      13,     0,    14,    53,    16,    10,    11,    12,    13,    18,
      14,    15,    16,    19,    20,     0,     0,    18,    21,    22,
       0,    19,    20,     0,     0,     0,    21,    22
};

static const yytype_int16 yycheck[] =
{
       0,     9,    54,    50,    24,    70,    34,    70,    44,    40,
      18,    32,    10,    11,    12,    13,     4,     5,     6,     7,
       0,     8,     9,    27,    24,    14,    15,    16,    17,    18,
      19,    46,    47,    48,     8,     9,    20,    21,    44,    45,
      22,    22,    35,    51,    42,    43,    40,    35,    40,    22,
      37,    22,    22,    50,    37,    63,    64,   109,   110,    95,
      35,    22,    70,    41,    14,    65,    74,   130,    26,    41,
      70,    36,    39,    41,    20,    41,    36,   142,    25,   126,
      36,   132,    39,   124,   136,   105,    65,    88,    91,    97,
      81,    -1,   100,    -1,   102,    80,    -1,    -1,    -1,     3,
       4,     5,     6,     7,    -1,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,    22,    23,
      24,    25,   130,    27,    28,    29,    30,    31,    -1,    33,
      34,    35,   140,    37,    -1,    -1,    40,    -1,    -1,    -1,
      44,    45,   142,    -1,    -1,    49,    50,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      -1,    -1,    28,    29,    30,    31,    -1,    33,    34,    35,
      -1,    37,    38,    -1,    40,    -1,    -1,    -1,    44,    45,
      -1,    -1,    -1,    49,    50,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    23,    24,    25,    -1,    -1,
      28,    29,    30,    31,    -1,    33,    34,    35,    -1,    37,
      -1,    -1,    40,    -1,    -1,    -1,    44,    45,    -1,    -1,
      -1,    49,    50,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    -1,    33,    34,    35,    28,    29,    30,    31,    40,
      33,    34,    35,    44,    45,    -1,    -1,    40,    49,    50,
      -1,    44,    45,    -1,    -1,    -1,    49,    50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    22,    23,    24,    25,
      28,    29,    30,    31,    33,    34,    35,    37,    40,    44,
      45,    49,    50,    52,    53,    54,    55,    56,    57,    58,
      60,    61,    62,    63,    64,    66,    68,    75,    77,    78,
      79,    80,    81,    82,    86,    87,    88,    89,    90,    91,
      34,    40,    76,    34,    70,    77,    87,    14,    15,    16,
      17,    18,    19,    59,    65,    67,    77,    32,     0,    54,
      27,    71,    22,    22,    40,    22,    22,    22,     8,     9,
      20,    21,    10,    11,    12,    13,    42,    43,    83,    44,
      45,    84,    46,    47,    48,    85,    82,    35,    62,    77,
      40,    66,    35,    77,    77,    53,    41,    50,    56,    70,
      72,    73,    77,    22,    77,    79,    78,    80,    81,    82,
      77,    14,    41,    77,    26,    77,    36,    38,    66,    66,
      39,    41,    36,    77,    41,    68,    69,    36,    62,    70,
      59,    66,    39,    77,    56,    74
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    54,    54,    54,    55,
      54,    54,    54,    56,    56,    56,    57,    57,    58,    58,
      59,    59,    59,    59,    59,    59,    60,    61,    61,    62,
      62,    63,    63,    63,    63,    65,    64,    67,    66,    68,
      68,    69,    68,    70,    71,    71,    72,    73,    74,    75,
      76,    75,    77,    77,    78,    78,    79,    79,    80,    80,
      81,    81,    82,    82,    83,    83,    83,    83,    83,    83,
      84,    84,    85,    85,    85,    86,    86,    86,    87,    87,
      87,    88,    88,    88,    88,    88,    89,    89,    89,    89,
      90,    91
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     2,     2,     2,     0,
       3,     2,     1,     1,     1,     1,     3,     5,     3,     6,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     0,     5,     0,     4,     3,
       5,     0,     6,     1,     3,     3,     5,     1,     1,     4,
       0,     5,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     3,
       4,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 96 "compiler_hw3.y" /* yacc.c:1646  */
    { dump_symbol(scope);
		      left_right=0;
		    }
#line 1470 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 110 "compiler_hw3.y" /* yacc.c:1646  */
    { FILE *f=fopen("hw3.j","a"); fprintf(f,"L_for_begin:\n"); fclose(f); }
#line 1476 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 120 "compiler_hw3.y" /* yacc.c:1646  */
    { insert_symbol((yyvsp[-1].str),(yyvsp[0].i_val),scope);
		      FILE *f=fopen("hw3.j","a");
		      addr_=lookup_symbol((yyvsp[-1].str)); 
		      //fprintf(f,"%d\n",array_t);
		      if(array_t==1)
			   fprintf(f,"astore %d\n",addr_);
                      else if(print_type==1)
			   {
				fprintf(f,"ldc 0\n");
                           	fprintf(f,"istore %d\n",addr_);
			   }
                      else if(print_type==2)
			   {
				fprintf(f,"ldc 0.0\n");
                           	fprintf(f,"fstore %d\n",addr_);
			   }
                      else if(print_type==0)
			   {
				fprintf(f,"iconst_0\n");
                           	fprintf(f,"istore %d\n",addr_);
			   }
                      else if(print_type==3)
			   {	
				fprintf(f,"ldc \"\"\n");
                           	fprintf(f,"astore %d\n",addr_);
			   }
                      array_t=0;
		      fclose(f);
		    }
#line 1510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 149 "compiler_hw3.y" /* yacc.c:1646  */
    {     insert_symbol((yyvsp[-3].str),(yyvsp[-2].i_val),scope); 
					
                                        FILE* f=fopen("hw3.j","a");  
					
					/*fprintf(f,"ldc ");
					if(print_type==1)
						fprintf(f,"%d",integer);
					else if(print_type==2)
					        fprintf(f,"%f",float_num);
					else if(print_type==0)
					{
						if(b==0) fprintf(f,"\"false\"");
						else if(b==1) fprintf(f,"\"true\"");
					}
					else if(print_type==3)
						fprintf(f,"%s",str);

					fprintf(f,"\n");*/
					addr_=lookup_symbol((yyvsp[-3].str));
				        if(print_type==1 && array_t==1)
                                        {
                                                fprintf(f,"newarray int\n");
                                                fprintf(f,"astore %d\n",addr_);
                                        }
					else if(print_type==1 && array_t==1)
					{
						fprintf(f,"newarray float\n");
						fprintf(f,"astore %d\n",addr_);
					}
					else if(print_type==1)
						fprintf(f,"istore %d\n",addr_);
					else if(print_type==2)
						fprintf(f,"fstore %d\n",addr_);
					else if(print_type==0)
						fprintf(f,"istore %d\n",addr_);
					else if(print_type==3)
						fprintf(f,"astore %d\n",addr_);
					array_t=0;
					fclose(f);
		    }
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 191 "compiler_hw3.y" /* yacc.c:1646  */
    {              
					//array_t=0;
					printf("%s\n",(yyvsp[-1].str));
					int left_add=0;
					  for(int i=scope;i>=0;i--)
        				  {
            					for(int j=0;j<scopes_index[i];j++)
                				{
                        				if(strcmp(symtable[i][j].name,(yyvsp[-2].str))==0)
                        				{
                                				left_add=symtable[i][j].addr;
                        				}

                			        }
                                          }      

					FILE *f=fopen("hw3.j","a"); 
					
					if(strcmp((yyvsp[-1].str),"ASSIGN")==0)
				       {
					
           					if(print_type==1)
                					fprintf(f,"istore %d\n",left_add);
           					else if(print_type==2)
                					fprintf(f,"fstore %d\n",left_add);
           					else if(print_type==0)
                					fprintf(f,"istore %d\n",left_add);
           					else if(print_type==3)
                					fprintf(f,"astore %d\n",left_add);
        					array_t=0;
					 
					}
					else if(strcmp((yyvsp[-1].str),"ADD_ASSIGN")==0)
					{
						if(print_type==1)
						{
							fprintf(f,"iload %d\n",addr_);
							fprintf(f,"swap\n");
							fprintf(f,"iadd\n");
							fprintf(f,"istore %d\n",left_add);
						}
						else if(print_type==2)
						{
						        fprintf(f,"fload %d\n",addr_);
                                                        fprintf(f,"swap\n");
                                                        fprintf(f,"fadd\n");
                                                        fprintf(f,"fstore %d\n",left_add);

						}
						
					}
					else if(strcmp((yyvsp[-1].str),"SUB_ASSIGN")==0)
					{
						if(print_type==1)
						{
							fprintf(f,"iload %d\n",addr_);
							fprintf(f,"swap\n");
							fprintf(f,"isub\n");
							fprintf(f,"istore %d\n",left_add);
						}
						else if(print_type==2)
                                                {      
                                                        fprintf(f,"fload %d\n",addr_);
                                                        fprintf(f,"swap\n");
                                                        fprintf(f,"fsub\n");
                                                        fprintf(f,"fstore %d\n",left_add);

                                                }

					}
					else if(strcmp((yyvsp[-1].str),"MUL_ASSIGN")==0)
                                        {
                                                if(print_type==1)
                                                {
                                                        fprintf(f,"iload %d\n",addr_);
                                                        fprintf(f,"swap\n");
                                                        fprintf(f,"imul\n");
                                                        fprintf(f,"istore %d\n",left_add);
                                                }
						else if(print_type==2)
                                                {      
                                                        fprintf(f,"fload %d\n",addr_);
                                                        fprintf(f,"swap\n");
                                                        fprintf(f,"fmul\n");
                                                        fprintf(f,"fstore %d\n",left_add);

                                                }

                                        }
					else if(strcmp((yyvsp[-1].str),"QUO_ASSIGN")==0)
                                        {
                                                if(print_type==1)
                                                {
                                                        fprintf(f,"iload %d\n",addr_);
                                                        fprintf(f,"swap\n");
                                                        fprintf(f,"idiv\n");
                                                        fprintf(f,"istore %d\n",left_add);
                                                }
						else if(print_type==2)
                                                {      
                                                        fprintf(f,"fload %d\n",addr_);
                                                        fprintf(f,"swap\n");
                                                        fprintf(f,"fdiv\n");
                                                        fprintf(f,"fstore %d\n",left_add);

                                                }

                                        }
					else if(strcmp((yyvsp[-1].str),"REM_ASSIGN")==0)
                                        {
                                                if(print_type==1)
                                                {
                                                        fprintf(f,"iload %d\n",addr_);
                                                        fprintf(f,"swap\n");
                                                        fprintf(f,"irem\n");
                                                        fprintf(f,"istore %d\n",left_add);
                                                }
                                        }



					
					fclose(f);

				      }
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 316 "compiler_hw3.y" /* yacc.c:1646  */
    {
								printf("%s\n",(yyvsp[-1].str));
                                        			FILE *f=fopen("hw3.j","a");

                                        			if(strcmp((yyvsp[-1].str),"ASSIGN")==0)
                                       				{
									if(print_type==1)
                                                       	 			fprintf(f,"iastore\n");
									else if(print_type==2)
										fprintf(f,"fastore\n");
                                                			

                                        			}
                                        			else if(strcmp((yyvsp[-1].str),"ADD_ASSIGN")==0)
                                        			{
                                                			if(print_type==1)
                                                			{
                                                        			fprintf(f,"iload %d\n",addr_);
                                                        			fprintf(f,"swap\n");
                                                        			fprintf(f,"iadd\n");
                                                			}

                                        			}
                                        			else if(strcmp((yyvsp[-1].str),"SUB_ASSIGN")==0)
                                        			{
                                        			        if(print_type==1)
                                                			{
                                                        			fprintf(f,"iload %d\n",addr_);
                                                        			fprintf(f,"swap\n");
                                                        			fprintf(f,"isub\n");
                                                			}
                                        			}
                                        			fclose(f);
                                        			left_arr=0;
                                     

                                      			     }
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 356 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.str),"ASSIGN"); }
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 357 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.str),"ADD_ASSIGN"); }
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 358 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.str),"SUB_ASSIGN"); }
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 359 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.str),"MUL_ASSIGN"); }
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 360 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.str),"QUO_ASSIGN"); }
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 361 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.str),"REM_ASSIGN"); }
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 368 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("INC\n");
			FILE *f=fopen("hw3.j","a");
			
			if(print_type==1) 
			{
				fprintf(f,"ldc 1\n");
				fprintf(f,"iadd\n");
				fprintf(f,"istore ");
				fprintf(f,"%d\n",addr_);
			}	
			else if(print_type==2) 
			{
				fprintf(f,"ldc 1.0\n");
				fprintf(f,"fadd\n");
                                fprintf(f,"fstore ");
                                fprintf(f,"%d\n",addr_);

			}
			
			fclose(f);
		      }
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 389 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("DEC\n"); 
			FILE *f=fopen("hw3.j","a");
                        
                        if(print_type==1)
                        {
				fprintf(f,"ldc 1\n");
                                fprintf(f,"isub\n");
                                fprintf(f,"istore ");
                                fprintf(f,"%d\n",addr_);
                        }
                        else if(print_type==2)
                        {
				fprintf(f,"ldc 1.0\n");
                                fprintf(f,"fsub\n");
                                fprintf(f,"fstore ");
                                fprintf(f,"%d\n",addr_);

                        }
			fclose(f);

		      }
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 412 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.i_val)=(yyvsp[0].i_val);}
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 413 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.i_val)=(yyvsp[0].i_val);}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 416 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.i_val) = 0; }
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 417 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.i_val) = 1; }
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 418 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.i_val) = 2; }
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 419 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.i_val) = 3; }
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 422 "compiler_hw3.y" /* yacc.c:1646  */
    { flag=1;}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 422 "compiler_hw3.y" /* yacc.c:1646  */
    {  (yyval.i_val) = (yyvsp[0].i_val)+4; 
					   array_t=1;
					   FILE *f=fopen("hw3.j","a");
				           if((yyvsp[0].i_val)==0)
						fprintf(f,"newarray int\n");  
					   else if((yyvsp[0].i_val)==1)
						fprintf(f,"newarray float\n");
					   fclose(f);
					 }
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 433 "compiler_hw3.y" /* yacc.c:1646  */
    { scope++;  }
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 433 "compiler_hw3.y" /* yacc.c:1646  */
    { dump_symbol(scope); if(scopes_index[scope]>0) scopes_index[scope]--; scope--; }
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 436 "compiler_hw3.y" /* yacc.c:1646  */
    {
				FILE *f=fopen("hw3.j","a");
				fprintf(f,"L_if_false_%d:\n",cmp3);
				cmp3++;
				fclose(f);
			}
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 442 "compiler_hw3.y" /* yacc.c:1646  */
    {
					FILE *f=fopen("hw3.j","a");
                                        fprintf(f,"goto L_if_exit_%d\n",cmp2);
                                        fprintf(f,"L_if_false_%d:\n",cmp3++);
                                        fclose(f);

				     }
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 450 "compiler_hw3.y" /* yacc.c:1646  */
    {          FILE *f=fopen("hw3.j","a");
                                        fprintf(f,"goto L_if_exit_%d\n",cmp2);
                                        fprintf(f,"L_if_false_%d:\n",cmp3++);
                                        fclose(f);
      }
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 455 "compiler_hw3.y" /* yacc.c:1646  */
    {
					FILE *f=fopen("hw3.j","a");
					fprintf(f,"L_if_exit_%d:\n",cmp2++);
					fclose(f);
				   }
#line 1926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 462 "compiler_hw3.y" /* yacc.c:1646  */
    {
			FILE *f=fopen("hw3.j","a");
			//fprintf(f,"ifeq L_if_false\n");
			fprintf(f,"ifeq L_if_false_%d\n",cmp3);
			fclose(f); 
		}
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 470 "compiler_hw3.y" /* yacc.c:1646  */
    { FILE *f=fopen("hw3.j","a"); fprintf(f,"goto L_for_begin\n"); fprintf(f,"L_if_false_%d:\n",cmp3);cmp3++; fclose(f); }
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 483 "compiler_hw3.y" /* yacc.c:1646  */
    {
                                        if(print_type==0) printf("PRINT bool\n");
                                        else if(print_type==1) printf("PRINT int32\n");
                                        else if(print_type==2) printf("PRINT float32\n");
                                        else printf("PRINT string\n");
					FILE *f=fopen("hw3.j","a");
					if(print_type==0)
					{	
						fprintf(f,"ifne L_cmp_%d\n",cmp++);
                                                fprintf(f,"ldc \"false\"\n");
                                                fprintf(f,"goto L_cmp_%d\n",cmp++);
                                                fprintf(f,"L_cmp_%d:\n",cmp-2);
                                                fprintf(f,"ldc \"true\"\n");
                                                fprintf(f,"L_cmp_%d:\n",cmp-1);
                                                fprintf(f,"getstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                                fprintf(f,"swap\n");
                                                fprintf(f,"invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
					}
					else if(print_type==1)
					{
						fprintf(f,"getstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                                fprintf(f,"swap\n");
                                                fprintf(f,"invokevirtual java/io/PrintStream/print(I)V\n");

					}
					else if(print_type==2)
					{
						fprintf(f,"getstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                                fprintf(f,"swap\n");
                                                fprintf(f,"invokevirtual java/io/PrintStream/print(F)V\n");

					}
					else if(print_type==3)
					{
						fprintf(f,"getstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                                fprintf(f,"swap\n");
                                                fprintf(f,"invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");

					}
					fclose(f);
					
				 }
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 525 "compiler_hw3.y" /* yacc.c:1646  */
    {left_right=1;}
#line 1996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 525 "compiler_hw3.y" /* yacc.c:1646  */
    { 
					if(print_type==0) printf("PRINTLN bool\n");
					else if(print_type==1) printf("PRINTLN int32\n");
					else if(print_type==2) printf("PRINTLN float32\n");
					else printf("PRINTLN string\n");
					flag=0;
					FILE *f=fopen("hw3.j","a");
					if(print_type==1)
					{
						fprintf(f,"getstatic java/lang/System/out Ljava/io/PrintStream;\n");
						fprintf(f,"swap\n");
						fprintf(f,"invokevirtual java/io/PrintStream/println(I)V\n");
					}
					else if(print_type==2)
					{
						fprintf(f,"getstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                                fprintf(f,"swap\n");
                                                fprintf(f,"invokevirtual java/io/PrintStream/println(F)V\n");

					}
					else if(print_type==0)
					{
						fprintf(f,"ifne L_cmp_%d\n",cmp++);
						fprintf(f,"ldc \"false\"\n");
						fprintf(f,"goto L_cmp_%d\n",cmp++);
						fprintf(f,"L_cmp_%d:\n",cmp-2);
						fprintf(f,"ldc \"true\"\n");
						fprintf(f,"L_cmp_%d:\n",cmp-1);
						fprintf(f,"getstatic java/lang/System/out Ljava/io/PrintStream;\n");
						fprintf(f,"swap\n");
						fprintf(f,"invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
					}
					else if(print_type==3)
					{
						fprintf(f,"getstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                                fprintf(f,"swap\n");
                                                fprintf(f,"invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");

					}
					fclose(f);
				 }
#line 2042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 568 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("LOR\n"); print_type=0;
				    FILE *f=fopen("hw3.j","a");
				    fprintf(f,"ior\n");
				    fclose(f);
				  }
#line 2052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 573 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.i_val)=(yyvsp[0].i_val);}
#line 2058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 577 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("LAND\n"); print_type=0;
			       FILE *f=fopen("hw3.j","a");
                               fprintf(f,"iand\n");
                               fclose(f);

			     }
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 583 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.i_val)=(yyvsp[0].i_val);}
#line 2075 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 587 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("%s\n",(yyvsp[-1].str));  
			   FILE *f=fopen("hw3.j","a");
			   if(strcmp((yyvsp[-1].str),"GTR")==0 && print_type==1)
			   {
				fprintf(f,"isub\n");
				fprintf(f,"ifgt L_cmp_%d\n",cmp++);
				fprintf(f,"iconst_0\n");
				fprintf(f,"goto L_cmp_%d\n",cmp++);
				fprintf(f,"L_cmp_%d:\n",cmp-2);
				fprintf(f,"iconst_1\n");
				fprintf(f,"L_cmp_%d:\n",cmp-1);
			   }
			   else if(strcmp((yyvsp[-1].str),"LSS")==0 && print_type==1)
                           {
                                fprintf(f,"isub\n");
                                fprintf(f,"iflt L_cmp_%d\n",cmp++);
                                fprintf(f,"iconst_0\n");
                                fprintf(f,"goto L_cmp_%d\n",cmp++);
                                fprintf(f,"L_cmp_%d:\n",cmp-2);
                                fprintf(f,"iconst_1\n");
                                fprintf(f,"L_cmp_%d:\n",cmp-1);
                           }
			   else if(strcmp((yyvsp[-1].str),"GTR")==0 && print_type==2)
			   {
				fprintf(f,"fcmpl\n");
				fprintf(f,"ifgt L_cmp_%d\n",cmp++);
				fprintf(f,"iconst_0\n");
				fprintf(f,"goto L_cmp_%d\n",cmp++);
				fprintf(f,"L_cmp_%d:\n",cmp-2);
				fprintf(f,"iconst_1\n");
				fprintf(f,"L_cmp_%d:\n",cmp-1);
			   }
			   else if(strcmp((yyvsp[-1].str),"LSS")==0 && print_type==2)
                           {
                                fprintf(f,"fcmpl\n");
                                fprintf(f,"iflt L_cmp_%d\n",cmp++);
                                fprintf(f,"iconst_0\n");
                                fprintf(f,"goto L_cmp_%d\n",cmp++);
                                fprintf(f,"L_cmp_%d:\n",cmp-2);
                                fprintf(f,"iconst_1\n");
                                fprintf(f,"L_cmp_%d:\n",cmp-1);
                           }
			   else if(strcmp((yyvsp[-1].str),"EQL")==0 && print_type==1)
                           {
                                fprintf(f,"isub\n");
                                fprintf(f,"ifeq L_cmp_%d\n",cmp++);
                                fprintf(f,"iconst_0\n");
                                fprintf(f,"goto L_cmp_%d\n",cmp++);
                                fprintf(f,"L_cmp_%d:\n",cmp-2);
                                fprintf(f,"iconst_1\n");
                                fprintf(f,"L_cmp_%d:\n",cmp-1);
                           }
			   else if(strcmp((yyvsp[-1].str),"EQL")==0 && print_type==2)
                           {
                                fprintf(f,"fcmpl\n");
                                fprintf(f,"ifeq L_cmp_%d\n",cmp++);
                                fprintf(f,"iconst_0\n");
                                fprintf(f,"goto L_cmp_%d\n",cmp++);
                                fprintf(f,"L_cmp_%d:\n",cmp-2);
                                fprintf(f,"iconst_1\n");
                                fprintf(f,"L_cmp_%d:\n",cmp-1);
                           }
			   else if(strcmp((yyvsp[-1].str),"LEQ")==0 && print_type==1)
                           {
                                fprintf(f,"isub\n");
                                fprintf(f,"ifle L_cmp_%d\n",cmp++);
                                fprintf(f,"iconst_0\n");
                                fprintf(f,"goto L_cmp_%d\n",cmp++);
                                fprintf(f,"L_cmp_%d:\n",cmp-2);
                                fprintf(f,"iconst_1\n");
                                fprintf(f,"L_cmp_%d:\n",cmp-1);
                           }
                           else if(strcmp((yyvsp[-1].str),"LEQ")==0 && print_type==2)
                           {
                                fprintf(f,"fcmpl\n");
                                fprintf(f,"ifle L_cmp_%d\n",cmp++);
                                fprintf(f,"iconst_0\n");
                                fprintf(f,"goto L_cmp_%d\n",cmp++);
                                fprintf(f,"L_cmp_%d:\n",cmp-2);
                                fprintf(f,"iconst_1\n");
                                fprintf(f,"L_cmp_%d:\n",cmp-1);
                           }
			   else if(strcmp((yyvsp[-1].str),"GEQ")==0 && print_type==1)
                           {
                                fprintf(f,"isub\n");
                                fprintf(f,"ifge L_cmp_%d\n",cmp++);
                                fprintf(f,"iconst_0\n");
                                fprintf(f,"goto L_cmp_%d\n",cmp++);
                                fprintf(f,"L_cmp_%d:\n",cmp-2);
                                fprintf(f,"iconst_1\n");
                                fprintf(f,"L_cmp_%d:\n",cmp-1);
                           }
                           else if(strcmp((yyvsp[-1].str),"GEQ")==0 && print_type==2)
                           {
                                fprintf(f,"fcmpl\n");
                                fprintf(f,"ifge L_cmp_%d\n",cmp++);
                                fprintf(f,"iconst_0\n");
                                fprintf(f,"goto L_cmp_%d\n",cmp++);
                                fprintf(f,"L_cmp_%d:\n",cmp-2);
                                fprintf(f,"iconst_1\n");
                                fprintf(f,"L_cmp_%d:\n",cmp-1);
                           }

		           

			   fclose(f);
			 }
#line 2187 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 694 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.i_val)=(yyvsp[0].i_val);}
#line 2193 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 697 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("%s\n",(yyvsp[-1].str));
     				//addr_=lookup_symbol(store_ID); 
				FILE *f=fopen("hw3.j","a");
                                if(strcmp((yyvsp[-1].str),"ADD")==0 && print_type==1) fprintf(f,"iadd\n");
                                else if(strcmp((yyvsp[-1].str),"ADD")==0 && print_type==2) fprintf(f,"fadd\n");
			        else if(strcmp((yyvsp[-1].str),"SUB")==0 && print_type==1) fprintf(f,"isub\n");
				else if(strcmp((yyvsp[-1].str),"SUB")==0 && print_type==2) fprintf(f,"fsub\n");
                                fclose(f);
				

			 }
#line 2209 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 708 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.i_val)=(yyvsp[0].i_val);}
#line 2215 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 711 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("%s\n",(yyvsp[-1].str)); 
				FILE *f=fopen("hw3.j","a");
				
                                if(strcmp((yyvsp[-1].str),"MUL")==0 && print_type==1) fprintf(f,"imul\n");
                                else if(strcmp((yyvsp[-1].str),"MUL")==0 && print_type==2) fprintf(f,"fmul\n");
                                else if(strcmp((yyvsp[-1].str),"QUO")==0 && print_type==1) fprintf(f,"idiv\n");
                                else if(strcmp((yyvsp[-1].str),"QUO")==0 && print_type==2) fprintf(f,"fdiv\n");
				else if(strcmp((yyvsp[-1].str),"REM")==0 && print_type==1) fprintf(f,"irem\n");
                                fclose(f);

			     }
#line 2231 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 722 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.i_val)=(yyvsp[0].i_val);}
#line 2237 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 726 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.i_val)=(yyvsp[0].i_val);}
#line 2243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 727 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("%s\n",(yyvsp[-1].str)); 
			   FILE *f=fopen("hw3.j","a");
                           if(strcmp((yyvsp[-1].str),"NEG")==0 && print_type==1) fprintf(f,"ineg\n");
			   else if(strcmp((yyvsp[-1].str),"NEG")==0 && print_type==2) fprintf(f,"fneg\n");
			   else if(strcmp((yyvsp[-1].str),"NOT")==0) 
			   {
				 fprintf(f,"iconst_1\n");
				 fprintf(f,"ixor\n");
			   }
			   fclose(f);
			 }
#line 2259 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 747 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.str),"EQL"); }
#line 2265 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 748 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.str),"NEQ"); }
#line 2271 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 749 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.str),"LSS"); }
#line 2277 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 750 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.str),"LEQ"); }
#line 2283 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 751 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.str),"GTR"); }
#line 2289 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 752 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.str),"GEQ"); }
#line 2295 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 755 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.str),"ADD"); print_type=1;}
#line 2301 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 756 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.str),"SUB"); print_type=1;}
#line 2307 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 759 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.str),"MUL"); }
#line 2313 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 760 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.str),"QUO"); print_type=2;}
#line 2319 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 761 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.str),"REM"); print_type=2;}
#line 2325 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 764 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.str),"POS"); }
#line 2331 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 765 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.str),"NEG"); }
#line 2337 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 766 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy((yyval.str),"NOT"); }
#line 2343 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 769 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.i_val)=(yyvsp[0].i_val);}
#line 2349 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 774 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.i_val)=(yyvsp[0].i_val); c=0;}
#line 2355 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 775 "compiler_hw3.y" /* yacc.c:1646  */
    { addr_= lookup_symbol((yyvsp[0].str)); printf("IDENT (name=%s, address=%d)\n",(yyvsp[0].str),addr_); (yyval.i_val)=(yyvsp[0].str);
           strcpy(store_ID,(yyvsp[0].str)); 
   
           FILE *f=fopen("hw3.j","a");
	   if(array_t==1)
		fprintf(f,"aload %d\n",addr_);

	   else if(print_type==1)
		fprintf(f,"iload %d\n",addr_);
	   else if(print_type==2)
		fprintf(f,"fload %d\n",addr_);
	   else if(print_type==0)
		fprintf(f,"iload %d\n",addr_);
	   else if(print_type==3)
		fprintf(f,"aload %d\n",addr_);
	   array_t=0;
	   
           fclose(f);
	 }
#line 2379 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 795 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("TRUE\n"); 
	     FILE *f=fopen("hw3.j","a");
	     fprintf(f,"iconst_1\n");
	     fclose(f);
	   }
#line 2389 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 800 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("FALSE\n");
	      FILE *f=fopen("hw3.j","a");
	      fprintf(f,"iconst_0\n");
	      fclose(f);
  	    }
#line 2399 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 808 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("INT_LIT %d\n",(yyvsp[0].i_val)); 
		/*if(flag==0)
		{
			print_type=1;
			conversion_t=1;
			
		}*/
		conversion_t=1;
		print_type=1;
		integer=(yyvsp[0].i_val);
		(yyval.i_val)=(yyvsp[0].i_val);
		FILE *f=fopen("hw3.j","a");
		fprintf(f,"ldc %d\n",(yyvsp[0].i_val));
		fclose(f);
	      }
#line 2419 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 823 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("FLOAT_LIT %f\n",(yyvsp[0].f_val));  
		  /*if(flag==0)
		  {
		    print_type=2;
		    conversion_t=2;
   		  } */	
		 print_type=2;
		 conversion_t=2;	
		 float_num=(yyvsp[0].f_val);
		 (yyval.i_val)=(yyvsp[0].f_val);
		 FILE *f=fopen("hw3.j","a");
		 fprintf(f,"ldc %f\n",(yyvsp[0].f_val));
		 fclose(f);
                }
#line 2438 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 837 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("BOOL_LIT %d\n",(yyvsp[0].i_val));  
                 /*if(flag==0)
		 {
		   print_type=0;
		   conversion_t=0;
		 }*/
		 b=(yyvsp[0].i_val);
		 print_type=0;
		 conversion_t=0;
		 FILE *f=fopen("hw3.j","a");
		 
		 if(b==0) fprintf(f,"iconst_0\n");
		 else if(b==1) fprintf(f,"iconst_1\n");
		 fclose(f);
 }
#line 2458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 852 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("STRING_LIT %s\n",(yyvsp[-1].s_val));
                           /*if(flag==0)
			   {	 
			      print_type=3;
			      conversion_t=3;
			   }*/
			   print_type=3;
			   conversion_t=3;
			   strcpy(str,(yyvsp[-1].s_val));
			   FILE *f=fopen("hw3.j","a");
			   fprintf(f,"ldc \"%s\"\n",str);
			   fclose(f);
}
#line 2476 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 867 "compiler_hw3.y" /* yacc.c:1646  */
    {	FILE *f=fopen("hw3.j","a"); 
					addr_=lookup_symbol(store_ID);
					array_t=1;
                			if(array_t==1 && print_type==1) fprintf(f,"iaload\n");
					else if(array_t==1 && print_type==2) fprintf(f,"faload\n");
                			array_t=0;

					fclose(f);
				    }
#line 2490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 878 "compiler_hw3.y" /* yacc.c:1646  */
    {
				int t1=(yyvsp[-3].i_val);
				char aa[3];
				char bb[3];
				if(t1==0) strcpy(aa,"I");
				else if(t1==1) strcpy(aa,"F");
				else if(t1==2) strcpy(aa,"S");
				else if(t1==3) strcpy(aa,"B");	
				if (conversion_t==0) strcpy(bb,"B");
				else if(conversion_t==1) strcpy(bb,"I");
				else if(conversion_t==2) strcpy(bb,"F");
   				else if(conversion_t==3) strcpy(bb,"S");
				printf("%s to %s\n",bb,aa);
				FILE *f=fopen("hw3.j","a");
				if(conversion_t==1 && t1==1)//I to F
					{
						fprintf(f,"i2f\n");
						print_type=2;
					}
				else if(conversion_t==2 && t1==0)// F to I
					{
						fprintf(f,"f2i\n");
						print_type=1;
					}

				fclose(f);
			     }
#line 2522 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2526 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 906 "compiler_hw3.y" /* yacc.c:1906  */


/* C code section */
int main(int argc, char *argv[])
{
    FILE* f=fopen("hw3.j","w");

    fprintf(f,".source hw3.j\n");
    fprintf(f,".class public Main\n");
    fprintf(f,".super java/lang/Object\n");
    fprintf(f,".method public static main([Ljava/lang/String;)V\n");
    fprintf(f,".limit stack 100  ;\n");
    fprintf(f,".limit locals 100 ;\n");
    fclose(f);
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }
    
    yylineno = 0;
    yyparse();

	printf("Total lines: %d\n", yylineno);
    
    fclose(yyin);
    f=fopen("hw3.j","a");
    fprintf(f,"	return\n");
    fprintf(f,".end method\n");
    fclose(f);
   

    return 0;
}

static void create_symbol(int s) {
	
}

static void insert_symbol(char* N , int type,int s) {
	int a=-1;
        //for(int i=scope;i>=0;i--)
        //{
            for(int j=0;j<scopes_index[scope];j++)
                {
                        if(strcmp(symtable[scope][j].name,N)==0)
                        {
				a = symtable[scope][j].addr;
                               
                        }
			

                }
	
        //}	
	if(a != -1)
	{
		FILE *f=fopen("hw3.j","a");
	
		fprintf(f,"goto error\n");
		fclose(f);
	}
    else if( type==0 )
	{ 
	    strcpy(symtable[s][ scopes_index[s] ].type,"int32");
	    strcpy(symtable[s][ scopes_index[s] ].element_type,"-");
	}
    else if( type==1 )
	{
	    strcpy(symtable[s][ scopes_index[s] ].type,"float32");
	    strcpy(symtable[s][ scopes_index[s] ].element_type,"-");
	}
    else if( type==2 )
	{
	    strcpy(symtable[s][ scopes_index[s] ].type,"string");
	    strcpy(symtable[s][ scopes_index[s] ].element_type,"-");
	}		
    else if ( type==3 )
        {
	    strcpy(symtable[s][ scopes_index[s] ].type,"bool");
	    strcpy(symtable[s][ scopes_index[s] ].element_type,"-");
	}
    else if ( type==4 )
	{
	    strcpy(symtable[s][ scopes_index[s] ].type,"array");
	    strcpy(symtable[s][ scopes_index[s] ].element_type,"int32");
	}
    else if ( type==5 )
	{
	    strcpy(symtable[s][ scopes_index[s] ].type,"array");
	    strcpy(symtable[s][ scopes_index[s] ].element_type,"float32");
	}
    else if ( type==6 )
	{
	    strcpy(symtable[s][ scopes_index[s] ].type,"array");
	    strcpy(symtable[s][ scopes_index[s] ].element_type,"string");
        }
    else
	{
 	    strcpy(symtable[s][ scopes_index[s] ].type,"array");
	    strcpy(symtable[s][ scopes_index[s] ].element_type,"bool");
	}
    strcpy(symtable[s][ scopes_index[s] ].name,N);
    symtable[s][ scopes_index[s] ].addr=address;
    symtable[s][ scopes_index[s] ].line=yylineno;

    address++;
    scopes_index[s]++;
  
    printf("> Insert {%s} into symbol table (scope level: %d)\n", N, scope);
}

int lookup_symbol(char *a) {
	for(int i=scope;i>=0;i--)
	{
	    for(int j=0;j<scopes_index[i];j++)
		{
			if(strcmp(symtable[i][j].name,a)==0)
			{
				if(strcmp(symtable[i][j].type,"bool")==0)
					{
						 print_type=0;
						 conversion_t=0;
					}					
				else if(strcmp(symtable[i][j].type,"int32")==0)
					 {
						print_type=1;
						conversion_t=1;
					 }
				else if(strcmp(symtable[i][j].type,"float32")==0) 
					 {
						print_type=2;
						conversion_t=2;
					 }	
				else if(strcmp(symtable[i][j].type,"string")==0) 
					 {
						print_type=3;
						conversion_t=3;
					 }
				else if(strcmp(symtable[i][j].type,"array")==0)
					 {	
						array_t=1;
						if(strcmp(symtable[i][j].element_type,"int32")==0)
							print_type=1;
						else if(strcmp(symtable[i][j].element_type,"float32")==0)
							print_type=2;
					 }

				return symtable[i][j].addr;
			}
						   
		}	
	}
}


static void dump_symbol(int s) {
    
    printf("> Dump symbol table (scope level: %d)\n", s);
   
    printf("%-10s%-10s%-0s%-10s%-10s%s\n",
           "Index", "Name", "Type", "Address", "Lineno", "Element type");
    for(int i=0;i<scopes_index[s];i++)
    	printf("%-10d%-10s%-10s%-10d%-10d%s\n",
            i, symtable[s][i].name, symtable[s][i].type, symtable[s][i].addr, symtable[s][i].line, symtable[s][i].element_type );
    
}
