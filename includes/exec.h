/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:58:58 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/18 15:52:55 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

#include "minishell.h"

typedef struct s_exec
{
	char	**env;
	bool	singlequote;
	bool	doublequote;
	int		stdin;
	int		stdout;
	int		in;
	int		out;
	int		exit;
	int		exec;
}			t_exec;

typedef struct s_job t_job;

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
bool	ms_pathname_error(char *cmd_name);
bool	ms_redirection_main(t_job *current);
bool	ms_exec_fork(char **cmd);
void	ms_return_fd(void);
char	*ms_get_cmdpath(char *cmd_name, char *cmd)

#endif