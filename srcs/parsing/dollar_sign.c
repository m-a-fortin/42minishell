/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_sign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:21:05 by mafortin          #+#    #+#             */
/*   Updated: 2021/11/01 11:48:47 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	find_dollarsign(t_job *job_head)
{
	t_job	*tmp;
	int		i;
	int		j;

	tmp = job_head;
	while (tmp)
	{
		i = 0;
		while (tmp->cmd[i])
		{
			j = 0;
			while (tmp->cmd[i][j])
			{
				if (tmp->cmd[i][j] == '$')
					return (true);
				j++;
			}
			i++;
		}
		tmp = tmp->next;
	}
	return (false);
}

t_dollar	*dollarsign_found(char *string, t_dollar *d_sign, t_quote *state)
{
	if (ft_isalpha(string[d_sign->index + 1]) == 0
		&& string[d_sign->index + 1] != '_' && string[d_sign->index + 1] != '?')
	{
		d_sign->found = 0;
		d_sign->index += 2;
		return (d_sign);
	}
	d_sign->index++;
	d_sign->found = 1;
	if (string[d_sign->index] == '?')
		return (dollarsign_exit(d_sign));
	d_sign = dollarsign_name(string, d_sign, state);
	d_sign->value = ms_getenv(d_sign->name, g_ms.env);
	free(d_sign->name);
	d_sign->name = NULL;
	if (!d_sign->value)
		d_sign->value = ft_strdup("\0");
	return (dollarsign_join(d_sign));
}

char	*manage_variable(t_dollar *d_sign, t_quote *state, char *string)
{
	char	*temp;

	if (string[d_sign->index] == '\'' || string[d_sign->index] == '\"')
		update_quotestatus(string[d_sign->index], state);
	if (string[d_sign->index] == '$' && state->singlequote == false)
	{
		if (string[d_sign->index + 1] != '\0')
			d_sign = dollarsign_found(string, d_sign, state);
	}
	if (d_sign->found == 0)
	{
		temp = ft_append_string(d_sign->new_string,
				string[d_sign->index]);
		d_sign->new_string = ft_strdup(temp);
		free(temp);
	}
	return (d_sign->new_string);
}

char	*dollarsign_loop(char *string)
{
	t_dollar	*d_sign;
	t_quote		*state;
	char		*temp;

	state = malloc(sizeof(t_quote));
	state->singlequote = false;
	state->doublequote = false;
	d_sign = malloc(sizeof(t_dollar));
	dollarstruct_init(d_sign);
	if (!string[d_sign->index])
		temp = ft_strdup("\0");
	while (string[d_sign->index])
	{
		d_sign->found = 0;
		temp = manage_variable(d_sign, state, string);
		d_sign->index++;
	}
	free (string);
	string = ft_strdup(temp);
	dollarsign_free(d_sign, state);
	return (string);
}

//*fonction qui gere les arguments $. Si l'argument suivi de $ est dans env, il
//*changer la valeur. Sinon il retourne une string vide.
//*La regle des quotes et double quotes agis comme dans bash.
//*Si ce qui suit $ n'est pas un nom de variable
//*avec une syntax valide, il skip le premier char
//*et ajoute le reste a la string
void	dollarsign_main(t_job *current)
{
	int	index;

	index = 0;
	if (current->cmd)
	{
		while (current->cmd[index])
		{
			current->cmd[index] = dollarsign_loop(current->cmd[index]);
			index++;
		}
	}
	index = 0;
	if (current->redir)
	{
		while (current->redir[index])
		{
			if (current->redir[index][0])
				current->redir[index] = dollarsign_loop(current->redir[index]);
			if (!current->redir[index + 1])
				break ;
			index += 2;
		}
	}
	if (current->next)
		dollarsign_main(current->next);
}
