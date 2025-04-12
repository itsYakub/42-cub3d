/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par-extract-data0.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:01:51 by joleksia          #+#    #+#             */
/*   Updated: 2025/03/28 08:59:56 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	par_extract(t_dat *dat, const char *s)
{
	char	*current_line;

	(void) dat;
	current_line = par_sgetline(s);
	if (!current_line)
		return (!par_dat_unload(dat));
	s += ft_strlen(current_line) + 1;
	while (*s || *current_line)
	{
		if (!par_process_line(dat, current_line))
		{
			free(current_line);
			return (!par_dat_unload(dat));
		}
		free(current_line);
		if (!*s)
			break ;
		current_line = par_sgetline(s);
		if (!current_line)
			return (!par_dat_unload(dat));
		s += ft_strlen(current_line) + 1;
	}
	return (1);
}

int	par_process_line(t_dat *dat, char *line)
{
	if (dat->parse_mode == PARSE_MODE_MISC && par_misc_filled(dat))
	{
		if (par_line_empty(line))
			return (1);
		dat->parse_mode = PARSE_MODE_CELL;
	}
	if (dat->parse_mode == PARSE_MODE_MISC)
		return (par_parse_misc(dat, line));
	else if (dat->parse_mode == PARSE_MODE_CELL)
		return (par_parse_cell(dat, line));
	else if (dat->parse_mode == PARSE_MODE_FIN)
		return (par_line_empty(line));
	else
		return (0);
	return (1);
}
