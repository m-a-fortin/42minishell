/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:56:43 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/12 10:40:19 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	closing_quotes(t_parser *par)
{
	int	i;

	i = 0;
	while (par->input[i])
	{
		if (ft_strchr(QUOTES, par->input[i]))
			change_state(par, i);
		i++;
	}
	return (par->state == TEXT);
}

bool	tokenize_string(t_parser *par, t_token *token)
{
	if (!closing_quotes(par))
	{
		bad_quotes_syntax(par);
		return (false);
	}
	add_token_to_list(par, token);
	token->type = STRING;
	return (true);
}

bool	tokenize_operator(t_parser *par, t_token *token)
{
	char	op;

	op = index_char(par);
	par->index++;
	if (index_char(par) == op)
		par->index++;
	if (!token->valid_token)
		token->valid_token = NULL;
	add_token_to_list(par, token);
	token->type = set_operator_type(token->valid_token);
	return (true);
}
