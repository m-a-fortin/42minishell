/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:44:10 by mafortin          #+#    #+#             */
/*   Updated: 2021/11/30 11:56:34 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_cmdispath(char **cmd)
{
	struct stat	info;

	if (stat(cmd[0], &info) == -1)
	{
		perror("Minishell");
		exit (127);
	}
	if (S_ISDIR(info.st_mode))
	{
		ft_putstr_fd("Minishell: ", 1);
		ft_putstr_fd(cmd[0], 1);
		ft_putendl_fd(": is a directory", 1);
		exit(126);
	}
	execve(cmd[0], cmd, g_ms.env);
	perror("Minishell");
	exit(127);
}

void	ms_fork(t_job *current)
{
	char	*path;

	path = NULL;
	if (ft_char_search(current->cmd[0], '/') > 0)
		ms_cmdispath(current->cmd);
	if (ft_strncmp(current->cmd[0], ".\0", 2) == 0)
	{
		printf("Minishell: .: filename argument required\n");
		exit (2);
	}
	path = ms_get_cmdpath(current->cmd[0]);
	if (execve(path, current->cmd, g_ms.env) == -1)
	{
		free(path);
		printf("Minishell: %s: command not found\n", current->cmd[0]);
		exit (127);
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
	ms_return_fd();
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
		ms_fork(current);
	waitpid(pid, &status, 0);
	return (ms_fork_exit(status));
}
