/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:56:43 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/30 11:47:07 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/parse.h"
#include "../../includes/token.h"

//TODO add valid tokens to the linked list
void	add_to_token_list(t_parser *par)
{
	t_token	*token;

	token = NULL;
	
}

//TODO Find token. when Done, substr the rest of the input and reset index
bool	find_token(t_parser *par)
{
	while (ft_strchr(OPERATORS, par->input[par->index]))
	{
		par->index++;
		//add_to_token_list(par);
	}
	while (ft_isalnum(par->input[par->index]))
		par->index++;
	if (!par->input[par->index])
		return (false);
	return (true);
}

char	*trim_input(char *input)
{
	char	*temp;

	temp = input;
	temp = ft_strtrim(input, SPACES);
	input = temp;
	// if (*input)
	// 	add_history(input);
	return (input);
}

void	init_parser(t_parser *par, char *input)
{
	par->input = trim_input(input);
	par->index = 0;
	par->state = TEXT;
}
