/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:00:36 by joleksia          #+#    #+#             */
/*   Updated: 2024/12/14 14:05:03 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*d;
	char	*s;
	size_t	dlen;
	size_t	n;

	d = dst;
	s = (char *) src;
	n = size;
	while ((d && *d) && n--)
		d++;
	dlen = d - dst;
	n = size - dlen;
	if (!n)
		return (dlen + ft_strlen(s));
	while (s && *s)
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = 0;
	return (dlen + (s - src));
}
