/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:14:45 by rpinoit           #+#    #+#             */
/*   Updated: 2018/06/11 15:12:26 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	parse_params(t_env *e, char **argv)
{
	if (argv != NULL && *argv != NULL)
	{
		stock_numbers(e, argv);
		check_numbers(e);
		create_piles(e);
		check_duplicate(e);
		pile_simplify(e);
	}
	else
		ft_error(0);
}
