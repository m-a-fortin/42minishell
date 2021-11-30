/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 21:55:12 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/30 08:19:48 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_redirection(t_token *token)
{
	if (token->type == INPUT || token->type == OUTPUT
		|| token->type == HDOC || token->type == APPEND)
		return (true);
	return (false);
}

int	set_operator_type(char *str)
{
	if (!ft_strcmp(str, ">>"))
		return (APPEND);
	else if (!ft_strcmp(str, "<<"))
		return (HDOC);
	else if (!ft_strcmp(str, ">"))
		return (OUTPUT);
	else if (!ft_strcmp(str, "<"))
		return (INPUT);
	else if (!ft_strcmp(str, "|"))
		return (PIPE);
	return (EMPTY);
}

t_token	*add_token_to_list(t_parser *par, t_token *token)
{
	char	*string;
	int		i;

	i = 0;
	string = ft_calloc(token_length(par) + 1, sizeof(char));
	if (!string)
		return (NULL);
	while (i < par->index)
	{
		string[i] = par->input[i];
		i++;
	}
	string[i] = '\0';
	token_lst_addback(&token, token_lst_addnew(string));
	return (token);
}

int	token_length(t_parser *par)
{
	int	i;

	i = 0;
	while (i <= par->index - 1)
		i++;
	return (i);
}
