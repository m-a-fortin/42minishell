/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_sign2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:21:59 by mafortin          #+#    #+#             */
/*   Updated: 2021/11/01 15:11:42 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_job	*dollarsign_redir(t_job *current)
{
	int	index;

	index = 0;
	if (current->redir)
	{
		while (current->redir[index])
		{
			if (current->redir[index][0])
				current->redir[index] = dollarsign_loop(current->redir[index]);
			index++;
		}
	}
	return (current);
}
