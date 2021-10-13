/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_sign_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 09:51:50 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/13 09:53:59 by mafortin         ###   ########.fr       */
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