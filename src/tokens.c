#include "tokens.h"
#include <string.h>
#include "config.h"

int is_operator(char token[]) {
	if (strcmp(token, MULTIPLY) == 0
		|| strcmp(token, DIVIDE) == 0
		|| strcmp(token, ADD) == 0
		|| strcmp(token, SUBTRACT) == 0)
		return 1;

	return 0;
}

int is_near_operator(char tokens[][MAX_TOKEN_LEN], int token_index) {
	if (is_operator(tokens[token_index - 1]) || is_operator(tokens[token_index + 1]))
		return 1;

	return 0;
}

int is_near_multiplication_or_division(char tokens[][MAX_TOKEN_LEN], int token_count, int token_index) {
	if (token_index > 2
		&& (strcmp(tokens[token_index - 2], MULTIPLY) == 0
		|| strcmp(tokens[token_index - 2], DIVIDE) == 0))
		return 1;

	if (token_index + 2 < token_count
		&& (strcmp(tokens[token_index + 2], MULTIPLY) == 0
		|| strcmp(tokens[token_index + 2], DIVIDE) == 0))
		return 1;

	return 0;
}

static void replace_token(char tokens[][MAX_TOKEN_LEN], int token_index, char token[]) {
	size_t token_len = strlen(token);

	for (size_t char_index = 0; char_index < token_len; char_index++) {
		tokens[token_index][char_index] = token[char_index];
	}

	tokens[token_index][token_len] = '\0';
}

void update_tokens(char tokens[][MAX_TOKEN_LEN], int *token_count, int token_index, char *result_token) {
	char tmp_tokens[MAX_TOKENS][MAX_TOKEN_LEN] = {0};
	int new_count = 0;

	for (int i = 0; i < token_index - 1; i++)
		replace_token(tmp_tokens, new_count++, tokens[i]);

	replace_token(tmp_tokens, new_count++, result_token);

	for (int i = token_index + 2; i < *token_count; i++)
		replace_token(tmp_tokens, new_count++, tokens[i]);

	for (int i = 0; i < *token_count; i++)
		replace_token(tokens, i, "");

	for (int i = 0; i < new_count; i++)
		replace_token(tokens, i, tmp_tokens[i]);

	*token_count = new_count;
}
