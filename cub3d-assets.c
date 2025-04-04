/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d-assets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:03:09 by joleksia          #+#    #+#             */
/*   Updated: 2025/04/04 10:27:04 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cub_ass_load(t_game *game)
{
	ft_memset(&game->s_assets, 0, sizeof(game->s_assets));
	game->s_assets.txt_no = mlx_xpm_file_to_image(
			game->s_win.mlx, game->map->map_txt_no,
			&game->s_assets.txt_no_siz[0], &game->s_assets.txt_no_siz[1]);
	if (!game->s_assets.txt_no)
		return (!printf("error: image load failed\n"));
	game->s_assets.txt_so = mlx_xpm_file_to_image(
			game->s_win.mlx, game->map->map_txt_so,
			&game->s_assets.txt_so_siz[0], &game->s_assets.txt_so_siz[1]);
	if (!game->s_assets.txt_no)
		return (!printf("error: image load failed\n"));
	game->s_assets.txt_we = mlx_xpm_file_to_image(
			game->s_win.mlx, game->map->map_txt_we,
			&game->s_assets.txt_we_siz[0], &game->s_assets.txt_we_siz[1]);
	if (!game->s_assets.txt_no)
		return (!printf("error: image load failed\n"));
	game->s_assets.txt_ea = mlx_xpm_file_to_image(
			game->s_win.mlx, game->map->map_txt_ea,
			&game->s_assets.txt_ea_siz[0], &game->s_assets.txt_ea_siz[1]);
	if (!game->s_assets.txt_no)
		return (!printf("error: image load failed\n"));
	printf("info: assets loaded successfully\n");
	return (1);
}

int	cub_ass_unload(t_game *game)
{
	if (game->s_assets.txt_no)
		mlx_destroy_image(game->s_win.mlx, game->s_assets.txt_no);
	if (game->s_assets.txt_so)
		mlx_destroy_image(game->s_win.mlx, game->s_assets.txt_so);
	if (game->s_assets.txt_we)
		mlx_destroy_image(game->s_win.mlx, game->s_assets.txt_we);
	if (game->s_assets.txt_ea)
		mlx_destroy_image(game->s_win.mlx, game->s_assets.txt_ea);
	return (1);
}
