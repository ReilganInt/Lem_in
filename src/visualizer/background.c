/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:33:51 by cormund           #+#    #+#             */
/*   Updated: 2019/12/13 15:39:16 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_visualizer.h"

SDL_Color			set_color(int clr, int alpha)
{
	SDL_Color		color;

	color.r = clr >> 16;
	color.g = (clr >> 8) & 0xff;
	color.b = clr & 0xff;
	color.a = alpha;
	return (color);
}

static void			set_colors(SDL_Color *colors)
{
	colors[0] = set_color(CLR_1, SDL_ALPHA_OPAQUE);
	colors[1] = set_color(CLR_2, SDL_ALPHA_OPAQUE);
	colors[2] = set_color(CLR_3, SDL_ALPHA_OPAQUE);
	colors[3] = set_color(CLR_4, SDL_ALPHA_OPAQUE);
	colors[4] = set_color(CLR_5, SDL_ALPHA_OPAQUE);
	colors[5] = set_color(CLR_6, SDL_ALPHA_OPAQUE);
	colors[6] = set_color(CLR_7, SDL_ALPHA_OPAQUE);
	colors[7] = set_color(CLR_8, SDL_ALPHA_OPAQUE);
	colors[8] = set_color(CLR_9, SDL_ALPHA_OPAQUE);
	colors[9] = set_color(CLR_10, SDL_ALPHA_OPAQUE);
	colors[10] = set_color(CLR_11, SDL_ALPHA_OPAQUE);
	colors[11] = set_color(CLR_12, SDL_ALPHA_OPAQUE);
	colors[12] = set_color(CLR_13, SDL_ALPHA_OPAQUE);
	colors[13] = set_color(CLR_14, SDL_ALPHA_OPAQUE);
	colors[14] = set_color(CLR_15, SDL_ALPHA_OPAQUE);
	colors[15] = set_color(CLR_16, SDL_ALPHA_OPAQUE);
	colors[16] = set_color(CLR_17, SDL_ALPHA_OPAQUE);
	colors[17] = set_color(CLR_18, SDL_ALPHA_OPAQUE);
	colors[18] = set_color(CLR_19, SDL_ALPHA_OPAQUE);
	colors[19] = set_color(CLR_20, SDL_ALPHA_OPAQUE);
}

static void			set_new_vrx_coord(t_vertex *v, int indent)
{
	SDL_Point		sq;

	sq.x = SCREEN_WIDTH - indent;
	sq.y = SCREEN_HEIGHT - indent;
	srand(indent);
	while (v)
	{
		if (v->type == LI_START)
		{
			v->coord.x = indent / 2;
			v->coord.y = indent / 2;
		}
		else if (v->type == LI_END)
		{
			v->coord.x = sq.x + indent / 2;
			v->coord.y = sq.y + indent / 2;
		}
		else
		{
			v->coord.x = rand() % (sq.x - indent) + indent;
			v->coord.y = rand() % (sq.y - indent) + indent;
		}
		v = v->next;
	}
}

static void			set_scale(t_vertex *vrx, int indent)
{
	SDL_Point		scale;
	SDL_Point		max;
	t_vertex		*v;

	v = vrx;
	max.x = v->coord.x;
	max.y = v->coord.y;
	while (v->next)
	{
		v = v->next;
		max.x = FT_MAX(v->coord.x, max.x);
		max.y = FT_MAX(v->coord.y, max.y);
	}
	scale.x = (SCREEN_WIDTH - indent * 2) / max.x;
	scale.y = (SCREEN_HEIGHT - indent * 2) / max.y;
	v = vrx;
	if (scale.x == 0 || scale.y == 0)
		set_new_vrx_coord(vrx, indent);
	else
		while (v)
		{
			v->coord.x = v->coord.x * scale.x + indent;
			v->coord.y = v->coord.y * scale.y + indent;
			v = v->next;
		}
}

void				background(t_vis *vis, t_lem_in *li)
{
	vis->bgrnd_clr = set_color(CLR_BG, SDL_ALPHA_OPAQUE);
	vis->gray = set_color(CLR_CIRCLE, LI_ALPHA_LINE);
	vis->black = set_color(CLR_BLACK, LI_ALPHA_BLACK);
	vis->ant = set_color(CLR_ANT, SDL_ALPHA_OPAQUE);
	vis->radius = FT_MIN(SCREEN_WIDTH, SCREEN_HEIGHT) / (li->count_vertex * 3);
	vis->radius = FT_MAX(2, vis->radius);
	vis->ant_radius = vis->radius / 2;
	vis->line_width = vis->radius / 2.1;
	vis->line_width = FT_MAX(1, vis->line_width);
	set_scale(li->start, SCREEN_WIDTH / 10);
	set_colors(vis->colors);
}
