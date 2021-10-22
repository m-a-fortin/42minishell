/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdoc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:40:01 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/22 14:52:57 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	create_pipe(int fd)
{
	if (pipe(fd) == -1)
	{
		perror("Minishell: ");
		return(false);
	}
	return (true);
}

char	*find_delimiter(t_token *token)
{
	token = token->next;
	return(token->token);
}

void	add_hdoc_job(t_job *job, char *heredoc, int *fd)
{
	if (job->hdoc)
		free(job->hdoc);
	job->hdoc = ft_calloc(ft_strlen(heredoc) + 1, sizeof(char));
	ft_strlcpy(job->hdoc, heredoc, ft_strlen(heredoc) + 1);
	ms_pipedup_in();
	ft_putstr_fd(heredoc, fd[1]);
}

char	*join_inputs(char *input, char *heredoc)
{
	char	*temp;
	
	temp = ft_strjoin(heredoc, input);
	temp = ft_append_string(temp, '\n');
	free(heredoc);
	return(temp);
}
