/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpst <hpst@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:39:22 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/23 10:39:06 by hpst             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ms_check_builtin2(t_job *current)
{
	if (ft_strncmp(current->cmd[0], "export", 7) == 0)
	{
		g_ms.exit = ms_export_main(current->cmd);
		return (true);
	}
	if (ft_strncmp(current->cmd[0], "unset", 6) == 0)
	{
		g_ms.exit = ms_unset_main(current->cmd);
		return (true);
	}
	if (ft_strncmp(current->cmd[0], "env", 4) == 0)
	{
		g_ms.exit = ms_env_main(current->cmd, 1);
		return (true);
	}
	if (ft_strncmp(current->cmd[0], "exit", 5) == 0)
	{
		g_ms.exit = ms_exit_main(current);
		return (true);
	}
	return (false);
}

bool	ms_check_builtin(t_job *current)
{
	if (ft_strncmp(current->cmd[0], "cd", 3) == 0)
	{
		g_ms.exit = ms_cd_main(current->cmd);
		return (true);
	}
	if (ft_strncmp(current->cmd[0], "echo", 5) == 0)
	{
		g_ms.exit = ms_echo_main(current->cmd, 1);
		return (true);
	}
	if (ft_strncmp(current->cmd[0], "pwd", 4) == 0)
	{
		g_ms.exit = ms_pwd_main(1);
		return (true);
	}
	return (ms_check_builtin2(current));
}
