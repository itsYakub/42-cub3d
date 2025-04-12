/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par-extract-data2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 06:53:12 by joleksia          #+#    #+#             */
/*   Updated: 2025/03/28 08:18:38 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	par_parse_misc(t_dat *dat, char *s)
{
	par_check_current_fill(dat, s);
	if (!ft_strncmp(s, "NO", 2))
		return (par_getpath(s + 2, &dat->wall_no_file));
	else if (!ft_strncmp(s, "SO", 2))
		return (par_getpath(s + 2, &dat->wall_so_file));
	else if (!ft_strncmp(s, "WE", 2))
		return (par_getpath(s + 2, &dat->wall_we_file));
	else if (!ft_strncmp(s, "EA", 2))
		return (par_getpath(s + 2, &dat->wall_ea_file));
	else if (!ft_strncmp(s, "F", 1))
		return (par_getcol(s + 1, dat->color_floor));
	else if (!ft_strncmp(s, "C", 1))
		return (par_getcol(s + 1, dat->color_ceiling));
	else if (par_line_empty(s))
		return (1);
	return (0);
}

int	par_parse_cell(t_dat *dat, char *s)
{
	if (!ft_strncmp(s, "NO", 2) || !ft_strncmp(s, "SO", 2)
		|| !ft_strncmp(s, "WE", 2) || !ft_strncmp(s, "EA", 2)
		|| !ft_strncmp(s, "F", 1) || !ft_strncmp(s, "C", 1))
		return (0);
	else if (par_line_empty(s))
		return (dat->parse_mode = PARSE_MODE_FIN);
	dat->cell_data
		= par_realloc(dat->cell_data, ++dat->height * sizeof(char *));
	dat->cell_data[dat->height - 1] = ft_strdup(s);
	return (1);
}

void	par_check_current_fill(t_dat *dat, char *s)
{
	dat->misc_fill[0] = dat->misc_fill[0] || !ft_strncmp(s, "NO", 2);
	dat->misc_fill[1] = dat->misc_fill[1] || !ft_strncmp(s, "SO", 2);
	dat->misc_fill[2] = dat->misc_fill[2] || !ft_strncmp(s, "WE", 2);
	dat->misc_fill[3] = dat->misc_fill[3] || !ft_strncmp(s, "EA", 2);
	dat->misc_fill[4] = dat->misc_fill[4] || !ft_strncmp(s, "F", 1);
	dat->misc_fill[5] = dat->misc_fill[5] || !ft_strncmp(s, "C", 1);
}

int	par_misc_filled(t_dat *dat)
{
	return (
		dat->misc_fill[0]
		&& dat->misc_fill[1]
		&& dat->misc_fill[2]
		&& dat->misc_fill[3]
		&& dat->misc_fill[4]
		&& dat->misc_fill[5]
	);
}
