/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:06:07 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/08 14:09:13 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	p_error(char *prg, char *arg, char *msg, char *token, int error)
{
	ft_putstr_fd(prg, STDERR_FILENO);
	if (arg)
		ft_putstr_fd(arg, STDERR_FILENO);
	if (msg)
		ft_putstr_fd(msg, STDERR_FILENO);
	if (token)
		ft_putendl_fd(token, STDERR_FILENO);
	error = 0;
	//g_ms.exit = error;
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
