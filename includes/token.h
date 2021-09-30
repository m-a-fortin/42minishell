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

void 	init_parser(t_parser *par, char *input);
char 	*trim_input(char *input);
bool 	find_token(t_token *token);

#endif
