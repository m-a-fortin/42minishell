/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_dollar_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpst <hpst@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 08:56:02 by hpst              #+#    #+#             */
/*   Updated: 2021/10/05 15:09:28 by hpst             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/exec.h"

char	*ms_arg_emty(char *arg)
{
	free (arg);
	return (arg = ft_calloc(1, sizeof(char)));
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
	return (ms_arg_empty(arg));
}

char	*ms_arg_number(char *arg, int index)
{
	char *new_arg;

	new_arg = ft_strdup(arg + index);
	free (arg);
	return (new_arg);
}

char	*ms_check_arg_main(char *arg, t_exec *ms)
{
	int		index;
	char	*name;
	int		x;

	index = 0;
	index++;
	x = 0;
	if (arg[index] == '$')
		return(ft_itoa(ms->exit));
	if (ft_isalpha(arg[index] == 0 && arg[index] != '_'))
			return (ms_arg_number(arg, index + 1));
	name = ft_strdup(arg + index);
	arg = ms_check_arg_loop(name, arg, ms, index);
	free(name);
	return (arg);
}
