/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:58:38 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/30 10:57:23 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/token.h"
#include "../../includes/parse.h"

void	change_state(t_parser *par)
{
	if (par->input[par->index] == '\'')
	{
		if (par->state == TEXT)
			par->state = S_QUOTE;
		else if (par->state == S_QUOTE)
			par->state = TEXT;
	}
	else if (par->input[par->index] == '"')
	{
		if (par->state == TEXT)
			par->state = D_QUOTE;
		else if (par->state == D_QUOTE)
			par->state = TEXT;
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
