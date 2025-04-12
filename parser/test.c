/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 07:46:08 by joleksia          #+#    #+#             */
/*   Updated: 2025/04/11 09:08:00 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	__test(const char *fpath, int i);

int	main(void)
{
	int			i;
	const char	*filepaths[] = {
		"./maps/example0.cub",
		"./maps/example1.cub",
		"./maps/example-inv-misc-after-cell.cub",
		"./maps/example-inv-hole-in-map.cub",
		"./maps/example-inv-characters.cub",
		"./maps/example-inv-multiple-spawn.cub",
		"./maps/example-inv-no-spawn.cub",
		"./maps/example-inv-hole-in-middle.cub",
		"./maps/example-inv-empty.cub",
		"./maps/example-inv-extension.cup",
		0
	};

	i = -1;
	while (filepaths[++i])
		__test(filepaths[i], i);
	printf("\033[1m---\033[0m\n");
	return (0);
}

static void	__test(const char *fpath, int i)
{
	t_map		*map;

	printf("\033[1m---\033[0m\n");
	map = par_map_init(fpath);
	if (!map)
	{
		printf("\033[31;1m[ test %d. ] Test failed\033[0m\n", i);
		return ;
	}
	printf("\033[32;1m[ test %d. ] Test passed\033[0m\n", i);
	printf("\033[1m> Size: %d, %d\n", map->map_size[0], map->map_size[1]);
	printf("\033[1m> Spawn: %d, %d\n", map->map_spawn[0], map->map_spawn[1]);
	printf("\033[1m> Facing: %c\n", map->dir);
	par_map_unload(map);
}
