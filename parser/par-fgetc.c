/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par-fgetc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 08:32:34 by joleksia          #+#    #+#             */
/*   Updated: 2025/03/27 10:00:39 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	par_fgetc(int fd)
{
	char	c;

	if (fd < 0)
		return (!printf("error: invalid file descriptor\n"));
	if (read(fd, &c, 1) < 0)
		return (!printf("error: invalid read\n"));
	return (c);
}

char	*par_sgetline(const char *s)
{
	char	*start;
	char	*end;

	start = (char *) s;
	end = ft_strchr(s, '\n');
	return (ft_substr(start, 0, end - start));
}
