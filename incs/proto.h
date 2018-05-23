/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 21:50:22 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/23 15:42:46 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

# include "push_swap.h"

void    ft_error(int nb);

void	operation_getter(t_env *e);

t_bool	do_operation(t_env *e, char *line);

void	sort_verifier(t_env *e);

void	operations_algo(t_env *e);

t_bool	issorted(t_env *e);

void	recursive_quicksort(t_env *e, int len, char pile, int turn);

void	instant_sort(t_env *e, int len, char pile);

#endif