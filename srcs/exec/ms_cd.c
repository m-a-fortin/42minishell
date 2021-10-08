/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:45:54 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/08 14:10:07 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//cd dans home si il est set. Si unset retourne un message d'erreur.
void	ms_cd_home(void)
{
	char	*new_pwd;

	new_pwd = ms_getenv("HOME=", g_ms.env);
	if (new_pwd == NULL)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 1);
		return ;
	}
	chdir(new_pwd);
}

//Si le path est bon, chdir dans le path et update l'envp_ms.
//Sinon retourne un message d'erreur comme bash.
int	ms_cd_main(char **cmd)
{
	char	*error;

	error = 0;
	if (cmd[1] == NULL || ft_strncmp(cmd[1], "~", 1) == 0)
		ms_cd_home();
	else if (chdir(cmd[1]) == -1)
	{
		error = strerror(errno);
		ft_putstr_fd("minishell: cd: ", 1);
		ft_putstr_fd(cmd[1], 1);
		ft_putstr_fd(": ", 1);
		ft_putendl_fd(error, errno);
		return (1);
	}
	else
		g_ms.env = ms_setenv("PWD=", cmd[1], g_ms.env);
	return (0);
}
