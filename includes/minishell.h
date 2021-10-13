/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:01:34 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/13 18:48:35 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>
typedef enum e_type
{
	PIPE,
	R_HDOC,
	L_HDOC,
	R_REDIR,
	L_REDIR,
	STRING,
	VARIABLE,
	EMPTY,
}	t_type;
typedef struct s_redir
{
	t_type	type;
	char	*file;
}	t_redir;

//linkedlist peupler par le parsing et utiliser par l'execution. les nodes doivent etre free apres l'exec
typedef struct s_job
{
	char			**cmd;//nom de la commande - name of the command
	t_redir			*redir; //job de redirection
	int				pipe;
	int				error;
	struct s_job	*next;//pointeur vers la prochaine commande NULL si y'en a pas - pointer to the next command, points to NULL if none.
}			t_job;

typedef struct s_exec
{
	char	**env;
	bool	singlequote;
	int		exit;
	int		exec;
}			t_exec;

extern t_exec g_ms;
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <limits.h>
# include <dirent.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# include "token.h"
# include "parse.h"
# include "exec.h"
# include "shell_errors.h"

void	ms_nl_signal(int signal);
char	*ms_getenv(char *name, char **envp_ms);
char	**ms_setenv(char *name, char *value, char **envp_ms);
void	ms_free_job(t_job *job_head, t_job *current);
t_job	*ms_create_node(t_job *node);
void	ms_initjob(t_job *node);

#endif
