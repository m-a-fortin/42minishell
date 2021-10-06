/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpst <hpst@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:01:34 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/06 09:33:14 by hpst             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//linkedlist peupler par le parsing et utiliser par l'execution. les nodes doivent etre free apres l'exec
typedef struct s_job
{
	char			**cmd;//nom de la commande - name of the command
	char			*redirection; //job de redirection
	int				pipe;
	int				error;
	struct s_job	*next;//pointeur vers la prochaine commande NULL si y'en a pas - pointer to the next command, points to NULL if none.
}			t_job;

typedef struct s_exec
{
	char	**env;
	int		exit;
}			t_exec;

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

void	ms_nl_signal(int signal);
char	*ms_getenv(char *name, char **envp_ms);
char	**ms_setenv(char *name, char *value, char **envp_ms);

#endif
