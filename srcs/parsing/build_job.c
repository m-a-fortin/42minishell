/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_job.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:46:17 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/14 10:24:22 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_tab(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		printf("%s\n", cmd[i++]);
	printf("Number of brackets: %d\n", i);
}

void	build_redirection(t_token *tok, t_job *job)
{

}

void	build_cmd_and_args(t_token *tok, t_job *job)
{
	int	i;
	int	count;

	i = 0;
	count = count_cmd_and_args(tok) + 1;
	job->cmd = (char **)ft_calloc(count, sizeof(char *));
	while (tok->type == STRING)
	{
		while (i <= count)
		{
			if (tok->type != STRING)
				return (tok) ;
			job->cmd[i] = ft_calloc(ft_strlen(tok->token) + 1, sizeof(char));
			ft_strlcpy(job->cmd[i], tok->token, ft_strlen(tok->token) + 1);
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
			build_cmd_and_args(token, job);
		if (token->next->type != STRING && token->next->type != PIPE)
		 	build_redirection(token, job);
		token = token->next;
		//job = job->next;
	}
	print_tab(job_head->cmd);
	return (job_head);
}
