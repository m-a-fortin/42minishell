/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:56:43 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/30 09:29:10 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/parse.h"
#include "../../includes/token.h"

void	add_to_token_list(t_parser *par, t_token *token)
{
	; //TODO add valid tokens to the linked list
}

bool	find_token(t_token *token)
{
	
}

char	*trim_input(char *input)
{
	char	*temp;

	temp = input;
	temp = ft_strtrim(input, SPACES);
	input = temp;
	if (*input)
		add_history(input);
	return (input);
}

void	init_parser(t_parser *par, char *input)
{
	par->input = NULL;
	par->index = 0;
	par->state = TEXT;
}
