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

#ifndef YY_YY_BLITZ_TAB_H_INCLUDED
# define YY_YY_BLITZ_TAB_H_INCLUDED
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
    NUMBER = 258,                  /* NUMBER  */
    IDENTIFIER = 259,              /* IDENTIFIER  */
    KEYWORD_INT = 260,             /* KEYWORD_INT  */
    KEYWORD_NUM = 261,             /* KEYWORD_NUM  */
    KEYWORD_IF = 262,              /* KEYWORD_IF  */
    KEYWORD_ELSE = 263,            /* KEYWORD_ELSE  */
    KEYWORD_WHILE = 264,           /* KEYWORD_WHILE  */
    KEYWORD_STOP = 265,            /* KEYWORD_STOP  */
    KEYWORD_READ = 266,            /* KEYWORD_READ  */
    KEYWORD_WRITE = 267,           /* KEYWORD_WRITE  */
    OP_ASSIGN = 268,               /* OP_ASSIGN  */
    OP_EQUAL = 269,                /* OP_EQUAL  */
    OP_EQUAL_EQUAL = 270,          /* OP_EQUAL_EQUAL  */
    OP_NOT_EQUAL = 271,            /* OP_NOT_EQUAL  */
    OP_LESS_THAN = 272,            /* OP_LESS_THAN  */
    OP_GREATER_THAN = 273,         /* OP_GREATER_THAN  */
    OP_LESS_EQUAL = 274,           /* OP_LESS_EQUAL  */
    OP_GREATER_EQUAL = 275,        /* OP_GREATER_EQUAL  */
    OP_PLUS = 276,                 /* OP_PLUS  */
    OP_MINUS = 277,                /* OP_MINUS  */
    OP_MULTIPLY = 278,             /* OP_MULTIPLY  */
    OP_DIVIDE = 279,               /* OP_DIVIDE  */
    SEMICOLON = 280,               /* SEMICOLON  */
    COMMA = 281,                   /* COMMA  */
    LPAREN = 282,                  /* LPAREN  */
    RPAREN = 283,                  /* RPAREN  */
    LBRACE = 284,                  /* LBRACE  */
    RBRACE = 285                   /* RBRACE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 38 "blitz.y"

    int num;
    char* str;
    struct ASTNode* node;

#line 100 "blitz.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_BLITZ_TAB_H_INCLUDED  */
