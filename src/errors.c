#include <stdio.h>
#include "errors.h"

void raise_error(int error_type) {
	switch (error_type) {
		case SYNTAX_ERROR:
			fprintf(stderr, "Syntax error\n");
			break;
		case DIVISION_ERROR:
			fprintf(stderr, "Division error\n");
			break;
		case TOO_MANY_TOKENS_ERROR:
			fprintf(stderr, "Too many tokens\n");
			break;
		case TOKEN_TOO_LONG_ERROR:
			fprintf(stderr, "Token too long\n");
			break;
		default:
			break;
	}
}
