/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pwd_echo_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:31:21 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/26 09:29:04 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//*ecrit le current working directory. Se sert de notre envp_ms pour ca.
int	ms_pwd_main(int fd)
{
	char	*pwd_line;

	pwd_line = NULL;
	pwd_line = getcwd(pwd_line, 0);
	ft_putendl_fd(pwd_line, fd);
	free(pwd_line);
	return (0);
}

void	ms_echo_loop(char **args, int index, int no_nl, int fd)
{
	if (no_nl == 1)
		index++;
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

//*Verifie le flag -n. Dans le cas ou -n est rencontrer:
//*pas de new line a la fin du echo. Plusieurs -n peuvent
//*etre chained. Si un char est different de n. Print le
//*flag aussi.
int	ms_echo_flag(char *arg, int no_nl)
{
	int	x;

	x = 0;
	if (arg[x] == '-')
	{
		x++;
		while (arg[x])
		{
			if (arg[x] != 'n' && arg[x] != '\0')
				return (0);
			x++;
			no_nl = 1;
		}
	}
	return (no_nl);
}

//*ecrit dans fd les args, option -n = sans newline.
int	ms_echo_main(char **args, int fd)
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
		return (0);
	}
	no_nl = ms_echo_flag(args[index], no_nl);
	ms_echo_loop(args, index, no_nl, fd);
	return (0);
}

//*print la variable envp_ms dans le fd (sans arguments)
//*envp_ms est une copie de envp du main et est update avec les cmds.
int	ms_env_main(char **args, int fd)
{
	int	count;

	count = ft_matrice_size(args);
	if (count != 1)
	{
		ft_putendl_fd("env: invalid number of arguments", 1);
		return (127);
	}
	ft_print_matrice_fd(g_ms.env, fd);
	return (0);
}
