#include "libft.h"
#include <string.h>

void *ft_memcpy(void *dest, void *src, int n)
{
	unsigned const char *s;
	unsigned char *d;

	d = (unsigned char *)dest;
	s = (unsigned const char *)src;

	while (n--)
		*d++ = *s++;
	return (dest);
}

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

int is_delimiter(char c)
{
	if (c == '"' || c == ' ' || c == '|' || c == '>' || c == '<')
		return (1);
	return (0);
}

//char *input = "   ls -l | cat file.txt >> here.txt   ";
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

// this function should start from str->q_pos 
// and keep moving inside str->str until w_q_len
char *tokanize_inside_quote(t_string *str)
{
	// maybe this function is the one causing the mess
	// the indexing here is the problem maybe
	char *s = malloc(sizeof(char) * (str->w_q_len + 1));
	if (!s)
		return NULL;
	ft_memcpy(s, str->str + str->q_pos + 1, str->w_q_len);
	s[str->w_q_len] = '\0';
	// or maybe add that 2 only under a condition
	str->peek += str->w_q_len; // + 2
	return (s);
}

void handle_quote(t_string *str)
{
	char *s;

	s = NULL;
	str->w_q_len = str->peek;
	str->q_pos = str->peek;
	while (str->w_q_len + 1 < str->len && str->str[str->w_q_len + 1] != str->quote)
		str->w_q_len++;

	str->w_q_len -= str->q_pos;
	//printf("l: %d\n", str->w_q_len);
	s = tokanize_inside_quote(str);
	printf("s: %s\n", s);
}

void collect_delimiter(t_string *str)
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
		return ;
	ft_memcpy(s, str->str + str->start, len);
	s[len] = '\0';
	printf("d: %s\n", s);
}
void pc(t_string *str)
{
	char *s;
	s = NULL;
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
		{
			if (str->str[str->peek] == '"')
			{
				if (str->quote == '\0')
				{
					str->quote = '"';
					handle_quote(str);
				}
				else
				{
					str->quote = '\0';
					//str->peek++;
				}
			}
			if (str->str[str->peek] == ' ')
			{
				str->peek++;
				continue ;
			}
			collect_delimiter(str);
			continue ;
		}
		else
		{
			s = tokanize_word(str);
			printf("s: %s\n", s);
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

int main(void)
{
	char *input = "   ls -l | cat file.txt >><here.txt |||||    echo \"hello world\"   \"karim is here\"<<<<<<<";
	input = "c <<<<<>";
	printf("\"%s\"\n", input);
	//char *input = "   ls -l | cat file.txt >> here.txt |||||    echo \"hello world\"   <<<<<<<";
	//char *input = "   ls -l | cat file.txt >> here.txt |||||    \"echo\"\"hello world\"\"\"\"\"\"\"   <<<<<<<";

	t_string *str = ft_newstr(input);
	set_def(str);

	pc(str);
	return (0);
}
//"   ls -l | cat file.txt >> here.txt   ";
//start creating tokens
//if just word , add word
//if delim, check if it's what you want , keep adding them until you find
//another thing other than that value!
//you can add it to the struct as last delim found,
//it can either be 0 or any of these > | < " '
//
//test examples 
//find the most complex  valid command 
//	this one should pass
//find the most complex unvalid command 
//	this one should not pass
//
//
//
//	what happens in this case
//char *input = "   ls -l | cat file.txt >> here.txt |||||    \"\"\"\"\"\"\"\"\"\"   <<<<<<<";
//you should legit ask about how to handle this thing
