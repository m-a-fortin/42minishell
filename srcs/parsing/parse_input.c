/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:50:35 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/30 12:00:00 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/parse.h"
#include "../../includes/token.h"

static bool	validate_token_syntax(t_parser *par, char *input)
{
	init_parser(par, input);
	while(!find_token(par)) //* check if token syntax is valid, if not return false
		return (false);
	par->input = ft_substr(par->input, par->index, ft_strlen(par->input));
	printf("%s\n", par->input);
	return (true);
}

void	parse_input(char *input)
{
	t_parser	par;

	par.input = NULL;
	if (!input)
		;// TODO Error code here

	while (validate_token_syntax(&par, input))
		input = par.input;
	 //TODO add error code function here
}

int	main(void)
{
	int		i;
	char *input;
	
	i = 0;
	input = ">>   HALO   ";
	while (true)
		parse_input(input);
}
