%{

/*
 * Parser.y file
 * To generate the parser run: "bison Parser.y"
 */

#include "Expression.h"
#include "Parser.h"
#include "Lexer.h"

// reference the implementation provided in Lexer.l
extern int		g_idx;

int yyerror(SExpression **expression, yyscan_t scanner, const char *msg);

%}

%code requires {
  typedef void* yyscan_t;
}

%output  "Parser.c"
%defines "Parser.h"

%define api.pure
%lex-param   { yyscan_t scanner }
%parse-param { SExpression **expression }
%parse-param { yyscan_t scanner }

%union {
    int value;
    SExpression *expression;
}

%token TOKEN_LPAREN   "("
%token TOKEN_RPAREN   ")"
%token TOKEN_PLUS     "+"
%token TOKEN_STAR     "*"
%token TOKEN_PERCENT  "%"
%token <value> TOKEN_NUMBER "number"

%type <expression> expr

/* Precedence (increasing) and associativity:
   a+b+c is (a+b)+c: left associativity
   a+b*c is a+(b*c): the precedence of "*" is higher than that of "+". */
%left "+"
%left "*" "%"

%%

input
    : expr { *expression = $1; }
    ;

expr
    : expr[L] "+" expr[R] { $$ = createOperation( eADD, $L, $R ); printf("%d: %d plus %d\n", g_idx++, $1->value, $3->value);}
    | expr[L] "*" expr[R] { $$ = createOperation( eMULTIPLY, $L, $R ); printf("%d: %d mul %d\n", g_idx++, $1->value, $3->value);}
    | expr[L] "%" expr[R] { $$ = createOperation( eMOD, $L, $R ); printf("%d: %d mod %d\n", g_idx++, $1->value, $3->value);}
    | "(" expr[E] ")"     { $$ = $E; printf("%d: paren\n", g_idx++);}
    | "number"            { $$ = createNumber($1); printf("%d: num %d\n", g_idx++, $1);}
    ;

%%

