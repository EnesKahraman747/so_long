/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekahram <sekahram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 19:03:20 by sekahram          #+#    #+#             */
/*   Updated: 2022/12/22 20:14:38 by sekahram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_payplen(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	ft_print(char *s, char c, int npp, char **gg)
{
	int	step;
	int	len;
	int	j;
	int	k;

	k = 0;
	step = 0;
	while (step < npp)
	{
		j = 0;
		while (s[k] == c)
			k++;
		len = ft_payplen(&s[k], c);
		gg[step] = (char *)malloc(len + 1);
		while (len--)
		{
			gg[step][j] = s[k];
			k++;
			j++;
		}
		gg[step][j] = '\0';
		step++;
	}
	gg[step] = 0;
}

static int	ft_payp(char *s, char c)
{
	int		i;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
			i++;
		while (*s != c && *s)
			s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	npp;
	char	**gg;

	if (!s)
		return (NULL);
	npp = ft_payp((char *)s, c);
	gg = (char **)malloc(sizeof(char *) * (npp + 1));
	if (!gg)
		return (NULL);
	ft_print((char *)s, c, npp, gg);
	return (gg);
}
