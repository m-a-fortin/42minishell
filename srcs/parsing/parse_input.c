/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:50:35 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/14 10:17:05 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	print_list(t_token *head)
// {
// 	int	i = 1;

// 	while (head->next)
// 	{
// 		printf("TOKEN[%d] = %s\n", i, head->token);
// 		head = head->next;
// 		i++;
// 	}
// }

char	*new_input(t_parser *par, char *input)
{
	char	*temp;

	temp = input;
	temp = ft_substr(par->input, token_length(par), ft_strlen(input));
	return (temp);
}

bool	find_token(t_parser *par, t_token *token)
{
	if (ft_strchr(OPERATORS, index_char(par)))
		return (tokenize_operator(par, token));
	while (!ft_strchr(OPERATORS, index_char(par))
		&& !ft_strchr(SPACES, index_char(par)))
	{
		check_state(par, par->input[par->index]);
		if (par->state != TEXT)
		{
			par->index = find_closing_quote(par, index_char(par));
			check_state(par, par->input[par->index]);
			if (par->index < 0)
			{
				bad_quotes_syntax(par);
				return (false);
			}
		}
		par->index++;
		
	}
	return (tokenize_string(par, token));
}

t_job	*parse_input(char *input, t_job *job_head)
{
	t_token		*token;
	t_token		*head;
	t_parser	par;
	char		*temp;

	token = token_lst_addnew(NULL);
	head = token;
	temp = ft_strdup(input);
	temp = trim_input(input);
	while (input_is_not_empty(temp))
	{
		reset_parser(&par, temp);
		if (find_token(&par, token))
		{
			temp = new_input(&par, temp);
			token = token->next;
			continue ;
		}
		return (NULL);
	}
	free(temp);
	if (!validate_tokens_syntax(head))
		return (NULL);
	return (build_job(head, job_head));
}
