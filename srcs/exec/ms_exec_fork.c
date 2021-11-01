/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:44:10 by mafortin          #+#    #+#             */
/*   Updated: 2021/11/01 15:24:51 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_cmdispath(char **cmd)
{
	struct stat	info;

	stat(cmd[0], &info);
	if (S_ISDIR(info.st_mode))
	{
		ms_return_fd();
		ft_putstr_fd("Minishell: ", 1);
		ft_putstr_fd(cmd[0], 1);
		ft_putendl_fd(": is a directory", 1);
		exit (1);
	}
	execve(cmd[0], cmd, g_ms.env);
	ms_nosuchfile(cmd[0] + 1);
}

void	ms_fork(char **cmd)
{
	char	*path;

	path = NULL;
	if (ms_getenv("PATH=", g_ms.env) == NULL)
	{
		g_ms.exit = 127;
		return (ms_nosuchfile(cmd[0]));
	}
	if (ft_char_search(cmd[0], '/') > 0)
		ms_cmdispath(cmd);
	path = ms_get_cmdpath(cmd[0]);
	if (!path)
		exit(1);
	if (execve(path, cmd, g_ms.env) == -1)
	{
		free(path);
		ms_nosuchfile(cmd[0]);
	}
}

bool	ms_fork_signal(int status)
{
	if (WIFEXITED(status))
		g_ms.exit = WEXITSTATUS(status);
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGINT)
			ft_putendl_fd("", 1);
		if (WTERMSIG(status) == SIGQUIT)
			ft_putendl_fd("Kit-Kat", 1);
	}
	ms_setsignals();
	if (g_ms.exit != 0)
		return (false);
	return (true);
}

bool	ms_fork_exit(int status)
{
	ms_fork_signal(status);
	if (g_ms.exit != 0)
		return (false);
	return (true);
}

bool	ms_exec_fork(t_job *current)
{
	pid_t	pid;
	int		status;

	pid = fork();
	signal(SIGINT, ms_donothing);
	signal(SIGQUIT, ms_donothing);
	if (pid == -1)
		return (ms_pid_error());
	if (pid == 0)
		ms_fork(current->cmd);
	waitpid(pid, &status, 0);
	return (ms_fork_exit(status));
}
