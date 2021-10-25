/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pipe_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:30:23 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/22 12:47:38 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ms_ifredir(char **redir)
{
	int	index;

	index = 0;
	if (!redir)
		return (false);
	while (redir[index])
	{
		if (ft_strncmp(redir[index], ">", 1) == 0)
			return (true);
		index++;
	}
	return (false);
}

int		ms_pipe_number(t_job *job_head)
{
	int	nb;
	t_job *node;

	nb = 0;
	node = job_head;
	if (!node->next)
		return (0);
	while (node->next)
	{
		nb++;
		node = node->next;
	}
	return (nb);
}
