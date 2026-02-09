#include <stdio.h>
#include "parse.h"
#include "eval.h"
#include "config.h"

int main(int argc, char *argv[]) {
	if (argc > 2) {
		fprintf(stderr, "Too many arguments");
		return 1;
	} else if (argc == 2) {
		char tokens[MAX_TOKENS][MAX_TOKEN_LEN] = {0};
		int token_count = 0;

		if (!parse(argv[1], tokens, &token_count))
			return 1;

		if (!eval(tokens, &token_count))
			return 1;

		printf("%s\n", tokens[0]);

		return 0;
	} else {
		while (1) {
			char input[MAX_INPUT_LEN];

			if (fgets(input, sizeof(input), stdin)) {
				char tokens[MAX_TOKENS][MAX_TOKEN_LEN] = {0};
				int token_count = 0;

				if (parse(input, tokens, &token_count)) {
					eval(tokens, &token_count);
				}

				printf("%s\n", tokens[0]);
			} else {
				return 1;
			}

		}
	}

	return 0;
}
