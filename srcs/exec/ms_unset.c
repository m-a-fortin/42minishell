/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:06:01 by mafortin          #+#    #+#             */
/*   Updated: 2021/11/25 15:38:11 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ms_unset_error(char *args)
{
	ft_putstr_fd("bash: unset: ", 1);
	ft_putstr_fd(args, 1);
	ft_putendl_fd(": not a valid identifier", 1);
	return (1);
}

bool	ms_valid_unset_name(char *args)
{
	int	index;

	index = 0;
	if (ft_isalpha(args[0]) == 0 && args[0] != '_')
		return (false);
	while (args[index])
	{
		if (ft_isalnum(args[index]) == 0 && args[0] != '_')
			return (false);
		index++;
	}
	return (true);
}

void	ms_unset_export(char *name, char *args)
{
	int	i;

	i = 0;
	while (g_ms.export[i])
	{
		if (!ft_char_search(g_ms.export[i], '='))
		{
			if (!ft_strncmp(args, g_ms.export[i], ft_strlen(g_ms.export[i])))
			{
				g_ms.export = ft_remove_line(g_ms.export, i);
				return ;
			}
		}
		if (ft_strncmp(name, g_ms.export[i], ft_strlen(name)) == 0)
		{
			g_ms.export = ft_remove_line(g_ms.export, i);
			return ;
		}
		i++;
	}
}

void	ms_unset_loop(char	*args)
{	
	int		index;
	char	*name;

	index = 0;
	name = ft_strjoin(args, "=");
	while (g_ms.env[index])
	{
		if (ft_strncmp(name, g_ms.env[index], ft_strlen(name)) == 0)
		{
			g_ms.env = ft_remove_line(g_ms.env, index);
			break ;
		}
		index++;
	}
	ms_unset_export(name, args);
	free(name);
}

//*Look in envp if value ARG is set. Change value if it is.
int	ms_unset_main(char **args)
{
	int		x;

	x = 1;
	if (args[x] == NULL)
		return (0);
	while (args[x])
	{
		if (ms_valid_unset_name(args[x]) == false)
			return (ms_unset_error(args[x]));
		ms_unset_loop(args[x]);
		x++;
	}
	return (0);
}
