/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:05:36 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/18 17:08:40 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# define SPACES " \n\t\v\f\r"
# define QUOTES "\"\'"

typedef enum e_state
{
	TEXT,
	D_QUOTE,
	S_QUOTE,
}	t_state;

typedef struct s_parser
{
	char	*input;
	int		index;
	t_state	state;
}	t_parser;

typedef struct	s_dollar
{
	char	*new_string;
	char	*name;
	char	*value;
	int		index;
	int		found;
}	t_dollar;

typedef struct s_job t_job;
int		find_closing_quote(t_parser *par, char quote);
char	*trim_input(char *input);
void	init_parser(t_parser *par, char *input);
bool	find_token(t_parser *par, t_token *token);
bool	tokenize_string(t_parser *par, t_token *token);
bool	tokenize_operator(t_parser *par, t_token *token);
bool	validate_tokens_syntax(t_token *head);
void	add_token_to_list(t_parser *par, t_token *token);
t_job	*parse_input(char *input, t_job *job_head);
t_job	*build_job(t_token *token_head, t_job *job_head);
t_job	*parse_input(char *input, t_job *job_head);

void	dollarsign_main(t_job *current);

/* PARSE UTILITIES */

int			token_length(t_parser *par);
char		index_char(t_parser *par);
char		*reset_parser(t_parser *par, char *input);
void		check_state(t_parser *par, int index);
bool		input_is_not_empty(char *input);
void		dollarstruct_init(t_dollar *d_sign);
void		dollarsign_free(t_dollar *d_sign);
int			count_redirections(t_token *token);
int			count_cmd_and_args(t_token *token);
t_dollar	*dollarsign_name(char *string, t_dollar *d_sign);
void		update_quotestatus(char type);
void		trimquotes_main(t_job *current);

#endif
