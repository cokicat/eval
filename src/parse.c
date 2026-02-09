#include "parse.h"
#include <ctype.h>
#include <string.h>
#include "errors.h"
#include "config.h"

int parse(char *input, char tokens[][MAX_TOKEN_LEN], int *token_count) {
	size_t input_len = strlen(input);

	int token_index = 0;
	int char_index = 0;

	for (size_t i = 0; i < input_len; i++) {
		if ((input[i] == '*')
			|| (input[i] == '/')
			|| (input[i] == '+')
			|| (input[i] == '-')) {
			if (char_index == 0 || i == input_len - 1) {
				raise_error(SYNTAX_ERROR);
				return 0;
			}

			char_index = 0;
			token_index++;

			if (token_index < MAX_TOKENS) {
				tokens[token_index][0] = input[i];
				tokens[token_index][1] = '\0';
				token_index++;
			} else {
				raise_error(TOO_MANY_TOKENS_ERROR);
				return 0;
			}
		} else if (isdigit((unsigned char)input[i])) {
			if (char_index + 1 < MAX_TOKEN_LEN) {
				tokens[token_index][char_index] = input[i];
				char_index++;
				tokens[token_index][char_index] = '\0';
			} else {
				raise_error(TOKEN_TOO_LONG_ERROR);
				return 0;
			}
		} else if (input[i] == ' ' || input[i] == '\n')
			continue;
		else {
			raise_error(SYNTAX_ERROR);
			return 0;
		}
	}

	*token_count = token_index + 1;

	return 1;
}
