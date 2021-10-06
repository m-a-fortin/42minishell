/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 09:56:11 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/06 10:27:53 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	validate_tokens_syntax(t_token *head)
{
	t_token	*token;

	token = head;
	while (token->next)
	{
		if (token->type == PIPE)
		{
			print_error(NAME, UNXP_TOKEN_PIPE, BAD_SYNTAX);
			return (false);
		}
		//if (!validate_command(token) || !validate_redir(token))
		//	return (false);
		token = token->next;
	}
	return (true);
}
