/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:25:12 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/29 18:20:49 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//loop de readline qui envoie les infos au parsing. FONCTIONNE
void	ms_readline_loop(char **envp_ms)
{
	char	*input;
	char	**cmd;

	cmd = malloc(sizeof(char *) * 3);
	cmd[0] = malloc(sizeof(char) * 3);
	cmd[1] = malloc(sizeof(char) * 3);
	cmd[2] = 0;
	ft_strlcpy(cmd[0], "cd", 3);
	ft_strlcpy(cmd[1], "..", 3);
	signal(SIGINT, ms_nl_signal);
	signal(SIGQUIT, SIG_IGN);
	while (true)
	{
		input = readline("MiniShell % ");
		if (ft_strncmp(input, "PWD", 3) == 0)
			ms_pwd_main();
		if (ft_strncmp(input, "cd ..", 5) == 0)
			ms_cd_main(cmd, envp_ms);

		//fonction qui recoit l'input (PARSING)
		//fonction qui exec avec la linked list global
		free (input);
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	**envp_ms = NULL;
	//t_job	*cmd_head;//structure-linkedlist peupler par le parsing et utliser pour l'execution
	//cree et placer ici une fonction pour bien init la linked list (EXEC OU PARSING)
	argv++;
	argc++;
	envp_ms = ft_matrice_cpy(envp);
	ms_readline_loop(envp_ms);
	ft_free_tab(envp_ms);
}
