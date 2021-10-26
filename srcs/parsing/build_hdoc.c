/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_hdoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:03:14 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/26 12:47:08 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exitsignal(int sig)
{
	(void)sig;
	ft_putendl_fd("", STDERR_FILENO);
	exit(CTRL_C);
}

void	add_hdoc_job(t_job *job, char *heredoc, int *fd)
{
	close(fd[0]);
	if (job->hdoc)
		free(job->hdoc);
	job->hdoc = ft_calloc(ft_strlen(heredoc) + 1, sizeof(char));
	ft_strlcpy(job->hdoc, heredoc, ft_strlen(heredoc) + 1);
	ft_putstr_fd(heredoc, fd[1]);
}

bool	read_from_input(int *fd, t_job *job)
{
	char	*line;
	char	*temp;
	char	buff[2];
	int		ret;

	close(fd[1]);
	line = NULL;
	while (true)
	{
		ret = read(fd[0], &buff, 1);
		buff[1] = '\0';
		if (ret < 0)
			return (false);
		else if (ret == 0)
			break ;
		temp = ft_append_string(line, buff[0]);
		line = temp;
	}
	job->hdoc = line;
	close(fd[0]);
	return (true);
}

void	heredoc_inputs(t_token *token, t_job *job, int *fd)
{
	char	*heredoc;
	char	*input;
	char	*delimiter;

	signal(SIGINT, exitsignal);
	heredoc = ft_calloc(1, sizeof(char));
	delimiter = find_delimiter(token);
	while (true)
	{
		input = readline("> ");
		if (!ft_strcmp(input, delimiter))
		{
			add_hdoc_job(job, heredoc, fd);
			break ;
		}
		heredoc = join_inputs(input, heredoc);
		free(input);
	}
	free(input);
	free(heredoc);
	exit(EXIT_SUCCESS);
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
	if (invalid_process_id(pid))
		return (false);
	if (pid == 0)
		heredoc_inputs(token, job, fd);
	waitpid(pid, &status, 0);
	ms_fork_signal(status);
	read_from_input(fd, job);
	ms_return_fd();
	return (true);
}
