/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:56:43 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/04 11:16:50 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
	token->valid_token = ft_calloc(token_length(par) + 1, sizeof(char));
	while (i != par->index)
	{
		token->valid_token[i] = par->input[i];
		i++;
	}
	token_lst_addback(&token, token_lst_addnew(NULL));
}

bool	tokenize_string(t_parser *par, t_token *token)
{
	// while (index_char(par) == ft_isalnum(index_char(par)))
	// 	par->index++;
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
