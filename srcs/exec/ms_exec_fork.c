/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:44:10 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/20 11:24:53 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ms_cmdispath(char **cmd)
{
	struct stat info;
	stat(cmd[0], &info);
	if (S_ISDIR(info.st_mode))
	{
		ft_putstr_fd("Minishell: ", 1);
		ft_putstr_fd(cmd[0], 1);
		ft_putendl_fd(": is a directory", 1);
		return (false);
	}
	
}

bool	ms_fork(char **cmd)
{
	char	*path;

	path = NULL;
	if (execve(cmd[0], cmd, g_ms.env) == -1)
	{
		if (ft_char_search(cmd[0], '/') > 0)
			return (ms_cmdispath(cmd));
		path = ms_get_cmdpath(cmd[0]);
		if (!path)
			return (ms_execve_error());
	}
}

bool	ms_exec_fork(t_job *current, t_job *job_head, bool pipe)
{
	
	pid_t	pid;
	int		status;

	pid = fork();
	signal(SIGINT, NULL);
	signal(SIGQUIT, NULL);
	if (pid == -1)
	{
		ms_return_fd();
		ft_putendl_fd("minishell: FATAL: fork error", 1);
		return (false);
	}
	if (pid == 0)
	{
		if (pipe = true)
			if (ms_check_builtin(current, job_head, 1) == false)
				return (ms_fork(current->cmd));
	}
	waitpid(pid, &status, 0);
	signal(SIGINT, ms_nl_signal);
	signal(SIGQUIT, SIG_IGN);
}