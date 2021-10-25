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

void	ms_pipedup_in(void)
{
	close(g_ms.pipes[0]);
	dup2(g_ms.pipes[1], 1);
	close(g_ms.pipes[1]);
}

void	ms_pipedup_out(void)
{
	close(g_ms.pipes[1]);
	dup2(g_ms.pipes[0], 0);
	close(g_ms.pipes[0]);
}

bool	ms_create_pipe(void)
{
	if (pipe(g_ms.pipes) == -1)
		return (false);
	return (true);
}

void	ms_pipe_redir(void)
{
	close(g_ms.pipes[0]);
	close(g_ms.pipes[1]);
}

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