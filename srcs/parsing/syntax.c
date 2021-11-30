/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 09:56:11 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/30 10:08:35 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	validate_redir(t_token *token)
{
	if (!is_redirection(token))
		return (false);
	if (!token->next)
		return (p_error(SHELL, NULL, UNXP_TOKEN, NEWLINE_TOKEN));
	if (token->next->type != STRING)
		return (p_error(SHELL, NULL, UNXP_TOKEN, next_token(token)));
	else
		return (true);
}

bool	validate_pipe(t_token *token)
{
	if (token->type != PIPE)
		return (false);
	while (token)
	{
		if (!token->next || !token->prev)
			return (p_error(SHELL, NULL, UNXP_TOKEN, PIPE_TOKEN));
		else if (token->next->type == STRING || is_redirection(token->next))
			return (true);
		else if (!token->next->next)
			return (p_error(SHELL, NULL, UNXP_TOKEN, NEWLINE_TOKEN));
		token = token->next;
	}
	return (false);
}

bool	validate_tokens_syntax(t_token *head)
{
	t_token	*token;

	token = head;
	while (token)
	{
		if (token->type == STRING)
			token = token->next;
		else if (token->type != STRING)
		{
			if (validate_pipe(token) || validate_redir(token))
				token = token->next;
			else
			{
				g_ms.exit = BAD_SYNTAX;
				free_list(head);
				return (false);
			}
		}
	}
	return (true);
}
