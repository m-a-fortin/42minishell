/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:56:43 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/05 15:00:39 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	closing_quotes(t_parser *par)
{
	int	i;

	i = 0;
	while (i != par->index)
	{
		if (ft_strchr(QUOTES, par->input[i]))
			change_state(par, i);
		i++;
	}
	return (par->state == TEXT);
}

void	set_operator_type(t_token *token, char *str)
{
	if (ft_strncmp(str, ">>", ft_strlen(str) + 1) == 0)
		token->type = R_HDOC;
	else if (ft_strncmp(str, "<<", ft_strlen(str) + 1) == 0)
		token->type = L_HDOC;
	else if (ft_strncmp(str, ">", ft_strlen(str) + 1) == 0)
		token->type = R_REDIR;
	else if (ft_strncmp(str, "<", ft_strlen(str) + 1) == 0)
		token->type = L_REDIR;
	else if (ft_strncmp(str, "|", ft_strlen(str) + 1) == 0)
		token->type = PIPE;
}

void	add_token_to_list(t_parser *par, t_token *token)
{
	int		i;

	i = 0;
	token->valid_token = ft_calloc(token_length(par), sizeof(char));
	while (i != par->index)
	{
		token->valid_token[i] = par->input[i];
		i++;
	}
	token_lst_addback(&token, token_lst_addnew(NULL));
}

bool	tokenize_string(t_parser *par, t_token *token)
{
	if (!closing_quotes(par))
	{
		bad_quotes_syntax(par, token);
		return (false);
	}
	add_token_to_list(par, token);
	token->type = STRING;
	return (true);
}

bool	tokenize_operator(t_parser *par, t_token *token)
{
	char	op;

	op = index_char(par);
	par->index++;
	if (index_char(par) == op)
		par->index++;
	if (!token->valid_token)
		token->valid_token = NULL;
	add_token_to_list(par, token);
	set_operator_type(token, token->valid_token);
	return (true);
}
