/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:39:22 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/20 15:11:42 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool ms_check_builtin2(t_job* current, t_job *job_head, int out)
{
	if (ft_strncmp(current->cmd[0], "export", 7) == 0)
	{
		g_ms.exit = ms_export_main(current->cmd, out);
		return (true);
	}
	if (ft_strncmp(current->cmd[0], "unset", 6) == 0)
	{
		g_ms.exit = ms_unset_main(current->cmd);
		return (true);
	}
	if (ft_strncmp(current->cmd[0], "env", 4) == 0)
	{
		g_ms.exit = ms_env_main(current->cmd, out);
		return (true);
	}
	if (ft_strncmp(current->cmd[0], "exit", 5) == 0)
	{
		g_ms.exit = ms_exit_main(job_head, current);//important de verifier les cas de pipe + redirection.
		return (true);
	}
	return (false);
}

bool	ms_check_builtin(t_job *current, t_job *job_head, int out)
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
		g_ms.exit = ms_pwd_main(out);
		return (true);
	}
	return (ms_check_builtin2(current, job_head, out));
}

//Si export n'a pas d'arguments, Il print envp avec "declare -x"
void	ms_export_print(char **envp, int fd)
{
	char	**print;

	print = ft_sort_strtab(envp);
	ft_print_matrice_fd(print, fd);
	ft_free_tab(print);
}
