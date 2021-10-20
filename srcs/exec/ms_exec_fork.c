/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:44:10 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/20 16:20:28 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_cmdispath(char **cmd)
{
	struct stat info;
	
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
	execve(cmd[0], cmd, g_ms.env);
	if (ft_char_search(cmd[0], '/') > 0)
		ms_cmdispath(cmd);
	path = ms_get_cmdpath(cmd[0]);
	if (!path)
		return ;
	if (execve(path, cmd, g_ms.env) == -1)
	{
		free(path);
		return (ms_cmdnotfound(cmd[0]));
	}
} 

bool	ms_exec_fork(t_job *current)
{
	pid_t	pid;
	int		status;

	pid = fork();
	signal(SIGINT, ms_donothing);
	signal(SIGQUIT, ms_donothing);
	if (pid == -1)
	{
		ms_return_fd();
		ft_putendl_fd("minishell: FATAL: fork error", 1);
		g_ms.exit = 1;
		return (false);
	}
	if (pid == 0)
		ms_fork(current->cmd);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_ms.exit = WEXITSTATUS(status);
	signal(SIGINT, ms_nl_signal);
	signal(SIGQUIT, SIG_IGN);
	if (g_ms.exit != 0)
		return (false);
	return (true);
}