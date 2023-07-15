/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekahram <sekahram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:32:56 by sekahram          #+#    #+#             */
/*   Updated: 2022/12/22 20:14:31 by sekahram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*gg;
	char	*ss;

	i = 0;
	gg = (char *)dst;
	ss = (char *)src;
	if (gg == 0 && ss == 0)
		return (0);
	while (i < n)
	{
		gg[i] = ss[i];
		i++;
	}
	return (gg);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*gg;
	char	*newstring;

	gg = (char *)s;
	i = ft_strlen(gg);
	newstring = (char *)malloc(i + 1);
	ft_memcpy(newstring, gg, i);
	newstring[i] = '\0';
	return (newstring);
}

static void	ft_print(char *gg, int n, int sign, int len)
{
	gg[len] = '\0';
	len--;
	if (sign == 1)
	{
		while (n > 0)
		{
			gg[len] = (n % 10) + 48;
			n = n / 10;
			len--;
		}
	}
	else
	{
		n = n * -1;
		while (len)
		{
			gg[len] = (n % 10) + 48;
			n = n / 10;
			len--;
		}
		gg[len] = '-';
	}
}

static int	ft_ffl(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	len++;
	return (len);
}

char	*ft_itoa(int n)
{
	char	*gg;
	int		sign;

	sign = 1;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		sign = -1;
	gg = (char *)malloc(ft_ffl(n) + 1);
	if (!gg)
		return (NULL);
	ft_print(gg, n, sign, ft_ffl(n));
	return (gg);
}
