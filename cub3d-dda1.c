/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d-dda1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 08:41:25 by joleksia          #+#    #+#             */
/*   Updated: 2025/04/10 10:36:02 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

unsigned int	cub_dda_dsh(t_game *game, t_ray *ray, unsigned int pix)
{
	t_vec4i	_col;
	float	_dist;
	float	_limit;
	float	_fact;

	cub_pix2col(pix, _col);
	_dist = cub_disti(game->player.pos, ray->pos);
	_limit = CUB_DDA_DISTANT_SHADOW_D;
	_fact = 1 - (cub_min(_dist, _limit) / _limit);
	_fact = cub_maxf(_fact, 0.1f);
	_col[0] *= _fact;
	_col[1] *= _fact;
	_col[2] *= _fact;
	return (cub_col2pix(_col));
}
