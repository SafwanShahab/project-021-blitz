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
#line 1 "blitz.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

void yyerror(const char* s);
int yylex(void);

extern FILE* yyin;
extern int yylineno;
extern char* yytext;

char* strdup_safe(const char* s) {
    size_t len = strlen(s) + 1;
    char* copy = (char*)malloc(len);
    if (copy) {
        memcpy(copy, s, len);
    }
    return copy;
}

void emit(const char* format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

void emit_declaration(const char* var, const char* type) {
    emit("DECLARE %s %s\n", var, type);
}

void emit_assignment(const char* var, const char* expr) {
    emit("ASSIGN %s %s\n", var, expr);
}

void emit_if_start(const char* expr) {
    emit("IF %s THEN\n", expr);
}

void emit_if_end() {
    emit("ENDIF\n");
}

void emit_else_start() {
    emit("ELSE\n");
}

void emit_while_start(const char* expr) {
    emit("WHILE %s DO\n", expr);
}

void emit_while_end() {
    emit("ENDWHILE\n");
}

void emit_for_start(const char* init, const char* cond) {
    emit("%s\n", init);  // Emit initialization
    emit("FOR_START:\n");
    emit("IF NOT %s THEN GOTO END_FOR\n", cond);  // Emit condition check
}

void emit_for_body_start() {
    emit("FOR_BODY_START:\n");
}

void emit_for_end(const char* update) {
    emit("%s\n", update);  // Emit update
    emit("GOTO FOR_START\n");
    emit("END_FOR:\n");
}

void emit_read(const char* var) {
    emit("READ %s\n", var);
}

void emit_write(const char* expr) {
    emit("WRITE %s\n", expr);
}

void emit_stop() {
    emit("STOP\n");
}

void emit_array_declaration(const char* var, const char* type, int size) {
    emit("DECLARE ARRAY %s %s %d\n", var, type, size);
}

void emit_array_assignment(const char* var, const char* index, const char* expr) {
    emit("ASSIGN %s[%s] %s\n", var, index, expr);
}

void emit_array_access(const char* var, const char* index) {
    emit("ACCESS %s[%s]\n", var, index);
}

#line 169 "blitz.tab.c"

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

#include "blitz.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_IDENTIFIER = 4,                 /* IDENTIFIER  */
  YYSYMBOL_KEYWORD_INT = 5,                /* KEYWORD_INT  */
  YYSYMBOL_KEYWORD_NUM = 6,                /* KEYWORD_NUM  */
  YYSYMBOL_KEYWORD_IF = 7,                 /* KEYWORD_IF  */
  YYSYMBOL_KEYWORD_ELSE = 8,               /* KEYWORD_ELSE  */
  YYSYMBOL_KEYWORD_WHILE = 9,              /* KEYWORD_WHILE  */
  YYSYMBOL_KEYWORD_STOP = 10,              /* KEYWORD_STOP  */
  YYSYMBOL_KEYWORD_READ = 11,              /* KEYWORD_READ  */
  YYSYMBOL_KEYWORD_WRITE = 12,             /* KEYWORD_WRITE  */
  YYSYMBOL_KEYWORD_FOR = 13,               /* KEYWORD_FOR  */
  YYSYMBOL_KEYWORD_FUNC = 14,              /* KEYWORD_FUNC  */
  YYSYMBOL_KEYWORD_RETURN = 15,            /* KEYWORD_RETURN  */
  YYSYMBOL_OP_ASSIGN = 16,                 /* OP_ASSIGN  */
  YYSYMBOL_OP_EQUAL = 17,                  /* OP_EQUAL  */
  YYSYMBOL_OP_EQUAL_EQUAL = 18,            /* OP_EQUAL_EQUAL  */
  YYSYMBOL_OP_NOT_EQUAL = 19,              /* OP_NOT_EQUAL  */
  YYSYMBOL_OP_LESS_THAN = 20,              /* OP_LESS_THAN  */
  YYSYMBOL_OP_GREATER_THAN = 21,           /* OP_GREATER_THAN  */
  YYSYMBOL_OP_LESS_EQUAL = 22,             /* OP_LESS_EQUAL  */
  YYSYMBOL_OP_GREATER_EQUAL = 23,          /* OP_GREATER_EQUAL  */
  YYSYMBOL_OP_PLUS = 24,                   /* OP_PLUS  */
  YYSYMBOL_OP_MINUS = 25,                  /* OP_MINUS  */
  YYSYMBOL_OP_MULTIPLY = 26,               /* OP_MULTIPLY  */
  YYSYMBOL_OP_DIVIDE = 27,                 /* OP_DIVIDE  */
  YYSYMBOL_SEMICOLON = 28,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 29,                     /* COMMA  */
  YYSYMBOL_LPAREN = 30,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 31,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 32,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 33,                    /* RBRACE  */
  YYSYMBOL_BEGINLOOP = 34,                 /* BEGINLOOP  */
  YYSYMBOL_ENDLOOP = 35,                   /* ENDLOOP  */
  YYSYMBOL_LBRACKET = 36,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 37,                  /* RBRACKET  */
  YYSYMBOL_YYACCEPT = 38,                  /* $accept  */
  YYSYMBOL_program = 39,                   /* program  */
  YYSYMBOL_statement_list = 40,            /* statement_list  */
  YYSYMBOL_statement = 41,                 /* statement  */
  YYSYMBOL_declaration = 42,               /* declaration  */
  YYSYMBOL_assignment = 43,                /* assignment  */
  YYSYMBOL_if_statement = 44,              /* if_statement  */
  YYSYMBOL_while_statement = 45,           /* while_statement  */
  YYSYMBOL_for_statement = 46,             /* for_statement  */
  YYSYMBOL_read_statement = 47,            /* read_statement  */
  YYSYMBOL_write_statement = 48,           /* write_statement  */
  YYSYMBOL_stop_statement = 49,            /* stop_statement  */
  YYSYMBOL_array_declaration = 50,         /* array_declaration  */
  YYSYMBOL_array_assignment = 51,          /* array_assignment  */
  YYSYMBOL_array_access = 52,              /* array_access  */
  YYSYMBOL_expression = 53                 /* expression  */
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
#define YYFINAL  34
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   175

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  38
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  100

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


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
      35,    36,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   126,   126,   130,   131,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   149,   152,   158,   164,
     168,   176,   183,   191,   197,   203,   209,   212,   218,   224,
     230,   233,   236,   240,   244,   248,   252,   256,   260
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
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "IDENTIFIER",
  "KEYWORD_INT", "KEYWORD_NUM", "KEYWORD_IF", "KEYWORD_ELSE",
  "KEYWORD_WHILE", "KEYWORD_STOP", "KEYWORD_READ", "KEYWORD_WRITE",
  "KEYWORD_FOR", "KEYWORD_FUNC", "KEYWORD_RETURN", "OP_ASSIGN", "OP_EQUAL",
  "OP_EQUAL_EQUAL", "OP_NOT_EQUAL", "OP_LESS_THAN", "OP_GREATER_THAN",
  "OP_LESS_EQUAL", "OP_GREATER_EQUAL", "OP_PLUS", "OP_MINUS",
  "OP_MULTIPLY", "OP_DIVIDE", "SEMICOLON", "COMMA", "LPAREN", "RPAREN",
  "LBRACE", "RBRACE", "BEGINLOOP", "ENDLOOP", "LBRACKET", "RBRACKET",
  "$accept", "program", "statement_list", "statement", "declaration",
  "assignment", "if_statement", "while_statement", "for_statement",
  "read_statement", "write_statement", "stop_statement",
  "array_declaration", "array_assignment", "array_access", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-32)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     127,   -13,     5,    23,    -8,    15,    21,    50,    52,    69,
      93,   127,   -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,
     -32,   -32,   -32,   -32,    17,    17,    20,    41,    17,    17,
     -32,    97,    17,   101,   -32,   -32,   -32,   -32,    17,   121,
      63,   -32,   103,   -32,   110,    71,    83,    90,    91,   111,
      17,    99,    17,    17,    17,    17,    17,    17,   -32,    18,
      92,    98,    96,   112,   115,   124,   130,   -32,   -14,   -14,
     148,   148,     4,     4,    17,   -32,   125,   133,   127,   127,
     -32,   -32,   101,   139,   -32,   -32,     6,    31,   131,   -32,
     162,   -32,   140,   141,   127,   127,    48,    61,   -32,   -32
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     3,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     0,     0,     0,     0,     0,     0,
      25,     0,     0,     0,     1,     4,    31,    30,     0,     0,
       0,    16,     0,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,     0,
       0,     0,     0,     0,     0,     0,     0,    38,    36,    37,
      32,    33,    34,    35,     0,    29,     0,     0,     0,     0,
      23,    24,     0,     0,    26,    27,     0,     0,     0,    28,
      19,    21,     0,     0,     0,     0,     0,     0,    22,    20
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -32,   -32,   -16,   -11,   -32,   -31,   -32,   -32,   -32,   -32,
     -32,   -32,   -32,   -32,   -32,   -24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    39
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      35,    40,    50,    24,    45,    46,    -1,    -1,    48,    26,
       1,     2,     3,     4,    51,     5,     6,     7,     8,     9,
      36,    37,    28,    25,    52,    53,    66,    27,    68,    69,
      70,    71,    72,    73,    74,     1,     2,     3,     4,    90,
       5,     6,     7,     8,     9,    29,    75,    38,    41,    30,
      83,    88,     1,     2,     3,     4,    42,     5,     6,     7,
       8,     9,    86,    87,    91,     1,     2,     3,     4,    43,
       5,     6,     7,     8,     9,    35,    35,    44,    96,    97,
      31,    98,    32,    52,    53,    35,    35,    54,    55,    56,
      57,    52,    53,    34,    99,    54,    55,    56,    57,    33,
      59,    47,    62,    52,    53,    49,    60,    54,    55,    56,
      57,    52,    53,    61,    63,    54,    55,    56,    57,    52,
      53,    64,    65,    54,    55,    56,    57,    24,    78,    76,
      67,     1,     2,     3,     4,    77,     5,     6,     7,     8,
       9,    52,    53,    80,    79,    54,    55,    56,    57,    58,
      52,    53,    81,    84,    54,    55,    56,    57,    82,    52,
      53,    85,    92,    54,    55,    56,    57,    89,    52,    53,
      93,     0,    94,    95,    56,    57
};

