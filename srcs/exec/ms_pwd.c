/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:17:02 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/27 17:38:07 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//ecrit le current working directory. Se sert de notre envp_ms pour ca.
void	ms_pwd_main(void)
{
	char	*pwd_line;
	
	pwd_line = NULL;
	pwd_line = getcwd(pwd_line, 0);
	ft_putstr_fd(pwd_line, 1);
	write(1, "\n", 1);
	free(pwd_line);
}