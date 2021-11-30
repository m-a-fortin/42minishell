/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 09:44:24 by mafortin          #+#    #+#             */
/*   Updated: 2021/11/30 14:07:20 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ms_saved_fd(void)
{
	g_ms.save_in = dup(0);
	g_ms.save_out = dup(1);
}

void	ms_return_fd(void)
{
	dup2(g_ms.save_in, 0);
	dup2(g_ms.save_out, 1);
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
	if (!current->cmd)
		return (false);
	trimquotes_main(current);
	return (true);
}

void	ms_exec_main(t_job *job_head)
{
	bool	pipe;
	t_job	*current;

	pipe = false;
	current = job_head;
	dollarsign_main(current);
	if (job_head->next)
		pipe = true;
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
