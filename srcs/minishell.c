/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:25:12 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/18 10:55:53 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_exec	g_ms = {0};

//loop principal. Le retour de readline passe par la syntax,
//le parsing et puis ensuite l'exec.
void	ms_readline_loop(t_job *job_head)
{
	char		*input;

	signal(SIGINT, ms_nl_signal);
	signal(SIGQUIT, SIG_IGN);
	while (true)
	{
		job_head = ms_create_node(job_head);
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
		else
			g_ms.exit = BAD_SYNTAX;
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
	g_ms.env = ft_matrice_cpy(envp);
	ms_readline_loop(job_head);
}
