/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_sign_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 09:51:50 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/14 16:00:36 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	dollarstruct_init(t_dollar *d_sign)
{
	d_sign->name = NULL;
	d_sign->value = NULL;
	d_sign->new_string = ft_calloc(1, sizeof(char));
	d_sign->index = 0;
}

t_dollar	*dollarsign_name(char *string, t_dollar *d_sign)
{
	char	*temp;
	char	*equal;

	while (string[d_sign->index])
	{
		if (string[d_sign->index] == '\'')
		{
			update_quotestatus(string[d_sign->index]);
			break ;
		}
		if (string[d_sign->index] == ' ' || string[d_sign->index] == '"'
			|| string[d_sign->index] == '\0' || string[d_sign->index] == '$'
			|| string[d_sign->index] == '=')
			break ;
		temp = ft_append_string(d_sign->name, string[d_sign->index]);
		d_sign->name = temp;
		d_sign->index++;
	}
	equal = ft_append_string(d_sign->name, '=');
	d_sign->name = equal;
	return (d_sign);
}

void	dollarsign_free(t_dollar *d_sign)
{
	if (d_sign->new_string)
		free (d_sign->new_string);
	if (d_sign)
		free (d_sign);
}
