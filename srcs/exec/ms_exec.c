/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 09:44:24 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/18 10:53:26 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ms_exec_main(t_job *job_head)
{
	t_job	*current;
	//bool	pipe;
	
	current = job_head;
	//if (job_head->next)
		//pipe = true;
	//else
		//pipe = false;
	//current->redir[0] = ft_strdup(">");
	//current->redir[1] = ft_strdup("test1");
	while (current)
	{
		//ms_check_quotes();
		dollarsign_main(current);
		if (ms_redirection_main(current) == false)
		{
			g_ms.exit = 127;
			return ;
		}
		trimquotes_main(current);
		g_ms.exec = 1;
		ms_check_builtin(current, job_head, g_ms.out);
		//if(ms_check_builtin(current, job_head, in_out[0], in_out[1] == false)
		//if(ms_exec_fork(t_job *current, t_job *job_head, in_out) == false)
		//{
			//return;
		//}
		if (current->next)
			current = current->next;
		else
			break ;
	}
}
