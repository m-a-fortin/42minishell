/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:56:43 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/30 09:04:48 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/parse.h"
#include "../../includes/token.h"

void	add_to_token_list(t_token *token, t_valid *valid)
{
	;
}

bool	find_token(t_token *token)
{
	
}

char	*trim_input(t_token *token, char *input)
{
	char	*temp;

	temp = input;
	temp = ft_strtrim(input, SPACES);
	input = temp;
	if (*input)
		add_history(input);
	return (input);
}

void	init_tokens(t_token *token, char *input)
{
	token->input = NULL;
	token->index = 0;
	token->state = TEXT;
}
