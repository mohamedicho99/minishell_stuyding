#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <readline/readline.h>

typedef enum
{
	T_WORD,
	T_PIPE,
	T_RED_IN,
	T_RED_OUT,
	T_APPEND,
	T_HEREDOC
} TokenType;

typedef struct
{
	char *str;
	TokenType type;
} Token;

typedef struct list
{
	Token 		*token;
	struct list	*next;
}	t_list;


typedef struct
{
	char *str;
	char del;
	int len;
	int cap;
	int start;
	int end;
	int peek;
	char quote;
	int q_pos;
	int w_q_len;
} t_string;

void *ft_memcpy(void *dest, void *src, int n);
Token *ft_newtoken(char *s, TokenType type);
t_list *ft_lstnew(Token *token);
void	ft_lstadd_back(t_list **head, t_list *new);
t_list *ft_lstlast(t_list *lst);
TokenType return_token_type(const char *s);
int is_delimiter(char c);
TokenType return_token_type(const char *s);
Token *ft_newtoken(char *s, TokenType type);
Token *ft_newtoken(char *s, TokenType type);
t_list *ft_lstnew(Token *token);
t_list *ft_lstlast(t_list *lst);
void ft_lstadd_back(t_list **head, t_list *new);

#endif
