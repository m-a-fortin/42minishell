/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pwd_echo_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:31:21 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/30 21:17:48 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//ecrit le current working directory. Se sert de notre envp_ms pour ca.
void	ms_pwd_main(int fd)
{
	char	*pwd_line;

	pwd_line = getcwd(pwd_line, 0);
	ft_putendl_fd(pwd_line, fd);
	free(pwd_line);
}

void	ms_echo_loop(char **args, int index, int no_nl, int fd)
{
	while (args[index])
	{
		ft_putstr_fd(args[index], fd);
		if (args[index + 1] != 0)
			ft_putchar_fd(' ', fd);
		index++;
	}
	if (no_nl == 0)
		ft_putchar_fd('\n', fd);
}

//ecrit dans fd les args, option -n = sans newline.
void	ms_echo_main(char **args, int fd)
{
	int	argc;
	int	no_nl;
	int	index;

	no_nl = 0;
	index = 1;
	argc = ft_matrice_size(args);
	if (argc == 1)
	{
		ft_putchar_fd('\n', fd);
		return ;
	}
	if (ft_strncmp(args[index], "-n", 2) == 0)
	{
		if (argc == 2)
			return ;
		index++;
		no_nl++;
	}
	ms_echo_loop(args, index, no_nl, fd);
}

//print la variable envp_ms dans le fd (sans arguments)
//envp_ms est une copie de envp du main et est update avec les cmds.
void	ms_env_main(char **envp_ms, char **args, int fd)
{
	int	count;

	count = ft_matrice_size(args);
	if (count != 1)
	{
		ft_putendl_fd("env: invalid number of arguments", 1);
		return ;
	}
	ft_print_matrice_fd(envp_ms, fd);
}
