/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:06:37 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/13 15:15:37 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# define OPERATORS "<>|"

typedef struct s_token
{
	struct s_token	*prev;
	char			*valid_token;
	t_type			type;
	struct s_token	*next;
}	t_token;

/* LIST UTILITIES */

t_token	*token_lst_last(t_token *token);
t_token	*token_lst_addnew(void	*valid_token);
t_type	set_operator_type(char *str);
bool	is_redirection(t_token *token);
void	token_lst_addback(t_token **token, t_token *new);
void 	free_list(t_token *head);

#endif
