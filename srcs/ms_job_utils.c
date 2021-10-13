/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_job_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 09:49:51 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/13 14:35:56 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_job	*ms_create_node(t_job *node)
{
	node = malloc(sizeof(t_job));
	node->redirection = NULL;
	node->cmd = NULL;
	node->error = 0;
	node->next = NULL;
	return (node);
}

void	ms_new_job(t_job *job_head)
{
	t_job	*current;

	current = job_head;
	if (job_head)
	{
		while (current->next)
			current = current->next;
		ms_create_node(current->next);
	}
}

//void	ms_free_job(t_job *job_head, t_job *current)
//{	
	//if (current->next)
		//ms_free_job(job_head, current->next);
	//if (current->cmd)
		//ft_free_tab(current->cmd);
	//if (current->redirection)
		//free(current->redirection);
	//job_head = current;
	//if (current)
		//free(current);
//}
