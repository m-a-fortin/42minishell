/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:06:07 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/06 16:35:46 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_error(char *name, char *msg)
{
	ft_putstr_fd(name, STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
}

void	bad_quotes_syntax(t_parser *par)
{
	char	*error_msg;

	if (par->state == D_QUOTE)
		error_msg = D_QUOTE_ERR;
	else
		error_msg = S_QUOTE_ERR;
	print_error(NAME, error_msg);
	g_job.error = BAD_SYNTAX;
}

