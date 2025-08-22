#include "minishell.h"

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
	//input = "   \"\"\"\" ";
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
