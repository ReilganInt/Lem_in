/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:41:25 by cormund           #+#    #+#             */
/*   Updated: 2019/12/14 20:27:09 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <stdbool.h>

# define LI_STDIN 0

# define LI_TRUE 1
# define LI_FALSE 0

# define LI_REQUIRED_TWO_PATHS 1
# define LI_COUNTER -1

# define LI_START 1
# define LI_END 2
# define LI_COMMENT 3
# define LI_VERTEX 4
# define LI_LINK 5

# define CH_START '1'
# define CH_END '0'

# define LI_OPEN 1
# define LI_CLOSE 0
# define LI_REVERSE -1

# define LI_COUNT_VRTX li->count_vertex
# define LI_COUNT_ADJACENTS vrx->count_edges
# define LI_ADJ_MARKED vrx->adj[i]->marked

# define LI_ERROR_NO_PATH_FROM_START_2_END "no path from the start to the end"
# define LI_ERROR_NOT_VALID_V "not valid vertexs."
# define LI_ERROR_NOT_VALID_EDGE "not valid edge."
# define LI_ERROR_NOT_VALID_ANTS "not valid count ants."
# define LI_ERROR_NOT_INPUT "no input, check usage: -h."
# define LI_ERROR_EMPTY_LINE "empty line is not defined."
# define LI_ERROR_NOT_VALID_COORD "not valid coordinates"
# define LI_ERROR_NOT_VALID_COMMAND "this command does not exist"

typedef struct s_input	t_input;
typedef struct s_pnt	t_pnt;
typedef struct s_vertex	t_vertex;
typedef struct s_link	t_link;
typedef struct s_lem_in	t_lem_in;
typedef struct s_queue	t_queue;
typedef struct s_path	t_path;
typedef struct s_paths	t_paths;
typedef struct s_ant	t_ant;

struct					s_input
{
	char				*line;
	int					type;
	struct s_input		*next;
};

struct					s_pnt
{
	int					y;
	int					x;
};

struct					s_vertex
{
	t_vertex			**adj;
	t_pnt				coord;
	int					id;
	int					count_edges;
	int					dist;
	char				*name;
	char				type;
	bool				marked;
	bool				splited;
	bool				vizited;
	int					count_ants;
	t_vertex			*out;
	struct s_vertex		*neighbor;
	struct s_vertex		*next;
};

struct					s_link
{
	t_vertex			*a;
	t_vertex			*b;
	struct s_link		*next;
};

struct					s_lem_in
{
	t_input				*first_line;
	t_vertex			*start;
	t_vertex			*end;
	t_vertex			**hash_table;
	t_vertex			**list_adj;
	t_link				*first_link;
	t_ant				*first_ant;
	char				**matrix_adj;
	char				**edges;
	int					count_ants;
	int					count_vertex;
	int					count_path;
	bool				flag_link;
	bool				visu;
};

struct					s_queue
{
	t_vertex			*vertex;
	t_queue				*next;
	t_queue				*prev;
};

struct					s_path
{
	t_vertex			**v;
	char				*edge;
	int					dist;
	int					ants;
	t_path				*next;
};

struct					s_paths
{
	t_path				*path;
	int					count_path;
	int					count_steps;
};

struct					s_ant
{
	int					number;
	bool				move;
	bool				end;
	float				x;
	float				y;
	t_vertex			**room;
	t_ant				*next;
};

void					read_input(t_input **beg_input);
void					parsing(t_lem_in *li);
void					adjacencies(t_lem_in *li);
int						id_increment(t_vertex *vertex);
t_vertex				**hash_table(t_vertex *vertex, int count_vertex);
t_paths					*suurballe(t_lem_in *li, int count_required_paths,\
																t_paths *vis);
t_paths					*find_paths(t_queue **queue, t_lem_in *li, int n_path,\
																		int i);
int						count_steps_and_ants(t_paths *paths, int count_ants);
void					enqueue(t_queue **queue, t_vertex *vertex,\
													t_queue **last);
t_vertex				*pop_queue(t_queue **queue);
void					clean_queue(t_queue **queue);
t_vertex				*bfs(t_queue **queue, t_lem_in *li);
t_paths					*check_paths(t_lem_in *li);
int						validation(t_lem_in *li, char *line);
t_ant					*push_ants(t_lem_in *li, t_paths *paths);
int						get_edge(t_lem_in *li, t_vertex *src,\
															t_vertex *dst);
void					set_matrix_adj(char **matrix_adj, t_link *link);
void					add_new_path(t_paths *paths, t_vertex *adj,\
											t_path **last_path, t_lem_in *li);
t_path					*new_path(t_vertex *vrx, t_lem_in *li);

/*
**	bonus
*/

void					print_input(t_input *in);
void					print_vertex(t_vertex *vertex);
void					print_links(t_link *link);
void					print_matrix_adj(char **matrix, int count_vertex);
void					print_list_adj(t_vertex **list_adj, int count_vertex);
void					print_finding(t_paths *finding);
void					print_help(void);

/*
**	Additional validation
*/

void					check_split(char **split);
void					check_split_vertex(char **split);
int						check_coord(char *coord);
char					*check_name(char *name);

/*
**	Vertexs functions
*/

t_vertex				*new_vertex(char *line, int vertex_type);
void					add_vertex(t_vertex **start, t_vertex *vertex);
t_vertex				*get_vertex(t_vertex *vertex, char *name);
void					add_new_link(t_link **first_link,\
									t_vertex *vertex, char *line);

/*
**	Clear functions
*/

void					clear_paths(t_path **paths);
void					clear_matrix(char **matrix);
void					clear_start(t_vertex *start);
void					clear_input(t_input *input);
void					clear_links(t_link *links);

/*
**	Visualizer function, other in li_vizualizer_h
*/

void					visualizer(t_lem_in *li, int count_paths);

#endif
