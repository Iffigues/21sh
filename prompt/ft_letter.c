/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_letter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 13:45:16 by bordenoy          #+#    #+#             */
/*   Updated: 2019/06/26 23:04:08 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_21.h"

static unsigned long	*remalloc(unsigned long *c, size_t y)
{
	unsigned long *t;
	size_t u;

	u = 0;
	if (!(t = (unsigned long *)malloc(sizeof(unsigned long) * (y + 61))))
		return (NULL);
	while (u < y)
	{
		t[u] = c[u];
		u++;
	}
	t[u] = '\0';
	free(c);
	return (t);
}

static unsigned long *add_begin(unsigned long *a, unsigned long c)
{
	unsigned long *r;
	size_t u;
	size_t y;

	u = 0;
	y = 0;
	r = ft_uldup(a);
	a[y++] = c;
	while (r[u])
		a[y++] = r[u++];
	a[y] = '\0';
	if (y && ((y % 60) == 0))
		a = remalloc(a, y);
	free(r);
	return (a);
}

static  unsigned long * add_alpha(unsigned long *ac, unsigned long c)
{
	size_t y;


	y = 0;
	while (ac[y])
		y++;
	ac[y++] = c;
	ac[y] = '\0';
	if (y && ((y % 60) == 0))
		ac = remalloc(ac, y);
	return (ac);
}

static unsigned long   *add_middle(unsigned long *ac, unsigned long t, size_t c)
{
	unsigned  long *r;
	size_t y;
	size_t u;

	u = 0;
	y = 0;
	while (c--)
		y++;
	r = ft_uldup(&ac[y]);
	ac[y++] = t;
	while (r[u])
		ac[y++] = r[u++];
	ac[y] = '\0';
	free(r);
	if (y && ((y % 60) == 0))
		ac = remalloc(ac, y);
	return (ac);
}

void aff(t_prompt *ac) 
{
	size_t i;
	size_t cc;	

	cc = ac->oui - 1;
	i = ft_ullen(ac->com);
	if (ac->com && i)
		while (++cc < i) 
			ulwrite(ac->com[cc]);
	while (--cc > ac->oui)
		tputs(tgetstr("le", NULL), 1, ft_charz);
	ac->oui++;
}

#include <stdio.h>

void	ft_alpha(t_prompt *ac, unsigned long c)
{
	size_t y;
	
	if (ac->com == NULL)
		ac->com = make_cursor();
	y = ft_ullen(ac->com);
	if (y == ac->oui)
		ac->com = add_alpha(ac->com, c);
	else if (ac->oui == 0)
		ac->com = add_begin(ac->com, c);
	else
		ac->com = add_middle(ac->com, c, ac->oui);
	aff(ac);
}
