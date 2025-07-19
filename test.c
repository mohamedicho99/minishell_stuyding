/*
#include "minishell.h"

TokenType ret_t_type(Token *token)
{
	if (strcmp(token->str, "|") == 0)
		return (T_PIPE);
	else if (strcmp(token->str, ">") == 0)
		return (T_RED_OUT);
	else 
		return (T_WORD);
}
// create the token first
// then 
// take that token and add a node to it on the t_list 
// linked list

int main(void)
{
	add_token("echo");
	exit(0);
	Token *test = malloc(sizeof(Token));
	if (!test)
		return (-1);
	test->str = "|";
	test->type = ret_t_type(test);

	printf("type: %d\n", test->type);

	return (0);
}*/
