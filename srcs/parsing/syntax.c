/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 09:56:11 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/05 11:41:38 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	validate_tokens_syntax(t_token *head, t_parser *par)
{
	t_token	*token;

	token = head;
	while (token->next)
	{
		if (token->type == PIPE)
		{
			set_error(token->valid_token);
			return (false);
		}
		if (!valid_command(token) || !valid_text(token))
			return (false);
		token = token->next;
	}
	return (true);
}
