/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantavar <dantavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 23:27:20 by dantavar          #+#    #+#             */
/*   Updated: 2022/08/03 14:49:50 by dantavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strjoin(char *main_str, char *buff)
{
	size_t	i;
	size_t	a;
	char	*str;

	if (!main_str)
	{
		main_str = malloc(1 * sizeof(char));
		main_str[0] = '\0';
	}
	if (!main_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(main_str) + ft_strlen(buff) + 1));
	if (!str)
		return (NULL);
	i = -1;
	a = 0;
	if (main_str)
		while (main_str[++i] != '\0')
			str[i] = main_str[i];
	while (buff[a] != '\0')
		str[i++] = buff[a++];
	str[ft_strlen(main_str) + ft_strlen(buff)] = '\0';
	free(main_str);
	return (str);
}
