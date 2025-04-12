/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:09:02 by joleksia          #+#    #+#             */
/*   Updated: 2024/12/14 10:16:50 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*arr1;
	unsigned char	*arr2;

	arr1 = (unsigned char *) s1;
	arr2 = (unsigned char *) s2;
	while (n-- != 0)
	{
		if (*arr1 != *arr2)
			return (*arr1 - *arr2);
		arr1++;
		arr2++;
	}
	return (0);
}
