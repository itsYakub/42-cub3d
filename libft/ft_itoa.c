/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:16:39 by joleksia          #+#    #+#             */
/*   Updated: 2024/12/17 08:05:01 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	fts_numlen(int n);
static char	*fts_strproc(char *s, int n);
static char	*fts_strrev(char *s, size_t len);

char	*ft_itoa(int n)
{
	char	*result;

	result = (char *) ft_calloc(fts_numlen(n) + 1, sizeof(char));
	if (!result)
		return (NULL);
	result = fts_strproc(result, n);
	return (result);
}

static int	fts_numlen(int n)
{
	int	result;

	result = 1;
	if (n < 0)
	{
		n *= -1;
		result++;
	}
	while (n)
	{
		n /= 10;
		if (n)
			result++;
	}
	return (result);
}

static char	*fts_strproc(char *s, int n)
{
	char	*scpy;
	int		negative;

	scpy = s;
	negative = 0;
	if (n == 0)
		*s++ = '0';
	else if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_strlcpy(s, "-2147483648", 12);
			return (s);
		}
		negative = 1;
		n *= -1;
	}
	while (n)
	{
		*s++ = n % 10 + '0';
		n /= 10;
	}
	if (negative)
		*s++ = '-';
	return (fts_strrev(scpy, ft_strlen(scpy)));
}

static char	*fts_strrev(char *s, size_t len)
{
	size_t	i;
	char	temp;

	i = -1;
	while (++i < len / 2)
	{
		temp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = temp;
	}
	return (s);
}
