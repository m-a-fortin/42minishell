/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 21:19:26 by mafortin          #+#    #+#             */
/*   Updated: 2021/10/04 15:49:42 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//Si export n'a pas d'arguments, Il print envp avec "declare -x"
void	ms_export_print(char **envp, int fd)
{
	int		x;
	char	**print;

	print = ft_calloc(ft_matrice_size(envp) + 1, sizeof(char *));
	x = 0;
	while (envp[x])
	{
		print[x] = ft_strjoin("declare -x ", envp[x]);
		x++;
	}
	ft_print_matrice_fd(print, fd);
	ft_free_tab(print);
}

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
			break ;
		index++;
	}
	return (false);
}

//fonction qui set le nom et la valeur de export dans envp
void	ms_setexp(t_shell *env, char *args)
{
	char	*name;
	char	*head;
	char	*value;
	int		index;

	head = args;
	index = 0;
	while (args[index] != '=')
		index++;
	name = ft_strndup(args, index + 1);
	value = ft_strdup(args += index + 1);
	env->ms = ms_setenv(name, value, env->ms);
	free(name);
	free(value);
}

//export prend "nom=valeur" en parametre et le met dans envp.
//si la valeur existe il change la valeur, si il n'existe pas il le rajoute.
void	ms_export_main(t_shell *env, char **args, int fd)
{
	int	x;

	x = 1;
	if (args[x] == NULL)
		ms_export_print(env->ms, fd);
	while (args[x])
	{
		if (ft_char_search(args[x], '=') == 0)
			x++;
		if (ms_valid_exp_name(args[x]) == true)
			ms_setexp(env, args[x]);
		else
		{
			ms_print_exec_error(args[x], args[0], "not a valid identifier");
			break ;
		}
		x++;
	}
}
