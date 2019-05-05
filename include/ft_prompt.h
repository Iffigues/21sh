/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_21.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 12:12:36 by bordenoy          #+#    #+#             */
/*   Updated: 2019/05/05 16:25:50 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROMPT_H
# define FT_PROMPT_H
# include "libft.h"
# include "ft_env.h"

# define ESCAPE		8
# define ENTER		10
# define ESC_KEY	27
# define RIGHT_KEY	4414235
# define LEFT_KEY	4479771
# define UP_KEY		4283163
# define DOWN_KEY	4348699
# define SPACE		32
# define DEL		127
# define DD			2117294875
# define MODE		5921563
# define CTRLD		4

typedef struct	s_ligne
{
	int		type;
	char	c;
	struct	t_list	*prev;
	struct	s_list	*next;
}				t_ligne;

typedef struct	s_prompt
{
	int			i;
	size_t		y;
	size_t		read;
	char		c[2];
	char		p[ESCAPE];
	t_ligne		*com;
}				t_prompt;

typedef struct s_seq
{
	unsigned long d;
	int			(*ptf)(t_prompt *ar, unsigned long c);
}				t_seq;

typedef struct s_action
{
	int			d;
	int			(*ptf)(t_prompt *ar, char c);
}				t_action;


void ft_add(t_prompt *ar, char c);
int	ft_escape(t_prompt *ar, char c);
int ft_letter(t_prompt *ar, char c);
void    ft_prompt(void);
void    clean(t_prompt *v, int a);
void ft_action(t_prompt *ar, char c);
int ft_seqence(t_prompt *ar, unsigned long  c);

#endif
