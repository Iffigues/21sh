/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:27:23 by bordenoy          #+#    #+#             */
/*   Updated: 2019/05/04 20:14:14 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

static void	init_prompt(t_prompt *ar)
{
	ar->i = 0;
	ar->y = 0;
	ar->read = 0;
	ft_memset(ar->p, 0, ESCAPE);
	ar->com = NULL;
	ft_memset(ar->c, 0, 2);
}

void	clean(t_prompt *v, int a)
{
	if (a)
		ft_memset(v->p, 0, ESCAPE);
	ft_memset(v->c, 0, 2);
}

static int 	ft_getchar(t_prompt *ar)
{
	size_t 	i;
	int 	b;

	i = 0;
	b = 0;
	while (i < ar->read)
	{
		if (ar->i == 1)
			b = ft_escape(ar, ar->c[i]);
		if (ar->i == 0  &&  b == 0)
			ft_letter(ar, ar->c[i]);
		i++;
	}
	return (0);
}

void	ft_prompt(void)
{
	t_prompt	ar;

	init_prompt(&ar);
	while ((ar.read = read(0, ar.c, 2)))
	{
		ft_getchar(&ar);
		clean(&ar, 0);
	}
}
