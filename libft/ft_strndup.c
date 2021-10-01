/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 23:12:16 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/01 00:36:36 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t len)
{
	char	*cpy;

	cpy = malloc(sizeof(*s1) * len + 1);
	if (!cpy)
		return (0);
	cpy = ft_memcpy((void *)cpy, s1, len);
	cpy[len + 1] = '\0';
	return (cpy);
}
