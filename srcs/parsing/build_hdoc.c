/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_hdoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:03:14 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/22 12:43:27 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_delimiter(t_token *token)
{
	token = token->next;
	return(token->token);
}

void	add_hdoc_job(t_job *job, char *heredoc)
{
	job->hdoc = ft_calloc(ft_strlen(heredoc) + 1, sizeof(char));
	ft_strlcpy(job->hdoc, heredoc, ft_strlen(heredoc) + 1);
}

char	*join_inputs(char *input, char *heredoc)
{
	char	*temp;
	
	temp = ft_strjoin(heredoc, input);
	temp = ft_append_string(temp, '\n');
	free(heredoc);
	return(temp);
}

void	heredoc_inputs(t_token *token, t_job *job)
{
	char	*heredoc;
	char	*input;
	char	*delimiter;

	heredoc = ft_calloc(1, sizeof(char));
	delimiter = find_delimiter(token);
	while (true)
	{
		input = readline("> ");
		if (!ft_strncmp(input, delimiter, ft_strlen(input) + 1))
		{
			add_hdoc_job(job, heredoc);
			break ;
		}
		heredoc = join_inputs(input, heredoc);
		free(input);
	}
	
	free(input);
	free(heredoc);
}

bool	build_heredoc(t_token *token, t_job *job)
{
	pid_t	pid;
	int		status;
	int		fd[2];

	if (!create_pipe(fd))
		return (false);
	pid = fork();
	signal(SIGINT, ms_donothing);
	signal(SIGQUIT, ms_donothing);
	if (pid == -1)
	{
		ms_return_fd();
		ft_putendl_fd("minishell: FATAL: fork error", 1);
		g_ms.exit = 1;
		return (false);
	}
	if (pid == 0)
		heredoc_inputs(token, job);
	waitpid(pid, &status, 0);
	ms_fork_signal(status);
	if (g_ms.exit != 0)
		return (false);
	return (true);
}
