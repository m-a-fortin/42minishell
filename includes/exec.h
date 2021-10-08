/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpst <hpst@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:58:58 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/06 18:05:35 by hpst             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

#include "minishell.h"


typedef struct s_exec
{
	char	**env;
	int		exit;
}			t_exec;

int		ms_pwd_main(int fd);
int		ms_cd_main(char **cmd, char **envp_ms);
int		ms_echo_main(char **args, int fd);
int		ms_env_main(char **envp_ms, char **args, int fd);
void	ms_exec_error(char *value, char *cmd_name, char *error_str);
void	ms_print_exec_error(char *value, char *cmd_name, char *error_str);
int		ms_export_main(t_exec *env, char **args, int fd);
int		ms_unset_main(t_exec *ms, char **args);
void	ms_check_dollarsign(t_exec *ms, t_job g_job);

#endif