/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_job_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 09:49:51 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/18 13:03:32 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_job	*ms_job_lastnode(t_job *job)
{
	while (job)
	{
		if (job->next == NULL)
			return (job);
	}
	return (job);
}

void	ms_job_addback(t_job **job, t_job *new)
{
	t_job	*last;

	if (job)
	{
		if (*job)
		{
			last = ms_job_lastnode(*job);
			last->next = new;
		}
		else
			*job = new;
	}
}

t_job	*ms_new_job(void)
{
	t_job	*new;

	new = ft_calloc(1, sizeof(t_job));
	if (!new)
		return (NULL);
	return (new);
}

void	ms_free_job(t_job *job_head, t_job *current)
{	
	if (!current)
		return ;
	if (current->next)
		ms_free_job(job_head, current->next);
	if (current->cmd)
		ft_free_tab(current->cmd);
	if (current->redir)
		free(current->redir);
	job_head = current;
	if (current)
		free(current);
}
