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
	int len = str->end - str->start;
	char *s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	i = str->start;
	ft_memcpy(s, str->str + str->start, len);
	s[len] = '\0';
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
			str->peek = ++i;
			continue ;
		}
		if (is_delimiter(str->str[i]) && str->str[i] != ' ')
		{
			//printf("d: %c\n", str->str[i]);
			++i;
			continue ;
		}
		s = tokanize_word(str);
		printf("s: %s\n", s);
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