static const yytype_int8 yycheck[] =
{
      11,    25,    33,    16,    28,    29,    20,    21,    32,     4,
       4,     5,     6,     7,    38,     9,    10,    11,    12,    13,
       3,     4,    30,    36,    20,    21,    50,     4,    52,    53,
      54,    55,    56,    57,    16,     4,     5,     6,     7,    33,
       9,    10,    11,    12,    13,    30,    28,    30,    28,    28,
      74,    82,     4,     5,     6,     7,    36,     9,    10,    11,
      12,    13,    78,    79,    33,     4,     5,     6,     7,    28,
       9,    10,    11,    12,    13,    86,    87,    36,    94,    95,
      30,    33,    30,    20,    21,    96,    97,    24,    25,    26,
      27,    20,    21,     0,    33,    24,    25,    26,    27,    30,
      37,     4,    31,    20,    21,     4,     3,    24,    25,    26,
      27,    20,    21,     3,    31,    24,    25,    26,    27,    20,
      21,    31,    31,    24,    25,    26,    27,    16,    32,    37,
      31,     4,     5,     6,     7,    37,     9,    10,    11,    12,
      13,    20,    21,    28,    32,    24,    25,    26,    27,    28,
      20,    21,    28,    28,    24,    25,    26,    27,    28,    20,
      21,    28,    31,    24,    25,    26,    27,    28,    20,    21,
       8,    -1,    32,    32,    26,    27
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,     6,     7,     9,    10,    11,    12,    13,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    16,    36,     4,     4,    30,    30,
      28,    30,    30,    30,     0,    41,     3,     4,    30,    53,
      53,    28,    36,    28,    36,    53,    53,     4,    53,     4,
      43,    53,    20,    21,    24,    25,    26,    27,    28,    37,
       3,     3,    31,    31,    31,    31,    53,    31,    53,    53,
      53,    53,    53,    53,    16,    28,    37,    37,    32,    32,
      28,    28,    28,    53,    28,    28,    40,    40,    43,    28,
      33,    33,    31,     8,    32,    32,    40,    40,    33,    33
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    42,    42,    43,    44,
      44,    45,    46,    47,    48,    49,    50,    50,    51,    52,
      53,    53,    53,    53,    53,    53,    53,    53,    53
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     4,     7,
      11,     7,    10,     5,     5,     2,     6,     6,     7,     5,
       1,     1,     3,     3,     3,     3,     3,     3,     3
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
  case 2: /* program: statement_list  */
#line 126 "blitz.y"
                   { printf("Program parsed successfully.\n"); }
#line 1281 "blitz.tab.c"
    break;

  case 3: /* statement_list: statement  */
#line 130 "blitz.y"
              { (yyval.str) = (yyvsp[0].str); }
#line 1287 "blitz.tab.c"
    break;

  case 4: /* statement_list: statement_list statement  */
#line 131 "blitz.y"
                               { (yyval.str) = (yyvsp[-1].str); }
#line 1293 "blitz.tab.c"
    break;

  case 16: /* declaration: KEYWORD_INT IDENTIFIER SEMICOLON  */
#line 149 "blitz.y"
                                     {
        emit_declaration((yyvsp[-1].str), "INT");
    }
#line 1301 "blitz.tab.c"
    break;

  case 17: /* declaration: KEYWORD_NUM IDENTIFIER SEMICOLON  */
#line 152 "blitz.y"
                                       {
        emit_declaration((yyvsp[-1].str), "NUM");
    }
#line 1309 "blitz.tab.c"
    break;

  case 18: /* assignment: IDENTIFIER OP_ASSIGN expression SEMICOLON  */
#line 158 "blitz.y"
                                              {
        emit_assignment((yyvsp[-3].str), (yyvsp[-1].str));
    }
#line 1317 "blitz.tab.c"
    break;

  case 19: /* if_statement: KEYWORD_IF LPAREN expression RPAREN LBRACE statement_list RBRACE  */
#line 164 "blitz.y"
                                                                     {
        emit_if_start((yyvsp[-4].str));
        emit_if_end();
    }
#line 1326 "blitz.tab.c"
    break;

  case 20: /* if_statement: KEYWORD_IF LPAREN expression RPAREN LBRACE statement_list RBRACE KEYWORD_ELSE LBRACE statement_list RBRACE  */
#line 168 "blitz.y"
                                                                                                                 {
        emit_if_start((yyvsp[-8].str));
        emit_else_start();
        emit_if_end();
    }
#line 1336 "blitz.tab.c"
    break;

  case 21: /* while_statement: KEYWORD_WHILE LPAREN expression RPAREN LBRACE statement_list RBRACE  */
#line 176 "blitz.y"
                                                                        {
        emit_while_start((yyvsp[-4].str));
        emit_while_end();
    }
#line 1345 "blitz.tab.c"
    break;

  case 22: /* for_statement: KEYWORD_FOR LPAREN assignment expression SEMICOLON assignment RPAREN LBRACE statement_list RBRACE  */
#line 183 "blitz.y"
                                                                                                      {
        emit_for_start((yyvsp[-7].str), (yyvsp[-6].str));
        emit_for_body_start();
        emit_for_end((yyvsp[-4].str));
    }
#line 1355 "blitz.tab.c"
    break;

  case 23: /* read_statement: KEYWORD_READ LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 191 "blitz.y"
                                                    {
        emit_read((yyvsp[-2].str));
    }
#line 1363 "blitz.tab.c"
    break;

  case 24: /* write_statement: KEYWORD_WRITE LPAREN expression RPAREN SEMICOLON  */
#line 197 "blitz.y"
                                                     {
        emit_write((yyvsp[-2].str));
    }
#line 1371 "blitz.tab.c"
    break;

  case 25: /* stop_statement: KEYWORD_STOP SEMICOLON  */
#line 203 "blitz.y"
                           {
        emit_stop();
    }
#line 1379 "blitz.tab.c"
    break;

  case 26: /* array_declaration: KEYWORD_INT IDENTIFIER LBRACKET NUMBER RBRACKET SEMICOLON  */
#line 209 "blitz.y"
                                                              {
        emit_array_declaration((yyvsp[-4].str), "INT", (yyvsp[-2].num));
    }
#line 1387 "blitz.tab.c"
    break;

  case 27: /* array_declaration: KEYWORD_NUM IDENTIFIER LBRACKET NUMBER RBRACKET SEMICOLON  */
#line 212 "blitz.y"
                                                                {
        emit_array_declaration((yyvsp[-4].str), "NUM", (yyvsp[-2].num));
    }
#line 1395 "blitz.tab.c"
    break;

  case 28: /* array_assignment: IDENTIFIER LBRACKET expression RBRACKET OP_ASSIGN expression SEMICOLON  */
#line 218 "blitz.y"
                                                                           {
        emit_array_assignment((yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[-1].str));
    }
#line 1403 "blitz.tab.c"
    break;

  case 29: /* array_access: IDENTIFIER LBRACKET expression RBRACKET SEMICOLON  */
#line 224 "blitz.y"
                                                      {
        emit_array_access((yyvsp[-4].str), (yyvsp[-2].str));
    }
#line 1411 "blitz.tab.c"
    break;

  case 30: /* expression: IDENTIFIER  */
#line 230 "blitz.y"
               {
        (yyval.str) = strdup_safe((yyvsp[0].str));
    }
#line 1419 "blitz.tab.c"
    break;

  case 31: /* expression: NUMBER  */
#line 233 "blitz.y"
             {
        (yyval.str) = strdup_safe(yytext);
    }
#line 1427 "blitz.tab.c"
    break;

  case 32: /* expression: expression OP_PLUS expression  */
#line 236 "blitz.y"
                                    {
        emit("ADD %s %s\n", (yyvsp[-2].str), (yyvsp[0].str));
        (yyval.str) = strdup_safe("RESULT");
    }
#line 1436 "blitz.tab.c"
    break;

  case 33: /* expression: expression OP_MINUS expression  */
#line 240 "blitz.y"
                                     {
        emit("SUB %s %s\n", (yyvsp[-2].str), (yyvsp[0].str));
        (yyval.str) = strdup_safe("RESULT");
    }
#line 1445 "blitz.tab.c"
    break;

  case 34: /* expression: expression OP_MULTIPLY expression  */
#line 244 "blitz.y"
                                        {
        emit("MUL %s %s\n", (yyvsp[-2].str), (yyvsp[0].str));
        (yyval.str) = strdup_safe("RESULT");
    }
#line 1454 "blitz.tab.c"
    break;

  case 35: /* expression: expression OP_DIVIDE expression  */
#line 248 "blitz.y"
                                      {
        emit("DIV %s %s\n", (yyvsp[-2].str), (yyvsp[0].str));
        (yyval.str) = strdup_safe("RESULT");
    }
#line 1463 "blitz.tab.c"
    break;

  case 36: /* expression: expression OP_LESS_THAN expression  */
#line 252 "blitz.y"
                                         {
        emit("LESS_THAN %s %s\n", (yyvsp[-2].str), (yyvsp[0].str));
        (yyval.str) = strdup_safe("RESULT");
    }
#line 1472 "blitz.tab.c"
    break;

  case 37: /* expression: expression OP_GREATER_THAN expression  */
#line 256 "blitz.y"
                                            {
        emit("GREATER_THAN %s %s\n", (yyvsp[-2].str), (yyvsp[0].str));
        (yyval.str) = strdup_safe("RESULT");
    }
#line 1481 "blitz.tab.c"
    break;

  case 38: /* expression: LPAREN expression RPAREN  */
#line 260 "blitz.y"
                               {
        (yyval.str) = (yyvsp[-1].str);
    }
#line 1489 "blitz.tab.c"
    break;


#line 1493 "blitz.tab.c"

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

#line 265 "blitz.y"


void yyerror(const char* s) {
    fprintf(stderr, "Error: %s at line %d\n", s, yylineno);
}

int main(int argc, char **argv) {
    ++argv, --argc;  /* skip over program name */
    if (argc > 0)
        yyin = fopen(argv[0], "r");
    else
        yyin = stdin;

    yyparse();
    return 0;
}
