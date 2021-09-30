#ifndef PARSE_H
# define PARSE_H

# define SPACES " \n\t\v\f\r"

typedef enum e_state
{
	TEXT,
	D_QUOTE,
	S_QUOTE,
} t_state;

typedef struct s_valid
{
	char *valid_token;
	struct s_valid *next;
} t_valid;

void	parse_input(char *input);

#endif
