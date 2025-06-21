#include "minishell.h"

TokenType ret_t_type(Token *token)
{
	if (strcmp(token->str, "|") == 0)
		return (T_PIPE);
	else if (strcmp(token->str, ">") == 0)
		return (T_RED);
	else 
		return (T_WORD);
}

int main(void)
{
	Token *test = malloc(sizeof(Token));
	if (!test)
		return (-1);
	test->str = "|";
	test->type = ret_t_type(test);

	printf("type: %d\n", test->type);

	return (0);
}