#include "eval.h"
#include <stdlib.h>
#include <string.h>
#include "tokens.h"
#include "operations.h"
#include "errors.h"
#include "config.h"

int eval(char tokens[][MAX_TOKEN_LEN], int *token_count) {
	for (int i = 0; i < *token_count; i++) {
		if (is_operator(tokens[i])) {
			char result_token[MAX_TOKEN_LEN] = {0};
			int left = atoi(tokens[i - 1]);
			int right = atoi(tokens[i + 1]);

			if (strcmp(tokens[i], MULTIPLY) == 0) {
				perform_multiplication(left, right, result_token);
				update_tokens(tokens, token_count, i, result_token);

				return eval(tokens, token_count);
			} else if (strcmp(tokens[i], DIVIDE) == 0) {
				if (right == 0) {
					raise_error(DIVISION_ERROR);
					return 0;
				}

				perform_division(left, right, result_token);
				update_tokens(tokens, token_count, i, result_token);

				return eval(tokens, token_count);
			} else if ((strcmp(tokens[i], ADD) == 0)
						&& !is_near_multiplication_or_division(tokens, *token_count, i)) {
				perform_addition(left, right, result_token);
				update_tokens(tokens, token_count, i, result_token);

				return eval(tokens, token_count);
			} else if ((strcmp(tokens[i], SUBTRACT) == 0)
						&& !is_near_multiplication_or_division(tokens, *token_count, i)) {
				perform_subtraction(left, right, result_token);
				update_tokens(tokens, token_count, i, result_token);

				return eval(tokens, token_count);
			}
		}
	}

	return 1;
}
