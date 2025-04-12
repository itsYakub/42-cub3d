/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:05:35 by joleksia          #+#    #+#             */
/*   Updated: 2024/12/14 09:56:44 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	ssize;

	if (!set || !s1)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	ssize = ft_strlen(s1);
	while (ssize && ft_strchr(set, s1[ssize - 1]))
		ssize--;
	str = (char *) malloc((ssize + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, ssize + 1);
	return (str);
}
