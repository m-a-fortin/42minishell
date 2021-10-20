/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 00:15:17 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/18 13:19:35 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ms_print_exec_error(char *value, char *cmd_name, char *error_str)
{
	ft_putstr_fd(SHELL, STDERR_FILENO);
	ft_putstr_fd(cmd_name, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(value, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(error_str, STDERR_FILENO);
}

bool	ms_pathname_error(char *cmd_name)
{
	ft_putstr_fd("Minishell: ", 1);
	ft_putstr_fd(cmd_name, 1);
	ft_putendl_fd(": command not found", 1);
	g_ms.exit = 127;
	return (false);
}

bool	ms_execve_error(char *pathname)
{
	free(pathname);
	ft_putendl_fd("Minishell: Execve failed", 1);
	g_ms.exit = errno;
	return (false);
}
