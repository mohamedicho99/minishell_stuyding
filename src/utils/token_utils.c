#include "minishell.h"

Token *ft_newtoken(char *s, TokenType type)
{
	Token *new;
	if (!s)
		return (NULL);
	new = malloc(sizeof(Token));
	if (!new)
		return (NULL);
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
