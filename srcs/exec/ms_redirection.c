/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:13:33 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/26 15:27:22 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ms_hdocs_write(t_job *current)
{
	if (pipe(current->hdoc_fd) == -1)
		return (false);
	dup2(current->hdoc_fd[0], 0);
	ft_putstr_fd(current->hdoc, current->hdoc_fd[1]);
	close(current->hdoc_fd[0]);
	close(current->hdoc_fd[1]);
	return (true);
}

bool	ms_redirection_in(char *sign, char *next, t_job *current)
{	
	int	fd_in;

	fd_in = 0;
	(void)current;
	if (sign[1] == '\0')
		fd_in = open(next, O_RDONLY);
	else
		return (ms_hdocs_write(current));
	if (fd_in == -1)
	{
		perror("Minishell:");
		ft_putchar_fd('\n', 1);
		return (false);
	}
	if (dup2(fd_in, 0) == -1)
	{
		perror("Minishell:");
		ft_putchar_fd('\n', 1);
		return (false);
	}
	close(fd_in);
	return (true);
}

bool	ms_redirection_out(char *sign, char *next)
{
	int	fd_out;

	if (sign[1] == '\0')
		fd_out = open(next, O_CREAT | O_RDWR | O_TRUNC, 0644);
	else
		fd_out = open(next, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (fd_out == -1)
	{
		perror("Minishell");
		return (false);
	}
	if (dup2(fd_out, 1) == -1)
	{
		perror("Minishell");
		return (false);
	}
	dup2(fd_out, 1);
	close (fd_out);
	return (true);
}

bool	ms_redirection_loop(char *sign, char *next, t_job *current)
{	
	(void)current;
	if (sign[0] == '>')
		return (ms_redirection_out(sign, next));
	if (sign[0] == '<')
		return (ms_redirection_in(sign, next, current));
	return (false);
}

//*A l'aide de dup2. Change le stdout/in pour 
//*un nouveau fd (g_ms.in ou g_ms.out). Fonctionne dans une loop
//*pour les cas de plusieurs redirection.
bool	ms_redirection_main(t_job *current)
{
	int		x;

	x = 0;
	if (!current->redir)
		return (true);
	while (current->redir[x])
	{
		if (ms_redirection_loop(current->redir[x],
				current->redir[x + 1], current) == false)
			return (false);
		if (!current->redir[x + 1])
			break ;
		x += 2;
	}
	return (true);
}
