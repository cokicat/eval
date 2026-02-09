#ifndef PARSE_H
#define PARSE_H

#include "config.h"

int validate(char *input);
int parse(char input[], char tokens[][MAX_TOKEN_LEN], int *token_count);

#endif
