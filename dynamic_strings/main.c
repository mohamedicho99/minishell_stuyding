#include "libft.h"
#include <string.h>

t_string *ft_newstr(char *s)
{
	t_string *new;

	new = malloc(sizeof(t_string));
	if (!new)
		return (NULL);
	int len = strlen(s);
	new->str = malloc(sizeof(char) * (len + 1));
	if (!new->str)
	{
		free(new);
		return (NULL);
	}
	int i = 0;
	while (s[i])
	{
		new->str[i] = s[i];
		i++;
	}
	new->str[i] = '\0';
	new->cap = len + 1;
	new->len = strlen(new->str);

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
	int i = 0;
	str->start = str->peek;
	str->end = str->peek;
	i = str->peek;
	while (i < str->len && !is_delimiter(str->str[i]))
	{
		str->end++;
		str->peek++;
		i++;
	}
	int len = str->end - str->start + 1;
	//printf("len: %d\n", len);
	char *s = malloc(sizeof(char) * len);
	if (!s)
		return (NULL);
	i = str->start;
	int j = 0;
	while (i < str->end)
	{
		s[j] = str->str[i];
		i++;
		j++;
	}
	s[j] = '\0';
	return (s);
}

void pc(t_string *str)
{
	int i = 0;
	char *s;
	s = NULL;
	while (str->str[i] == ' ')
		str->peek = ++i;
	while (i < str->len)
	{
		if (str->str[i] == ' ')
		{
			i++;
			str->peek++;
			continue ;
		}
		s = tokanize_word(str);
		printf("%s\n", s);
		i++;
	}
	exit(0);
}

void set_def(t_string *str)
{
	str->start = 0;
	str->end = 0;
	str->peek = 0;
}

int main(void)
{
	char *input = "   ls -l | cat file.txt >> here.txt   ";

	t_string *str = ft_newstr(input);
	set_def(str);

	pc(str);
	return (0);
}
