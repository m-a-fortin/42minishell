/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:58:38 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/19 08:24:44 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*trim_input(char *input)
{
	char	*temp;
	char	*str;

	temp = ft_strdup(input);
	str = temp;
	str = ft_strtrim(temp, SPACES);
	free (temp);
	return (str);
}

bool	input_is_not_empty(char *input)
{
	int	i;

	i = 0;
	while (input[i])
		i++;
	if (i > 0)
		return (true);
	return (false);
}

char	index_char(t_parser *par)
{
	return (par->input[par->index]);
}

char	*reset_parser(t_parser *par, char *input)
{
	char	*temp;
	char	*str;

	par->index = 0;
	par->state = TEXT;
	temp = ft_strdup(input);
	str = temp;
	str = ft_strtrim(temp, SPACES);
	free(input);
	free(temp);
	par->input = str;
	return (str);
}

void	check_state(t_parser *par, int index)
{
	if (index == '\'')
	{
		if (par->state == D_QUOTE)
			return ;
		if (par->state == TEXT)
			par->state = S_QUOTE;
		else if (par->state == S_QUOTE)
			par->state = TEXT;
	}
	else if (index == '\"')
	{
		if (par->state == S_QUOTE)
			return ;
		if (par->state == TEXT)
			par->state = D_QUOTE;
		else if (par->state == D_QUOTE)
			par->state = TEXT;
	}
}
