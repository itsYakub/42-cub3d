/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d-player0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 07:26:10 by joleksia          #+#    #+#             */
/*   Updated: 2025/04/11 07:27:43 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	__cub_p_init_rotation(t_game *game, float r);

int	cub_player(t_game *game)
{
	if (!game)
		return (!printf("error: null pointer\n"));
	game->player.game = game;
	game->player.plane[0] = 0.0f;
	game->player.plane[1] = 3.14159 / 4.0f;
	ft_memcpy(game->player.dir, (t_vec2){1.0f, 0.0f}, sizeof(t_vec2));
	__cub_p_init_rotation(game, 3.14f);
	game->player.pos[0] = game->map->map_spawn[0] + 0.5f;
	game->player.pos[1] = game->map->map_spawn[1] + 0.5f;
	printf("info: player init\n");
	return (1);
}

int	cub_p_update(t_game *game)
{
	if (!game)
		return (!printf("error: null pointer\n"));
	cub_p_rotate(game, cub_deltatime(game));
	cub_p_move(game, cub_deltatime(game));
	cub_p_strafe(game, cub_deltatime(game));
	cub_p_render(game);
	cub_minimap(game, (t_vec2i){8, 8});
	return (1);
}

int	cub_p_render(t_game *game)
{
	t_vec2i	line;
	int		x;

	if (!game)
		return (!printf("error: null pointer\n"));
	x = -1;
	while (++x < CUB_WIN_W)
		cub_dda(game, x, line);
	return (1);
}

static int	__cub_p_init_rotation(t_game *game, float r)
{
	t_vec2	dir;
	t_vec2	plane;
	
	ft_memcpy(dir, game->player.dir, sizeof(t_vec2));
	ft_memcpy(plane, game->player.plane, sizeof(t_vec2));
	if (game->map->dir == DIR_NORTH)
		r *= -0.5f;
	else if (game->map->dir == DIR_SOUTH)
		r *= 0.5f;
	else if (game->map->dir == DIR_WEST)
		r *= 1.0f;
	else if (game->map->dir == DIR_EAST)
		r *= 2.0f;
	else
		return (!printf("warn: invalid direction\n"));
	game->player.dir[0] = dir[0] * cosf(r) - dir[1] * sinf(r);
	game->player.dir[1] = dir[0] * sinf(r) + dir[1] * cosf(r);
	game->player.plane[0] = plane[0] * cosf(r) - plane[1] * sinf(r);
	game->player.plane[1] = plane[0] * sinf(r) + plane[1] * cosf(r);
	return (1);
}
