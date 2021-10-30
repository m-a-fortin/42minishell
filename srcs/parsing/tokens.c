/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:56:43 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/30 13:09:56 by mmondell         ###   ########.fr       */
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

t_token	*tokenize_string(t_parser *par, t_token *token)
{
	token = add_token_to_list(par, token);
	while (token->next)
		token = token->next;
	token->type = STRING;
	return (token);
}

t_token	*tokenize_operator(t_parser *par, t_token *token)
{
	char	op;

	op = index_char(par);
	par->index++;
	if (index_char(par) == op)
		par->index++;
	token = add_token_to_list(par, token);
	if (!token->token)
		token->token = NULL;
	token->type = set_operator_type(token->token);
	return (token);
}
