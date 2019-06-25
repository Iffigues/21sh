/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:41:26 by bordenoy          #+#    #+#             */
/*   Updated: 2019/05/08 20:31:57 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_21.h"

int ft_up(t_prompt *ar, unsigned long c)
{
	if (ar->i && c)
		;
	return (1);
}

int ft_down(t_prompt *ar, unsigned long c)
{
	if (ar->i && c)
		;
	return (1);
}

void mv(int c)
{
	int i;
	i = 0;
	while(i++ < c)
		tputs(tgetstr("nd", NULL), 1, ft_charz);
}

void mv_cursor(t_prompt *ar)
{
	size_t i;
	int c;	

	c = 0;
	i = ar->oui - 1;
	while (i && ar->com[i--] != '\n')
		c++;
	if (c)
		mv(c % ar->w.ws_col);
}

int ft_left(t_prompt *ar, unsigned long c)
{
	if (ar->i && c)
		;
	get_size(ar);
	if (ar->oui)
                ar->oui--;
	if (ar->oui && ar->com[ar->oui] == 10)
	{
		tputs(tgetstr("up", NULL), 1, ft_charz);
		mv_cursor(ar);
	}
	else
		tputs(tgetstr("le", NULL), 1, ft_charz);
	return (1);
}

int ft_right(t_prompt *ar, unsigned long c)
{
	size_t r;
	int t;

	get_size(ar);
	if (c) 
	;
	if (ar->com)
		r = ft_ullen(ar->com);
	else
		r = 0;
	if (ar->oui < r)
	{
		ar->oui++;
		t = ar->oui % ar->w.ws_col;
		ulwrite(ar->com[ar->oui - 1]);
	}
	return (1);
}
