/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:06:07 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/07 11:48:26 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_error(char *prg, char *arg, char *msg, char *token)
{
	ft_putstr_fd(prg, STDERR_FILENO);
	if (arg)
		ft_putstr_fd(arg, STDERR_FILENO);
	if (msg)
		ft_putstr_fd(msg, STDERR_FILENO);
	if (token)
		ft_putendl_fd(token, STDERR_FILENO);
}

void	bad_quotes_syntax(t_parser *par)
{
	char	*error_msg;

	if (par->state == D_QUOTE)
		error_msg = D_QUOTE_ERR;
	else
		error_msg = S_QUOTE_ERR;
	print_error(SHELL, NULL, error_msg, NULL);
}
