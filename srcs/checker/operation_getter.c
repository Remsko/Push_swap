/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_getter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 13:33:45 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/10 18:17:09 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

static void	cleaner(t_env *e, char *line)
{
	free(e->a);
	free(e->b);
	free(line);
}

void		operation_getter(t_env *e)
{
	char *line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (do_operation(e, line) == FALSE)
		{
			cleaner(e, line);
			ft_error(8);
		}
		else
			free(line);
	}
}