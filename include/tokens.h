#ifndef TOKENS_H
#define TOKENS_H

#include "config.h"

#define MULTIPLY "*"
#define DIVIDE "/"
#define ADD "+"
#define SUBTRACT "-"

int is_operator(char token[]);
int is_near_operator(char tokens[][MAX_TOKEN_LEN], int token_index);
int is_near_multiplication_or_division(char tokens[][MAX_TOKEN_LEN], int token_count, int token_index);
void update_tokens(char tokens[][MAX_TOKEN_LEN], int *token_count, int token_index, char result_token[]);

#endif
