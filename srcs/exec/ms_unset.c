/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpst <hpst@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:06:01 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/06 09:35:52 by hpst             ###   ########.fr       */
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

//Look in envp if value ARG is set. Change value if it is.
void	ms_unset_main(t_exec *ms, char **args)
{
	int		x;
	int		index;

	x = 1;
	if (args[x] == NULL)
		return ;
	while (args[x])
	{
		index = 0;
		if (ms_valid_unset_name(args[x]) == false)
			return (ms_unset_error(args[x]));
		while (ms->env[index])
		{
			if (ft_strncmp(args[x], ms->env[index], ft_strlen(args[x])) == 0)
			{
				ms->env = ft_remove_line(ms->env, index);
				break ;
			}
			index++;
		}
		x++;
	}
	return (0);
}
