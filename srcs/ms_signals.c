/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:32:43 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/05 09:22:53 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
