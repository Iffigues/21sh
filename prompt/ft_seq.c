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

int ft_left(t_prompt *ar, unsigned long c)
{
	if (ar->i && c)
		;
	get_size(ar);
	if (ar->oui)
                ar->oui--;
	if (ar->oui && ar->com[ar->oui] == 10)
		tputs(tgetstr("up", NULL), 1, ft_charz);
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
		r = ft_strlen(ar->com);
	else
		r = 0;
	if (ar->oui < r)
	{
		ar->oui++;
		t = ar->oui % ar->w.ws_col;
		if ((ar->oui && t == 0) || ar->com[ar->oui -1]  == 10)
			ft_charz(10);
		else
			tputs(tgetstr("nd", NULL), 1, ft_charz);
	}
	return (1);
}
