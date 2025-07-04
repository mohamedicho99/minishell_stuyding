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
// these are the things that i'm going to use as delimiters 
//
// space
// '\0' null terminator
// operators
// 	append
// 	heredoc
// 	pipe
// 	redirect input
// 	redirect output

int is_space(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int is_pipe(char c)
{
	if (c == '|')
		return (1);
	return (0);
}

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

void pc(char *str)
{
	char *buffer; 
	buffer = malloc(sizeof(char));
	buffer[0] = '\0';

	int i = 0;
	int buf_len = 0;
	while (str[i])
	{
		buffer = realloc(buffer, sizeof(char) * (buf_len + 2));
		buffer[i] = str[i];
		buffer[i+1] = '\0';
		printf("buffer content: %s\n", buffer);
		
		// instead of printing this, i need to add it to buffer 
		// keep doing that until i hit a pipe or space
		i++;
	}
	printf("%s", buffer);
	printf("\n");
	exit(0);
}


int main(void)
{
	char *input;
	while (1)
	{
		input = readline("prompt $ ");
		if (!input)
			break;
		//printf("you said: %s\n", input);
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
