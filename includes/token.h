#ifndef TOKEN_H
#define TOKEN_H

# define OPERATORS "<>|$="

typedef enum e_type
{
	PIPE,
	R_HDOC,
	L_HDOC,
	R_REDIR,
	L_REDIR,
	STRING,
	EMPTY,
} t_type;

typedef struct s_token
{
	char			*valid_token;
	t_type 			type;
	struct s_token 	*next;
} t_token;

char 	*trim_input(char *input);
bool	tokenize_operator(t_parser *par, t_token *token)

#endif
