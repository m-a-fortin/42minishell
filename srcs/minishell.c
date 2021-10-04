/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:25:12 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/04 15:47:16 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//loop de readline qui envoie les infos au parsing. FONCTIONNE
void	ms_readline_loop(t_shell *env)
{
	char	*input;
	//char	**job;


	signal(SIGINT, ms_nl_signal);
	signal(SIGQUIT, SIG_IGN);
	while (true)
	{
		input = readline("MiniShell % ");
		//parse_input(input);
		//ms_exec_main(t_job *job_head, char **envp_ms);
		free (input);
		//ft_free_tab(job);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_shell *env;

	env = malloc(sizeof(t_shell));//pas oublier de free la struct et son
	//t_job	*job_head;//structure-linkedlist peupler par le parsing et utliser pour l'execution
	//cree et placer ici une fonction pour bien init la linked list (EXEC OU PARSING)

	if (argc > 1)
	{
		ft_putstr_fd("Error\nminishell: invalid number of arguments\n", 1);
		exit(-1);
	}
	argv++;
	env->ms = ft_matrice_cpy(envp);
	ms_readline_loop(env);
	ft_free_tab(env->ms);
}
