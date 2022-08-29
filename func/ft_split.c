/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantavar <dantavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 01:48:12 by dantavar          #+#    #+#             */
/*   Updated: 2022/08/03 14:46:00 by dantavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_bzero(void *s, size_t n)
{
	char	*a;

	a = s;
	while (n)
	{	
		*a = '\0';
		a++;
		n--;
	}
}

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	if (n != 0)
	{
		while (src[a] != '\0' && a < (n - 1))
		{
			dst[a] = src[a];
			a++;
		}
		dst[a] = '\0';
	}
	while (src[b] != '\0')
		b++;
	return (b);
}

void	*ft_calloc(size_t n, size_t s)
{
	void	*a;

	a = malloc(n * s);
	if (a)
		ft_bzero (a, n * s);
	return (a);
}

static unsigned int	ft_strarray(const char *s, char limiter)
{
	unsigned int	n;

	n = 0;
	while (*s)
	{
		if (*s == limiter)
			s++;
		else
		{
			while (*s != limiter && *s)
				s++;
			n++;
		}
	}
	return (n);
}

char	**ft_split(char const *s, char c)
{
	char			**array;
	unsigned int	a;
	unsigned int	b;

	if (!s)
		return (NULL);
	array = (char **) ft_calloc(ft_strarray(s, c) + 1, sizeof(char *));
	if (!array)
		return (NULL);
	b = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			a = 0;
			while (*s != c && *s && ++a)
				s++;
			array[++b -1] = (char *) ft_calloc(a + 1, sizeof(char));
			ft_strlcpy(array[b -1], s - a, a + 1);
		}
	}
	return (array);
}
