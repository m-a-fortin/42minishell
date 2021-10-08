/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_dollar_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 08:56:02 by hpst              #+#    #+#             */
/*   Updated: 2021/10/08 13:56:02 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//Regarde dans env si la variable est defined. Si oui elle retour sa valeur
//Si non retourne une string vide.
char	*ms_check_arg_loop(char *arg)
{
	int		x;
	int		y;
	int		len;
	char	*new_line;

	x = 0;
	len = ft_strlen(arg) - 1;
	while (g_ms.env[x])
	{
		y = 0;
		if (ft_strncmp(arg + 1, g_ms.env[x], len) == 0)
		{
			while (g_ms.env[x][y] != '=')
				y++;
			new_line = ft_strdup(g_ms.env[x] + (y + 1));
			free (arg);
			return (new_line);
		}
		x++;
	}
	return (ms_arg_empty(arg));
}

//Si la suite de $ est un chiffre imprime ce qui est apres le premier chiffre
char	*ms_arg_number(char *arg)
{
	char	*new_arg;

	new_arg = ft_strdup(arg + 2);
	if (arg[0])
		new_arg = ft_strjoin(new_arg, arg);
	free (arg);
	return (new_arg);
}

char	*ms_check_arg_main(char *arg)
{
	if (arg[1] == '?')
		return (ms_dollar_exit(arg));
	if (ft_isalpha(arg[1] == 0 && arg[1] != '_'))
		return (ms_arg_number(arg));
	if (arg[1] == '_' && arg[2] == 0)
		return (ms_arg_empty(arg));
	return (ms_check_arg_loop(arg));
}

//Fonction qui gere les arguments $ARG existant dans la variable ENV.
void	ms_check_dollarsign(t_job *current)
{
	int	index;

	index = 0;
	while (current->cmd[index])
	{
		if (current->cmd[index][0] == '$')
			current->cmd[index] = ms_check_arg_main(current->cmd[index]);
		index++;
	}
}
