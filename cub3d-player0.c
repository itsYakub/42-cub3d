/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d-player0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 07:26:10 by joleksia          #+#    #+#             */
/*   Updated: 2025/04/03 11:23:40 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*	> https://github.com/jdah/doomenstein-3d/blob/main/src/main_wolf.c
 *	> https://lodev.org/cgtutor/raycasting.html
 * */
static int	__cub_p_dda(t_game *game, int x, t_vec2i l, int *o);
static int	__cub_p_verline(t_game *game, int x, t_vec2i l, int pix);

int	cub_player(t_game *game)
{
	if (!game)
		return (!printf("error: null pointer\n"));
	game->player.game = game;
	game->player.plane[0] = 0.0f;
	game->player.plane[1] = 0.66f;
	game->player.dir[0] = 1.0f;
	game->player.dir[1] = 0.0f;
	game->player.pos[0] = game->map->map_spawn[0];
	game->player.pos[1] = game->map->map_spawn[1];
	printf("info: player init\n");
	return (1);
}

int	cub_p_update(t_game *game)
{
	if (!game)
		return (!printf("error: null pointer\n"));
	cub_p_rotate(game);
	cub_p_move(game);
	cub_p_strafe(game);
	cub_p_render(game);
	cub_minimap(game, (t_vec2i){8, 8});
	return (1);
}

int	cub_p_render(t_game *game)
{
	t_vec2i	line;
	int		orient;
	int		x;

	if (!game)
		return (!printf("error: null pointer\n"));
	x = -1;
	while (++x < CUB_WIN_W)
	{
		__cub_p_dda(game, x, line, &orient);
		if (!orient)
			__cub_p_verline(game, x, line, 0xffd32734);
		else
			__cub_p_verline(game, x, line, 0xff2d93dd);
	}
	return (1);
}

static int	__cub_p_dda(t_game *game, int x, t_vec2i l, int *o)
{
	t_vec2i	pos;
	t_vec2	dir;
	t_vec2	delta;
	t_vec2	side;
	t_vec2	step;
	float	cam;
	float	dperp;
	int		hit;
	int		h;

	cam = 2 * x / (float) CUB_WIN_W - 1;
	dir[0] = game->player.dir[0] + game->player.plane[0] * cam;
	dir[1] = game->player.dir[1] + game->player.plane[1] * cam;
	delta[0] = fabs(1.0f / dir[0]);
	delta[1] = fabs(1.0f / dir[1]);
	pos[0] = (int) game->player.pos[0];
	pos[1] = (int) game->player.pos[1];
	side[0] = delta[0];
	if (dir[0] < 0)
		side[0] *= game->player.pos[0] - pos[0];
	else
		side[0] *= pos[0] + 1 - game->player.pos[0];
	side[1] = delta[1];
	if (dir[1] < 0)
		side[1] *= game->player.pos[1] - pos[1];
	else
		side[1] *= pos[1] + 1 - game->player.pos[1];
	step[0] = (dir[0] > 0) - (dir[0] <= 0);
	step[1] = (dir[1] > 0) - (dir[1] <= 0);
	hit = 0;
	while (!hit)
	{
		if (side[0] < side[1])
		{
			side[0] += delta[0];
			pos[0] += step[0];
			*o = 0;
		}
		else
		{
			side[1] += delta[1];
			pos[1] += step[1];
			*o = 1;
		}
		if (game->map->cell[pos[1]][pos[0]] == '1')
			hit = 1;
	}
	if (!*o)
		dperp = side[0] - delta[0];
	else
		dperp = side[1] - delta[1];
	h = (int)(CUB_WIN_H / dperp);
	l[0] = cub_max((CUB_WIN_H / 2) - (h / 2), 0);
	l[1] = cub_min((CUB_WIN_H / 2) + (h / 2), CUB_WIN_H - 1);
	return (1);
}

static int	__cub_p_verline(t_game *game, int x, t_vec2i l, int pix)
{
	int	y;

	y = l[0] - 1;
	while (++y < l[1])
		cub_setpix(game, x, y, pix);
	return (1);
}
