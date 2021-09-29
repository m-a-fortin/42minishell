/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:45:54 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/29 17:17:01 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ms_cd_doubledot(char **envp_ms, char *current_pwd)
{
	char	*new_pwd = NULL;

	new_pwd = ms_cd_removepath(current_pwd);
	ms_cd_updatepath(current_pwd, new_pwd, envp_ms);
	chdir(new_pwd);
	free(new_pwd);
}

void	ms_cd_home(char **envp_ms, char *current_pwd)
{
	char *new_pwd;

	new_pwd = ms_getenv("HOME=", envp_ms);
	ms_cd_updatepath(current_pwd, new_pwd, envp_ms);
	chdir(new_pwd);
}

void	ms_cd_path(char **envp_ms, char *current_pwd, char *path)
{
	int		ret;
	char	*error = NULL;

	ret = access(path, F_OK);
	if (ret != 0)
	{
		error = ft_strjoin("cd: no such file or directory:", path);
		perror(error);
		free(error);
		return ;
	}
	
}

void	ms_cd_main(char **cmd, char **envp_ms)
{
	char	*current_pwd;

	current_pwd = getcwd(current_pwd, 0);
	if (cmd[1] == ".")
		ms_cd_updatepath(current_pwd, current_pwd, envp_ms);
	if (cmd[1] == "..")
		ms_cd_doubledot(envp_ms, current_pwd);
	if (cmd[1] == NULL || cmd[1] == "~")
		ms_cd_home(envp_ms, current_pwd);
	else
		ms_cd_path(envp_ms, current_pwd, cmd[1]);
	free(current_pwd);
}
