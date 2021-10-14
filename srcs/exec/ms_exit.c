/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:46:55 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/13 14:36:45 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ms_exit_number(char **cmd)
{
	int	number;

	number = ft_atoi(cmd[1]);
	if (number >= 0)
		g_ms.exit = number % 256;
	else
	{
		number %= 256;
		g_ms.exit = 256 + number;
	}
	return (true);
}

bool	ms_exit_check(char **cmd)
{
	if (ft_isdigit_string(cmd[1]) == 1)
		return (ms_exit_number(cmd));
	g_ms.exit = 255;
	ft_putstr_fd("exit: ", 1);
	ft_putstr_fd(cmd[1], 1);
	ft_putendl_fd(": numeric argument required", 1);
	return (true);
}

//sujet a changer, par exemple si on decide que chaque job est une node dans la linked list
//faut je change le code, si une node = un pipe/fork, la fonctions est correct.
int	ms_exit_return(t_job *job_head, t_job *current)
{
	if (job_head == current && current->next == NULL)
	{
		ft_free_tab(g_ms.env);
		//ms_free_job(job_head, job_head);
		exit (g_ms.exit);
	}
	return (g_ms.exit);
}

//Exit avec un code de retour. Set g_ms.exit au chiffre entrer en arguments de exit.
// 0 si aucun argument, 1 si il y + que un argument et 255 si l'argument n'est pas un chiffre.
// N'exit pas minishell si exit est dans un pipe.
int	ms_exit_main(t_job *job_head, t_job *current)
{
	int		depth;
	char	**cmd;
	int		check;

	cmd = current->cmd;
	depth = ft_matrice_size(cmd);
	if (depth > 2)
	{
		ft_putendl_fd("exit: too many arguments", 1);
		g_ms.exit = 1;
		check = false;
	}
	if (depth == 1)
	{
		g_ms.exit = 0;
		check = true;
	}
	else
		check = ms_exit_check(cmd);
	return (ms_exit_return(job_head, current));
}
