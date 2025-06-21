#include "minishell.h"
#include <readline/readline.h>

// build these functions
// is operator
// 	is redirect input
// 	is redirect output
// is space
// is pipe
// is null terminator
//

void pc(char *str)
{
	int i = 0;
	while (str[i])
	{
		
		i++;
	}
}


int main(void)
{
	char *input;
	while (1)
	{
		input = readline("prompt $ ");
		if (!input)
			break;
		printf("you said: %s\n", input);
		pc(input);
		if (*input == '\0')
		{
			free(input);
			break;
		}
		free(input);
	}
	return (0);
}


/*

the next step or the next problem to tackle is breaking down the text into 
	tokens and then after that comes the lexing part!

	first we loop through the string somehow until we find any of them already 
		defined tokens! 
	
	we delimit with these, either:
		operator
		redirect input
		redirect output
		pipe
		null terminator
		space

	a pipe , a word , redirect input, redirect output
 
 * */
