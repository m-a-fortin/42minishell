/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:01:17 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/13 17:25:16 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Si src est vide, calloc une string de size de 2.
char	*ft_append_empty(char *new_str, char c)
{
	new_str = ft_calloc(2, sizeof(char));
	if (!new_str)
		return (NULL);
	new_str[0] = c;
	return (new_str);
}

//Ajoute char c a la find de la string src et retourne une nouvelle string
char	*ft_append_string(char *src, char c)
{
	int		new_len;
	char	*new_str;
	int		index;

	new_str = NULL;
	if (!src)
		return (ft_append_empty(new_str, c));
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
