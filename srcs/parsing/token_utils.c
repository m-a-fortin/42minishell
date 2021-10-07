/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 21:55:12 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/07 11:32:37 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_type	redirection(t_token *token)
{
	if (token->type == L_REDIR)
		return (L_REDIR);
	else if (token->type == R_REDIR)
		return (R_REDIR);
	else if (token->type == R_HDOC)
		return (R_HDOC);
	else if (token->type == L_HDOC)
		return (L_HDOC);
}

t_type	operator_type(t_token *token, char *str)
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
