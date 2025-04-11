/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d-player1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 10:52:41 by joleksia          #+#    #+#             */
/*   Updated: 2025/04/11 07:05:46 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	__cub_p_mov(t_game *g, float up, float right);
static int	__cub_p_strf(t_game *g, float up, float right);

int	cub_p_rotate(t_game *game, float delta)
{
	t_vec2	dir;
	t_vec2	plane;
	float	rot;
	int		input;

	if (!game)
		return (!printf("error: null pointer\n"));
	input = (cub_key_down(game, XK_Right) - cub_key_down(game, XK_Left));
	rot = (CUB_P_SENS * delta) * input;
	ft_memcpy(dir, game->player.dir, sizeof(t_vec2));
	ft_memcpy(plane, game->player.plane, sizeof(t_vec2));
	game->player.dir[0] = dir[0] * cosf(rot) - dir[1] * sinf(rot);
	game->player.dir[1] = dir[0] * sinf(rot) + dir[1] * cosf(rot);
	game->player.plane[0] = plane[0] * cosf(rot) - plane[1] * sinf(rot);
	game->player.plane[1] = plane[0] * sinf(rot) + plane[1] * cosf(rot);
	return (1);
}

int	cub_p_move(t_game *game, float delta)
{
	float	up;
	float	right;

	up = game->player.dir[1] * CUB_P_VEL * delta;
	right = game->player.dir[0] * CUB_P_VEL * delta;
	if (cub_key_down(game, XK_w))
		__cub_p_mov(game, up, right);
	else if (cub_key_down(game, XK_s))
		__cub_p_mov(game, -up, -right);
	return (1);
}

int	cub_p_strafe(t_game *game, float delta)
{
	float	up;
	float	right;

	up = game->player.dir[1] * CUB_P_VEL * delta;
	right = game->player.dir[0] * CUB_P_VEL * delta;
	if (cub_key_down(game, XK_a))
		__cub_p_strf(game, up, right);
	else if (cub_key_down(game, XK_d))
		__cub_p_strf(game, -up, -right);
	return (1);
}

static int	__cub_p_mov(t_game *g, float up, float right)
{
	g->player.pos[0] += right;
	g->player.pos[1] += up;
	if (g->map->cell[(int) g->player.pos[1]]
		[(int) g->player.pos[0]] == '1')
	{
		g->player.pos[0] -= right;
		g->player.pos[1] -= up;
	}
	return (1);
}

static int	__cub_p_strf(t_game *g, float up, float right)
{
	g->player.pos[0] += up;
	g->player.pos[1] -= right;
	if (g->map->cell[(int) g->player.pos[1]]
		[(int) g->player.pos[0]] == '1')
	{
		g->player.pos[0] -= up;
		g->player.pos[1] += right;
	}
	return (1);
}
