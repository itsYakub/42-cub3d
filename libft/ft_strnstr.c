/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:40:52 by joleksia          #+#    #+#             */
/*   Updated: 2024/12/14 10:08:38 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	llen;
	size_t	i;

	llen = ft_strlen(little);
	if (!little || !llen)
		return ((char *) big);
	i = 0;
	while (len && *big && i++ <= (len - llen))
	{
		if (*big == *little)
		{
			if (ft_strncmp(big, little, llen) == 0)
				return ((char *) big);
		}
		big++;
	}
	return (NULL);
}
