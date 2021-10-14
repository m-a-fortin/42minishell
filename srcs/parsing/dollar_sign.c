/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_sign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:21:05 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/14 14:30:53 by mmondell         ###   ########.fr       */
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
	return (d_sign);
}

t_dollar	*dollarsign_found(char *string, t_dollar *d_sign)
{
	d_sign->index++;
	if (string[d_sign->index] == '?')
		return (dollarsign_exit(d_sign));
	if (ft_isalpha(string[d_sign->index]) == 0
		&& string[d_sign->index] != '_')
	{
		d_sign->index++;
		return (d_sign);
	}
	d_sign = dollarsign_name(string, d_sign);
	d_sign->value = ms_getenv(d_sign->name, g_ms.env);
	free(d_sign->name);
	d_sign->name = NULL;
	if (!d_sign->value)
		return (d_sign);
	return (dollarsign_join(d_sign));
}

char	*dollarsign_loop(char *string)
{
	t_dollar	*d_sign;
	char		*temp;

	d_sign = malloc(sizeof(t_dollar));
	dollarstruct_init(d_sign);
	while (string[d_sign->index])
	{
		if (string[d_sign->index] == '$' && g_ms.singlequote == false)
			d_sign = dollarsign_found(string, d_sign);
		else
		{
			temp = ft_append_string(d_sign->new_string,
					string[d_sign->index]);
			d_sign->new_string = ft_strdup(temp);
			free(temp);
			d_sign->index++;
		}
	}
	free (string);
	string = ft_strdup(d_sign->new_string);
	dollarsign_free(d_sign);
	return (string);
}

void	dollarsign_main(t_job *current)
{
	int		index;

	index = 0;
	while (current->cmd[index])
	{
		current->cmd[index] = dollarsign_loop(current->cmd[index]);
		index++;
	}
}
