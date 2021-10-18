/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:25:12 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/18 13:07:39 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_exec	g_ms = {0};

void	print_header(void)
{
	PF("\e[32m| |_|  |_|_|_| |_|_|\e[36m___/_| |_|\\___|_|_| |\e[0m\n");
	PF("\e[36m\\ _________________\e[32m____________________ /\e[0m\n");
	PF("Created by: Marc-Andre Fortin & Maxime Mondello\n");
	PF("Version: 1.0\n");
	PF("\n\n\n");
}

//loop de readline qui envoie les infos au parsing et qui execute 
//le retour du parsing.
void	ms_readline_loop(void)
{
	char		*input;

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
		job_head = parse_input(input, job_head);
		if (job_head)
		{
			ms_exec_main(job_head);
			ms_free_job(job_head, job_head);
		}
		free (input);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_job		*job_head;

	job_head = NULL;
	argv++;
	if (argc > 1)
	{
		ft_putstr_fd("Error\nminishell: invalid number of arguments\n", 1);
		exit(-1);
	}
	print_header();
	g_ms.env = ft_matrice_cpy(envp);
	ms_readline_loop(job_head);
}
