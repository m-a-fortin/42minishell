/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:59:07 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/30 13:53:52 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	find_redirection(t_token *token)
{
	while (token)
	{
		if (is_redirection(token))
			return (true);
		token = token->next;
	}
	return (false);
}

int	count_redirections(t_token *token)
{
	int	i;

	i = 0;
	while (token)
	{
		if (token->type == PIPE)
			break ;
		if (is_redirection(token))
		{
			i++;
			if (token->next->type == STRING)
				i++;
			token = token->next->next;
			continue ;
		}
		token = token->next;
	}
	return (i);
}

int	count_cmd_and_args(t_token *token)
{
	int	i;

	i = 0;
	while (token)
	{
		if (token->type == PIPE)
			break ;
		else if (is_redirection(token))
			token = token->next->next;
		else if (token->type == STRING)
			i++;
		if (!token)
			break ;
		token = token->next;
	}
	return (i);
}
