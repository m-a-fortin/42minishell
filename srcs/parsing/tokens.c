/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:56:43 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/29 21:27:50 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_closing_quote(t_parser *par, char quote)
{
	int	i;

	i = par->index + 1;
	while (par->input[i])
	{
		if (par->input[i] == quote)
			return (i);
		i++;
	}
	return (-1);
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
	add_token_to_list(par, token);
	if (!token->token)
		token->token = NULL;
	token->type = set_operator_type(token->token);
	return (true);
}
