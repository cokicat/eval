#ifndef ERRORS_H
#define ERRORS_H

#define TOO_MANY_ARGUMENTS_ERROR 0
#define SYNTAX_ERROR 1
#define TOO_MANY_TOKENS_ERROR 2
#define TOKEN_TOO_LONG_ERROR 3
#define DIVISION_ERROR 4

void raise_error(int error_type);

#endif
