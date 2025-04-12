/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par-extract-data1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:58:57 by joleksia          #+#    #+#             */
/*   Updated: 2025/03/26 09:46:24 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	par_getpath(char *s, char **dst)
{
	char	*e;

	if (*s && !par_isspace(*s))
		return (0);
	while (*s && par_isspace(*s))
		s++;
	e = s;
	while (*e && !par_isspace(*e))
		e++;
	*dst = ft_substr(s, 0, e - s);
	if (!*dst)
		return (0);
	if (*e)
	{
		free(*dst);
		*dst = 0;
		return (0);
	}
	return (1);
}

int	par_getcol(char *s, t_vec3i dst)
{
	int	i;

	i = 0;
	if (*s && !par_isspace(*s))
		return (0);
	while (*s && par_isspace(*s))
		s++;
	while (*s)
	{
		if (i > 2)
			return (0);
		while (par_isspace(*s))
			s++;
		dst[i++] = ft_atoi(s);
		if (dst[i - 1] < 0 || dst[i + 1] > 255)
			return (0);
		while (ft_isdigit(*s))
			s++;
		if (i <= 2 && *s != ',')
			return (0);
		s++;
	}
	return (1);
}

int	par_line_empty(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (!par_isspace(*s))
			return (0);
		s++;
	}
	return (1);
}
