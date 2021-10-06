/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:58:38 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/05 13:27:40 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*trim_input(char *input)
{
	char	*temp;

	temp = input;
	temp = ft_strtrim(input, SPACES);
	input = temp;
	return (input);
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

void	reset_parser(t_parser *par, char *input)
{
	par->index = 0;
	par->state = TEXT;
	par->input = trim_input(input);
}

void	change_state(t_parser *par, int index)
{
	if (par->input[index] == '\'')
	{
		if (par->state == TEXT)
			par->state = S_QUOTE;
		else if (par->state == S_QUOTE)
			par->state = TEXT;
	}
	else if (par->input[index] == '\"')
	{
		if (par->state == TEXT)
			par->state = D_QUOTE;
		else if (par->state == D_QUOTE)
			par->state = TEXT;
	}
}
