/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 21:50:22 by rpinoit           #+#    #+#             */
/*   Updated: 2018/06/08 18:43:23 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "push_swap.h"

typedef struct  s_env
{
	t_list	*lst;
    int     *a;
    int     *b;
    int     elem_nb;
    int     op_nb;
    int     a_len;
    int     b_len;
    t_bool  print;
    t_bool  visual;
}               t_env;

typedef struct  s_stack_nb
{
    int nb;
    int index;
}               t_stack_nb;

#endif
