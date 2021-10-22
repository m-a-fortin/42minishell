/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_hdoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:03:14 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/22 14:50:02 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	read_from_input(int *fd)
{
	char	*line;
	char	*temp;
	char	buff[1];
	int		ret;

	line = NULL;
	dup2(fd[0], 0);
	while (true)
	{
		ret = read(0, &buff, 1);
		if (ret < 0)
			return (false);
		else if (ret == 0)
			break ;
		temp = ft_append_string(line, buff[0]);
	}
	close(fd[0]);
	ms_return_fd();
	return (true);
}

void	heredoc_inputs(t_token *token, t_job *job, int *fd)
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
			add_hdoc_job(job, heredoc, fd);
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
	ms_saved_fd();
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
		heredoc_inputs(token, job, fd);
	waitpid(pid, &status, 0);
	ms_fork_signal(status);
	if (g_ms.exit != 0)
		return (false);
	return (true);
}
