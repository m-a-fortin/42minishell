/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:29:46 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/04 17:33:25 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_remove_line(char **matrice, int index)
{
	char	**new_matrice;
	int		depth;
	int		x;
	int		x_2;

	x = 0;
	x_2 = 0;
	depth = ft_matrice_size(matrice);
	new_matrice = ft_calloc(depth, sizeof(char *));
	while (matrice[x])
	{
		if (x == index)
			x++;
		new_matrice[x_2] = ft_strdup(matrice[x]);
		x++;
		x_2++;
	}
	ft_free_tab(matrice);
	return (new_matrice);
}
