/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:50:35 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/25 11:58:42 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*rewind_list(t_token *token)
{
	if (!token)
		return (NULL);
	if (token->prev)
	{
		while (token->prev)
			token = token->prev;
	}
	return (token);
}

char	*new_input(t_parser *par, char *input)
{
	char	*temp;

	temp = input;
	temp = ft_substr(par->input, token_length(par), ft_strlen(input));
	free(input);
	return (temp);
}

t_token	*find_token(t_parser *par, t_token *token)
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
			if (par->index < 0)
				par->index = 0;
			check_state(par, par->input[par->index]);
			if (par->index == 0)
			{
				bad_quotes_syntax(par);
				free_list(rewind_list(token));
				return (NULL);
			}
		}
		par->index++;
	}
	return (tokenize_string(par, token));
}

t_job	*parse_input(char *input, t_job *job_head)
{
	t_token		*token;
	t_parser	par;
	char		*temp;

	token = NULL;
	temp = trim_input(input);
	while (input_is_not_empty(temp))
	{
		temp = reset_parser(&par, temp);
		token = find_token(&par, token);
		if (token)
		{
			temp = new_input(&par, temp);
			continue ;
		}
		free(temp);
		return (NULL);
	}
	free(temp);
	if (!validate_tokens_syntax(rewind_list(token)))
		return (NULL);
	return (build_job(rewind_list(token), job_head));
}
