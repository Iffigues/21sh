/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oseq.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:45:23 by bordenoy          #+#    #+#             */
/*   Updated: 2019/06/26 23:05:53 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_21.h"

int ft_dd(t_prompt *ar, unsigned long c)
{
	int i;
	int cc;

	if (ar->i && c)
		;
	if (ar->oui > 0) {
		i = ar->oui - 1;
		cc = i + 1;
		while (ar->com[i])
			ar->com[i++] = ar->com[cc++];
		ar->oui--;
		aff(ar);
		ar->oui++;
	}
	return (1);
}

int ft_home(t_prompt *ar, unsigned long c)
{
	if (ar->i && c)
		;
	return (1);
}

int ft_end(t_prompt *ar, unsigned long c)
{
	if (ar->i && c)
		;
	return (1);
}

int ft_pu(t_prompt *ar, unsigned long c)
{
	if (ar->i && c)
		;
	return (1);
}

int ft_pd(t_prompt *ar, unsigned long c)
{
	if (ar->i && c)
		;
	return (1);
}
