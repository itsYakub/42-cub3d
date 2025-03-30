/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d-player0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 07:26:10 by joleksia          #+#    #+#             */
/*   Updated: 2025/03/30 11:35:45 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float	__cub_p_getdist(t_game *game, int i)
{
	int		wall_hit;
	float	wall_dist;
	float	ray_ang;
	t_vec2i	test;

	ray_ang
		= (game->player.rot - game->player.fov / 2.0f)
		+ ((float) i / (float) CUB_WIN_W) * game->player.fov;
	wall_hit = 0;
	wall_dist = 0.0f;
	while (!wall_hit && wall_dist < CUB_FAR_PLANE)
	{
		wall_dist += 0.1f;
		test[0] = (int)(game->player.pos[0] + sinf(ray_ang) * wall_dist);
		test[1] = (int)(game->player.pos[1] + cosf(ray_ang) * wall_dist);
		if (test[0] < 0 || test[0] >= CUB_WIN_W
			|| test[1] < 0 || test[1] >= CUB_WIN_H)
		{
			wall_hit = 1;
			wall_dist = CUB_FAR_PLANE;
		}
		else
			wall_hit = (game->map->cell[test[1]][test[0]] == '1');
	}
	return (wall_dist);
}

int	cub_player(t_game *game)
{
	if (!game)
		return (!printf("error: null pointer\n"));
	game->player.game = game;
	game->player.fov = 3.14159f / 4.0f;
	if (game->map->dir == 'N')
		game->player.rot = 0.0f;
	else if (game->map->dir == 'E')
		game->player.rot = 90.0f;
	else if (game->map->dir == 'S')
		game->player.rot = 270.0f;
	else if (game->map->dir == 'W')
		game->player.rot = 360.0f;
	game->player.pos[0] = game->map->map_spawn[0];
	game->player.pos[1] = game->map->map_spawn[1];
	printf(
		"info: player init | rot: %.2f | pos: %.2f, %.2f | fov: %.2f\n",
		game->player.rot,
		game->player.pos[0], game->player.pos[1],
		game->player.fov
		);
	return (1);
}

int	cub_p_update(t_game *game)
{
	t_vec2i	pos;

	if (!game)
		return (!printf("error: null pointer\n"));
	pos[0] = (int) game->player.pos[0];
	pos[1] = (int) game->player.pos[1];
	cub_p_rotate(game);
	cub_p_move(game);
	cub_p_strafe(game);
	cub_p_render(game);
	cub_minimap(game, (t_vec2i){8, 8});
	return (1);
}

int	cub_p_render(t_game *game)
{
	t_vec2i	i;
	t_vec2	floor_ceil_dist;
	float	dist;

	if (!game)
		return (!printf("error: null pointer\n"));
	i[0] = -1;
	while (++i[0] < CUB_WIN_W)
	{
		dist = __cub_p_getdist(game, i[0]);
		floor_ceil_dist[0] = (CUB_WIN_H / 2.0f) - CUB_WIN_H / dist;
		floor_ceil_dist[1] = CUB_WIN_H - floor_ceil_dist[0];
		i[1] = -1;
		while (++i[1] < CUB_WIN_H)
		{
			if (i[1] > floor_ceil_dist[0] && i[1] <= floor_ceil_dist[1])
				cub_setpix(game, i[0], i[1], 0xffffffff);
		}
	}
	return (1);
}
