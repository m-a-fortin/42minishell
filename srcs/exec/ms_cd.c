/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:45:54 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/29 15:02:08 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ms_cd_doubledot(char **envp_ms, char *current_pwd)
{
	int		index;
	char	*new_pwd = NULL;

	index = ft_strlen(current_pwd);
	new_pwd = ms_cd_removepath(current_pwd);
	ms_cd_updatepath(current_pwd, new_pwd, envp_ms);
	chdir(new_pwd);
	free(new_pwd);
}

void	ms_cd_main(char **cmd, char **envp_ms)
{
	char	*current_pwd;

	current_pwd = getcwd(current_pwd, 0);
	if (cmd[1] == ".")
	{
		//refresh pwd.
		return ;
	}
	if (cmd[1] == "..")
	{
		//old_pwd = currect_pwd
		//path va etre le dir avant dans pwd.
		chdir()
	}
	if (cmd[1] == NULL || cmd[1] == "~")
	{
		//old_pwd = currect_pwd
		//path va etre le root dir
		chdir()
	}
	else
	{
		chdir(cmd[1]);

	free(current_pwd);
}