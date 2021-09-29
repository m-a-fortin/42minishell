/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:45:54 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/29 11:16:36 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ms_cd_doubledot(char **envp_ms, char *old_pwd, char *current_pwd, char *new_pwd)
{
	int	index;

	index = ft_strlen(current_pwd);
	while (current_pwd[index])
	{
		if (current_pwd[index] == '/')
			break ;
		else
			index--;
	}
	new_pwd = calloc(index + 1, sizeof(char));
	ft_strlcpy(new_pwd, current_pwd, index + 1);
	ms_setenv("PWD=", new_pwd, envp_ms);
	

}

char	*ms_cd_removepath(char *current_pwd)
{
	int	index;
	int	len;
	int	count;

	index = 0;
	len = ft_strlen(current_pwd);
	while (len >= 0)
	{
		if (current_pwd[len] == '/')
		{
			count++;
			break ;
		}
		len--;
	}
	
}
void	ms_cd_main(t_job *cmd_head, char **envp_ms)
{
	char	*old_pwd;
	char	*current_pwd;
	char	*new_pwd;

	current_pwd = getcwd(current_pwd, 0);
	if (cmd_head->args == ".")
	{
		//refresh pwd.
		return ;
	}

	if (cmd_head->args == "..")
	{
		//old_pwd = currect_pwd
		//path va etre le dir avant dans pwd.
		chdir()
	}

	if (cmd_head->args == NULL || cmd_head->args == "~")
	{
		//old_pwd = currect_pwd
		//path va etre le root dir
		chdir()
	}
	else
		chdir(cmd_head->args);
	//faire fonction qui change le envp PWD et OLD_PWD
	free(current_pwd);
	free(old_pwd);
	free(new_pwd);
}