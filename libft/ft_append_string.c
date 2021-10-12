/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:32:57 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/12 10:41:19 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Ajoute char c a la find de la string src et retourne une nouvelle string
char	*ft_append_string(char *src, char c)
{
	int		new_len;
	char	*new_str;
	int		index;

	if (!src)
		return (NULL);
	new_len = ft_strlen(src) + 2;
	new_str = ft_calloc(new_len, sizeof(char));
	if (!new_str)
		return (NULL);
	index = 0;
	while (src[index])
	{
		new_str[index] = src[index];
		index++;
	}
	new_str[index] = c;
	free(src);
	return (new_str);
}
