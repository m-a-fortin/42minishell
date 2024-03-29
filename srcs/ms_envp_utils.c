/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_envp_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:21:31 by mafortin          #+#    #+#             */
/*   Updated: 2021/11/08 12:31:35 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//*retourne et alloue une ligne de envp qui commence par name
//*name est le nom de la varable env avec son deleminteur EX:PATH=
char	*ms_getenv(char *name, char **envp_ms)
{
	int		index;
	int		len;
	char	*line;

	if (!name)
		return (NULL);
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

//*Change la valeur de name dans envp_ms, si name n'existe pas
//*la rejoute avec sa valeur name est le nom de la varable
//*env avec son deleminteur EX:PATH=
//*valeur est la ligne suivant le nom
char	**ms_setenv_addback(char *name, char *value, char **envp_ms)
{
	char	*new_line;
	char	**new_envp;

	new_line = ft_strjoin(name, value);
	new_envp = ft_addline(envp_ms, new_line);
	free (new_line);
	return (new_envp);
}

char	**ms_set_noequal(char *name, char **export_ms)
{
	int		index;
	char	*new_name;

	index = 0;
	while (export_ms[index])
	{
		if (!ft_strncmp(name, export_ms[index], ft_strlen(export_ms[index])))
			return (export_ms);
		index++;
	}
	new_name = ft_strjoin(name, "=");
	index = 0;
	while (export_ms[index])
	{
		if (ft_strncmp(new_name, export_ms[index], ft_strlen(new_name)) == 0)
		{
			free(new_name);
			return (export_ms);
		}
		index++;
	}
	free(new_name);
	return (ms_setenv_addback(name, "", export_ms));
}

char	**ms_setequal(char *name, char **envp_ms, int index)
{
	size_t	len;
	char	**new_ms;

	len = ft_strlen(name);
	if (ft_strncmp(envp_ms[index], name, len - 1) == 0)
	{
		if (ft_strlen(envp_ms[index]) == len - 1)
		{
			new_ms = ft_remove_line(envp_ms, index);
			return (new_ms);
		}
	}
	return (envp_ms);
}

char	**ms_setenv(char *name, char *value, char **envp_ms)
{
	int		index;
	char	*new_line;

	index = 0;
	while (envp_ms[index])
	{
		if (!ft_char_search(envp_ms[index], '=') && envp_ms[index][0] != '\0')
		{
			envp_ms = ms_setequal(name, envp_ms, index);
			if (envp_ms[index] == NULL)
				break ;
		}
		else if (ft_strncmp(envp_ms[index], name, ft_strlen(name)) == 0)
		{
			new_line = ft_strjoin(name, value);
			free(envp_ms[index]);
			envp_ms[index] = ft_strdup(new_line);
			free(new_line);
			return (envp_ms);
		}
		index++;
	}
	return (ms_setenv_addback(name, value, envp_ms));
}
