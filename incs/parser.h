/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:13:53 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/11 15:23:03 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "push_swap.h"

void	parse_params(t_env *e);

void	stock_numbers(t_env *e);

void	check_numbers(t_env *e);

void	check_duplicate(t_env *e);

void	create_piles(t_env *e);

void	pile_simplify(t_env *e);

#endif
