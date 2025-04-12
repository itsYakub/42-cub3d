/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par-map0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 07:09:39 by joleksia          #+#    #+#             */
/*   Updated: 2025/03/30 08:23:23 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	__par_map_siz(t_dat dat, t_vec2i dst);
static int	__par_map_playerspawn(t_dat dat, t_vec2i dst);

t_map	*par_map_init(const char *file)
{
	t_dat	dat;
	t_map	*map;

	if (!par_dat_init(&dat, file))
		return (0);
	map = (t_map *) ft_calloc(1, sizeof(t_map));
	if (!map)
	{
		par_dat_unload(&dat);
		return (0);
	}
	__par_map_siz(dat, map->map_size);
	__par_map_playerspawn(dat, map->map_spawn);
	map->cell = par_mapdup(dat.cell_data, dat.height);
	map->dir = dat.cell_data[map->map_spawn[1]][map->map_spawn[0]];
	ft_memcpy(map->map_col_c, dat.color_ceiling, sizeof(t_vec3i));
	ft_memcpy(map->map_col_f, dat.color_floor, sizeof(t_vec3i));
	map->map_col_c[3] = 255;
	map->map_col_f[3] = 255;
	map->map_txt_no = ft_strdup(dat.wall_no_file);
	map->map_txt_so = ft_strdup(dat.wall_so_file);
	map->map_txt_we = ft_strdup(dat.wall_we_file);
	map->map_txt_ea = ft_strdup(dat.wall_ea_file);
	par_dat_unload(&dat);
	return (map);
}

int	par_map_unload(t_map *map)
{
	if (!map)
		return (0);
	free(map->map_txt_no);
	free(map->map_txt_so);
	free(map->map_txt_we);
	free(map->map_txt_ea);
	if (map->cell)
	{
		while (map->map_size[1]--)
			free(map->cell[map->map_size[1]]);
		free(map->cell);
	}
	free(map);
	return (1);
}

static int	__par_map_siz(t_dat dat, t_vec2i dst)
{
	int	i;

	dst[1] = dat.height;
	i = -1;
	while (++i < (int) dat.height)
		dst[0] = par_max(ft_strlen(dat.cell_data[i]), dst[0]);
	return (1);
}

static int	__par_map_playerspawn(t_dat dat, t_vec2i dst)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (int) dat.height)
	{
		j = -1;
		while (dat.cell_data[i][++j])
		{
			if (ft_strchr("NSWE", dat.cell_data[i][j]))
			{
				dst[0] = j;
				dst[1] = i;
				return (1);
			}
		}
	}
	return (0);
}
