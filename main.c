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
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int is_delimiter(char c)
{
	if (c == '|' || c == ' ' || c == '>' || c == '<')
		return (1);
	return (0);
}

TokenType ret_t_type(char *s)
{
	if (*s == '|')
		return (T_PIPE);
	else if (*s == '>')
		return (T_RED_OUT);
	else if (*s == '<')
		return (T_RED_OUT);
	else
		return (T_WORD);
}

void print_list(t_list *head)
{
	while (head)
	{
		printf("%s is of type %d\n", head->token->str, head->token->type);
		head = head->next;
	}
}

void pc(char *str)
{
	char *buffer; 
	buffer = malloc(sizeof(char));
	buffer[0] = '\0';
	t_list *head;
	Token *t;
	t_list *new;
	int intoken = 0;


	int i = 0;
	int buf_len = 0;
	head = NULL;
	while (str[i])
	{
		if (!cut_str(str, i, &head, &intoken))
		{
			buffer = realloc(buffer, sizeof(char) * (buf_len + 2));
			buffer[i] = str[i];
			buffer[i+1] = '\0';
			intoken = 1;
		}
		if (!intoken)
		{
			intoken = 0;
			t = ft_newtoken(buffer, T_PIPE);
			new = ft_lstnew(t);
			ft_lstadd_back(&head, new);
		}
		i++;
	}
	print_list(head);
}


int main(void)
{
	char *input;
	while (1)
	{
		input = readline("prompt $ ");
		if (!input)
			break;
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
