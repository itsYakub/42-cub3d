/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d-texture0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 07:23:12 by joleksia          #+#    #+#             */
/*   Updated: 2025/04/09 07:43:24 by joleksia         ###   ########.fr       */
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
	return (printf("info: textture loaded | path: %s\n", s));
}

int	cub_tex_unload(t_game *game, t_texture *tex)
{
	if (!game || !tex)
		return (!printf("error: null pointer\n"));
	if (tex->img)
		mlx_destroy_image(game->s_win.mlx, tex->img);
	return (1);
}
