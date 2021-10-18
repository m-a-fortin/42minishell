/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 09:44:24 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/18 13:05:12 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ms_saved_fd(void)
{
	g_ms.stdin = dup(0);
	g_ms.stdout = dup(1);
	g_ms.in = 0;
	g_ms.out = 1;
	g_ms.stdin = 0;
	g_ms.stdout = 1;
	g_ms.singlequote = false;
	g_ms.doublequote = false;
}

void	ms_return_fd(void)
{
	dup2(g_ms.stdin, 0);
	dup2(g_ms.stdout, 1);
}

void	ms_exec_main(t_job *job_head)
{
	t_job	*current;
	//bool	pipe;
	
	current = job_head;
	//if (job_head->next)
		//pipe = true;
	//else
		//pipe = false;
	while (current)
	{
		//ms_check_quotes();
		ms_saved_fd();
		dollarsign_main(current);
		if (ms_redirection_main(current) == false)
		{
			g_ms.exit = 127;
			return ;
		}
		trimquotes_main(current);
		g_ms.exec = 1;
		ms_check_builtin(current, job_head, 1);
		//if(ms_check_builtin(current, job_head, in_out[0], in_out[1] == false)
		//if(ms_exec_fork(t_job *current, t_job *job_head, in_out) == false)
		//{
			//return;
		//}
		ms_return_fd();
		if (current->next)
			current = current->next;
		else
			break ;
	}
}
