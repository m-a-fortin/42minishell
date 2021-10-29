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

void	ms_pipe_dup(t_job *current, t_pipe *data, int index)
{

	if (index > 0)
	{
		if (dup2(data->prev_pipe[0], 0) == -1)
		{
			perror("Minishell:");
			exit (1);
		}
		close(data->prev_pipe[0]);
		close(data->prev_pipe[1]);
	}
	if (current->next)
	{
		if (dup2(data->pipe_fd[1], 1) == -1)
		{
			perror("Minishell:");
			exit (1);
		}
		close(data->pipe_fd[1]);
		close(data->pipe_fd[0]);
	}
}

void	ms_pipe_exec(t_job *current, t_pipe *data, int index)
{
	ms_pipe_dup(current, data, index);
	ms_exec_prep(current);
	if (ms_check_builtin(current) == false)
		ms_fork(current->cmd);
	exit(g_ms.exit);
}

void	ms_pipe_wait(t_pipe *data)
{
	int	status[data->nb_pipe];
	int	index;

	(void)status;
	index = 0;
	while (index <= data->nb_pipe)
	{
		waitpid(data->pids[index], &status[index], 0);
		index++;
	}
	if (WIFEXITED(status[data->nb_pipe]))
		g_ms.exit = WEXITSTATUS(status[data->nb_pipe]);
}

void	ms_pipe_loop(t_job *current, t_pipe *data)
{
	int	index;

	index = 0;
	while (index <= data->nb_pipe)
	{
		if (index < data->nb_pipe)
		{
			if (pipe(data->pipe_fd) == -1)
				return(perror("Minishell:"));
		}
		data->pids[index] = fork();
		if (invalid_process_id(data->pids[index]))
			return ;
		if (!data->pids[index])
			ms_pipe_exec(current, data, index);
		if (index > 0)
			ms_close_pipe(data->prev_pipe);
		current = current->next;
		ms_pipe_save(data);
		index++;
	}
}

bool	ms_pipe_main(t_job *job_head)
{
	t_job *current;
	t_pipe *data;

	data = malloc(sizeof(t_pipe));
	current = job_head;
	data->nb_pipe = ms_pipe_number(current);
	data->pids = malloc(sizeof(int) * data->nb_pipe);
	ms_pipe_loop(current, data);
	ms_pipe_wait(data);
	free(data->pids);
	data->pids = NULL;
	free(data);
	data = NULL;
	return (true);
}
