/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:29:54 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/21 13:10:31 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_pipedup_in(void)
{
	close(g_ms.pipes[0]);
	dup2(g_ms.pipes[1], g_ms.stdout);
	close(g_ms.pipes[1]);
}

void	ms_pipedup_out(void)
{
	close(g_ms.pipes[1]);
	dup2(g_ms.pipes[0], g_ms.stdin);
	close(g_ms.pipes[0]);
}

bool	ms_create_pipe(t_job *current)
{
	if (current->next == NULL)
		return (true);
	if (pipe(g_ms.pipes) == -1)
		return (false);
	return (true);
}

bool	ms_pipe_exec(t_job *current)
{
	(void)current;
	return (false);
}
