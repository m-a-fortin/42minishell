/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pwd_echo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:31:21 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/30 20:33:32 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//ecrit le current working directory avec la string de getcwd.
void	ms_pwd_main(void)
{
	char	*pwd_line;

	pwd_line = NULL;
	pwd_line = getcwd(pwd_line, 0);
	ft_putendl_fd(pwd_line, 1);
	free(pwd_line);
}

void	ms_echo_loop(char **args, int index, int no_nl)
{
	while (args[index])
	{
		if (no_nl == 1)
			ft_putstr_fd(args[index], 1);
		else
			ft_putendl_fd(args[index], 1);
		index++;
	}
}

void	ms_echo_main(char **args)
{
	int	argc;
	int	no_nl;
	int	index;

	no_nl = 0;
	index = 1;
	argc = ft_matrice_size(args);
	if (argc == 1)
	{
		ft_putendl_fd("\n", 1);
		return ;
	}
	if (ft_strncmp(args[index], "-n", 2) == 0)
	{
		if (argc == 2)
		{
			ft_putchar_fd('\n', 1);
			return ;
		}
		index++;
		no_nl++;
	}
	ms_echo_loop(args, index, no_nl);
}
