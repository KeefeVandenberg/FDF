/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvandenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 13:57:20 by kvandenb          #+#    #+#             */
/*   Updated: 2017/10/05 18:05:30 by kvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*fresh;
	int				start;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	while ((s[i] == ' ') || (s[i] == '\t') || (s[i] == '\n'))
		i++;
	start = i;
	if (s[start] == '\0')
	{
		fresh = (char *)malloc(1);
		*fresh = '\0';
		return (fresh);
	}
	while (s[i + 1])
		i++;
	while ((s[i] == ' ') || (s[i] == '\t') || (s[i] == '\n'))
		i--;
	if (!(fresh = (ft_strsub(s, start, i - start + 1))))
		return (NULL);
	return (fresh);
}
