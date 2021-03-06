
#include "Expression.h"
#include "Parser.h"
#include "Lexer.h"

#include <stdio.h>

int yyparse(SExpression **expression, yyscan_t scanner);

SExpression *getAST(const char *expr)
{
    SExpression *expression;
    yyscan_t scanner;
    YY_BUFFER_STATE state;

    if (yylex_init(&scanner)) {
        /* could not initialize */
        return NULL;
    }

    state = yy_scan_string(expr, scanner);

    if (yyparse(&expression, scanner)) {
        /* error parsing */
        return NULL;
    }

    yy_delete_buffer(state, scanner);

    yylex_destroy(scanner);

    return expression;
}

int evaluate(SExpression *e)
{
    switch (e->type) {
        case eVALUE:
            return e->value;
        case eMULTIPLY:
            return evaluate(e->left) * evaluate(e->right);
        case eADD:
            return evaluate(e->left) + evaluate(e->right);
		case eMOD:
			return evaluate(e->left) % evaluate(e->right);
        default:
            /* should not be here */
            return 0;
    }
}

int main(void)
{
    char test[] = " 4 + 2*10 + 3*( 5 + 1 )";
	char *ptr;
    SExpression *e = getAST(test);
    int result = evaluate(e);
    printf("Result of '%s' is %d\n", test, result);
    deleteExpression(e);
//	ptr = strdup("1 + 2 % 3 + 4 + 9 * (1 + 2) % 4 ");
	ptr = strdup("((1 + 5) % 4) * 5");
	SExpression *e2 = getAST(ptr);
	result = evaluate(e2);
	printf("%s = %d\n", ptr, result);
    deleteExpression(e2);
    return 0;
}
