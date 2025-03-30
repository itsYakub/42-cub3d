/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:48:22 by joleksia          #+#    #+#             */
/*   Updated: 2025/03/30 11:04:47 by joleksia         ###   ########.fr       */
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

/*	SECTION:
 *		Typedefs
 * */

struct					s_game;
struct					s_player;

struct s_player
{
	struct s_game	*game;
	t_vec2			pos;
	float			rot;
	float			fov;
};

struct s_game
{
	struct s_player	player;
	unsigned int	input[1024];
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
};

typedef struct s_game	t_game;
typedef struct s_player	t_player;

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
int	cub_p_rotate(t_game *game);
int	cub_p_move(t_game *game);

/* ./cub3d-minimap.c */

int	cub_minimap(t_game *game, t_vec2i pos);

#endif
