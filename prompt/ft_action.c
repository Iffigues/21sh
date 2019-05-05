/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 12:49:04 by bordenoy          #+#    #+#             */
/*   Updated: 2019/05/05 17:03:07 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21.h"

static int ft_d(t_prompt *ar, char c)
{
	if (ar->i && c)
		;
	return (1);
}

static int ft_starter(t_prompt *ar, char c)
{
	int  i;
	t_action b[1] = {
		{4, ft_d}
	};

	if (ar->i)
		;
	i = 0;
	while (i < 1)
		if (b[i++].d == c)
			return (b[i - 1].ptf(ar, c));
	return (0);
}

static int up(t_prompt *ar, unsigned long c)
{
	if (ar->i && c)
		;
	ft_putstr("iiiiiiiiiiiii\n");
	return (1);
}

int	ft_seqence(t_prompt *ar, unsigned long  c)
{
	int i;

	t_seq b[5] = {
		{UP_KEY, up},
		{DOWN_KEY, up},
		{LEFT_KEY, up},
		{RIGHT_KEY, up},
		{DD, up}
	};
	i = 0;
	while (i < 5)
		if (b[i++].d == c)
			return (b[i - 1].ptf(ar, c));
	return (0);
}

void ft_action(t_prompt *ar, char c)
{
	if (ft_starter(ar, c))
		;
	else
		ft_putstr("hahaha\n");
}
