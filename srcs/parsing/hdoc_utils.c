/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdoc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:40:01 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/01 14:25:59 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	invalid_process_id(int pid)
{
	if (pid == -1)
	{
		ms_return_fd();
		ft_putendl_fd("Minishell: FATAL: fork error", 1);
		g_ms.exit = 1;
		return (true);
	}
	return (false);
}

bool	create_pipe(int *fd)
{
	if (pipe(fd) == -1)
	{
		perror("Minishell: ");
		return (false);
	}
	return (true);
}

char	*find_delimiter(t_token *token)
{
	char	*temp;

	temp = NULL;
	token = token->next;
	if (token->token[0] == '\'')
		temp = ft_strtrim(token->token, "\'");
	else if (token->token[0] == '\"')
		temp = ft_strtrim(token->token, "\"");
	if (temp)
	{
		token->token = ft_strdup(temp);
		free(temp);
	}
	return (token->token);
}

char	*join_inputs(char *input, char *heredoc)
{
	char	*temp;

	temp = ft_strjoin(heredoc, input);
	temp = ft_append_string(temp, '\n');
	free(heredoc);
	return (temp);
}
