/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:48:48 by joleksia          #+#    #+#             */
/*   Updated: 2025/04/04 09:47:08 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (printf("./cub3d [ PATH_TO_MAP ]\n"));
	game.map = par_map_init(av[1]);
	if (!game.map)
		return (printf("error: map failed\n"));
	printf("info: map loaded successfully\n");
	if (!cub_init(&game))
		return (1);
	cub_player(&game);
	cub_run(&game);
	return (0);
}

int	cub_init(t_game *game)
{
	if (!game)
		return (!printf("error: null pointer\n"));
	ft_memset(&game->s_win, 0, sizeof(game->s_win));
	ft_memset(&game->s_time, 0, sizeof(game->s_time));
	ft_memset(&game->input, 0, sizeof(game->input));
	game->s_win.mlx = mlx_init();
	if (!game->s_win.mlx)
		return (!printf("error: cannot init mlx\n"));
	game->s_win.win = mlx_new_window(
			game->s_win.mlx,
			CUB_WIN_W, CUB_WIN_H,
			"42warsaw - cub3d");
	if (!game->s_win.win)
		return (!printf("error: cannot create window\n"));
	game->s_win.img = mlx_new_image(game->s_win.mlx, CUB_WIN_W, CUB_WIN_H);
	if (!game->s_win.img)
		return (!printf("error: cannot create image\n"));
	game->s_win.fb = mlx_get_data_addr(
			game->s_win.img,
			&game->s_win.fb_bits,
			&game->s_win.fb_stride,
			&game->s_win.fb_endian);
	printf(
		"info: init success | w: %d | h: %d | t: %s\n",
		CUB_WIN_W, CUB_WIN_H, "42warsaw - cub3d");
	return (1);
}

int	cub_run(t_game *game)
{
	if (!game)
		return (!printf("error: null pointer\n"));
	mlx_hook(game->s_win.win, 2, 1L << 0, cub_input_down, game);
	mlx_hook(game->s_win.win, 3, 1L << 1, cub_input_up, game);
	mlx_hook(game->s_win.win, 17, 0, cub_quit, game);
	mlx_loop_hook(game->s_win.mlx, cub_update, game);
	mlx_loop(game->s_win.mlx);
	return (1);
}

int	cub_update(t_game *game)
{
	const t_vec4i	rfloor = {
		0, CUB_WIN_H / 2, CUB_WIN_W, CUB_WIN_H
	};
	const t_vec4i	rceil = {
		0, 0, CUB_WIN_W, CUB_WIN_H / 2
	};

	if (!game)
		return (!printf("error: null pointer\n"));
	cub_clear_region(game, cub_col_int(game->map->map_col_f), rfloor);
	cub_clear_region(game, cub_col_int(game->map->map_col_c), rceil);
	cub_updatetime(game);
	cub_p_update(game);
	cub_display(game);
	return (1);
}

int	cub_quit(t_game *game)
{
	if (!game)
		return (!printf("error: null pointer\n"));
	printf("info: quit\n");
	par_map_unload(game->map);
	mlx_loop_end(game->s_win.mlx);
	mlx_destroy_image(game->s_win.mlx, game->s_win.img);
	mlx_destroy_window(game->s_win.mlx, game->s_win.win);
	mlx_destroy_display(game->s_win.mlx);
	free(game->s_win.mlx);
	exit (0);
}
