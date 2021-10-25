/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpst <hpst@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:29:54 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/23 11:02:48 by hpst             ###   ########.fr       */
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

bool	ms_pipe_exec(t_job *current)
{
	pid_t	pid;
	//int		status;

	//status = 0;
	(void)current;
	signal(SIGINT, ms_donothing);
	signal(SIGQUIT, ms_donothing);
	ms_saved_fd();
	if (ms_create_pipe() == false)
	{
		perror("Minishell: ");
		return (false);
	}
	pid = fork();
	if (pid == -1)
		return(ms_pid_error());
	return (false);
}
