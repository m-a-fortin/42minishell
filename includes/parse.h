/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:05:36 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/13 15:25:28 by mmondell         ###   ########.fr       */
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

t_job	*parse_input(char *input, t_job *job_head);
int		find_closing_quote(t_parser *par, char quote);
char	*trim_input(char *input);
void	init_parser(t_parser *par, char *input);
bool	find_token(t_parser *par, t_token *token);
bool	tokenize_string(t_parser *par, t_token *token);
bool	tokenize_operator(t_parser *par, t_token *token);
bool	validate_tokens_syntax(t_token *head);
void	add_token_to_list(t_parser *par, t_token *token);
t_job	*build_job(t_token *token, t_job *job);



/* PARSE UTILITIES */

int		token_length(t_parser *par);
char	index_char(t_parser *par);
void	reset_parser(t_parser *par, char *input);
void	check_state(t_parser *par, int index);
bool	input_is_not_empty(char *input);
int		count_string_nodes(t_token *token);

#endif
