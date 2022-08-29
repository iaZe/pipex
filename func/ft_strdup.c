/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantavar <dantavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:48:01 by dantavar          #+#    #+#             */
/*   Updated: 2022/08/03 14:46:05 by dantavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	a;

	a = 0;
	while (a < n)
	{
		((unsigned char *)dest)[a] = ((unsigned char *)src)[a];
		a++;
	}
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*a;

	a = malloc(ft_strlen(s) + 1);
	if (!a)
		return (NULL);
	ft_memcpy(a, s, ft_strlen(s) + 1);
	return (a);
}
