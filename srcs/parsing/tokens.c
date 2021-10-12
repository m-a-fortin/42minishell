/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:56:43 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/12 18:12:42 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_closing_quote(t_parser *par, char quote)
{
	int	i;

	i = par->index;
	while (par->input[i])
	{
		if (par->input[i] == quote)
			return (i);
	}
	return (0);
}	

bool	tokenize_string(t_parser *par, t_token *token)
{
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
