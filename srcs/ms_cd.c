/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:45:54 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/29 18:30:49 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
//Tested, fonctionne
void	ms_cd_doubledot(char **envp_ms, char *current_pwd)
{
	char	*new_pwd = NULL;

	new_pwd = ms_cd_removepath(current_pwd);
	ms_cd_updatepath(current_pwd, new_pwd, envp_ms);
	chdir(new_pwd);
	free(new_pwd);
}
//Not tested
void	ms_cd_home(char **envp_ms, char *current_pwd)
{
	char *new_pwd;

	new_pwd = ms_getenv("HOME=", envp_ms);
	ms_cd_updatepath(current_pwd, new_pwd, envp_ms);
	chdir(new_pwd);
}
//Manque a gerer comme il faut path, on doit join path et le currend_pwd
void	ms_cd_path(char **envp_ms, char *current_pwd, char *path)
{
	int		ret;
	char	*error = NULL;

	//ft_strjoin path et current_pwd
	ret = access(path, F_OK);
	if (ret != 0)
	{
		error = ft_strjoin("cd: no such file or directory:", path);
		perror(error);
		free(error);
		return ;
	}
	ms_cd_updatepath(current_pwd, path, envp_ms);
	
}

void	ms_cd_main(char **cmd, char **envp_ms)
{
	char	*current_pwd;

	current_pwd = NULL;
	current_pwd = getcwd(current_pwd, 0);
	if (ft_strncmp(cmd[1], ".\0", 2) == 0)
		ms_cd_updatepath(current_pwd, current_pwd, envp_ms);
	if (ft_strncmp(cmd[1], "..\0", 3) == 0)
		ms_cd_doubledot(envp_ms, current_pwd);
	if (cmd[1] == NULL || ft_strncmp(cmd[1], "~", 1) == 0)
		ms_cd_home(envp_ms, current_pwd);
	else
		ms_cd_path(envp_ms, current_pwd, cmd[1]);
	free(current_pwd);
}
