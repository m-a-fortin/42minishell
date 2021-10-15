/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tester.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 09:31:21 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/15 12:53:59 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_exec	g_ms = {0};

int	main(void)
{
	t_job	*job;
	char	*input;

	job = NULL;
	while (true)
	{
		job = ms_create_node(job);
		input = readline("TESTER: ");
		job = parse_input(input, job);	
		ms_free_job(job, job);
		free(input);
	}
}
