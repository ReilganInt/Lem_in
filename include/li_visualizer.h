/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_visualizer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:03:24 by cormund           #+#    #+#             */
/*   Updated: 2019/12/13 16:04:44 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LI_VISUALIZER_H
# define LI_VISUALIZER_H

# include "lem_in.h"
# include "SDL.h"
# include "SDL2_gfxPrimitives.h"

# define SCREEN_WIDTH 2040
# define SCREEN_HEIGHT 1240

# define SDL_EVENT vis->e.type
# define SDL_KEYSTATE vis->keystate
# define SDL_ESCAPE SDL_SCANCODE_ESCAPE
# define SDL_SPACE SDL_SCANCODE_SPACE
# define SDL_RIGHT SDL_SCANCODE_RIGHT
# define SDL_LEFT SDL_SCANCODE_LEFT
# define SDL_UP SDL_SCANCODE_UP
# define SDL_DOWN SDL_SCANCODE_DOWN
# define SDL_R SDL_SCANCODE_R

# define LI_ALPHA_BLACK 50
# define LI_ALPHA_LINE 120

# define CLR_BG 0x414244
# define CLR_CIRCLE 0xbcbaac
# define CLR_LINE 0xddd9c9
# define CLR_BLACK 0x000000
# define CLR_ANT 0xbebebe

# define CLR_1 0xea7c78
# define CLR_2 0x896287
# define CLR_3 0xf2b13e
# define CLR_4 0x96dcd1
# define CLR_5 0xd26476
# define CLR_6 0x4ca5cd
# define CLR_7 0x7ff7ab
# define CLR_8 0xec88b8
# define CLR_9 0x629542
# define CLR_10 0xf5d272
# define CLR_11 0xb3e3ee
# define CLR_12 0xbcc1e8
# define CLR_13 0xf3cdb7
# define CLR_14 0xe6e0b2
# define CLR_15 0x41837f
# define CLR_16 0x448c54
# define CLR_17 0xa82e26
# define CLR_18 0x039482
# define CLR_19 0x820199
# define CLR_20 0xf2b13e

# define COUNT_COLORS 19
# define COUNT_MOVE_STEPS 75

typedef struct		s_circle
{
	float			x;
	float			y;
	float			dx;
	float			dy;
	SDL_Color		clr;
}					t_circle;

typedef struct		s_step
{
	SDL_Color		**m_clrs;
	t_circle		*clr_v;
	t_circle		*ants_move;
	SDL_bool		fin;
	int				n_ant;
	struct s_step	*prev;
	struct s_step	*next;
}					t_step;

typedef struct		s_vis
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Color		bgrnd_clr;
	SDL_Color		gray;
	SDL_Color		black;
	SDL_Color		ant;
	SDL_Color		colors[17];
	SDL_Point		scale;
	SDL_Event		e;
	SDL_bool		quit;
	SDL_bool		pause;
	t_paths			*paths;
	t_paths			*srbll;
	t_step			*first_step;
	t_step			*final_paths;
	bool			srbll_flag;
	int				radius;
	int				ant_radius;
	int				line_width;
	const Uint8		*keystate;
	int				delay;
}					t_vis;

void				background(t_vis *vis, t_lem_in *li);
SDL_Color			set_color(int clr, int alpha);
void				loop(t_vis *vis, t_lem_in *li, t_step *step);
t_step				*collection_steps(t_vis *vis, t_lem_in *li, t_step *step);
void				render_graph(t_vis *vis, t_lem_in *li, t_step *step);
t_step				*next_step(t_vis *vis, t_lem_in *li, t_step *step);
t_step				*new_step();
SDL_Color			**init_matrix_clr(SDL_Color **m_cpy, int n_v, t_link *link);
t_circle			*init_vertex_clr(t_circle *cpy_v, t_lem_in *li);
t_step				*collect_srbll_paths(t_vis *vis, t_step *step,\
											t_lem_in *li, t_paths *paths);
t_step				*collect_final_paths(t_vis *vis, t_step *step,\
											t_lem_in *li, t_paths *paths);
t_step				*turn_off_unused_paths(t_step *step, t_lem_in *li,\
															t_link *link);
void				collect_ant_move(t_vis *vis, t_lem_in *li,\
											t_step *final_step);
void				render_update(t_vis *vis, t_lem_in *li, t_step *step);

#endif
