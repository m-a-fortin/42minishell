/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:06:07 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/15 08:41:01 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*next_token(t_token *token)
{
	token = token->next;
	if (token->type == L_REDIR)
		return (L_REDIR_TOKEN);
	else if (token->type == R_REDIR)
		return (R_REDIR_TOKEN);
	else if (token->type == L_HDOC)
		return (L_HDOC_TOKEN);
	else
		return (R_HDOC_TOKEN);
}

void	p_error(char *prg, char *arg, char *msg, char *token, int error)
{
	ft_putstr_fd(prg, STDERR_FILENO);
	if (arg)
		ft_putstr_fd(arg, STDERR_FILENO);
	if (msg)
		ft_putstr_fd(msg, STDERR_FILENO);
	if (token)
		ft_putstr_fd(token, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	g_ms.exit = error;
}

void	bad_quotes_syntax(t_parser *par)
{
	char	*error_msg;

	if (par->state == D_QUOTE)
		error_msg = D_QUOTE_ERR;
	else
		error_msg = S_QUOTE_ERR;
	p_error(SHELL, NULL, error_msg, NULL, BAD_SYNTAX);
}
