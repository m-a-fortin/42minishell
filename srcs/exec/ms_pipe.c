/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:29:54 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/28 14:39:24 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_pipe_dup(t_job *current, int **fd, int index)
{
	int	fd_in;
	int	fd_out;

	if (index > 0)
	{
		fd_in = fd[index - 1][0];
		dup2(fd_in, 0);
		close(fd_in);
	}
	if (current->next)
	{
		fd_out = fd[index][1];
		dup2(fd_out, 1);
		close(fd_out);
	}
	if (current->next == NULL)
		dup2(g_ms.stdout, 1);
}

void	ms_pipe_exec(t_job *job_head, t_job *current, t_pipes *save)
{
	(void)save;
	(void)job_head;
	ms_pipe_dup(current, save->fd_pipe, index);
	ms_exec_prep(current);
	if (ms_check_builtin(current) == false)
		ms_fork(current->cmd);
	exit(g_ms.exit);
}

void	ms_pipe_wait(pid_t *pid, int nb_pipe, int status)
{
	int	status[nb_pipe];
	int	index;

	(void)status;
	index = 0;
	while (index < nb_pipesave - 1)
	{
		waitpid(pid[nb_pipe], &status[index], 0);
		index++;
	}
	if (WIFEXITED(status[nb_pipe]))
		g_ms.exit = WEXITSTATUS(status[nb_pipe]);
}

void	ms_pipe_loop(t_job *job_head, int nb_pipe, int **pipe_fd, pid_t *pid)
{
	int		index;
	t_job	*current;

	index = 0;
	current = job_head;
	(void)job_head;
	while (index < nb_pipe)
	{
		if (index < nb_pipe - 1)
		{
			pipe_fd[index] = malloc(sizeof(int) * 2);
			pipe(pipe_fd[index]);
		}
		pid[index] = fork();
		if (invalid_process_id(pid[index]))
			return ;
		if (pid[index] == 0)
			ms_pipe_exec(job_head, current, pipe_fd);
		if (index >= 1)
			ms_close_pipe(pipe_fd[index - 1])
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
	pid_t	*pid;

	index = 0;
	nb_pipe = ms_pipe_number(job_head);
	pipe_fd = malloc(sizeof(int) * nb_pipe);
	signal(SIGINT, ms_donothing);
	signal(SIGQUIT, ms_donothing);
	pid = malloc(sizeof(int) * nb_pipe);
	ms_pipe_loop(job_head, nb_pipe, pipe_fd, pid);
	ms_pipe_wait(pid, nb_pipe,
	free(pid);
	while (index < nb_pipe)
	{
		free(pipe_fd[index]);
		index++;
	}
	free(pipe_fd);
	ms_setsignals();
	return (true);
}
