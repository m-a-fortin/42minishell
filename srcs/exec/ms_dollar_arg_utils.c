/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_dollar_arg_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:25:47 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/08 13:48:09 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//Si $ est suivi de ?, retourne la derniere valeur de sortie (g_ms.exit)
char	*ms_dollar_exit(char *arg)
{
	char	*new;
	char	*join;

	join = NULL;
	new = ft_itoa(g_ms.exit);
	if (arg[2])
	{
		join = ft_strjoin(new, arg + 2);
		free(arg);
		free(new);
		return (join);
	}
	else
	{
		free(arg);
		return (new);
	}
}

//Retourne une string vide.
char	*ms_arg_empty(char *arg)
{
	free (arg);
	return (arg = ft_calloc(1, sizeof(char)));
}
