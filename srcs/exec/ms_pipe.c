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

void	ms_pipe_exec(t_job *job_head, t_job *current)
{
	bool	redir;

	(void)redir;
	(void)job_head;
	redir = ms_ifredir(current->redir);
	//if (current != job_head && redir == false)
		//ms_pipedup_in();
	//if (redir == false)
		//ms_pipedup_out();
	if (ms_check_builtin(current) == false)
		return(ms_fork(current->cmd));
}

bool	ms_create_pipes(t_job *job_head)
{
	t_job	*node;
	int		nb;
	
	node = job_head;
	nb = ms_pipe_number(job_head);

}

bool	ms_pipe_main(t_job *job_head)
{
	pid_t	pid;
	int		status;
	t_pipe	*save;
	t_job	*current;

	(void)job_head;
	current = job_head;
	save = malloc(sizeof(t_pipe));
	//if (ms_create_pipe() == false)
	//{
		//perror("Minishell: ");
		//return (false);
	//}
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
