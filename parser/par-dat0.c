/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par-dat0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 07:34:01 by joleksia          #+#    #+#             */
/*   Updated: 2025/04/11 09:06:41 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	__par_extract_dat(t_dat *dat, const char *filepath);
static int	__par_process_dat(t_dat *dat);

int	par_dat_init(t_dat *dat, const char *filepath)
{
	if (!__par_extract_dat(dat, filepath))
		return (0);
	if (!__par_process_dat(dat))
	{
		par_dat_unload(dat);
		return (0);
	}
	return (1);
}

int	par_dat_unload(t_dat *dat)
{
	if (dat->wall_no_file)
		free(dat->wall_no_file);
	if (dat->wall_so_file)
		free(dat->wall_so_file);
	if (dat->wall_we_file)
		free(dat->wall_we_file);
	if (dat->wall_ea_file)
		free(dat->wall_ea_file);
	if (dat->cell_data)
	{
		while (dat->height--)
		{
			if (dat->cell_data[dat->height])
				free(dat->cell_data[dat->height]);
		}
		free(dat->cell_data);
	}
	return (1);
}

static int	__par_extract_dat(t_dat *dat, const char *filepath)
{
	char	*fc;
	int		fd;

	dat = ft_memset(dat, 0, sizeof(t_dat));
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (!printf("error: invalid filepath\n"));
	if (!par_dat_ext(filepath))
	{
		close(fd);
		return (!printf("error: invalid extension\n"));
	}
	fc = par_readfile(fd);
	close (fd);
	if (!fc)
		return (!printf("error: readfile error\n"));
	else if (!*fc)
		return (!printf("error: empty file\n"));
	if (!par_extract(dat, fc))
	{
		free(fc);
		return (!printf("error: extract error\n"));
	}
	free(fc);
	return (1);
}

static int	__par_process_dat(t_dat *dat)
{
	if (!par_dat_inv_char(dat))
		return (0);
	if (!par_empty_char(dat))
		return (0);
	if (par_dat_spawn_present(dat) != 1)
		return (0);
	return (1);
}
