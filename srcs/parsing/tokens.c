/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:56:43 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/30 15:37:33 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/parse.h"
#include "../../includes/token.h"

//TODO add valid tokens to the linked list
void	add_to_token_list(t_parser *par)
{
	t_token	*token;

	ft_lstadd_back(token, ft_lstnew(par->input));
}

//TODO Find token. when Done, substr the rest of the input.
bool	find_token(t_parser *par)
{
	while (ft_strchr(OPERATORS, par->input[par->index]))
		par->index++;
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
