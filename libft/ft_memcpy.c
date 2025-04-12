/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 09:13:50 by joleksia          #+#    #+#             */
/*   Updated: 2024/12/14 10:11:52 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	unsigned char	*dcpy;
	unsigned char	*scpy;

	dcpy = (unsigned char *) dest;
	scpy = (unsigned char *) src;
	if (!dest && !src)
		return (NULL);
	while (count--)
		*dcpy++ = *scpy++;
	return (dest);
}
