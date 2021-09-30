/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:58:38 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/30 08:56:56 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "token.h"

void	change_state(t_token *token)
{
	if (token->input[token->index] == '\'')
	{
		if (token->state == TEXT)
			token->state = S_QUOTE;
		else if (token->state == S_QUOTE)
			token->state = TEXT;
	}
	else if (token->input[token->index] == '"')
	{
		if (token->state == TEXT)
			token->state = D_QUOTE;
		else if (token->state == D_QUOTE)
			token->state = TEXT;
	}
}

bool	ft_isoperator(char *op, int	c)
{
	int	i;

	i = 0;
	while (op[i])
	{
		if (c == op[i++])
			return (true);
	}
	return (false);
}
