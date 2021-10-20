/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_strtab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:04:31 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/20 11:46:07 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_sort_strtab(char **tab)
{
	char	**temp;

	temp = ft_calloc(ft_matrice_size(tab) + 1, sizeof(char *));
	if (!temp)
		return (tab);
	
	return (tab);
}
