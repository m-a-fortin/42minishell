/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 09:44:24 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/09 12:48:31 by mafortin         ###   ########.fr       */
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
	while (current)
	{
		ms_check_dollarsign(current);
		//in_out = ms_redirection_main(current, job_head, in_out);
		ms_check_builtin(current, job_head, in_out[1]);
		//if(ms_check_builtin(current, job_head, in_out[0], in_out[1] == false)
		//ms_execve()
		if (current->next)
			current = current->next;
		else
			break ;
	}
	ms_free_job(job_head, job_head);
}
