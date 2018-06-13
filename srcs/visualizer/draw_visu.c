/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 15:32:00 by rpinoit           #+#    #+#             */
/*   Updated: 2018/06/13 16:19:51 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

static void draw_background(t_visual *v)
{
    SDL_Rect r;

    r.w = WIN_W / 2;
    r.h = WIN_H;
    r.x = 0;
    r.y = 0;
    SDL_SetRenderDrawColor(v->renderer, 255, 200, 150, 0);
    SDL_RenderFillRect(v->renderer, &r);
    r.x = r.w;
    SDL_SetRenderDrawColor(v->renderer, 245, 190, 140, 0);
    SDL_RenderFillRect(v->renderer, &r);
}

void        draw_visu(t_env *e, t_visual *v)
{
    (void)e;

    SDL_SetRenderTarget(v->renderer, v->texture);
    draw_background(v);
    //draw_a(e, v);
    //draw_b(e, v);
    SDL_SetRenderTarget(v->renderer, NULL);
    SDL_RenderCopy(v->renderer, v->texture, NULL, NULL);
    SDL_RenderPresent(v->renderer);
}