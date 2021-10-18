/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:06:37 by mmondell          #+#    #+#             */
/*   Updated: 2021/10/18 17:08:55 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# define OPERATORS "<>|"

typedef enum e_type
{
	PIPE,
	R_HDOC,
	L_HDOC,
	R_REDIR,
	L_REDIR,
	STRING,
	EMPTY,
}	t_type;
typedef struct s_token
{
	struct s_token	*prev;
	char			*token;
	t_type			type;
	struct s_token	*next;
}	t_token;

/* LIST UTILITIES */
t_token	*token_lst_last(t_token *token);
t_token	*token_lst_addnew(void	*token);
t_type	set_operator_type(char *str);
bool	is_redirection(t_token *token);
bool	find_redirection(t_token *token);
void	token_lst_addback(t_token **token, t_token *new);
void 	free_list(t_token *head);

#endif
