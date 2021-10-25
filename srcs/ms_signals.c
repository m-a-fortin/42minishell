/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:32:43 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/22 11:45:59 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Fonctions qui gere le signal envoyer quand ctrl+c est entree au clavier.
void	ms_nl_signal(int signal)
{	
	(void)signal;
	signal = g_ms.exit;
	write(1, "\n", 2);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	ms_nl_signal_exec(int *signal)
{
	*signal = 130;
	write(1, "\n", 2);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	ms_exit_signal(int signal, char **envp)
{
	(void)signal;
	ft_free_tab(envp);
	exit (0);
}

void	ms_donothing(int signal)
{
	(void)signal;
}

void	ms_setsignals(void)
{
	signal(SIGINT, ms_nl_signal);
	signal(SIGQUIT, SIG_IGN);
}
