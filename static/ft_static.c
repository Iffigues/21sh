/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_static.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 22:27:57 by bordenoy          #+#    #+#             */
/*   Updated: 2019/05/09 15:54:18 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21.h"

t_data	*stati(t_data *h, int i)
{
	static t_data *bb = NULL;

	if (i == 0)
		bb = h;
	return (bb);
}

