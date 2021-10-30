/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:25:12 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/30 14:25:44 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_exec	g_ms = {0};

void	print_header(void)
{
	printf("\e[96m  _________________\e[92m____________________\n");
	printf("\e[92m/  __  __ _       _\e[96m     _          _ _  \\ \n");
	printf("\e[92m| |  \\/  (_)_ __ (_)\e[96m___| |__   ___| | | |\n");
	printf("\e[92m| | |\\/| | | '_ \\| \e[96m/ __| '_ \\ / _ \\ | | | \n");
	printf("\e[92m| | |  | | | | | | \e[96m\\__ \\ | | |  __/ | | |\n");
	printf("\e[92m| |_|  |_|_|_| |_|_|\e[96m___/_| |_|\\___|_|_| |\n");
	printf("\e[96m\\ _________________\e[92m____________________ /\e[0m\n");
	printf("______________________________________________\n");
	printf("Created by: Marc-Andre Fortin & Maxime Mondello\n");
	printf("Version: 1.0\n");
	printf("______________________________________________");
	printf("\n\n\n");
}

//*loop de readline qui envoie les infos au parsing et qui execute 
//*le retour du parsing.
void	ms_readline_loop(t_job *job_head)
{
	char	*input;

	ms_setsignals();
	while (true)
	{
		input = readline(PROMPT);
		if (!input)
		{
			ft_putendl_fd("Exit", 2);
			exit(g_ms.exit);
		}
		if (input[0] == '\0')
		{
			free(input);
			continue ;
		}
		add_history(input);
		job_head = parse_input(input, job_head);
		if (job_head && job_head->cmd)
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
	(void)argv;
	if (argc > 1)
	{
		ft_putstr_fd("Error\nminishell: invalid number of arguments\n", 1);
		exit(-1);
	}
	g_ms.env = ft_matrice_cpy(envp);
	g_ms.export = ft_sort_strtab(g_ms.env);
	ms_saved_fd();
	print_header();
	ms_readline_loop(job_head);
}
