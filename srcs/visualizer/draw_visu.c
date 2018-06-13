/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 15:32:00 by rpinoit           #+#    #+#             */
/*   Updated: 2018/06/13 15:34:44 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void draw_visu(t_env *e, t_visual *v)
{
    (void)e;
    SDL_Rect r;

    //SDL_SetRenderTarget(v->renderer, v->texture);
    r.w = 1500 / 2;
    r.h = 900;
    r.x = 0;
    r.y = 0;
    SDL_SetRenderDrawColor(v->renderer, 255, 200, 150, 0);
    SDL_RenderFillRect(v->renderer, &r);
    r.x = r.w;
    SDL_SetRenderDrawColor(v->renderer, 245, 190, 140, 0);
    SDL_RenderFillRect(v->renderer, &r);
    SDL_RenderPresent(v->renderer);
}