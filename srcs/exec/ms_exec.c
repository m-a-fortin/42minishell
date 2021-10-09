/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 09:44:24 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/09 15:42:59 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


bool	ms_exec_fork(t_job *current, t_job *job_head, int *in_out)
{
	pid_t	pid;
	char	*pathname;
	char	*cmd_name;

	pid = fork();
	//open les fd
	//regarder comment je fais avec pipex pour close les fd et tout.
	dup2(in_out[0], 0);
	dup2(in_out[1], 1);
	cmd_name = ft_strjoin('/', current->cmd[0]);
	pathname = ms_findpath(cmd_name);
	if (!pathname)
		return (ms_pathname_error(cmd_name));
	// (if pid == -1)
	if (pid == 0)
	{
		if (execve(pathname, current->cmd, g_ms.env) == -1)
			return (ms_execve_error(pathname, cmd_name, job_head));
	}
	else
	{
		wait (0);
		free (cmd_name);
		free (pathname);
		close (in_out[0]);
		close (in_out[1]);
	}
	return (true);
}

void	ms_exec_main(t_job *job_head)
{
	t_job	*current;
	int		in_out[2];

	in_out[0] = 0;
	in_out[1] = 1;
	current = job_head;
	g_ms.exec = 1;
	while (current)
	{
		ms_check_dollarsign(current);
		//in_out = ms_redirection_main(current, job_head, in_out);
		ms_check_builtin(current, job_head, in_out[1]);
		//if(ms_check_builtin(current, job_head, in_out[0], in_out[1] == false)
		//ms_exec_fork(t_job *current, t_job *job_head, in_out);
		if (current->next)
			current = current->next;
		else
			break ;
	}
	ms_free_job(job_head, job_head);
}
