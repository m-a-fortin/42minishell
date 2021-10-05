/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:06:07 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/05 15:35:58 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	check_error(int error_type)
// {
// 	if (error_type == BAD_SYNTAX)
// 		syntax_error();//TODO Bad_Syntax function;
// 	else if (error_type == NO_EXEC_CMD)
// 		;//TODO No exec function
// 	else if (error_type == CMD_NOT_FOUND)
// 		;//TODO CMD_NOT_FOUND function
// 	else if (error_type == INV_ARG)
// 		;//TODO Invalid arg function
// 	else if (error_type == CTRL_C)
// 		;//TODO Script terminated 
// }

void	bad_quotes_syntax(t_parser *par, t_token *token)
{
	char	*err_str;

	err_str = ft_calloc(ft_strlen(D_QUOTE_ERR) + 1, sizeof(char));
	
}
