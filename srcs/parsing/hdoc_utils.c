/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdoc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:40:01 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/22 12:43:02 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	create_pipe(int fd)
{
	if (pipe(fd) == -1)
	{
		perror("Minishell: ");
		return(false);
	}
	return (true);
}
