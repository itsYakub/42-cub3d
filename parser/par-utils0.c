/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par-utils0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:46:32 by joleksia          #+#    #+#             */
/*   Updated: 2025/03/30 08:15:58 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	*par_realloc(void *ptr, size_t size)
{
	void	*newptr;

	if (!ptr)
		return (malloc(size));
	newptr = malloc(size);
	if (!newptr)
		return (0);
	newptr = ft_memcpy(newptr, ptr, size);
	free(ptr);
	return (newptr);
}

char	*par_readfile(int fd)
{
	char	*fc;
	char	*tmp;
	char	c[2];
	size_t	len;

	tmp = 0;
	fc = ft_strdup("");
	ft_memset(c, 0, 2);
	c[1] = 0;
	len = 0;
	while (read(fd, c, 1))
	{
		tmp = ft_strjoin(fc, c);
		free(fc);
		fc = ft_strdup(tmp);
		free(tmp);
		len++;
	}
	if (!len)
	{
		free(fc);
		return (0);
	}
	fc[len] = 0;
	return (fc);
}

int	par_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	par_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

char	**par_mapdup(char **src, size_t cnt)
{
	char	**dst;

	dst = (char **) malloc(cnt * sizeof(char *));
	if (!dst)
		return (0);
	while (cnt--)
		dst[cnt] = ft_strdup(src[cnt]);
	return (dst);
}
