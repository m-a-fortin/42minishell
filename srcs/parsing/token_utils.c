/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 21:55:12 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/08 11:26:07 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_type	is_redirection(t_token *token)
{
	if (token->type == L_REDIR)
		return (L_REDIR);
	else if (token->type == R_REDIR)
		return (R_REDIR);
	else if (token->type == R_HDOC)
		return (R_HDOC);
	else if (token->type == L_HDOC)
		return (L_HDOC);
	return (EMPTY);
}

t_type	set_operator_type(char *str)
{
	if (ft_strncmp(str, ">>", ft_strlen(str) + 1) == 0)
		return (R_HDOC);
	else if (ft_strncmp(str, "<<", ft_strlen(str) + 1) == 0)
		return (L_HDOC);
	else if (ft_strncmp(str, ">", ft_strlen(str) + 1) == 0)
		return (R_REDIR);
	else if (ft_strncmp(str, "<", ft_strlen(str) + 1) == 0)
		return (L_REDIR);
	else if (ft_strncmp(str, "|", ft_strlen(str) + 1) == 0)
		return (PIPE);
	return (EMPTY);
}

void	add_token_to_list(t_parser *par, t_token *token)
{
	int	i;

	i = 0;
	token->valid_token = ft_calloc(token_length(par), sizeof(char));
	while (i != par->index)
	{
		token->valid_token[i] = par->input[i];
		i++;
	}
	token_lst_addback(&token, token_lst_addnew(NULL));
}

int	token_length(t_parser *par)
{
	int	i;

	i = 0;
	while (i <= par->index - 1)
		i++;
	return (i);
}
