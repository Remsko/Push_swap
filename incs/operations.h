/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:59:00 by rpinoit           #+#    #+#             */
/*   Updated: 2018/06/09 18:05:27 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "push_swap.h"

void	sa(t_env *e);

void	sb(t_env *e);

void	ss(t_env *e);

void	pa(t_env *e);

void	pb(t_env *e);

void	ra(t_env *e);

void	rb(t_env *e);

void	rr(t_env *e);

void	rra(t_env *e);

void	rrb(t_env *e);

void	rrr(t_env *e);

void	n_rotate(t_env *e, int until, t_bool reverse, char stack_id);

void	final_rotate(t_env *e);

#endif
