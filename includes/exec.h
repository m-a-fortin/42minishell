/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:58:58 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/09 13:40:46 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

#include "minishell.h"

int		ms_pwd_main(int fd);
int		ms_cd_main(char **cmd);
int		ms_echo_main(char **args, int fd);
int		ms_env_main(char **args, int fd);
void	ms_exec_error(char *value, char *cmd_name, char *error_str);
void	ms_print_exec_error(char *value, char *cmd_name, char *error_str);
int		ms_export_main(char **args, int fd);
int		ms_unset_main(char **args);
void	ms_check_dollarsign(t_job *job_head);
void	ms_exec_main(t_job *job_head);
char	*ms_dollar_exit(char *arg);
char	*ms_arg_empty(char *arg);
int		ms_exit_main(t_job *job_head, t_job *current);
bool	ms_check_builtin(t_job *current, t_job *job_head, int out);
void	ms_export_print(char **envp, int fd);

#endif