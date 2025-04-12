/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par-dat2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 13:58:23 by joleksia          #+#    #+#             */
/*   Updated: 2025/04/11 09:08:18 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	par_get_neigh(char **t, t_vec2i i, int h, char l[5])
{
	int	_i;

	ft_memset(l, 0, 5);
	_i = 0;
	if (i[0] > 0)
		l[_i++] = t[i[1]][i[0] - 1];
	if (ft_strlen(t[i[1]]) > i[0] + 1)
		l[_i++] = t[i[1]][i[0] + 1];
	if (i[1] > 0 && ft_strlen(t[i[1] - 1]) > i[0])
		l[_i++] = t[i[1] - 1][i[0]];
	if (i[1] + 1 < h && ft_strlen(t[i[1] + 1]) > i[0])
		l[_i++] = t[i[1] + 1][i[0]];
	return (1);
}

int	par_strdiff(char *a, char *b)
{
	while (*b)
	{
		if (!ft_strchr((const char *) a, *b))
			return (0);
		b++;
	}
	return (1);
}
