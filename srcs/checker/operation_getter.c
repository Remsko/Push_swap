/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_getter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 13:33:45 by rpinoit           #+#    #+#             */
/*   Updated: 2018/06/13 15:47:57 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

static void cleaner(t_env *e, char *line)
{
	free(e->a);
	free(e->b);
	free(line);
}

void operation_getter(t_env *e, t_visual *v)
{
	char *line;

	line = NULL;
	if (e->visual)
		draw_visu(e, v);
	while (get_next_line(0, &line) > 0)
	{
		if (do_operation(e, line) == FALSE)
		{
			cleaner(e, line);
			if (e->visual)
			{
				SDL_DestroyWindow(v->window);
				SDL_Quit();
			}
			ft_error(8);
		}
		else
		{
			free(line);
			if (e->visual)
			{
				sdl_event(v, FALSE);
				//draw_visu(e, v);
			}
			++e->op_nb;
		}
	}
	if (e->visual)
		sdl_event(v, TRUE);
}