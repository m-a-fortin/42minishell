/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:01:34 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/19 07:53:45 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

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
typedef struct s_redir
{
	t_type	type;
	char	*file;
}	t_redir;

// linkedlist peupler par le parsing et utiliser par l'execution. 
// les nodes doivent etre free apres l'exec
typedef struct s_job
{
	char			**cmd;//nom de la commande - name of the command
	char			**redir; //job de redirection
	int				pipe;
	int				error;
	struct s_job	*next;//pointeur vers la prochaine commande NULL 
						  //si y'en a pas - pointer to the next command, points to NULL if none.
}			t_job;

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

extern	t_exec g_ms;
void	ms_nl_signal(int signal);
char	*ms_getenv(char *name, char **envp_ms);
char	**ms_setenv(char *name, char *value, char **envp_ms);
void	ms_free_job(t_job *job_head, t_job *current);
t_job	*init_node(t_job *node);
t_job	*ms_new_job(void);
void	ms_job_addback(t_job **job, t_job *new);
void	ms_initjob(t_job *node);

#endif
