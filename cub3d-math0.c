/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d-math0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 06:27:09 by joleksia          #+#    #+#             */
/*   Updated: 2025/04/10 10:35:47 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cub_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	cub_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

float	cub_maxf(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

int	cub_col_int(t_vec4i col)
{
	return (
		col[3] << 8 * 3
		| col[0] << 8 * 2
		| col[1] << 8 * 1
		| col[2] << 8 * 0
	);
}
