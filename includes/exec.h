/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:58:58 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/08 11:28:24 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

#include "minishell.h"


typedef struct s_exec
{
	char	**env;
	int		exit;
	int		exec;
}			t_exec;

extern t_exec ms;

int		ms_pwd_main(int fd);
int		ms_cd_main(char **cmd, char **envp_ms);
int		ms_echo_main(char **args, int fd);
int		ms_env_main(char **envp_ms, char **args, int fd);
void	ms_exec_error(char *value, char *cmd_name, char *error_str);
void	ms_print_exec_error(char *value, char *cmd_name, char *error_str);
int		ms_export_main(char **args, int fd);
int		ms_unset_main(char **args);
void	ms_check_dollarsign(t_job *job_head);
void	ms_exec_main(t_job *job_head);

#endif