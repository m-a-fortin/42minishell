/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:45:54 by mafortin          #+#    #+#             */
/*   Updated: 2021/11/15 10:31:25 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_cd_update_env(char *old_pwd)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	g_ms.env = ms_setenv("PWD=", pwd, g_ms.env);
	g_ms.env = ms_setenv("OLDPWD=", old_pwd, g_ms.env);
	g_ms.export = ms_setenv("PWD=", pwd, g_ms.export);
	g_ms.export = ms_setenv("OLDPWD=", old_pwd, g_ms.export);
	free (pwd);
	free (old_pwd);
}

//*cd dans home si il est set. Si unset retourne un message d'erreur.
void	ms_cd_home(void)
{
	char	*new_pwd;
	char	*old_pwd;

	new_pwd = ms_getenv("HOME=", g_ms.env);
	if (new_pwd == NULL)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 1);
		return ;
	}
	old_pwd = getcwd(NULL, 0);
	chdir(new_pwd);
	ms_cd_update_env(old_pwd);
}

//*Si le path est bon, chdir dans le path et update l'envp_ms.
//*Sinon retourne un message d'erreur comme bash.
int	ms_cd_main(char **cmd)
{
	char	*error;
	char	*old_pwd;

	(void)error;
	old_pwd = getcwd(NULL, 0);
	if (cmd[1] == NULL || ft_strncmp(cmd[1], "~", 1) == 0)
	{
		free(old_pwd);
		ms_cd_home();
	}
	else if (chdir(cmd[1]) == -1)
	{
		free(old_pwd);
		ft_putstr_fd("Minishell: ", 2);
		perror(cmd[1]);
		return (1);
	}
	else
		ms_cd_update_env(old_pwd);
	return (0);
}
