/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:44:10 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/18 16:35:23 by mafortin         ###   ########.fr       */
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
		if (cmd[0] != '/' || cmd[0] != '.')
			path = ms_get_cmdpath(cmd_name, cmd[0]);
		else
		{
			path = ft_strdup(cmd[0]);
			if (access(path, F_OK) != 0)
				return (ms_nofiledir_error(path));
		}
		free (cmd_name);
		if (access(path, F_OK) != 0)
		if (!path)
			return (ms_execve_error());
	}
}

bool	ms_exec_fork(char **cmd)
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
		ms_fork(cmd);
}