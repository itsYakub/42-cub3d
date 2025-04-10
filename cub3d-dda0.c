/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d-dda0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 06:52:04 by joleksia          #+#    #+#             */
/*   Updated: 2025/04/10 10:47:16 by joleksia         ###   ########.fr       */
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
	if (!cub_ass_gettex(game, &tex, ray.o))
		return (0);
	cub_dda_draw(game, &ray, tex, (t_vec3i){l[0], l[1], x});
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

/*	Norme-proof variables layout:
 * */
/*	t_vec3i i3:
 *	[0] - l[0];
 *	[1] - l[1];
 *	[2] - x;
 * */
/*	double d[3]:
 *	[0] - wallx;
 *	[1] - step;
 *	[2] - tpos;
 * */
/*	int	i[4]:
 *	[0] - texx;
 *	[1] - texy;
 *	[2] - lineheight;
 *	[3] - y;
 * */
void	cub_dda_draw(t_game *game, t_ray *ray, t_texture t, t_vec3i i3)
{
	double	d[3];
	int		i[4];

	if (!ray->o || ray->o == 2)
		d[0] = game->player.pos[1] + ray->dperp * ray->dir[1];
	else
		d[0] = game->player.pos[0] + ray->dperp * ray->dir[0];
	d[0] -= (int)(d[0]);
	i[0] = (int)(d[0] * (double)(t.w));
	if ((!ray->o || ray->o == 2) && ray->dir[0] > 0)
		i[0] = t.w - i[0] - 1;
	if ((ray->o == 1 || ray->o == 3) && ray->dir[1] < 0)
		i[0] = t.w - i[0] - 1;
	i[2] = ((int) CUB_WIN_H / ray->dperp);
	d[1] = 1.0 * t.h / i[2];
	d[2] = (i3[0] - CUB_WIN_H / 2.0 + i[2] / 2.0) * d[1];
	i[3] = i3[0] - 1;
	while (++i[3] < i3[1])
	{
		i[1] = (int) d[2] & (t.h - 1);
		d[2] += d[1];
		cub_setpix(game, i3[2], i[3],
			cub_dda_dsh(game, ray, cub_tex_getpix(t, i[0], i[1])));
	}
}
