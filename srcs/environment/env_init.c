/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 17:52:26 by rpinoit           #+#    #+#             */
/*   Updated: 2018/06/11 14:39:05 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	env_init(t_env *e, t_bool print)
{
	e->lst = NULL;
	e->a = NULL;
	e->b = NULL;
	e->elem_nb = 0;
	e->op_nb = 0;
	e->a_len = 0;
	e->b_len = 0;
	e->print = print;
	e->visual = FALSE;
	e->number = FALSE;
}
