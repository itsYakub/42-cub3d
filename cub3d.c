/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:48:48 by joleksia          #+#    #+#             */
/*   Updated: 2025/03/28 10:19:39 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (printf("./cub3d [ PATH_TO_MAP ]\n"));
	game.map = par_map_init(av[1]);
	if (!cub_init(&game))
		return (1);
	cub_run(&game);
	return (0);
}

int	cub_init(t_game *game)
{
	if (!game)
		return (printf("error: invalid pointer\n"));
	ft_memset(&game->s_win, 0, sizeof(game->s_win));
	game->s_win.mlx = mlx_init();
	if (!game->s_win.mlx)
		return (!printf("error: cannot init mlx\n"));
	game->s_win.win = mlx_new_window(
		game->s_win.mlx,
		CUB_WIN_W, CUB_WIN_H,
		"42warsaw - cub3d"
	);
	game->s_win.img = mlx_new_image(game->s_win.mlx, CUB_WIN_W, CUB_WIN_H);
	game->s_win.fb = mlx_get_data_addr(
		game->s_win.img,
		&game->s_win.fb_bits,
		&game->s_win.fb_stride,
		&game->s_win.fb_endian
	);
	printf(
		"info: init success | w: %d | h: %d | t: %s\n",
		CUB_WIN_W, CUB_WIN_H, "42warsaw - cub3d"
	);
	return (1);
}

int	cub_run(t_game *game)
{
	if (!game)
		return (printf("error: invalid pointer\n"));
	mlx_hook(game->s_win.win, 17, 0, cub_quit, game);
	mlx_loop(game->s_win.mlx);
	return (1);
}

int	cub_quit(t_game *game)
{
	if (!game)
		return (printf("error: invalid pointer\n"));
	printf("info: quit\n");
	par_map_unload(game->map);
	mlx_loop_end(game->s_win.mlx);
	mlx_destroy_image(game->s_win.mlx, game->s_win.img);
	mlx_destroy_window(game->s_win.mlx, game->s_win.win);
	mlx_destroy_display(game->s_win.mlx);
	free(game->s_win.mlx);
	exit (0);
}
