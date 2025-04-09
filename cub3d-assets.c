/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d-assets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:03:09 by joleksia          #+#    #+#             */
/*   Updated: 2025/04/09 10:34:39 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cub_ass_load(t_game *game)
{
	if (!game)
		return (!printf("error: null pointer\n"));
	ft_memset(&game->s_assets, 0, sizeof(game->s_assets));
	if (!cub_tex_load(game, &game->s_assets.txt_no, game->map->map_txt_no))
		return (0);
	if (!cub_tex_load(game, &game->s_assets.txt_so, game->map->map_txt_so))
		return (0);
	if (!cub_tex_load(game, &game->s_assets.txt_we, game->map->map_txt_we))
		return (0);
	if (!cub_tex_load(game, &game->s_assets.txt_ea, game->map->map_txt_ea))
		return (0);
	return (printf("info: assets loaded successfully\n"));
}

int	cub_ass_unload(t_game *game)
{
	if (!game)
		return (!printf("error: null pointer\n"));
	return (
		cub_tex_unload(game, &game->s_assets.txt_no)
		&& cub_tex_unload(game, &game->s_assets.txt_so)
		&& cub_tex_unload(game, &game->s_assets.txt_we)
		&& cub_tex_unload(game, &game->s_assets.txt_ea));
}

int	cub_ass_gettex(t_game *game, t_texture *tex, int i)
{
	if (!game || !tex)
		return (!printf("error: null pointer\n"));
	if (i < 0 || i >= 4)
		return (!printf("error: index out of bounds\n"));
	if (!i)
		*tex = game->s_assets.txt_we;
	else if (i == 1)
		*tex = game->s_assets.txt_no;
	else if (i == 2)
		*tex = game->s_assets.txt_ea;
	else if (i == 3)
		*tex = game->s_assets.txt_so;
	return (1);
}
