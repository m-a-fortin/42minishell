/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:59:07 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/14 10:26:00 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_cmd_and_args(t_token *token)
{
	int	i;

	i = 0;
	while (token->type == STRING)
	{
		if (token->type != STRING)
		
		token = token->next;
		i++;
	}
	return (i);
}
