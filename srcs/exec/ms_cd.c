/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:45:54 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/05 09:21:58 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//cd dans home si il est set. Si unset retourne un message d'erreur.
void	ms_cd_home(char **envp_ms)
{
	char	*new_pwd;

	new_pwd = ms_getenv("HOME=", envp_ms);
	if (new_pwd == NULL)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 1);
		return ;
	}
	chdir(new_pwd);
}

//Si le path est bon, chdir dans le path et update l'envp_ms.
//Sinon retourne un message d'erreur comme bash.
void	ms_cd_main(char **cmd, char **envp_ms)
{
	char	*error;

	error = 0;
	if (cmd[1] == NULL || ft_strncmp(cmd[1], "~", 1) == 0)
		ms_cd_home(envp_ms);
	else if (chdir(cmd[1]) == -1)
	{
		error = strerror(errno);
		ft_putstr_fd("minishell: cd: ", 1);
		ft_putstr_fd(cmd[1], 1);
		ft_putstr_fd(": ", 1);
		ft_putendl_fd(error, errno);
	}
	else
		ms_setenv("PWD=", cmd[1], envp_ms);
}
