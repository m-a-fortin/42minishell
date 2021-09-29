#ifndef TOKEN_H
#define TOKEN_H

typedef enum e_type
{
	PIPE,
	OUTPUT,
	INPUT,
	HEREDOC,
	STRING,
	APPEND,
} t_type;

typedef enum e_state
{
	TEXT,
	D_QUOTE,
	S_QUOTE,
} t_state;

typedef struct s_token
{
	char *input;
	int pos;
	t_state state;
} t_token;

#endif
