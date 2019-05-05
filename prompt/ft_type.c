/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 12:11:42 by bordenoy          #+#    #+#             */
/*   Updated: 2019/05/05 17:46:30 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"
#include "stdio.h"

int	is_escape(unsigned long c)
{
	if (c == 23323 || c == 3365659)
		return (1);
	return (0);
}

int is_in(unsigned long m)
{
	if (UP_KEY == m || m == DD || DOWN_KEY == m || LEFT_KEY == m)
		return (1);
	if (RIGHT_KEY == m || HOME == m  || END == m || m == PD)
		return (1);
	if (m == PU)
		return (1);
	return (0);
}

static int	is_in_escape(t_prompt *a, char c)
{	
	unsigned long num;

	ft_add(a, c);
	num = *(unsigned long *)a->p;
	printf("%zu\n",num);
	if (!(is_escape(num)) && is_in(num))
	{
		ft_seqence(a, num);
		a->y = 0;
		a->i = 0;
		clean(a, 1);
	}
	else if (!(is_escape(num)) && !(is_in(num)))
	{
		a->i = 0;
		a->y = 0;
		clean(a, 1);
		return (0);
	}
	return (1);
}

int	ft_escape(t_prompt *ar, char c)
{
	return (is_in_escape(ar, c));
}

void	ft_add(t_prompt *ar, char c)
{
	ar->p[ar->y++] = c;
	ar->p[ar->y] = '\0';
	if (ar->y > ESCAPE)
	{
		ft_memset(ar->p, '\0', ESCAPE);
		ar->y = 0;
	}
}

int ft_letter(t_prompt *ar, char c)
{
	if (c == 27 )
	{
		if (ar->read == 1)
		{
		}
		else
		{	
			ar->i = 1;
			ft_add(ar, c);
		}
	}
	else
		ft_action(ar, c);
	return (0);
}
