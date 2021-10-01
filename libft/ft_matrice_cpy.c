/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrice_cpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpst <hpst@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:38:01 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/01 16:02:08 by hpst             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Alloc et copie une matrice. Ne free pas la matrice original. Doit etre free
// a l'exterieur de la fonction.
char	**ft_matrice_cpy(char **matrice)
{
	int		x;
	int		len;
	char	**new_matrice;

	x = 0;
	len = ft_matrice_size(matrice);
	new_matrice = ft_calloc(len + 1, sizeof(char *));
	while (matrice[x])
	{
		new_matrice[x] = ft_strdup(matrice[x]);
		x++;
	}
	return (new_matrice);
}
