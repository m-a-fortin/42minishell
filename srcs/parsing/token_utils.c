/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 21:55:12 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/21 15:03:30 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_redirection(t_token *token)
{
	if (token->type == L_REDIR || token->type == R_REDIR
		|| token->type == L_HDOC || token->type == R_HDOC)
		return (true);
	return (false);
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
	token->token = ft_calloc(token_length(par) + 1, sizeof(char));
	while (i < par->index)
	{
		token->token[i] = par->input[i];
		i++;
	}
	token->token[i] = '\0';
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
