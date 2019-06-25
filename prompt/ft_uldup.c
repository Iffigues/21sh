/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:25:11 by bordenoy          #+#    #+#             */
/*   Updated: 2018/11/17 14:53:31 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21.h"

size_t ft_ullen(unsigned long *e) {
	size_t i;

	i = 0;
	while (e[i])
		i++;
	return(i);
}

void	ulwrite(unsigned long c) {
	wchar_t v = (wchar_t)c;
	write(1,&v,1);
}

unsigned long	*ft_uldup(const  unsigned long *s1)
{
	unsigned long	*str;
	unsigned long	*g;

	if (!(str = ft_memalloc(ft_ullen((unsigned long *)s1) + 1)))
		return (NULL);
	g = str;
	while (*s1)
		ft_memset(str++, *s1++, 1);
	ft_memset(str, 0, 1);
	return (g);
}
