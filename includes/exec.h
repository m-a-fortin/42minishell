/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpst <hpst@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:58:58 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/15 21:39:37 by hpst             ###   ########.fr       */
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
void	ms_exec_main(t_job *job_head);
int		ms_exit_main(t_job *job_head, t_job *current);
bool	ms_check_builtin(t_job *current, t_job *job_head, int out);
void	ms_export_print(char **envp, int fd);
char	*ms_findpath(char *cmd);
bool	ms_execve_error(char *pathname, char *cmd_name);
bool	ms_pathname_error(char *cmd_name);
bool	ms_redirection_main(t_job *current);


#endif