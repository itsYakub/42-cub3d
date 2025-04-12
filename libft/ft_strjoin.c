/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:45:33 by joleksia          #+#    #+#             */
/*   Updated: 2024/12/07 15:59:52 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fts_strcpy(char *dst, const char *src);
static char	*fts_strcat(char *dst, const char *src);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		s1len;
	int		s2len;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	result = (char *) ft_calloc(s1len + s2len + 1, sizeof(char));
	if (!result)
		return (NULL);
	fts_strcpy(result, s1);
	fts_strcat(result, s2);
	return (result);
}

static char	*fts_strcpy(char *dst, const char *src)
{
	while (*src)
		*dst++ = *src++;
	*dst = 0;
	return (dst);
}

static char	*fts_strcat(char *dst, const char *src)
{
	char	*dcpy;

	dcpy = dst + ft_strlen(dst);
	return (fts_strcpy(dcpy, src));
}
