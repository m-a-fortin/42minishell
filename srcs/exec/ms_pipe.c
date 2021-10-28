/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:29:54 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/28 17:46:15 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_pipe_dup(t_job *current, int **fd, int index)
{

	if (index > 0)
	{
		dup2(fd[index - 1][0], 0);
		close(fd[index - 1][0]);
		close(fd[index - 1][1]);
	}
	if (current->next)
	{
		dup2(fd[index][1], 1);
		close(fd[index][1]);
		close(fd[index][0]);
	}
}

void	ms_pipe_exec(t_job *current, int **fd_pipe, int index)
{
	ms_pipe_dup(current, fd_pipe ,index);
	ms_exec_prep(current);
	if (ms_check_builtin(current) == false)
		ms_fork(current->cmd);
	exit(g_ms.exit);
}

void	ms_pipe_wait(pid_t *pid, int nb_pipe)
{
	int	status[nb_pipe];
	int	index;

	(void)status;
	index = 0;
	while (index <= nb_pipe)
	{
		waitpid(pid[index], &status[index], 0);
		index++;
	}
	if (WIFEXITED(status[nb_pipe]))
		g_ms.exit = WEXITSTATUS(status[nb_pipe]);
}

void	ms_pipe_loop(t_job *current, int nb_pipe, int **pipe_fd, pid_t *pid)
{
	int		index;

	index = 0;
	while (index <= nb_pipe)
	{
		if (index < nb_pipe)
		{
			pipe_fd[index] = ft_calloc(sizeof(int), 2);
			pipe(pipe_fd[index]);
		}
		pid[index] = fork();
		if (invalid_process_id(pid[index]))
			return ;
		if (!pid[index])
			ms_pipe_exec(current, pipe_fd, index);
		if (index > 0)
			ms_close_pipe(pipe_fd[index - 1]);
		if (current->next == NULL)
			break ;
		current = current->next;
		index++;
	}
}

bool	ms_pipe_main(t_job *job_head)
{
	int	nb_pipe;
	int	index;
	int	**pipe_fd;
	t_job *current;
	pid_t	*pid;

	index = 0;
	current = job_head;
	nb_pipe = ms_pipe_number(current);
	pipe_fd = ft_calloc(sizeof(int), nb_pipe + 1);
	pid = malloc(sizeof(int) * nb_pipe);
	ms_pipe_loop(current, nb_pipe, pipe_fd, pid);
	ms_pipe_wait(pid, nb_pipe);
	free(pid);
	while (index < nb_pipe - 1)
	{
		if (pipe_fd[index])
			free(pipe_fd[index]);
		index++;
	}
	free(pipe_fd);
	return (true);
}
