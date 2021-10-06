/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tester.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 09:31:21 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/06 09:10:21 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*input;

	input = "   echo blabla'pouetputine $ABC  >> $$echo< |< >> << < >   HALO   ";
	parse_input(input);
}
