/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d-time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 08:18:23 by joleksia          #+#    #+#             */
/*   Updated: 2025/04/04 09:42:53 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	cub_deltatime(t_game *game)
{
	if (!game)
		return (!printf("error: null pointer\n"));
	game->s_time.dt = (game->s_time.cur - game->s_time.prev) / 1000.0f;
	return (game->s_time.dt);
}

long	cub_gettime(void)
{
	struct timeval	t;

	if (gettimeofday(&t, 0) < 0)
		return (!printf("error: %s\n", strerror(errno)));
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

int	cub_updatetime(t_game *game)
{
	if (!game)
		return (!printf("error: null pointer\n"));
	game->s_time.prev = game->s_time.cur;
	game->s_time.cur = cub_gettime();
	return (1);
}
