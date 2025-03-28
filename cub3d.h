/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:48:22 by joleksia          #+#    #+#             */
/*   Updated: 2025/03/28 10:17:57 by joleksia         ###   ########.fr       */
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
#  define CUB_WIN_W 800
# endif
# ifndef CUB_WIN_H
#  define CUB_WIN_H 600
# endif

/*	SECTION:
 *		Typedefs
 * */

struct s_game
{
	t_map	*map;
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

/*	SECTION:
 *		Function declarations
 * */

/* ./cub3d.c */

int	cub_init(t_game *game);
int	cub_run(t_game *game);
int	cub_quit(t_game *game);

#endif
