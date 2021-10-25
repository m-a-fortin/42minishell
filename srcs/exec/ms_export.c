/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 21:19:26 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/25 14:05:32 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//valide si la valeur de export est imprimable
bool	ms_valid_exp_value(char *args, int index)
{
	while (args[index])
	{
		if (ft_isprint(args[index]) == 0)
			return (false);
		index++;
	}
	return (true);
}

//valide si le nom de export commence par une lettre et est alpha numerique
bool	ms_valid_exp_name(char *args)
{
	int	index;

	index = 0;
	if (ft_isalpha(args[0]) == 0 && args[0] != '_')
		return (false);
	while (args[index])
	{
		if (args[index] == '=')
			return (ms_valid_exp_value(args, index));
		if (ft_isalnum(args[index]) == 0 && args[0] != '_')
			return (false);
		index++;
	}
	return (true);
}

//fonction qui set le nom et la valeur de export dans envp
void	ms_setexp(char *args)
{
	char	*name;
	char	*value;
	int		index;

	index = 0;
	if (ft_char_search(args, '=') == 0)
	{
		g_ms.export = ms_set_noequal(args, g_ms.export);
		return ;
	}
	while (args[index] != '=')
		index++;
	name = ft_strndup(args, index + 1);
	value = ft_strdup(args + (index + 1));
	g_ms.env = ms_setenv(name, value, g_ms.env);
	g_ms.export = ms_setenv(name, value, g_ms.export);
	free(name);
	name = NULL;
	free(value);
	value = NULL;
}

bool	ms_export_loop(char **args, int index)
{
	if (ms_valid_exp_name(args[index]) == true)
		ms_setexp(args[index]);
	else
	{
		ms_print_exec_error(args[index], args[0], "not a valid identifier");
		return (false);
	}
	return (true);
}

//export prend "nom=valeur" en parametre et le met dans envp.
//si la valeur existe il change la valeur, si il n'existe pas il le rajoute.
int	ms_export_main(char **args)
{
	int	x;

	x = 1;
	if (args[x] == NULL)
		ft_print_matrice(g_ms.export);
	while (args[x])
	{
		if (ms_export_loop(args, x) == false)
			return (1);
		x++;
	}
	return (0);
}
