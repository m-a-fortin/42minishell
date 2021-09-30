/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:50:35 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/30 09:04:15 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/token.h"
#include "../../includes/parse.h"

static bool	validate_token_syntax(t_token *token)
{
	t_valid	*valid;

	valid = NULL;
	while (token->input[token->index])
	{
		while (ft_strchr(SPACES, token->input[token->index])); // * coupe les whitespaces entre les tokens
			token->index++;
		if(!find_token(token)) //* check if token syntax is valid, if not return false
			return (false);
		add_to_token_list(token, valid);
	}
	return (true);
}

void	parse_input(char *input)
{
	t_token	token;

	init_tokens(&token, input);
	if (!input)
		;// TODO Error code here
	token.input = trim_input(&token, input);
	if (!validate_token_syntax(&token))
	{
		//TODO print error near invalid syntax
	}
}
