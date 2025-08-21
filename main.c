#include "minishell.h"

t_string *ft_newstr(char *s)
{
	t_string	*new;
	int			len;

	new = malloc(sizeof(t_string));
	if (!new)
		return (NULL);
	len = strlen(s);
	new->str = malloc(sizeof(char) * (len + 1));
	if (!new->str)
	{
		free(new);
		return (NULL);
	}
	ft_memcpy(new->str, s, len);
	new->str[len] = '\0';
	new->cap = len + 1;
	new->len = len;
	return (new);
}


char *tokanize_word(t_string *str)
{
	int len;
	char *s;

	s = NULL;
	str->start = str->peek;
	str->end = str->peek;
	while (str->peek < str->len && !is_delimiter(str->str[str->peek]))
	{
		str->end++;
		str->peek++;
	}
	len = str->end - str->start;
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	ft_memcpy(s, str->str + str->start, len);
	s[len] = '\0';
	return (s);
}

char *create_quote_word(t_string *str)
{
	int len;
	char *s;

	s = NULL;
	str->peek++;
	str->start = str->peek;
	str->end = str->peek;
	while (str->peek < str->len && str->str[str->peek] != str->quote)
	{
		str->end++;
		str->peek++;
	}
	len = str->end - str->start;
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	ft_memcpy(s, str->str + str->start, len);
	s[len] = '\0';
	str->peek++;
	return (s);
}

char	*collect_delimiter(t_string *str)
{
	int len;
	char *s;

	s = NULL;
	str->del = str->str[str->peek];
	str->start = str->peek;
	str->end = str->peek;
	while ((str->peek < str->len) && (str->str[str->peek] == str->del))
	{
		str->peek++;
		str->end++;
	}
	len = str->end - str->start;
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	ft_memcpy(s, str->str + str->start, len);
	s[len] = '\0';
	return (s);
}

void create_token_node(t_list **head, char *s)
{
	Token *token;
	t_list *new;
	TokenType t_type;

	t_type = return_token_type(s);
	token = ft_newtoken(s, t_type);
	new = ft_lstnew(token);
	ft_lstadd_back(head, new);
}

void handle_delimiter(t_string *str, t_list **head)
{
	char *word;
	char *delimiter;

	word = NULL;
	delimiter = NULL;
	if (str->str[str->peek] == '"' || str->str[str->peek] == '\'')
	{
		str->quote = str->str[str->peek];
		word = create_quote_word(str);
		if (word)
			create_token_node(head, word);
	}
	else
	{
		delimiter = collect_delimiter(str);
		if (delimiter)
			create_token_node(head, delimiter);
	}
}

void pc(t_string *str, t_list **head)
{
	char *s = NULL;
	while (str->str[str->peek] == ' ')
		str->peek++;
	while (str->peek < str->len)
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

void set_def(t_string *str)
{
	str->start = 0;
	str->end = 0;
	str->peek = 0;
	str->del = '\0';
	str->quote = '\0';
	str->q_pos = 0;
	str->w_q_len = 0;
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

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);

	t_list *head;
	head = NULL;
	char *input = "   ls -l | cat file.txt >><here.txt |||||    echo \'hello world\'   \"karim is here\"<<<<<<<";
	input = argv[1];
	input = "   ls -l | cat file.txt >> here.txt |||||    \"okey \" here\" nice\" right\" word\" something\"\"\"\"   <<<<<<<";
	input = "   \"\"\"\" ";
	//char *input = "   ls -l | cat file.txt >><here.txt |||||    echo \"hello world\"   \"karim is here\"<<<<<<<";
	//input = " echo \"hello world\" c <<<<<>";
	//input = "   echo \"hello world\"   \"karim is here\"<<<<<<< ls -l || cat file.txt >><here.txt |||||    ";
	printf("cmd: %s\n", input);
	//char *input = "   ls -l | cat file.txt >> here.txt |||||    echo \"hello world\"   <<<<<<<";
	//char *input = "   ls -l | cat file.txt >> here.txt |||||    \"echo\"\"hello world\"\"\"\"\"\"\"   <<<<<<<";

	t_string *str = ft_newstr(input);
	set_def(str);

	pc(str, &head);

	print_list(head);
	return (0);
}
//you should legit ask about how to handle this thing
