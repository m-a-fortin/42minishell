/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:06:07 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/06 16:39:06 by mmondell         ###   ########.fr       */
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
	if (par->state == D_QUOTE)
		print_error(NAME, D_QUOTE_ERR);
	else
		print_error(NAME, S_QUOTE_ERR);
	g_job.error = BAD_SYNTAX;
}

