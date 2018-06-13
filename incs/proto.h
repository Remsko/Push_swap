/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 21:50:22 by rpinoit           #+#    #+#             */
/*   Updated: 2018/06/13 11:23:03 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

# include "push_swap.h"

void	ft_error(int nb);

void	env_init(t_env *e, t_bool print);

void	operation_getter(t_env *e, t_visual *v);

t_bool	do_operation(t_env *e, char *line);

void	sort_verifier(t_env *e);

void	quicksort(t_env *e);

void	littlesort(t_env *e);

void	insertionsort(t_env *e, int turn);

#endif
