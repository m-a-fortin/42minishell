/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:25:12 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/08 11:23:22 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_exec ms = {0};
//loop de readline qui envoie les infos au parsing et qui execute le retour du parsing.
void	ms_readline_loop(void)
{
	char	*input;
	t_job	*job_head = NULL;
	
	
	signal(SIGINT, ms_nl_signal);
	signal(SIGQUIT, SIG_IGN);
	ms_initjob(job_head);
	while (true)
	{
		ms.exec = 0;
		input = readline("MiniShell % ");
		//parse_input(input, job_head);
		ms_exec_main(job_head);
		free (input);
		
	}
}

int	main(int argc, char **argv, char **envp)
{
	argv = NULL;
	if (argc > 1)
	{
		ft_putstr_fd("Error\nminishell: invalid number of arguments\n", 1);
		exit(-1);
	}
	ms.env = ft_matrice_cpy(envp);
	ms_readline_loop();
	ft_free_tab(ms.env);
}
