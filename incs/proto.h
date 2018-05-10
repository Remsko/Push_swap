/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 21:50:22 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/10 14:16:23 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

# include "push_swap.h"

void    parse_params(t_env *e);

void    stock_numbers(t_env *e);

void	check_numbers(t_env *e);

void	check_duplicate(t_env *e);

t_bool	number_checker(char *nb);

void	create_piles(t_env *e);

void	pile_simplify(t_env *e);

void    ft_error(int nb);

void	operation_getter(t_env *e);

t_bool	do_operation(t_env *e, char *line);

#endif