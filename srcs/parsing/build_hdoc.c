/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_hdoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:03:14 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/22 08:24:33 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	count_hdoc(t_token *token)
{
	int	i;

	i = 0;
	while (token)
	{
		if (token->type == L_HDOC)
			i++;
		token = token->next;
	}
	return (i);
}

char	*find_delimiter(t_token *token)
{
	token = token->next;
	return(token->token);
}

void	build_heredoc(t_job *job, char *heredoc, int size)
{
	int	i;

	i = 0;
	if (!job->hdoc)
		job->hdoc = (char **)ft_calloc(size + 1, sizeof(char *));
	while (job->hdoc[i])
		i++;
	job->hdoc[i] = ft_calloc(ft_strlen(heredoc) + 1, sizeof(char));
	ft_strlcpy(job->hdoc[i], heredoc, ft_strlen(heredoc) + 1);
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
	char	*input;
	char	*delimiter;
	char	*heredoc;
	int		hdoc_total;

	heredoc = ft_calloc(1, sizeof(char));
	hdoc_total = count_hdoc(token);
	delimiter = find_delimiter(token);
	while (true)
	{
		input = readline("> ");
		if (!ft_strncmp(input, delimiter, ft_strlen(input)))
			break ;
		heredoc = join_inputs(input, heredoc);
		free(input);
	}
	build_heredoc(job, heredoc, hdoc_total);
	free(heredoc);
	free(input);
}
