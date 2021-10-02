/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 21:55:12 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/01 21:56:51 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	token_length(t_parser *par)
{
	int	i;

	i = 0;
	while (i < par->index)
		i++;
	return (i);
}