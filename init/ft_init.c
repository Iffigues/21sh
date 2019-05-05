/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:51:54 by bordenoy          #+#    #+#             */
/*   Updated: 2019/05/02 12:36:21 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>

void	ft_set(int i)
{
	static struct termios old;	
	struct termios new;

	if (i == 0)
	{
		tcgetattr(0, &old);
		new = old;
		new.c_lflag &= ~ECHO;
		new.c_lflag &= ~ICANON;
		tcsetattr(0, 0, &new);
	}
	else
		tcsetattr(0, 0, &old);
}
