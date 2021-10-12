/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:05:36 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/12 18:11:07 by mmondell         ###   ########.fr       */
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

int		find_closing_quote(t_parser *par, char quote);
char	*trim_input(char *input);
void	init_parser(t_parser *par, char *input);
bool	parse_input(char *input);
bool	find_token(t_parser *par, t_token *token);
bool	tokenize_string(t_parser *par, t_token *token);
bool	tokenize_operator(t_parser *par, t_token *token);
bool	validate_tokens_syntax(t_token *head);
void	add_token_to_list(t_parser *par, t_token *token);



/* PARSE UTILITIES */

int		token_length(t_parser *par);
char	index_char(t_parser *par);
void	reset_parser(t_parser *par, char *input);
void	check_state(t_parser *par, int index);
bool	input_is_not_empty(char *input);

#endif
