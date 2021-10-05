/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpst <hpst@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:32:43 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/01 15:31:07 by hpst             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//Fonctions qui gere le signal envoyer quand ctrl+c est entree au clavier.
void	ms_nl_signal(int signal)
{
	signal++;
	write(1, "\n", 2);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	ms_exit_signal(int signal, char **envp)
{
	signal++;
	ft_free_tab(envp);
	exit (0);
}
