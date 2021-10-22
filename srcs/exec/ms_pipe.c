/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:29:54 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/21 14:46:33 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_pipe_redir(void)
{
	g_ms.pipes[0] = 0;
	g_ms.pipes[1] = 1;
}

void	ms_pipe_in(t_job *current)
{
	if (!current->redir)
		ms_pipedup_in();
	else
		ms_pipe_redir();
	//if (ms_check_builtin(current) == false)
	//{
		
	//}
}

void	ms_pipe_out(t_job *current)
{
	(void)current;
}

bool	ms_pipe_exec(t_job *current)
{
	pid_t	pid;

	if (ms_create_pipe(current) == false)
	{
		perror("Minishell: ");
		return (false);
	}
	pid = fork();
	if (pid == -1)
	{
		ms_return_fd();
		ft_putendl_fd("minishell: FATAL: fork error", 1);
		g_ms.exit = 1;
		return (false);
	}
	if (pid == 0)
		ms_pipe_in(current);
	else if (pid > 0)
		ms_pipe_out(current);
	return (false);
}
