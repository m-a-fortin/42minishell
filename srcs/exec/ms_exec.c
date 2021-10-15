/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpst <hpst@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 09:44:24 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/15 12:09:42 by hpst             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ms_exec_main(t_job *job_head)
{
	t_job	*current;
	int		in_out[2];
	
	in_out[0] = 0;
	in_out[1] = 1;
	current = job_head;
	g_ms.exec = 1;
	g_ms.singlequote = false;
	g_ms.doublequote = false;
	while (current)
	{
		//ms_check_quotes();
		dollarsign_main(current);
		//if (g_ms.doublequote == false && g_ms.singlequote == false)
			//in_out = ms_redirection_main(current, job_head, in_out);
		trimquotes_main(current);
		ms_check_builtin(current, job_head, in_out[1]);
		//if(ms_check_builtin(current, job_head, in_out[0], in_out[1] == false)
		//if(ms_exec_fork(t_job *current, t_job *job_head, in_out) == false)
		//{
			//ms_free_job(job_head, job_head);
			//return;
		//}
		if (current->next)
			current = current->next;
		else
			break ;
	}
}
