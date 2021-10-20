/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpst <hpst@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:44:10 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/19 11:30:33 by hpst             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ms_fork(char **cmd)
{
	char	*path;
	char	*cmd_name;

	path = NULL;
	if (execve(cmd[0], cmd, g_ms.env) == -1)
	{
		cmd_name = ft_strjoin("/", cmd);
		if (ft_char_search(cmd[0], '/') == 0)
			path = ms_get_cmdpath(cmd_name, cmd[0]);
		else
			path = ft_strdup(cmd[0]);
		free (cmd_name);
		if (!path)
			return (ms_execve_error());
	}
}

bool	ms_exec_fork(t_job *current, t_job *job_head, bool pipe)
{
	
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		ms_return_fd();
		ft_putendl_fd("minishell: FATAL: fork error", 1);
		return (false);
	}
	if (pid == 0)
	{
		if (ms_check_builtin(current, job_head, 1) == false)
			ms_fork(current->cmd);
	}
}