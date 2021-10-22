/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:29:54 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/22 12:49:45 by mafortin         ###   ########.fr       */
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

void	ms_pipe_in(t_job *current)
{
	if (ms_ifredir(current->redir) == false)
		ms_pipedup_in();
	else
		ms_pipe_redir();
	if (ms_check_builtin(current) == false)
		ms_fork(current->cmd);
}

void	ms_pipe_out(t_job *current, pid_t pid)
{
	int	status;
	int	fd;

	waitpid(pid, &status, 0);
	if (fd < 0)
		px_error_fd(infos, fd);
	dup2(fd, 1);
	ms_return_fd();
	printf("ALLO\n");
	if (ms_pipe_signal(status) == false)
		exit (g_ms.exit);
	if (ms_ifredir(current->redir) == false)
		ms_pipedup_out();
	else
		ms_pipe_redir();
	if (ms_check_builtin(current) == false) 
		ms_fork(current->cmd);
}

bool	ms_pipe_exec(t_job *current)
{
	pid_t	pid;
	int		status;

	status = 0;
	signal(SIGINT, ms_donothing);
	signal(SIGQUIT, ms_donothing);
	ms_saved_fd();
	if (ms_create_pipe(current) == false)
	{
		perror("Minishell: ");
		return (false);
	}
	pid = fork();
	if (pid == -1)
		return(ms_pid_error());
	if (pid == 0)
		ms_pipe_in(current);
	else if (pid > 0)
		ms_pipe_out(current, pid);
	waitpid(pid, &status, 0);
	return (ms_fork_exit(status));
}
