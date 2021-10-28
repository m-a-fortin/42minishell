/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_sign_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 09:51:50 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/27 19:08:51 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_dollar	*dollarsign_exit(t_dollar *d_sign)
{
	char	*temp;

	d_sign->value = ft_itoa(g_ms.exit);
	temp = ft_strjoin(d_sign->new_string, d_sign->value);
	free (d_sign->new_string);
	d_sign->new_string = temp;
	d_sign->index++;
	return (d_sign);
}

t_dollar	*dollarsign_join(t_dollar *d_sign)
{
	char	*temp;

	temp = NULL;
	if (d_sign->new_string)
	{
		temp = ft_strjoin(d_sign->new_string, d_sign->value);
		free(d_sign->new_string);
		d_sign->new_string = temp;
	}
	else
		d_sign->new_string = ft_strdup(d_sign->value);
	d_sign->index--;
	return (d_sign);
}

void	dollarstruct_init(t_dollar *d_sign)
{
	d_sign->name = NULL;
	d_sign->value = NULL;
	d_sign->new_string = ft_calloc(1, sizeof(char));
	d_sign->index = 0;
}

t_dollar	*dollarsign_name(char *string, t_dollar *d_sign, t_quote *state)
{
	char	*temp;
	char	*equal;

	while (string[d_sign->index])
	{
		if (string[d_sign->index] == '\'')
		{
			update_quotestatus(string[d_sign->index], state);
			break ;
		}
		if (ft_isalpha(string[d_sign->index]) == 0 && string[d_sign->index] != '_')
		{
			break ;
		}
		temp = ft_append_string(d_sign->name, string[d_sign->index]);
		d_sign->name = temp;
		d_sign->index++;
	}
	equal = ft_append_string(d_sign->name, '=');
	d_sign->name = equal;
	return (d_sign);
}

void	dollarsign_free(t_dollar *d_sign, t_quote *state)
{
	if (d_sign->new_string)
		free (d_sign->new_string);
	if (state)
		free (state);
	if (d_sign)
		free (d_sign);
}
