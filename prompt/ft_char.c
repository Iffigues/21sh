/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:49:16 by bordenoy          #+#    #+#             */
/*   Updated: 2019/06/26 22:59:09 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_21.h"

int ft_ctrld(t_prompt *ar, unsigned long c)
{
	if ((ar->com  == NULL || ft_ullen(ar->com) == 0) &&  c)
		exit(0);
	return (1);
}

int ft_enter(t_prompt *ar, unsigned long c)
{
	unsigned long *cpy;

	if (ar->i && c)
		;
	if (ar->read == 1)
	{
		if(ar->com) 
		{	
			cpy = ft_uldup(ar->com);
			reset();
			free(cpy);
		}
		ft_putchar('\n');
	}
	if (ar->read == 2)
		ft_alpha(ar, 10);
	return (1);
}

int ft_del(t_prompt *ar, unsigned long c)
{
	if (ar->i && c)
		;
	return (1);
}
int ft_tab(t_prompt *ar, unsigned long c)
{
	if (ar->i && c)
		;
	return (1);
}
