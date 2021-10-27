/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:29:54 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/26 20:20:08 by mafortin         ###   ########.fr       */
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
	}
	if (current->next)
	{
		fd_out = fd[index][1];
		dup2(fd_out, 1);
		close(fd_out);
		close(fd_in);
	}
	if (current->next == NULL)
	{
		dup2(g_ms.stdout, 1);
	}
}

bool	ms_create_pipes(t_job *job_head, t_pipes *save)
{
	int		nb;
	int		index;

	index = 0;
	nb = ms_pipe_number(job_head);
	save->fd_pipe = ft_calloc(sizeof(int), nb + 1);
	while (nb > 0)
	{
		save->fd_pipe[index] = malloc(sizeof(int) * 2);
		if (pipe(save->fd_pipe[index]) == -1)
		{
			perror("Minishell");
			g_ms.exit = 1;
			return (false);
		}
		nb--;
		if (nb == 0)
			return (true);
		index++;
	}
	return (true);
}

void	ms_pipe_exec(t_job *job_head, t_job *current, t_pipes *save)
{
	(void)save;
	(void)job_head;
	if (ms_check_builtin(current) == false)
		ms_fork(current->cmd);
	exit(g_ms.exit);
}

void	ms_pipe_loop(t_job *job_head, t_pipes *save)
{
	pid_t	pid;
	t_job	*current;
	int		index;

	index = 0;
	current = job_head;
	(void)job_head;
	while (current)
	{
		ms_pipe_dup(current, save->fd_pipe, index);
		ms_exec_prep(current);
		pid = fork();
		if (invalid_process_id(pid))
			return ;
		if (pid == 0)
			ms_pipe_exec(job_head, current, save);
		waitpid(pid, &save->status, 0);
		ms_return_fd();
		if (ms_pipe_signal(save->status) == false)
			break ;
		if (current->next == NULL)
			break ;
		index++;
		current = current->next;
	}
}

bool	ms_pipe_main(t_job *job_head)
{
	t_pipes	*save;

	save = malloc(sizeof(t_pipes));
	signal(SIGINT, ms_donothing);
	signal(SIGQUIT, ms_donothing);
	ms_create_pipes(job_head, save);
	ms_pipe_loop(job_head, save);
	ms_setsignals();
	return (true);
}
