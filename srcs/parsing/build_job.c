/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_job.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:46:17 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/11 14:13:41 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_job	*build_or_free(t_token *token, t_job *job_head)
{
	t_token *head;
	t_token	*tmp;

	head = token;
	while (token)
	{
		if (token->interupt == true)
		{
			if (job_head)
				ms_free_job(job_head);
			return (NULL);
		}
		token = token->next;
	}
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->token);
		free(tmp);
	}
	return (job_head);
}

void	allocate_and_copy(t_token *tok, t_job *job, int i)
{
	job->redir[i] = ft_calloc(ft_strlen(tok->token) + 1, sizeof(char));
	ft_strlcpy(job->redir[i], tok->token, ft_strlen(tok->token) + 1);
}

bool	build_redirection(t_token *tok, t_job *job)
{
	int	i;
	int	count;

	i = 0;
	if (tok->type == L_HDOC)
		return (build_heredoc(tok, job));
	if (!job->redir)
	{
		count = count_redirections(tok);
		job->redir = (char **)ft_calloc(count + 1, sizeof(char *));
	}
	while (job->redir[i])
		i++;
	allocate_and_copy(tok, job, i);
	i++;
	if (!tok->next)
		return (true);
	tok = tok->next;
	allocate_and_copy(tok, job, i);
	return (true);
}

void	build_cmd_and_args(t_token *tok, t_job *job)
{
	int	i;
	int	count;

	i = 0;
	if (!job->cmd)
	{
		count = count_cmd_and_args(tok);
		job->cmd = (char **)ft_calloc(count + 1, sizeof(char *));
	}
	while (job->cmd[i])
		i++;
	job->cmd[i] = ft_calloc(ft_strlen(tok->token) + 1, sizeof(char));
	ft_strlcpy(job->cmd[i], tok->token, ft_strlen(tok->token) + 1);
}

t_job	*build_job(t_token *token, t_job *job)
{
	t_job	*job_head;

	job = ms_new_job();
	job_head = job;
	while (token)
	{
		if (token->type == PIPE)
		{
			ms_job_addback(&job, ms_new_job());
			job = job->next;
		}
		else if (token->type == STRING)
			build_cmd_and_args(token, job);
		else if (is_redirection(token))
		{
			if (!build_redirection(token, job))
				break ;
			token = token->next;
		}
		if (!token->next)
			break ;
		token = token->next;
	}
	return (build_or_free(rewind_list(token), job_head));
}
