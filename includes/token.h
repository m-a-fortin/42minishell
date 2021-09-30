#ifndef TOKEN_H
#define TOKEN_H

# define OPERATORS "<>|$="

typedef enum e_type
{
	PIPE,
	OUTPUT,
	INPUT,
	HEREDOC,
	STRING,
	APPEND,
} t_type;

typedef struct s_token
{
	char 			*valid_token;
	t_type 			type;
	struct s_valid 	*next;
} t_token;

char 	*trim_input(char *input);

#endif
