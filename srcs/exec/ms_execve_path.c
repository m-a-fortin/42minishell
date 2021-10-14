/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execve_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:03:31 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/13 14:00:55 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ms_create_paths(void)
{
	int		x;
	int		y;
	bool	found_path;

	x = 0;
	y = 0;
	found_path = false;
	while (g_ms.env[x])
	{
		if (ft_strncmp(g_ms.env[x], "PATH=", 5) == 0)
		{
			found_path = true;
			break ;
		}
		x++;
	}
	if (found_path == false)
		return (NULL);
	while (g_ms.env[x][y])
	{
		if (g_ms.env[x][y] == '/')
			break ;
		y++;
	}
	return (ft_split(g_ms.env[x] + y, ':'));
}

char	*ms_findpath(char *cmd)
{
	char	**env_path;
	char	*cmd_path;
	int		index;

	index = 0;
	env_path = ms_create_paths();
	cmd_path = NULL;
	if (!env_path)
		return (NULL);
	while (env_path[index])
	{
		cmd_path = ft_strjoin(env_path[index], cmd);
		if (access(cmd_path, F_OK) == 0)
		{
			ft_free_tab(env_path);
			return (cmd_path);
		}
		index++;
	}
	free(cmd_path);
	free(env_path);
	return (NULL);
}
