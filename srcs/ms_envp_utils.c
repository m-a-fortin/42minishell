/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_envp_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpst <hpst@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:21:31 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/06 09:33:26 by hpst             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//retourne et alloue une ligne de envp qui commence par name
//name est le nom de la varable env avec son deleminteur EX:PATH=
char	*ms_getenv(char *name, char **envp_ms)
{
	int		index;
	int		len;
	char	*line;

	index = 0;
	len = ft_strlen(name);
	while (envp_ms[index])
	{
		if (ft_strncmp(envp_ms[index], name, len) == 0)
		{
			line = envp_ms[index] + len;
			return (line);
		}
		else
			index++;
	}
	return (NULL);
}

//Change la valeur de name dans envp_ms, si name n'existe pas
//la rejoute avec sa valeur name est le nom de la varable
//env avec son deleminteur EX:PATH=
//valeur est la ligne suivant le nom

char	**ms_setenv_addback(char *name, char *value, char **envp_ms)
{
	char	*new_line;
	char	**new_envp;

	new_line = ft_strjoin(name, value);
	new_envp = ft_addline(envp_ms, new_line);
	free (new_line);
	return (new_envp);
}

char	**ms_setenv(char *name, char *value, char **envp_ms)
{
	int		index;
	char	*new_line;
	int		done;

	index = 0;
	done = 0;
	while (envp_ms[index])
	{
		if (ft_strncmp(envp_ms[index], name, ft_strlen(name)) == 0)
		{
			new_line = ft_strjoin(name, value);
			free(envp_ms[index]);
			envp_ms[index] = ft_strdup(new_line);
			free(new_line);
			done++;
		}
		index++;
	}
	if (done == 0)
		return (ms_setenv_addback(name, value, envp_ms));
	return (envp_ms);
}

char	*ms_check_arg_loop(char *name, char *arg, t_exec *ms, int index)
{
	int		x;
	int		y;
	int		len;
	char	*new_line;

	x = 0;
	len = ft_strlen(name);
	while (ms->env[x])
	{
		y = 0;
		if (ft_strncmp(name, ms->env[x], len) == 0)
		{
			while (ms->env[x][y] != '=')
				y++;
			new_line = ft_strdup(ms->env[x][y + 1]);
			free (arg);
			return (new_line);
		}
		x++;
	}
	return (arg);
}

void	ms_check_arg(char *arg, t_exec *ms)
{
	int		index;
	char	*name;
	int		x;

	index = 0;
	index++;
	x = 0;
	name = ft_strdup(arg + index);
	arg = ms_check_arg_loop(name, arg, ms, index);
}
