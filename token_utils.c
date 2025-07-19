#include "minishell.h"

int cut_str(char *str, int i, t_list **head, int *intoken)
{
	char *buffer;
	Token *t;
	t_list *new;
	if (str[i] == '|')
	{
		buffer = malloc(sizeof(char) * 2);
		buffer[0] = '|';
		buffer[1] = '\0';
		t = ft_newtoken(buffer, T_PIPE);
		new = ft_lstnew(t);
		ft_lstadd_back(head, new);
		return (1);
	}
	*intoken = 0;
	return (0);
}

Token *ft_newtoken(char *s, TokenType type)
{
	Token *new;
	if (!s)
		return (NULL);
	// look more into this
	new = malloc(sizeof(Token));
	if (!new)
		return (NULL);
	// there's a complication of this s! 
	// when did i allocate it 
	// when should i free it? and how can i do that? 
	new->str = s;
	new->type = type;

	return (new);
}

t_list *ft_lstnew(Token *token)
{
	t_list *new;

	if (!token)
		return (NULL);

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->token = token;
	new->next = NULL;

	return (new);
}

t_list *ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void ft_lstadd_back(t_list **head, t_list *new)
{
	t_list *last;

	last = NULL;
	if (!head || !new)
		return ;

	if (!*head)
	{
		*head = new;
		return ;
	}
	last = ft_lstlast(*head);
	last->next = new;
}
/*
int main(void)
{
	char *cmd = "echo";
	Token *here = ft_newtoken(cmd, T_WORD);

	t_list *new = ft_lstnew(here);
	printf("%s is %d\n", new->token->str, new->token->type);

	return (0);
}
*/
