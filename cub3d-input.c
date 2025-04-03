/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d-input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 07:30:11 by joleksia          #+#    #+#             */
/*   Updated: 2025/04/03 11:20:42 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <X11/keysymdef.h>

int	cub_input_down(int key, t_game *game)
{
	if (key == XK_Escape)
		cub_quit(game);
	if ((size_t) key < sizeof(game->input) / sizeof(int))
		game->input[key] = 1;
	return (1);
}

int	cub_input_up(int key, t_game *game)
{
	if ((size_t) key < sizeof(game->input) / sizeof(int))
		game->input[key] = 0;
	return (1);
}

int	cub_key_down(t_game *game, int key)
{
	return (game->input[key]);
}

int	cub_key_up(t_game *game, int key)
{
	return (!game->input[key]);
}
