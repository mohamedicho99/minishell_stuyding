#include "minishell.h"

// first, i'll need the struct from the other header file, 
// 	we need to put everything in one header file 
// 		or 
// 	figure out how to map multiple header files in c 
//


// this can either take t_string *str and get the value from it 
// 	pass just the address of that str->str to it
TokenType return_token_type(const char *s)
{
	// we need to check this s if it does even exit somewhere before this
	// function
	if (!s || !*s)
		return (0);
	if (s[0] == '|')
		return (T_PIPE);
	else if (s[0] == '>')
	{
		if (s[1] != '\0' && s[1] == '>')
			return (T_APPEND);
		else
			return (T_RED_OUT);
	}
	else if (s[0] == '<')
	{
		if (s[1] != '\0' && s[1] == '<')
			return (T_HEREDOC);
		else
			return (T_RED_IN);
	}
	return (0);
}

// this file will be used first to test this function,
// only then we will move it to join the rest of the project
// we'll need to move it along with the main file here to the main dir of 
// the project and rename the old main file to something else and keep 
// using it until we're done with it.
int main(void)
{
	char *test = ">>";
	TokenType re = return_token_type(test);
	printf("re: %d\n", re);
	return (0);
}
