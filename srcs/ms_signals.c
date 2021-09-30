/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:32:43 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/30 17:16:16 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//Fonctions qui gere le signal envoyer quand ctrl+c est entree au clavier.
void	ms_nl_signal(int signal)
{
	signal = 1;
	write(1, "\n", 2);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	ms_exit_signal(int signal, char **envp)
{
	signal = 1;
	ft_free_tab(envp);
	exit (0);
}
