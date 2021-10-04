/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 21:59:24 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/04 12:30:45 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*token_lst_last(t_token *token)
{
	while (token)
	{
		if (token->next == NULL)
			return (token);
		token = token->next;
	}
	return (token);
}

void	token_lst_addback(t_token **token, t_token *new)
{
	t_token	*last;

	if (token)
	{
		if (*token)
		{
			last = token_lst_last(*token);
			last->next = new;
		}
		else
			*token = new;
	}
}

t_token *token_lst_addnew(void	*valid_token)
{
	t_token	*new;

	new = ft_calloc(1, sizeof(t_token));
	if (!new)
		return (NULL);
	new->valid_token = valid_token;
	new->type = STRING;
	new->next = NULL;
	return (new);
}
