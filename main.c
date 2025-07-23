#include "minishell.h"
#include <readline/readline.h>

int ft_strlen(char *s)
{
	int i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
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

void tokanize(char *s, int i)
{
	char *word = NULL;
	int j = 0;
	word = malloc(sizeof(char) * (i + 1));
	while (s[j] && j < i)
	{
		word[j] = s[j];
		j++;
	}
	word[j] = '\0';
	printf("%s\n", word);
}

// the main loop 
// while not delimiter move through the str and collect the word
// once met a delimiter 
// make a word token
// take that delimiter and see it's not \0 or space 
// keep moving through the string until you find another thing that
// doesn't equal that delimiter, for example:
// 	keep collecting them pipes ||||||>
// 	until you hit the redirect output delimiter
// before moving on, make a check for every redirection 
// append, and pipe or heredocc,
// check their length, if not one, then syntax error
// make another token for that if only one proper delimiter is given
//

void pc(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] != '|' && str[i] != '>' && str[i] != '<' && str[i] != ' ')
			i++;
		else
		{
			tokanize(str, i);
			break;
		}
	}
}


/*
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

	int i = 0;
	int buf_len = 0;
	head = NULL;
	while (str[i])
	{
		if (!cut_str(str, i, &head))
		{
			buffer = realloc(buffer, sizeof(char) * (buf_len + 2));
			buffer[i] = str[i];
			buffer[i+1] = '\0';
		}
		else if (!intoken)
		{
			t = ft_newtoken(buffer, T_PIPE);
			new = ft_lstnew(t);
			ft_lstadd_back(&head, new);
		}
		i++;
	}
	print_list(head);
}
*/


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

//
// space
// '\0' null terminator
// operators
// 	append
// 	heredoc
// 	pipe
// 	redirect input
// 	redirect output
 
 * */
