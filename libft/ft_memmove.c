/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 09:15:26 by joleksia          #+#    #+#             */
/*   Updated: 2024/12/14 13:57:36 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	unsigned char	*dcpy;
	unsigned char	*scpy;
	unsigned char	*lasts;
	unsigned char	*lastd;

	dcpy = (unsigned char *) dest;
	scpy = (unsigned char *) src;
	if (!dest && !src)
		return (NULL);
	if (dest < src)
	{
		while (count--)
			*dcpy++ = *scpy++;
	}
	else
	{
		lasts = scpy + (count - 1);
		lastd = dcpy + (count - 1);
		while (count--)
			*lastd-- = *lasts--;
	}
	return (dest);
}
