/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:43:52 by joleksia          #+#    #+#             */
/*   Updated: 2024/12/14 10:14:41 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*scpy;
	int		slen;
	int		i;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	scpy = (char *) ft_calloc(slen + 1, sizeof(char));
	if (!scpy)
		return (NULL);
	i = -1;
	while (++i < slen)
		scpy[i] = f(i, s[i]);
	scpy[i] = 0;
	return (scpy);
}
