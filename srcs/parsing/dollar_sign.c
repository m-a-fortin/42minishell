/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_sign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:21:05 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/13 09:57:38 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*dollarsign_found(char *string t_dolloar *d_sign)
{

}

char	*dollarsign_loop(char *string)
{

	t_dollar	*d_sign;

	d_sign = malloc(sizeof(t_dollar));
	dollarstruct_init(d_sign);
	while (string[d_sign->index])
	{
		if (string[d_sign->index] == '$')
			d_sign->new_string = dollarsign_found(string, d_sign);
		else
		{
			d_sign->new_string[index_new] = ft_append_string(d_sign->new_string,
				string[d_sign->index]);
			d_sign->index++;
		}
	}
}

void	dollarsign_main(t_job *current)
{
	int	index;

	index = 0;
	while (current.cmd[index])
	{
		current.cmd[index] = dollarsign_loop(current.cmd[index]);
		index++;
	}
	index = 0;
	while (current.redirection[index])
	{
		current.redirection[index] = dollarsign_loop(current.cmd[index]);
		index++;
	}
}