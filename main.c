#include "minishell.h"
#include <readline/readline.h>



/* flag = 0;
 *     "ls"       -l  >>>>>>>>> out | "cat  | "      0
 * while is space = skip
 * {text = ls / type = word }
 * {text = -l / type = word}
 * {text = >>>>>>>> / type = redirect_app}
 * {text = out / type = word}
 * {text = | / type = pipe}
 * {text = cat   |  / type = word}
 * */



int ft_strlen(char *s)
{
	int i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void print_list(t_list *head)
{
	while (head)
	{
		printf("%s is of type %d\n", head->token->str, head->token->type);
		head = head->next;
	}
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

void tokanize_word(char *s, int i, int j, t_list **head)
{
	int		len;
	char	*word;
	t_list	*new;
	Token	*token;

	len = i - j;
	word = malloc(sizeof(char) * (len + 1));
	j = 0;
	while (s[j] && j < len)
	{
		word[j] = s[j];
		j++;
	}
	word[j] = '\0';

	token = ft_newtoken(word, T_WORD);
	new = ft_lstnew(token);
	ft_lstadd_back(head, new);
	return ;
}

int is_delimiter(char c)
{
	if (c == '|' || c == '>' || c == '<' || c == ' ' || c == '\0')
		return (1);
	return (0);
}

void pc(char *str)
{
	int i = 0;
	int j = 0;
	t_list *head;
	head = NULL;

	while (str[i])
	{
		if (!is_delimiter(str[i]))
			i++;
		else if (is_delimiter(str[i]))
		{
			// save the value of str[i], example: str[i] = '|'
			// continue reading until you find anything that doesn't equal pipe
			tokanize_word(str, i, j, &head);
			j = ++i;
			/*
			c = str[i];
			while (str[j] && str[j] == c)
				j++;
			tokanize_del(str, c, i, j, &head);
			i += j;
			*/
		}
		tokanize_word(str, i, j, &head);
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

// space
// '\0' null terminator
// operators
// 	append
// 	heredoc
// 	pipe
// 	redirect input
// 	redirect output
