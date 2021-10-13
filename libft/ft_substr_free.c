/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 08:44:51 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/13 08:47:11 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr_free(const char *s, unsigned int start, size_t len)
{
	char		*str;
	char		*tmp;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	str = malloc(sizeof(*s) * len + 1);
	if (!s)
		return (NULL);
	if (!str)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	tmp = str;
	free(str);
	return (tmp);
}
