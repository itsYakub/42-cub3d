/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 08:50:36 by joleksia          #+#    #+#             */
/*   Updated: 2024/12/08 11:31:30 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	fts_tokc(const char *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**warr;
	int		tlen;
	int		i;

	warr = (char **) malloc((fts_tokc(s, c) + 1) * sizeof(char *));
	if (!warr)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			if (ft_strchr(s, c))
				tlen = ft_strchr(s, c) - s;
			else if (!ft_strchr(s, c))
				tlen = ft_strlen(s);
			warr[i++] = ft_substr(s, 0, tlen);
			s += tlen;
		}
	}
	warr[i] = NULL;
	return (warr);
}

static int	fts_tokc(const char *s, char c)
{
	int	res;

	if (!s || !*s)
		return (0);
	res = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
			res++;
		while (*s && *s != c)
			s++;
	}
	return (res);
}
