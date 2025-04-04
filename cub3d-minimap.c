/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d-minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 09:45:48 by joleksia          #+#    #+#             */
/*   Updated: 2025/04/04 08:14:30 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	__cub_draw_square(t_game *game, t_vec2i pos, int siz, int col);

int	cub_minimap(t_game *game, t_vec2i pos)
{
	t_vec2i	i;
	t_vec2i	p;

	ft_memcpy(p, pos, sizeof(t_vec2i));
	i[1] = -1;
	while (++i[1] < game->map->map_size[1])
	{
		i[0] = -1;
		while (game->map->cell[i[1]][++i[0]])
		{
			if (game->map->cell[i[1]][i[0]] == '1')
				__cub_draw_square(game, p, 8, CUB_BLACK);
			else if ((int) game->player.pos[0] == i[0]
				&& (int) game->player.pos[1] == i[1])
				__cub_draw_square(game, p, 8, CUB_GREEN);
			else if (game->map->cell[i[1]][i[0]] != 32)
				__cub_draw_square(game, p, 8, CUB_WHITE);
			p[0] += 8;
		}
		p[0] = pos[0];
		p[1] += 8;
	}
	return (1);
}

static int	__cub_draw_square(t_game *game, t_vec2i pos, int siz, int col)
{
	t_vec2i	i;

	i[1] = -1;
	while (++i[1] < siz)
	{
		i[0] = -1;
		while (++i[0] < siz)
			cub_setpix(game, pos[0] + i[0], pos[1] + i[1], col);
	}
	return (1);
}
