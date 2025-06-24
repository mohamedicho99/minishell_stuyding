#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum
{
	T_WORD,
	T_PIPE,
	T_RED_IN,
	T_RED_OUT,
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

#endif


// before i hit the delimiter 
// keep buffering
//
// challeges are:
// 	:q
//
// after i hit the delimiter 