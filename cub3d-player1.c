/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d-player1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 10:52:41 by joleksia          #+#    #+#             */
/*   Updated: 2025/04/03 11:23:07 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cub_p_rotate(t_game *game)
{
	t_vec2	dir;
	t_vec2	plane;
	float	rot;
	int		input;

	if (!game)
		return (!printf("error: null pointer\n"));
	input = (cub_key_down(game, XK_Right) - cub_key_down(game, XK_Left));
	rot = (CUB_P_SENS * 0.016f) * input;
	ft_memcpy(dir, game->player.dir, sizeof(t_vec2));
	ft_memcpy(plane, game->player.plane, sizeof(t_vec2));
	game->player.dir[0] = dir[0] * cosf(rot) - dir[1] * sinf(rot);
	game->player.dir[1] = dir[0] * sinf(rot) + dir[1] * cosf(rot);
	game->player.plane[0] = plane[0] * cosf(rot) - plane[1] * sinf(rot);
	game->player.plane[1] = plane[0] * sinf(rot) + plane[1] * cosf(rot);
	return (1);
}

int	cub_p_move(t_game *game)
{
	if (!game)
		return (!printf("error: null pointer\n"));
	if (cub_key_down(game, XK_w))
	{
		game->player.pos[0] += game->player.dir[0] * CUB_P_VEL * 0.016f;
		game->player.pos[1] += game->player.dir[1] * CUB_P_VEL * 0.016f;
		if (game->map->cell[(int) game->player.pos[1]]
			[(int) game->player.pos[0]] == '1')
		{
			game->player.pos[0] -= game->player.dir[0] * CUB_P_VEL * 0.016f;
			game->player.pos[1] -= game->player.dir[1] * CUB_P_VEL * 0.016f;
		}
	}
	else if (cub_key_down(game, XK_s))
	{
		game->player.pos[0] -= game->player.dir[0] * CUB_P_VEL * 0.016f;
		game->player.pos[1] -= game->player.dir[1] * CUB_P_VEL * 0.016f;
		if (game->map->cell[(int) game->player.pos[1]]
			[(int) game->player.pos[0]] == '1')
		{
			game->player.pos[0] += game->player.dir[0] * CUB_P_VEL * 0.016f;
			game->player.pos[1] += game->player.dir[1] * CUB_P_VEL * 0.016f;
		}
	}
	return (1);
}

int	cub_p_strafe(t_game *game)
{
	if (!game)
		return (!printf("error: null pointer\n"));
	if (cub_key_down(game, XK_a))
	{
		game->player.pos[0] += game->player.dir[1] * CUB_P_VEL * 0.016f;
		game->player.pos[1] -= game->player.dir[0] * CUB_P_VEL * 0.016f;
		if (game->map->cell[(int) game->player.pos[1]]
			[(int) game->player.pos[0]] == '1')
		{
			game->player.pos[0] -= game->player.dir[1] * CUB_P_VEL * 0.016f;
			game->player.pos[1] += game->player.dir[0] * CUB_P_VEL * 0.016f;
		}
	}
	else if (cub_key_down(game, XK_d))
	{
		game->player.pos[0] -= game->player.dir[1] * CUB_P_VEL * 0.016f;
		game->player.pos[1] += game->player.dir[0] * CUB_P_VEL * 0.016f;
		if (game->map->cell[(int) game->player.pos[1]]
			[(int) game->player.pos[0]] == '1')
		{
			game->player.pos[0] += game->player.dir[1] * CUB_P_VEL * 0.016f;
			game->player.pos[1] -= game->player.dir[0] * CUB_P_VEL * 0.016f;
		}
	}
	return (1);
}
