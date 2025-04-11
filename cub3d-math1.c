/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d-math1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 08:10:19 by joleksia          #+#    #+#             */
/*   Updated: 2025/04/11 07:53:48 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	cub_dist(t_vec2 a, t_vec2 b)
{
	return (sqrt(pow(b[0] - a[0], 2) + pow(b[1] - a[1], 2)));
}

float	cub_disti(t_vec2 a, t_vec2i b)
{
	t_vec2	_b;

	_b[0] = (float)(b[0]);
	_b[1] = (float)(b[1]);
	return (cub_dist(a, _b));
}

int	cub_col2pix(t_vec4i col)
{
	unsigned int	_pix;

	_pix = col[0] << 0
		| col[1] << 8
		| col[2] << 16
		| col[3] << 24;
	return (_pix);
}

int	cub_pix2col(unsigned int pix, t_vec4i dst)
{
	dst[0] = pix >> 0 & 0xff;
	dst[1] = pix >> 8 & 0xff;
	dst[2] = pix >> 16 & 0xff;
	dst[3] = pix >> 24 & 0xff;
	return (1);
}
