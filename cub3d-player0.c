/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d-player0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 07:26:10 by joleksia          #+#    #+#             */
/*   Updated: 2025/04/10 11:04:38 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cub_player(t_game *game)
{
	if (!game)
		return (!printf("error: null pointer\n"));
	game->player.game = game;
	game->player.plane[0] = 0.0f;
	game->player.plane[1] = 3.14159 / 4.0f;
	ft_memcpy(game->player.dir, (t_vec2){1.0f, 0.0f}, sizeof(t_vec2));
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
