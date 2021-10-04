/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:50:35 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/02 07:37:09 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	find_token(t_parser *par, t_token *token)
{
	if (ft_strchr(OPERATORS, index_char(par)))
		return (tokenize_operator(par, token));
	if (ft_strchr(QUOTES, index_char(par)))
		return (tokenize_text(par, token));
	return (false);
}

bool	parse_input(char *input)
{
	t_token		*token;
	t_token		*head;
	t_parser	par;

	token = token_lst_addnew(NULL);
	head = token;
	if (!input)
		return (NULL);
	input = trim_input(input);
	while (input_is_not_empty(input))
	{
		reset_parser(&par, input);
		if (find_token(&par, token))
			input = ft_substr(input, par.index, ft_strlen(input));
		token = token->next;
	}
	return (true);
}

int	main(void)
{
	char *input;
	
	input = "   >> < >> << < >   HALO   ";
	while (true)
		parse_input(input);
}
