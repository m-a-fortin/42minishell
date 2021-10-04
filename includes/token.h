#ifndef TOKEN_H
#define TOKEN_H

# define OPERATORS "<>|"

typedef enum e_type
{
	PIPE,
	R_HDOC,
	L_HDOC,
	R_REDIR,
	L_REDIR,
	STRING,
	VARIABLE,
	EMPTY,
} t_type;

typedef struct s_token
{
	char			*valid_token;
	t_type 			type;
	struct s_token 	*next;
} t_token;


/* LIST UTILITIES */

t_token	*token_lst_last(t_token *token);
t_token *token_lst_addnew(void	*valid_token);
void	token_lst_addback(t_token **token, t_token *new);


#endif
