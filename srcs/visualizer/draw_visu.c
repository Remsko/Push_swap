/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 15:32:00 by rpinoit           #+#    #+#             */
/*   Updated: 2018/06/13 17:03:26 by rpinoit          ###   ########.fr       */
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
    SDL_SetRenderDrawColor(v->renderer, 255, 200, 150, 255);
    SDL_RenderFillRect(v->renderer, &r);
    r.x = r.w;
    SDL_SetRenderDrawColor(v->renderer, 245, 190, 140, 255);
    SDL_RenderFillRect(v->renderer, &r);
}

static void draw_a(t_env *e, t_visual *v)
{
    SDL_Rect    r;
    int         index;
    int         ratio_h;
    int         ratio_w;

    SDL_SetRenderDrawColor(v->renderer, 255, 255, 255, 255);
    index = e->a_len;
    ratio_h = WIN_H / e->elem_nb;
    ratio_w = WIN_W / 2 / e->elem_nb;
    r.y = WIN_H;
    while (index > 0)
    {
        /* temporary formula for r.w */
        r.w = (e->a[index] * ratio_w);
        r.h = ratio_h;
        r.x = WIN_W / 4 - (r.w / 2);
        SDL_RenderFillRect(v->renderer, &r);
        r.y -= ratio_h;
        --index;
    }
}

static void draw_b(t_env *e, t_visual *v)
{
    SDL_Rect    r;
    int         index;
    int         ratio_h;
    int         ratio_w;

    SDL_SetRenderDrawColor(v->renderer, 0, 0, 0, 255);
    index = e->b_len;
    ratio_h = WIN_H / e->elem_nb;
    ratio_w = WIN_W / 2 / e->elem_nb;
    r.y = WIN_H;
    while (index > 0)
    {
        /* temporary formula for r.w */
        r.w = (e->b[index] * ratio_w);
        r.h = ratio_h;
        r.x = WIN_W / 2 + WIN_W / 4 - (r.w / 2);
        SDL_RenderFillRect(v->renderer, &r);
        r.y -= ratio_h;
        --index;
    }
}

void        draw_visu(t_env *e, t_visual *v)
{
    (void)e;

    SDL_SetRenderTarget(v->renderer, v->texture);
    draw_background(v);
    draw_a(e, v);
    draw_b(e, v);
    SDL_SetRenderTarget(v->renderer, NULL);
    SDL_RenderCopy(v->renderer, v->texture, NULL, NULL);
    SDL_RenderPresent(v->renderer);
}