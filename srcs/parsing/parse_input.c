/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:50:35 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/30 09:31:10 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/token.h"
#include "../../includes/parse.h"

static bool	validate_token_syntax(t_parser *par)
{
	t_token	*token;

	par = NULL;
	while (par->input[par->index])
	{
		while (ft_strchr(SPACES, par->input[par->index])); //* coupe les whitespaces entre les tokens
			par->index++;
		if(!find_token(par)) //* check if token syntax is valid, if not return false
			return (false);
		add_to_token_list(par, token);
	}
	return (true);
}

void	parse_input(char *input)
{
	t_parser	par;

	init_parser(&par, input);
	if (!input)
		;// TODO Error code here
	par.input = trim_input(input);
	if (!validate_token_syntax(&par))
	{
		//TODO print error near invalid syntax
	}
}
