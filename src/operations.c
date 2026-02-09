#include "operations.h"
#include <stdio.h>
#include "config.h"

void perform_multiplication(int left, int right, char result_token[]) {
	int result = left * right;
	snprintf(result_token, MAX_TOKEN_LEN, "%d", result);
}

void perform_division(int left, int right, char result_token[]) {
	int result = left / right;
	snprintf(result_token, MAX_TOKEN_LEN, "%d", result);
}

void perform_addition(int left, int right, char result_token[]) {
	int result = left + right;
	snprintf(result_token, MAX_TOKEN_LEN, "%d", result);
}

void perform_subtraction(int left, int right, char result_token[]) {
	int result = left - right;
	snprintf(result_token, MAX_TOKEN_LEN, "%d", result);
}
