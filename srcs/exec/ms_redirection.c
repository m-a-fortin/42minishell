/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:13:33 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/18 11:28:17 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ms_redirection_in(char *sign, char *next)
{	
	if (sign[1] == '\0')
		g_ms.in = open(next, O_RDONLY);
	if (g_ms.in == -1)
	{
		ft_putstr_fd("ERROR OPEN", 1);//faire msg d'erreur.
		return (false);
	}
	if (dup2(g_ms.in, 0) == -1)
	{
		ft_putstr_fd("ERROR DUP", 1);//faire msg d'erreur.
		return (false);
	}
	close(g_ms.in);
	return (true);
}

bool	ms_redirection_out(char *sign, char *next)
{
	if (sign[1] == '\0')
		g_ms.out = open(next, O_CREAT | O_RDWR |O_TRUNC, 0644);
	else
		g_ms.out = open(next, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (g_ms.out == -1)
	{
		ft_putstr_fd("ERROR OPEN", 1);//faire msg d'erreur.
		close(g_ms.out);
		return (false);
	}
	if (dup2(g_ms.out, 1) == -1)
	{
		ft_putstr_fd("ERROR DUP", 1);//faire msg d'erreur.
		return (false);
	}
	dup2(g_ms.out, 1);
	close (g_ms.out);
	return (true);
}

bool	ms_redirection_loop(char *sign, char *next)
{

	if (sign[0] == '>')
		return (ms_redirection_out(sign, next));
	if (sign[0] == '<')
		return (ms_redirection_in(sign, next));
	return (false);
}

//A l'aide de dup2. Change le stdout/in pour 
//un nouveau fd (g_ms.in ou g_ms.out). Fonctionne dans une loop
//pour les cas de plusieurs redirection.
bool	ms_redirection_main(t_job *current)
{
	int		x;

	x = 0;
	if (!current->redir)
		return (true);
	while (current->redir[x])
	{
		if (ms_redirection_loop(current->redir[x], current->redir[x + 1])
			==	false)
			return (false);
		if (!current->redir[x + 1])
			break ;
		x += 2;
	}
	return (true);
}