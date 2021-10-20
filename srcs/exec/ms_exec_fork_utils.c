/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_fork_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:24:55 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/20 13:01:13 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ms_nosuchfile(char *cmd)
{
	ms_return_fd();
	ft_putstr_fd("Minishell: ", 1);
	ft_putstr_fd(cmd, 1);
	ft_putendl_fd(": No such file or directory", 1);
	return (false);
}

bool	ms_cmdnotfound(char *cmd)
{
	ms_return_fd();
	ft_putstr_fd("Minishell: ", 1);
	ft_putstr_fd(cmd, 1);
	ft_putendl_fd(": Command not found", 1);
	return (false);
}

char	*ms_find_cmdpath(char *cmd_name, char **paths)
{
	int		index;
	char	*cmd_path;

	index = 0;
	while (paths[index])
	{
		cmd_path = ft_strjoin(paths[index], cmd_name);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		index++;
	}
	ms_nosuchfile(cmd_name);
	return (NULL);
}

char	*ms_get_cmdpath(char *cmd)
{
	char	**paths;
	char	*cmd_name;

	cmd_name = ft_strjoin("/", cmd);
	paths = ms_create_paths();
	if (!paths)
	{
		ms_nosuchfile(cmd);
		return (NULL);
	}
	return (ms_find_cmdpath(cmd_name, paths));
}

char	**ms_create_paths(void)
{
	int		index;
	bool	found;

	index = 0;
	found = false;
	while (g_ms.env[index])
	{
		if (ft_strncmp("PATH=", g_ms.env[index], 5) == 0)
		{
			found = true;
			break ;
		}
		index ++;
	}
	return (ft_split(g_ms.env[index] + 5, ':'));
}