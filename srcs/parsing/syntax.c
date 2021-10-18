/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 09:56:11 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/18 11:58:04 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	validate_redir(t_token *token)
{
	if (!is_redirection(token))
		return (false);
	if (token->next->token == NULL)
	{
		p_error(SHELL, NULL, UNXP_TOKEN, NEWLINE_TOKEN);
		return (false);
	}
	if (token->next->type != STRING)
	{
		p_error(SHELL, NULL, UNXP_TOKEN, next_token(token));
		return (false);
	}
	else
		return (true);
}

bool	validate_pipe(t_token *token)
{
	if (token->type != PIPE)
		return (false);
	if (token->next == NULL || token->next->type != STRING)
	{
		p_error(SHELL, NULL, UNXP_TOKEN, PIPE_TOKEN);
		return (false);
	}
	else
		return (true);
}

bool	validate_tokens_syntax(t_token *head)
{
	t_token	*token;

	token = head;
	while (token->next)
	{
		if (token->type == STRING)
			token = token->next;
		else if (token->type == PIPE)
		{
			if (!validate_pipe(token))
				return (false);
			token = token->next->next;
		}
		else if (is_redirection(token))
		{
			if (!validate_redir(token))
				return (false);
			token = token->next->next;
		}
	}
	return (true);
}
