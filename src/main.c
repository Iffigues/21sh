/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 14:29:49 by bordenoy          #+#    #+#             */
/*   Updated: 2019/05/04 20:13:17 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21.h"

void init_env(t_env *c, char **env)
{
	size_t  a;
	size_t  cc;

	c->b = NULL;
	a = 0;
	cc = 0;
	c->i = &a;
	c->c = &cc;
	c->b = make_env(env, c, 0);
}

int main(int ac, char **av, char **env)
{
	t_env	c;

	if (ac && av)
		;
	grab_sign();
	init_env(&c, env);
	ft_set(0);
	ft_prompt();
	return (0);
}
