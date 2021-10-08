/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 09:44:24 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/08 14:50:44 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ms_check_builtin(t_job *current)
{
	int	in;
	int	out;

	in = 0;
	out = 1;
	if (ft_strncmp(current->cmd[0], "cd", 3) == 0)
		return(ms_cd_main(current->cmd));
	if (ft_strncmp(current->cmd[0], "echo", 5) == 0)
		return(ms_echo_main(current->cmd, out));
	if (ft_strncmp(current->cmd[0], "pwd", 4) == 0)
		return(ms_pwd_main(out));
	if (ft_strncmp(current->cmd[0], "export", 7) == 0)
		return(ms_export_main(current->cmd, out));
	if (ft_strncmp(current->cmd[0], "unset", 6) == 0)
		return(ms_unset_main(current->cmd));
	if (ft_strncmp(current->cmd[0], "env", 4) == 0)
		return(ms_env_main(current->cmd, out));
	//if (ft_strncmp(current->cmd[0], "exit", 5) == 0)
		//return(ms_exit_main());
	return (42);
}

void	ms_exec_main(t_job *job_head)
{
	t_job	*current;

	current = job_head;
	g_ms.exec = 1;
	while (current)
	{
		ms_check_dollarsign(current);
		g_ms.exit = ms_check_builtin(current);
		//if (g_ms.exit == 42)
			//ms_execve_main(current);
		if (current->next)
			current = current->next;
		else
			break ;
	}
	ms_free_job(job_head, job_head);
}
