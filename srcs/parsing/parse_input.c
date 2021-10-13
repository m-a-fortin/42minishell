/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:50:35 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/13 08:50:44 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	print_list(t_token *head)
// {
// 	int	i = 1;

// 	while (head->next)
// 	{
// 		printf("TOKEN[%d] = %s\n", i, head->valid_token);
// 		head = head->next;
// 		i++;
// 	}
// }

bool	find_token(t_parser *par, t_token *token)
{
	if (ft_strchr(OPERATORS, index_char(par)))
		return (tokenize_operator(par, token));
	while (!ft_strchr(OPERATORS, index_char(par))
		&& !ft_strchr(SPACES, index_char(par)))
	{
		check_state(par, par->input[par->index]);
		if (par->state != TEXT)
		{
			par->index = find_closing_quote(par, index_char(par));
			check_state(par, par->input[par->index]);
			if (par->index < 0)
			{
				bad_quotes_syntax(par);
				return (false);
			}
		}
		par->index++;
		
	}
	return (tokenize_string(par, token));
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
		{
			input = ft_substr_free(par.input, token_length(&par), ft_strlen(input));
			token = token->next;
			token->next = NULL;
			continue ;
		}
		return (NULL);
	}
	return (validate_tokens_syntax(head));
}
