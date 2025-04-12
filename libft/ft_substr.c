/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:26:05 by joleksia          #+#    #+#             */
/*   Updated: 2024/12/14 10:09:26 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	bytes;

	if (!s)
		return (NULL);
	if (start >= (size_t) ft_strlen(s))
		start = (size_t) ft_strlen(s);
	s += start;
	bytes = 0;
	if (len >= (size_t) ft_strlen(s))
		bytes = (size_t) ft_strlen(s);
	else
		bytes = len;
	result = (char *) malloc((bytes + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s, bytes + 1);
	return (result);
}
