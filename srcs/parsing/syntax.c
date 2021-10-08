/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 09:56:11 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/07 19:35:56 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	validate_redir(t_token *token)
{
	if (token->next->type != STRING)
	{
		p_error(SHELL, NULL, UNXP_TOKEN, token->next->valid_token, BAD_SYNTAX);
		return (false);
	}
	if (token->next == NULL)
	{
		p_error(SHELL, NULL, UNXP_TOKEN, NEWLINE_TOKEN, BAD_SYNTAX);
		return (false);
	}
	else
	{
		token = token->next->next;
		return (true);
	}
}

bool	validate_pipe(t_token *token)
{
	if (token->next == NULL)
	{
		p_error(SHELL, NULL, UNXP_TOKEN, PIPE_TOKEN, BAD_SYNTAX);
		return (false);
	}
}

bool	validate_cmd(t_token *token)
{
	if (token->next->type != STRING)
		return (false);
	token = token->next->next;
	return (true);
}

bool	validate_tokens_syntax(t_token *head)
{
	t_token	*token;

	token = head;
	while (token)
	{
		if (token->type == PIPE)
			if (!validate_pipe(token))
				return (false);
		else if (token->type == redirection(token))
			if (!validate_redir(token))
				return (false);
		else if (token->type == STRING)
			if (!validate_cmd(token))
				return (false);
	}
	return (true);
}
