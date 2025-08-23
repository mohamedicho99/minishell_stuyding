#include "minishell.h"
#include <stdbool.h>

void pipe_syntax_error(t_list *head)
{
	// TODO: handle if pipe is last node
	if (!head)
		return ;
	t_list *cur = head;
	int i = 0;
	TokenType prev_token_type;
	while (cur)
	{
		if (cur->token->type == T_PIPE)
		{
			if (i == 0)
			{	
				printf("[+] syntax error\n");
				printf("{-} pipe cannot be first node\n");
				exit(0);
			}
			if (prev_token_type == T_PIPE)
			{	
				printf("[+] syntax error\n");
				printf("{-} multiple pipes after each other\n");
				exit(0);
			}
			if (!cur->next || cur->next->token->type != T_WORD)
			{
				printf("[+] syntax error\n");
				printf("{-} pipe without next command\n");
				exit(0);
			}
		}
		prev_token_type = cur->token->type;
		i++;
		cur = cur->next; 
	}
}

void redir_syntax_error(t_list *head)
{
	if (!head)
		return ;
	t_list *cur = head;
	TokenType pttype;
	TokenType cttype;
	while (cur)
	{
		cttype = cur->token->type;
		if (cttype == T_RED_OUT || cttype == T_RED_IN || cttype == T_APPEND || cttype == T_HEREDOC)
		{
			if (pttype == T_RED_OUT || pttype == T_RED_IN || pttype == T_APPEND || pttype == T_HEREDOC)
			{
				printf("[+] syntax error\n");
				printf("{-} multiple redirections after each other\n");
				exit(0);
			}
			if (!cur->next || cur->next->token->type != T_WORD)
			{
				printf("[+] syntax error\n");
				printf("{-} redirection without target\n");
				exit(0);
			}
		}
		pttype = cur->token->type;
		cur = cur->next;
	}
}

void syntax_error(t_list *head)
{
	pipe_syntax_error(head);
	redir_syntax_error(head);
}
	

void print_list(t_list *head)
{
	printf("_______________________________________________________\n");
	if (!head)
	{
		printf("error: exiting...\n");
		exit(0);
	}
	while (head)
	{
		printf("%s is of type %d\n", head->token->str, head->token->type);
		head = head->next;
	}
}

void init(t_list **head)
{
	char *input = "echo'sjid'|echo -n";
	//input = "   ls -l | cat file.txt >> here.txt |||||    \"okey \" here\" nice\" right\" word\" something\"\"\"\"   <<<<<<<";
	input = "   echo |    \"okey \" here\" nice\" right\" word\" something\"\"\"\"   > echo << end";
	// TODO: handle these cases
	//input = "   \"\"\"\" ";
	//input = "   ls -l | cat file.txt >> here.txt     \"echo \"\"hello world\"\"\"\"\"\"\"   ";
	tokenize(input, head);
	syntax_error(*head);
}

int main()
{

	t_list *head;
	head = NULL;
	// printf("cmd: %s\n", input);

	init(&head);

	print_list(head);
	return (0);
}
