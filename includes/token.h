#ifndef TOKEN_H
#define TOKEN_H

# define OPERATORS ""
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
	char 		*input;
	int 		index;
	t_state 	state;
} t_token;


void	init_tokens(t_token *token, char *input);
char	*trim_input(t_token *token, char *input);
bool 	find_token(t_token *token);

#endif
