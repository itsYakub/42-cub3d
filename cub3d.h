/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:48:22 by joleksia          #+#    #+#             */
/*   Updated: 2025/04/04 10:09:12 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*	SECTION:
 *		Header includes
 * */

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <sys/time.h>
# include <X11/keysym.h>
# include <X11/keysymdef.h>
# include "parser/parser.h"
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include "minilibx/mlx_int.h"

/*	SECTION:
 *		Macro definitions
 * */

# ifndef CUB_WIN_W
#  define CUB_WIN_W 1024
# endif
# ifndef CUB_WIN_H
#  define CUB_WIN_H 768
# endif
# ifndef CUB_FAR_PLANE
#  define CUB_FAR_PLANE 64
# endif
# ifndef CUB_P_SENS
#  define CUB_P_SENS 2.0f
# endif
# ifndef CUB_P_VEL
#  define CUB_P_VEL 2.0f
# endif
# ifndef CUB_RED
#  define CUB_RED 0xffd32734
# endif
# ifndef CUB_GREEN
#  define CUB_GREEN 0xff28c641
# endif
# ifndef CUB_BLUE
#  define CUB_BLUE 0xff2d93dd
# endif
# ifndef CUB_YELLOW
#  define CUB_YELLOW 0xffe6da29
# endif
# ifndef CUB_WHITE
#  define CUB_WHITE 0xfff8f8f8
# endif
# ifndef CUB_BLACK
#  define CUB_BLACK 0xff0f0f0f
# endif

/*	SECTION:
 *		Typedefs
 * */

struct					s_game;
struct					s_player;
struct					s_ray;

struct s_player
{
	struct s_game	*game;
	t_vec2			pos;
	t_vec2			dir;
	t_vec2			plane;
};

struct s_game
{
	struct s_player	player;
	unsigned int	input[65536];
	t_map			*map;
	struct
	{
		t_xvar		*mlx;
		t_win_list	*win;
		t_img		*img;
		char		*fb;
		int			fb_bits;
		int			fb_stride;
		int			fb_endian;
	}	s_win;
	struct
	{
		time_t		cur;
		time_t		prev;
		float		dt;
	}	s_time;
	struct
	{
		t_img		*txt_no;
		t_vec2i		txt_no_siz;
		char		*txt_no_buf;
		t_img		*txt_so;
		t_vec2i		txt_so_siz;
		char		*txt_so_buf;
		t_img		*txt_we;
		t_vec2i		txt_we_siz;
		char		*txt_we_buf;
		t_img		*txt_ea;
		t_vec2i		txt_ea_siz;
		char		*txt_ea_buf;
	}	s_assets;
};

struct s_ray
{
	t_vec2i	pos;
	t_vec2	dir;
	t_vec2	delta;
	t_vec2	side;
	t_vec2	step;
	int		hit;
};

typedef struct s_game	t_game;
typedef struct s_player	t_player;
typedef struct s_ray	t_ray;
typedef unsigned int	t_pix;

/*	SECTION:
 *		Function declarations
 * */

/* ./cub3d.c */

int	cub_init(t_game *game);
int	cub_run(t_game *game);
int	cub_update(t_game *game);
int	cub_quit(t_game *game);

/* ./cub3d-input.c */

int	cub_input_down(int key, t_game *game);
int	cub_input_up(int key, t_game *game);
int cub_key_down(t_game *game, int key);
int cub_key_up(t_game *game, int key);

/* ./cub3d-gl.c */

int	cub_getpix(t_game *game, int x, int y);
int	cub_setpix(t_game *game, int x, int y, unsigned int color);
int	cub_clear(t_game *game, unsigned int color);
int	cub_clear_region(t_game *game, unsigned int color, const t_vec4i region);
int	cub_display(t_game *game);

/* ./cub3d-math0.c */

int	cub_min(int a, int b);
int	cub_max(int a, int b);
int	cub_col_int(t_vec4i col);

/* ./cub3d-player0.c ./cub3d-player1.c */

int	cub_player(t_game *game);
int	cub_p_update(t_game *game);
int	cub_p_render(t_game *game);
int	cub_p_rotate(t_game *game, float delta);
int	cub_p_move(t_game *game, float delta);
int	cub_p_strafe(t_game *game, float delta);

/* ./cub3d-minimap.c */

int	cub_minimap(t_game *game, t_vec2i pos);

/* ./cub3d-dda0.c */

int	cub_dda(t_game *game, int x, t_vec2i l, int *o);
int	cub_dda_ray(t_game *game, t_ray *ray, float cam);
int	cub_dda_perform(t_game *game, t_ray *ray, int *o);
int	cub_dda_ns(t_ray *ray);
int	cub_dda_we(t_ray *ray);

/* ./cub3d-time.c */
float	cub_deltatime(t_game *game);
long	cub_gettime(void);
int		cub_updatetime(t_game *game);

/* ./cub3d-assets.c */
int	cub_ass_load(t_game *game);
int	cub_ass_unload(t_game *game);

#endif
