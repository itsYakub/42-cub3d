/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d-player1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 10:52:41 by joleksia          #+#    #+#             */
/*   Updated: 2025/03/30 11:36:06 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cub_p_rotate(t_game *game)
{
	if (!game)
		return (!printf("error: null pointer\n"));
	game->player.rot
		+= (cub_key_down(game, XK_Right) - cub_key_down(game, XK_Left)) * 0.01f;
	return (1);
}

int	cub_p_move(t_game *game)
{
	if (!game)
		return (!printf("error: null pointer\n"));
	if (cub_key_down(game, XK_w))
	{
		game->player.pos[0] += sinf(game->player.rot) * 0.02f;
		game->player.pos[1] += cosf(game->player.rot) * 0.02f;
		if (game->map->cell[(int) game->player.pos[1]]
			[(int) game->player.pos[0]] == '1')
		{
			game->player.pos[0] -= sinf(game->player.rot) * 0.02f;
			game->player.pos[1] -= cosf(game->player.rot) * 0.02f;
		}
	}
	else if (cub_key_down(game, XK_s))
	{
		game->player.pos[0] -= sinf(game->player.rot) * 0.02f;
		game->player.pos[1] -= cosf(game->player.rot) * 0.02f;
		if (game->map->cell[(int) game->player.pos[1]]
			[(int) game->player.pos[0]] == '1')
		{
			game->player.pos[0] += sinf(game->player.rot) * 0.02f;
			game->player.pos[1] += cosf(game->player.rot) * 0.02f;
		}
	}
	return (1);
}

int	cub_p_strafe(t_game *game)
{
	if (!game)
		return (!printf("error: null pointer\n"));
	if (cub_key_down(game, XK_d))
	{
		game->player.pos[0] += cosf(game->player.rot) * 0.02f;
		game->player.pos[1] -= sinf(game->player.rot) * 0.02f;
		if (game->map->cell[(int) game->player.pos[1]]
			[(int) game->player.pos[0]] == '1')
		{
			game->player.pos[0] -= cosf(game->player.rot) * 0.02f;
			game->player.pos[1] += sinf(game->player.rot) * 0.02f;
		}
	}
	else if (cub_key_down(game, XK_a))
	{
		game->player.pos[0] -= cosf(game->player.rot) * 0.02f;
		game->player.pos[1] += sinf(game->player.rot) * 0.02f;
		if (game->map->cell[(int) game->player.pos[1]]
			[(int) game->player.pos[0]] == '1')
		{
			game->player.pos[0] += cosf(game->player.rot) * 0.02f;
			game->player.pos[1] -= sinf(game->player.rot) * 0.02f;
		}
	}
	return (1);
}
