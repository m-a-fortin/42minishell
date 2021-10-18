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
	free (string);
	string = NULL;
	string = ft_strdup(trimmed);
	free(trimmed);
	return (string);
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
	//pas oublier de regarder les redirections
}
