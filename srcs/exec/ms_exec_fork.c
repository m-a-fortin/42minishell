/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:44:10 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/18 12:59:02 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *ms_get_cmdpath(char *cmd_name)
{
	char	*path_return;
	int		index;

	
}

bool	ms_fork(t_job *current)
{
	char	*path;

	path = NULL;
	if (execve(current->cmd[0], current->cmd, g_ms.env) == -1)
	{
		path = ms_get_cmdpath(current->cmd[0])
	}
}

bool	ms_exec_fork(t_job *current])
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
		ms_fork(current);
}