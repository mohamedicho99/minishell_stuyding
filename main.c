#include "minishell.h"
#include <stdbool.h>

void add_token(t_list **head, char *str, TokenType type)
{
	t_list *node = malloc(sizeof(t_list));
	node->token = malloc(sizeof(Token));
	node->token->type = type;
	node->token->str = str;
	node->next = NULL;
	ft_lstadd_back(head, node);
}


char *extract_word(char **p, int size)
{
	char *string = malloc((size + 1) * sizeof(char));
	ft_memcpy(string, *p, size);
	string[size] = '\0';
	*p += size;
	return string;
}

bool tokenize_word(char **p, t_list **head)
{
	char in_quote = '\0';
	char *str = *p;
	while (*str)
	{
		if (!in_quote && (*str == '"' || *str == '\''))
			in_quote = *str;
		else if (*str == in_quote)
			in_quote = '\0';
		else if (!in_quote && strchr("><| \t", *str))
			break;
		str++;
	}
	int size = str - *p;
	if (size <= 0)
		return false;
	add_token(head, extract_word(p, size), T_WORD);
	return true;
}

bool tokenize_metachar(char **str, t_list **head)
{
	if ((*str)[0] == '|')
		return ((*str)++, add_token(head, NULL, T_PIPE), true);
	if ((*str)[0] == '>' && (*str)[1] == '>')
		return (*str+=2, add_token(head, NULL, T_APPEND), true);
	if ((*str)[0] == '<' && (*str)[1] == '<')
		return (*str+=2, add_token(head, NULL, T_HEREDOC), true);
	if ((*str)[0] == '>')
		return ((*str)++, add_token(head, NULL, T_RED_OUT), true);
	if ((*str)[0] == '<')
		return ((*str)++, add_token(head, NULL, T_RED_IN), true);
	return false;
}

void tokenize(char *str, t_list **head)
{
	while (str && *str)
	{
		while (*str == ' ' || *str == '\t') str++;
		if (tokenize_word(&str, head))
		{ }
	  	else if (tokenize_metachar(&str, head))
		{ }
	}
}

void syntax_error(t_list *head)
{
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
		}
		prev_token_type = cur->token->type;
		i++;
		cur = cur->next; 
	}
}
	

/*
void *random() 
{
	{
		if (str->str[str->peek] == ' ')
		{
			str->peek++;
			continue ;
		}
		if (is_delimiter(str->str[str->peek]) && str->str[str->peek] != ' ')
			handle_delimiter(str, head);
		else
		{
			s = tokanize_word(str);
			create_token_node(head, s);
		}
	}
}
*/
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

int main()
{
	// if (argc != 2)
		// return (1);

	t_list *head;
	head = NULL;
	// char *input = "   ls -l | cat file.txt >><here.txt |||||    echo \'hello world\'   \"karim is here\"<<<<<<<";
	// input = argv[1];
	//input = "   \"\"\"\" ";
	//char *input = "   ls -l | cat file.txt >><here.txt |||||    echo \"hello world\"   \"karim is here\"<<<<<<<";
	//input = " echo \"hello world\" c <<<<<>";
	//input = "   echo \"hello world\"   \"karim is here\"<<<<<<< ls -l || cat file.txt >><here.txt |||||    ";
	// printf("cmd: %s\n", input);
	//char *input = "   ls -l | cat file.txt >> here.txt |||||    echo \"hello world\"   <<<<<<<";
	//char *input = "   ls -l | cat file.txt >> here.txt |||||    \"echo\"\"hello world\"\"\"\"\"\"\"   <<<<<<<";

	/*
	t_string *str = ft_newstr(input);
	set_def(str);
	*/
	//char tokenize(char *str, t_list **head)
	char *input = "echo'sjid'|echo -n";
	input = "   ls -l | cat file.txt >> here.txt |||||    \"okey \" here\" nice\" right\" word\" something\"\"\"\"   <<<<<<<";
	tokenize(input, &head);
	syntax_error(head);

	print_list(head);
	return (0);
}
//you should legit ask about how to handle this thing
//o
