/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:57:17 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/07 20:08:25 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

int	main(void)
{
	char	*s;

	s = NULL;
	ft_putnbr(strncat_mal(&s, "HELLO WORLD", 6));
	ft_putchar('\n');
	ft_putstr(s);
	ft_putnbr(strncat_mal(&s, "WIRLD", 5));
	ft_putchar('\n');
	ft_putstr(s);
	free(s);
	s = NULL;
	ft_putnbr(get_next_line(0, &s));
	ft_putchar('\n');
	ft_putendl(s);
	return (0);
}
