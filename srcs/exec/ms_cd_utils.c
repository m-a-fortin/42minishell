/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:21:38 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/29 15:11:22 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//fonctions pour remove le dernier directory dans le path PWD.
char	*ms_cd_removepath(char *current_pwd)
{
	int	index;
	int	len;
	int	count;
	char	*new_pwd;

	index = 0;
	len = ft_strlen(current_pwd);
	while (len >= 0)
	{
		if (current_pwd[len] == '/')
			break ;
		else
			len--;
	}
	new_pwd = ft_calloc(len + 1, sizeof(char));
	new_pwd = ft_strlcpy(new_pwd, current_pwd, len + 1);
	return (new_pwd);
}

//Update le PWD et OLDPWD dans envp_ms
void	ms_cd_updatepath(char *current_pwd, char *new_pwd, char **envp_ms)
{
	int	pwd_path;
	int	oldpwd_path;
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (envp_ms[index])
	{
		if (ft_strncmp(envp_ms[index], "PWD=", 3) == 0)
			count++;
		index++;
	}
	ms_setenv("PWD=", new_pwd, envp_ms);
	if (count == 0)
		ms_setenv("OLDPWD=", "\0", envp_ms);
	else
		ms_setenv("OLDPWD=", current_pwd, envp_ms);
}