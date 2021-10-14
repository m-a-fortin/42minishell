/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:13:33 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/14 17:34:33 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ms_redirection_out(int *in_out, char *sign, char *next)
{
	int	fd;

	if (sign[1] == '\0')
		fd = open(next, O_CREAT, O_RDWR);
	else
		fd = open(next, O_CREAT, O_TRUNC);
	//if (fd == -1)
	 //DEAL ERROR
	dup2(fd, 1);
	close(fd);
	in_out[1] = fd;
}

void	ms_redirection_loop(int *in_out, char *sign, char *next)
{

	if (sign[0] == '>')
		return (ms_redirection_out(in_out, sign, next));
}

void	ms_redirection_main(int	*in_out, t_job *current)
{
	int		x;

	x = 0;
	if (!current->redir)
		return ;
	while (current->redir[x])
	{
		ms_redirection_loop(in_out, current->redir[x], current->redir[x + 1]);
		x++;
	}
	
}