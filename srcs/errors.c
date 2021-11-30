/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:06:07 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/30 09:50:19 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*next_token(t_token *token)
{
	token = token->next;
	if (token->type == INPUT)
		return (L_REDIR_TOKEN);
	else if (token->type == OUTPUT)
		return (R_REDIR_TOKEN);
	else if (token->type == HDOC)
		return (L_HDOC_TOKEN);
	else if (token->type == PIPE)
		return (PIPE_TOKEN);
	else
		return (R_HDOC_TOKEN);
}

bool	p_error(char *prg, char *arg, char *msg, char *token)
{
	ft_putstr_fd(prg, STDERR_FILENO);
	if (arg)
		ft_putstr_fd(arg, STDERR_FILENO);
	if (msg)
		ft_putstr_fd(msg, STDERR_FILENO);
	if (token)
		ft_putendl_fd(token, STDERR_FILENO);
	return (false);
}

void	bad_quotes_syntax(t_parser *par)
{
	char	*error_msg;

	if (par->state == D_QUOTE)
		error_msg = D_QUOTE_ERR;
	else
		error_msg = S_QUOTE_ERR;
	g_ms.exit = BAD_SYNTAX;
	p_error(SHELL, NULL, error_msg, NULL);
}
