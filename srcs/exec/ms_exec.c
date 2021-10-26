/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 09:44:24 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/26 13:43:38 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ms_saved_fd(void)
{
	g_ms.stdin = dup(0);
	g_ms.stdout = dup(1);
}

void	ms_return_fd(void)
{
	dup2(g_ms.stdin, 0);
	dup2(g_ms.stdout, 1);
}

bool	ms_exec_phase(t_job *current)
{
	bool	pipe;

	if (current->next)
		pipe = true;
	else
		pipe = false;
	if (pipe == false)
	{
		if (ms_exec_prep(current) == false)
			return (false);
		if (ms_check_builtin(current) == false)
			return (ms_exec_fork(current));
		return (true);
	}
	return (ms_pipe_main(current));
}

bool	ms_exec_prep(t_job *current)
{
	if (ms_redirection_main(current) == false)
	{
		g_ms.exit = 127;
		return (false);
	}
	trimquotes_main(current);
	return (true);
}

void	ms_exec_main(t_job *job_head)
{
	bool	pipe;

	pipe = false;
	dollarsign_main(job_head);
	if (job_head->next)
		pipe = true;
	else
		pipe = false;
	if (pipe == false)
	{
		if (ms_exec_prep(job_head) == false)
			return (ms_return_fd());
		if (ms_check_builtin(job_head) == false)
			ms_exec_fork(job_head);
		return (ms_return_fd());
	}
	ms_pipe_main(job_head);
	ms_return_fd();
}
