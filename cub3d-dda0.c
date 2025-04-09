/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d-dda0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 06:52:04 by joleksia          #+#    #+#             */
/*   Updated: 2025/04/09 11:33:35 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*	> https://github.com/jdah/doomenstein-3d/blob/main/src/main_wolf.c
 *	> https://lodev.org/cgtutor/raycasting.html
 * */
int	cub_dda(t_game *game, int x, t_vec2i l)
{
	t_ray		ray;
	t_texture	tex;
	float		cam;
	int			lh;

	cam = 2 * x / (float) CUB_WIN_W - 1;
	cub_dda_ray(game, &ray, cam);
	if (!cub_dda_perform(game, &ray))
		return (0);
	ray.dperp = ray.side[ray.o % 2] - ray.delta[ray.o % 2];
	lh = (int)(CUB_WIN_H / ray.dperp);
	l[0] = cub_max((CUB_WIN_H / 2) - (lh / 2), 0);
	l[1] = cub_min((CUB_WIN_H / 2) + (lh / 2), CUB_WIN_H - 1);
	if (!cub_ass_gettex(game, &tex, ray.o)
		|| !cub_dda_draw(game, &ray, tex, l, x))
		return (0);
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

int	cub_dda_perform(t_game *game, t_ray *ray)
{
	while (!ray->hit)
	{
		if (ray->side[0] < ray->side[1])
		{
			ray->side[0] += ray->delta[0];
			ray->pos[0] += ray->step[0];
			ray->o = cub_dda_we(ray);
		}
		else
		{
			ray->side[1] += ray->delta[1];
			ray->pos[1] += ray->step[1];
			ray->o = cub_dda_ns(ray);
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

int	cub_dda_draw(t_game *game, t_ray *ray, t_texture t, t_vec2i l, int x)
{
	double			wallx;
	int				texx;
	double			step;
	double			tpos;
	int				lh;
	int				y;
	int				texy;
	unsigned int	pix;

	if (!ray->o || ray->o == 2)
	   wallx = game->player.pos[1] + ray->dperp * ray->dir[1];
	else
	   wallx = game->player.pos[0] + ray->dperp * ray->dir[0];
	wallx -= floor(wallx);
	texx = (int) (wallx * (double) (t.w));
	if ((!ray->o || ray->o == 2) && ray->dir[0] > 0)
		texx = t.w - texx - 1;
	if ((ray->o == 1 || ray->o == 3) && ray->dir[1] < 0)
		texx = t.w - texx - 1;
	lh = ((int) CUB_WIN_H / ray->dperp);
	step = 1.0 * t.h / lh;
	tpos = (l[0] - CUB_WIN_H / 2.0 + lh / 2.0) * step;
	y = l[0] - 1;
	while (++y < l[1])
	{
		texy = (int) tpos & (t.h - 1);
		tpos += step;
		pix = cub_tex_getpix(t, texx, texy);
		cub_setpix(game, x, y, pix);
	}
	return (1);
}
