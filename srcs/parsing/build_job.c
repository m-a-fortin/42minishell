/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_job.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:46:17 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/21 15:03:41 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	print_tab(t_job *job)
// {
// 	int	i;
// 	int	j;

// 	j = 1;
// 	if (job)
// 	{
// 		while (job)
// 		{
// 			printf("\n\e[32mJOB %d\n\e[0mCOMMANDS\n----------------\n", j);
// 			i = 0;
// 			if (job->cmd)
// 			{
// 				while (job->cmd[i])
// 				{
// 					printf("CMD:[%d]  %s\n", i, job->cmd[i]);
// 					i++;
// 				}
// 			}
// 			if (job->redir)
// 			{
// 				printf("\nREDIRECTION\n--------------\n");
// 				i = 0;
// 				while (job->redir[i])
// 				{
// 					printf("[%d]  %s\n", i, job->redir[i]);
// 					i++;
// 				}
// 			}
// 			j++;
// 			job = job->next;
// 		}
// 	}
// 	printf("\n");
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
	if (tok->type == L_HDOC)
	{
		heredoc_inputs(tok, job);
		return ;
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

t_job	*build_job(t_token *token, t_job *job)
{
	t_job	*job_head;
	t_token	*token_head;

	job = ft_calloc(1, sizeof(t_job));
	job_head = job;
	token_head = token;
	while (token->next != NULL)
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
			build_redirection(token, job);
			token = token->next;
		}
		token = token->next;
	}
	free_list(token_head);
	return (job_head);
}
