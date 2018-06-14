/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 15:29:40 by rpinoit           #+#    #+#             */
/*   Updated: 2018/06/14 11:07:12 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	sdl_event(t_visual *v, t_bool loop)
{
	if (loop == FALSE)
	{
		if (SDL_PollEvent(&v->event))
		{
			if (v->event.type == SDL_QUIT)
				return ;
			else if (v->event.key.keysym.sym == SDLK_ESCAPE)
				return ;
		}
	}
	else
	{
		while (loop)
		{
			if (SDL_PollEvent(&v->event))
			{
				if (v->event.type == SDL_QUIT)
					return ;
				else if (v->event.key.keysym.sym == SDLK_ESCAPE)
					return ;
			}
		}
	}
}
