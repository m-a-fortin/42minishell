/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 00:15:17 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/04 16:51:10 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ms_print_exec_error(char *value, char *cmd_name, char *error_str)
{
	ft_putstr_fd("minishell: ", 1);
	ft_putstr_fd(cmd_name, 1);
	ft_putstr_fd(": ", 1);
	ft_putstr_fd(value, 1);
	ft_putstr_fd(": ", 1);
	ft_putendl_fd(error_str, 1);
}
