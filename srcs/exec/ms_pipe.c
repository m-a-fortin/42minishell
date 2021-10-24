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

void	ms_pipe_exec(t_job *job_head, t_job *current)
{
	bool	redir;

	redir = ms_ifredir(current);
	if (current != job_head && redir == false)
		ms_pipedup_in();
	if (redir == false)
		ms_pipe_dup_out();
	if (ms_check_builtin(current) == false)
		return(ms_fork(current));
}

bool	ms_pipe_main(t_job *job_head, t_job *current)
{
	pid_t	pid;
	int		status;

	ms_saved_fd();
	if (ms_create_pipe(current) == false)
	{
		perror("Minishell: ");
		return (false);
	}
	signal(SIGINT, ms_donothing);
	signal(SIGQUIT, ms_donothing);
	pid = fork();
	if (pid == -1)
		return(ms_pid_error());
	if (pid == 0)
		ms_pipe_exec(job_head, current);
	waitpid(pid, &status, 0);
	return (true);
}
