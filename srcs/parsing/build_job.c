/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_job.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:46:17 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/15 12:26:08 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	print_tab(t_job *job)
// {
// 	int	i;

// 	i = 0;
// 	printf("commands and args\n------------------\n");
// 	while (job->cmd[i])
// 	{
// 		printf("[%d]  %s\n",i ,job->cmd[i]);
// 		i++;
// 	}
// 	printf("all redirections\n------------------\n");
// 	i = 0;
// 	while (job->redir[i])
// 	{
// 		printf("[%d]  %s\n",i ,job->redir[i]);
// 		i++;
// 	}
// }

void	build_redirection(t_token *tok, t_job *job)
{
	int	i;
	int	count;

	i = 0;
	if (!job->redir)
	{
		count = count_redirections(tok);
		job->redir = (char **)ft_calloc(count + 1, sizeof(char *));
	}
	while (job->redir[i])
		i++;
	job->redir[i] = ft_calloc(ft_strlen(tok->token) + 1, sizeof(char));
	ft_strlcpy(job->redir[i], tok->token, ft_strlen(tok->token) + 1);
	i++;
	tok = tok->next;
	job->redir[i] = ft_calloc(ft_strlen(tok->token) + 1, sizeof(char));
	ft_strlcpy(job->redir[i], tok->token, ft_strlen(tok->token) + 1);
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

t_job	*build_job(t_token *token_head, t_job *job_head)
{
	t_job	*job;
	t_token	*token;

	job = job_head;
	token = token_head;
	while (token->next != NULL)
	{
		if (token->type == PIPE)
		{
			token = token->next;
			job = job->next;
		}
		else if (token->type == STRING)
		{
			build_cmd_and_args(token, job);
			token = token->next;
		}
		else if (is_redirection(token))
		{
			build_redirection(token, job);
			token = token->next->next;
		}
	}
	free_list(token_head);
	return (job_head);
}
