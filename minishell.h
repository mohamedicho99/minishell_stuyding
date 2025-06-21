#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum
{
	T_WORD,
	T_PIPE,
	T_RED,
} TokenType;

typedef struct
{
	char *str;
	TokenType type;
} Token;


#endif