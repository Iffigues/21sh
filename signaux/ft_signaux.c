/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signaux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 19:45:15 by bordenoy          #+#    #+#             */
/*   Updated: 2019/05/05 13:47:26 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21.h"

static void	sig_handler(int signo)
{
	if (signo == SIGINT)
		;
}

void		grab_sign(void)
{
	int	i;

	i = 0;
	while (i < NSIG)
	{
		if (i != SIGINT && signal(i, sig_handler) == SIG_ERR)
			ft_putstr("");
		i++;
	}
}
