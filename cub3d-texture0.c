/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d-texture0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kobrebsk <kobrebsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 07:23:12 by joleksia          #+#    #+#             */
/*   Updated: 2025/04/30 13:14:33 by kobrebsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cub_tex_load(t_game *game, t_texture *tex, const char *s)
{
	if (!game || !tex)
		return (!printf("error: null pointer\n"));
	tex->img = mlx_xpm_file_to_image(
			game->s_win.mlx, (char *) s, &tex->w, &tex->h);
	if (!tex->img)
		return (!printf("error: texture load failed\n"));
	tex->dat = mlx_get_data_addr(tex->img, &tex->b, &tex->s, &tex->e);
	if (!tex->dat)
		return (!printf("error: image parse failed\n"));
	return (printf("info: texture loaded | path: %s\n", s));
}

int	cub_tex_unload(t_game *game, t_texture *tex)
{
	if (!game || !tex)
		return (!printf("error: null pointer\n"));
	if (tex->img)
		mlx_destroy_image(game->s_win.mlx, tex->img);
	return (1);
}

unsigned int	cub_tex_getpix(t_texture t, int x, int y)
{
	int		stride;
	int		bits;

	if (!t.img || !t.dat)
		return (!printf("warn: invalid texture\n"));
	if (x < 0 || x >= t.w || y < 0 || y >= t.h)
		return (!printf("warn: index out of bounds\n"));
	bits = t.b;
	stride = t.s;
	return (*((unsigned int *)(t.dat + (y * stride + x * ((bits / 8))))));
}
