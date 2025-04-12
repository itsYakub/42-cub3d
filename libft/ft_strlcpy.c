/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 09:57:09 by joleksia          #+#    #+#             */
/*   Updated: 2024/12/14 10:14:54 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char	*d;
	char	*s;
	size_t	n;

	d = dst;
	s = (char *) src;
	n = size;
	if (n)
	{
		while (--n)
		{
			*d++ = *s;
			if (!*s++)
				break ;
		}
	}
	if (!n)
	{
		if (size != 0)
			*d = 0;
		while (*s++)
			;
	}
	return (s - src - 1);
}
