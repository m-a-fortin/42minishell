/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:43:19 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/18 10:26:34 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	update_quotestatus(char type)
{
	if (type == '\"')
	{
		if (g_ms.doublequote == false && g_ms.singlequote == false)
		{
			g_ms.doublequote = true;
			return ;
		}
		if (g_ms.doublequote == true && g_ms.singlequote == false)
			g_ms.doublequote = false;
	}
	if (type == '\'')
	{
		if (g_ms.singlequote == false && g_ms.doublequote == false)
		{
			g_ms.singlequote = true;
			return ;
		}
		if (g_ms.singlequote == true && g_ms.doublequote == false)
			g_ms.singlequote = false;
	}
}

char	*swap_trimmed(char *string, char *trimmed)
{
	free (string);
	string = NULL;
	if (!trimmed)
		string = ft_strdup("\0");
	else
	{
		string = ft_strdup(trimmed);
		free (trimmed);
	}
	return (string);
}

char	*trimquotes_loop(char *string)
{
	char	*trimmed;
	char	*temp;
	int		index;

	index = 0;
	trimmed = NULL;
	while (string[index])
	{
		if ((string[index] == '\'' && g_ms.doublequote == false)
			|| (string[index] == '\"' && g_ms.singlequote == false))
				update_quotestatus(string[index]);
		else
		{
			temp = ft_append_string(trimmed, string[index]);
			trimmed = ft_strdup(temp);
			free(temp);
			temp = NULL;
		}
		index++;
	}
	string = swap_trimmed(string, trimmed);
	return (string);
}

void	trimquotes_redir(t_job *current)
{
	int	index;

	index = 0;
	if (current->redir)
	{
		while (current->redir[index])
		{
			index++;
			if (current->redir[index][0])
				current->redir[index] = trimquotes_loop(current->redir[index]);
			if (!current->redir[index + 1])
				break;
			index += 2;
		}
	}
}

void	trimquotes_main(t_job *current)
{
	int	index;

	index = 0;
	while (current->cmd[index])
	{
		if (current->cmd[index][0])
			current->cmd[index] = trimquotes_loop(current->cmd[index]);
		index++;
	}
	index = 0;
	trimquotes_redir(current);
	if (current->next)
		trimquotes_main(current->next);
}
