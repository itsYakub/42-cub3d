/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d-dda0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 06:52:04 by joleksia          #+#    #+#             */
/*   Updated: 2025/04/04 08:04:05 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*	> https://github.com/jdah/doomenstein-3d/blob/main/src/main_wolf.c
 *	> https://lodev.org/cgtutor/raycasting.html
 * */
int	cub_dda(t_game *game, int x, t_vec2i l, int *o)
{
	t_ray	ray;
	float	cam;
	float	dperp;
	int		h;

	cam = 2 * x / (float) CUB_WIN_W - 1;
	cub_dda_ray(game, &ray, cam);
	if (!cub_dda_perform(game, &ray, o))
		return (0);
	dperp = ray.side[*o % 2] - ray.delta[*o % 2];
	h = (int)(CUB_WIN_H / dperp);
	l[0] = cub_max((CUB_WIN_H / 2) - (h / 2), 0);
	l[1] = cub_min((CUB_WIN_H / 2) + (h / 2), CUB_WIN_H - 1);
	return (1);
}

int	cub_dda_ray(t_game *game, t_ray *ray, float cam)
{
	ray->dir[0] = game->player.dir[0] + game->player.plane[0] * cam;
	ray->dir[1] = game->player.dir[1] + game->player.plane[1] * cam;
	ray->delta[0] = fabs(1.0f / ray->dir[0]);
	ray->delta[1] = fabs(1.0f / ray->dir[1]);
	ray->pos[0] = (int) game->player.pos[0];
	ray->pos[1] = (int) game->player.pos[1];
	ray->side[0] = ray->delta[0];
	if (ray->dir[0] < 0)
		ray->side[0] *= game->player.pos[0] - ray->pos[0];
	else
		ray->side[0] *= ray->pos[0] + 1 - game->player.pos[0];
	ray->side[1] = ray->delta[1];
	if (ray->dir[1] < 0)
		ray->side[1] *= game->player.pos[1] - ray->pos[1];
	else
		ray->side[1] *= ray->pos[1] + 1 - game->player.pos[1];
	ray->step[0] = (ray->dir[0] > 0) - (ray->dir[0] <= 0);
	ray->step[1] = (ray->dir[1] > 0) - (ray->dir[1] <= 0);
	ray->hit = 0;
	return (1);
}

int	cub_dda_perform(t_game *game, t_ray *ray, int *o)
{
	while (!ray->hit)
	{
		if (ray->side[0] < ray->side[1])
		{
			ray->side[0] += ray->delta[0];
			ray->pos[0] += ray->step[0];
			*o = cub_dda_we(ray);
		}
		else
		{
			ray->side[1] += ray->delta[1];
			ray->pos[1] += ray->step[1];
			*o = cub_dda_ns(ray);
		}
		if (ray->pos[1] < 0 || ray->pos[0] < 0
			|| ray->pos[1] >= game->map->map_size[1]
			|| ray->pos[0] >= ft_strlen(game->map->cell[ray->pos[1]]))
			return (0);
		if (game->map->cell[ray->pos[1]][ray->pos[0]] == '1')
			ray->hit = 1;
	}
	return (1);
}

int	cub_dda_ns(t_ray *ray)
{
	if (ray->dir[1] < 0.0f)
		return (1);
	return (3);
}

int	cub_dda_we(t_ray *ray)
{
	if (ray->dir[0] < 0.0f)
		return (0);
	return (2);
}
