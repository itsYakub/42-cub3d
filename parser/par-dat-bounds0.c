/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par-dat-bounds0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 08:05:10 by joleksia          #+#    #+#             */
/*   Updated: 2025/04/11 09:08:48 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	par_empty_char(t_dat *dat)
{
	char	neighs[5];
	t_vec2i	i;

	i[1] = -1;
	while (++i[1] < (int) dat->height)
	{
		i[0] = -1;
		while (dat->cell_data[i[1]][++i[0]])
		{
			if (dat->cell_data[i[1]][i[0]] == '0')
			{
				par_get_neigh(dat->cell_data, i, dat->height, neighs);
				if (!par_strdiff("NEWS10", neighs) || ft_strlen(neighs) != 4)
					return (!printf("error: hole in the wall\n"));
			}
		}
	}
	return (1);
}
