/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_envp_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:21:31 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/29 18:27:12 by mafortin         ###   ########.fr       */
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
int	ms_setenv(char *name, char *value, char **envp_ms)
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
	{
		new_line = ft_strjoin(name, value);
		envp_ms = ft_addline(envp_ms, new_line);
	}
	return (0);
}
