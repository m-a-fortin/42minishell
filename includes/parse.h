#ifndef PARSE_H
# define PARSE_H

# define SPACES " \n\t\v\f\r"

typedef enum e_state
{
	TEXT,
	D_QUOTE,
	S_QUOTE,
} t_state;

typedef struct s_parser
{
	char 	*input;
	int 	index;
	t_state state;
} t_parser;

void	parse_input(char *input);
void 	init_parser(t_parser *par, char *input);
bool find_token(t_parser *par);

#endif
