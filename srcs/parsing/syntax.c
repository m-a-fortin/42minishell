/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 09:56:11 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/06 16:35:55 by mmondell         ###   ########.fr       */
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
			print_error(NAME, UNXP_TOKEN_PIPE);
			return (false);
		}
		//if (!validate_command(token) || !validate_redir(token))
		//	return (false);
		token = token->next;
	}
	return (true);
}
