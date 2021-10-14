/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_job.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:46:17 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/14 08:16:59 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*copy_to_job_cmd(t_token *tok, t_job *job)
{
	int	i;
	int	count;

	i = 0;
	count = count_string_nodes(tok) + 1;
	while (tok->type == STRING)
	{
		job->cmd = ft_calloc(count, sizeof(char));
		while (i < count)
		{
			if (tok->next->type != STRING)
				return (tok) ;
			job->cmd[i] = ft_calloc(ft_strlen(tok->valid_token) + 1, sizeof(char));
			ft_strlcpy(job->cmd[i], tok->valid_token, ft_strlen(tok->valid_token) + 1);
			i++;
			tok = tok->next;
		}
	}
	return (tok);
}

t_job	*build_job(t_token *token, t_job *job)
{
	t_job	*job_head;
	t_token	*token_head;

	job_head = job;
	token_head = token;
	while (token)
	{
		if (token->type == STRING)
			token = copy_to_job_cmd(token, job);
		job = job->next;
	}
	return (job_head);
}
