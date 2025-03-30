/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d-gl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:36:30 by joleksia          #+#    #+#             */
/*   Updated: 2025/03/30 06:43:08 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cub_getpix(t_game *game, int x, int y)
{
	int		stride;
	int		bits;

	if (!game)
		return (!printf("error: null pointer\n"));
	if (x < 0 || x >= CUB_WIN_W || y < 0 || y >= CUB_WIN_H)
		return (!printf("error: index out of bounds\n"));
	bits = game->s_win.fb_bits;
	stride = game->s_win.fb_stride;
	return ((int) *game->s_win.fb + (y * stride + x * ((bits / 8))));
}

int	cub_setpix(t_game *game, int x, int y, unsigned int color)
{
	char	*dst;
	int		stride;
	int		bits;

	if (!game)
		return (!printf("error: null pointer\n"));
	if (x < 0 || x >= CUB_WIN_W || y < 0 || y >= CUB_WIN_H)
		return (!printf("error: index out of bounds\n"));
	bits = game->s_win.fb_bits;
	stride = game->s_win.fb_stride;
	dst = game->s_win.fb + (y * stride + x * ((bits / 8)));
	*(unsigned int *) dst = color;
	return (1);
}

int	cub_clear(t_game *game, unsigned int color)
{
	t_vec2i	i;

	if (!game)
		return (!printf("error: null pointer\n"));
	i[1] = -1;
	while (++i[1] < CUB_WIN_H)
	{
		i[0] = -1;
		while (++i[0] < CUB_WIN_W)
		{
			cub_setpix(game, i[0], i[1], color);
		}
	}
	return (1);
}

int	cub_clear_region(t_game *game, unsigned int color, const t_vec4i region)
{
	t_vec2i	i;

	if (!game)
		return (!printf("error: null pointer\n"));
	i[1] = region[1] - 1;
	while (++i[1] < region[3])
	{
		i[0] = region[0] - 1;
		while (++i[0] < region[2])
		{
			cub_setpix(game, i[0], i[1], color);
		}
	}
	return (1);
}

int	cub_display(t_game *game)
{
	if (!game)
		return (!printf("error: null pointer\n"));
	mlx_put_image_to_window(
		game->s_win.mlx,
		game->s_win.win,
		game->s_win.img,
		0, 0
		);
	return (1);
}
