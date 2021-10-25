/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pipe_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:30:23 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/25 17:20:15 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ms_pipe_signal(int	status)
{
	if (WIFEXITED(status))
		g_ms.exit = WEXITSTATUS(status);
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGINT)
		{
			ft_putendl_fd("", 1);
			exit (g_ms.exit);
		}
		if (WTERMSIG(status) == SIGQUIT)
			exit (g_ms.exit);
	}
	if (g_ms.exit != 0)
		return (false);
	return (true);
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
