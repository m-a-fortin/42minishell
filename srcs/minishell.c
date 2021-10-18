/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:25:12 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/18 11:24:10 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_exec	g_ms = {0};

//loop de readline qui envoie les infos au parsing et qui execute 
//le retour du parsing.
void	ms_readline_loop(void)
{
	char		*input;
	t_job		*job_head;

	job_head = NULL;
	signal(SIGINT, ms_nl_signal);
	signal(SIGQUIT, SIG_IGN);
	while (true)
	{
		g_ms.exec = 0;
		input = readline("MiniShell % ");
		if (!input)
		{
			free(input);
			ms_free_job(job_head, job_head);
			exit(g_ms.exit);
		}
		add_history(input);
		//job_head->cmd = ft_split(input, ' ');
		job_head = parse_input(input, job_head);
		//TODO if job_head == NULL set g_ms.error to BAD_SYNTAX
		ms_exec_main(job_head);
		ms_free_job(job_head, job_head);
		free (input);
	}
}

int	main(int argc, char **argv, char **envp)
{
	argv++;
	if (argc > 1)
	{
		ft_putstr_fd("Error\nminishell: invalid number of arguments\n", 1);
		exit(-1);
	}
	g_ms.env = ft_matrice_cpy(envp);
	ms_readline_loop();
}
