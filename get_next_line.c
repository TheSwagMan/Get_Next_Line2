/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:34:43 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/07 20:11:13 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Returns the size of a given str until occurence of char c
** If the char if not found, the function acts like strlen
*/

size_t	strlen_bfrchr(char *s, char c)
{
	int	n;

	n = 0;
	if (!s)
		return (0);
	while (s[n] && s[n] != c)
		n++;
	return (n);
}

/*
** Reallocates and cat a new str to a given str (only n chars + '\0')
** Given str can be NULL and the return value will just be a copy of the str
** to cat.
** return 1 on success
*/

int		strncat_mal(char **s1, char *s2, size_t n)
{
	char	*new;
	size_t	k;
	size_t	i;

	if (n == 0 || !s1)
		return (0);
	i = 0;
	if (*s1)
		i = ft_strlen(*s1);
	if (!(new = (char *)malloc((i + n + 1) * sizeof(char))))
		return (0);
	ft_putnbr(i);
	ft_putnbr(n);
	k = 0;
	while (*s1 && k < i)
	{
		new[k] = *(s1)[k];
		k++;
	}
	ft_putchar('K');
	new[k + n] = '\0';
	while (s2 && n--)
		new[k + n] = s2[n];
	free(*s1);
	*s1 = new;
	return (1);
}

/*
** Return the a pointer on the fd corresponding to fd, and create one if none is
** found.
*/

t_fb	*get_corresponding_fd(t_list **l, int fd)
{
	t_list	*li;
	t_list	*new;

	if (!l)
		return (NULL);
	li = *l;
	while (li)
	{
		if (((t_fb *)(li->content))->fd == fd)
			return (li->content);
		li = li->next;
	}
	if (!(new = (t_list *)malloc(sizeof(*new))))
		return (NULL);
	new->next = NULL;
	if (!(new->content = (t_fb *)malloc(sizeof(t_fb))))
		return (NULL);
	((t_fb *)(new->content))->fd = fd;
	((t_fb *)(new->content))->buff = NULL;
	li = *l;
	if (!*l)
		return ((*l = new)->content);
	while (li && li->next)
		li = li->next;
	return ((li->next = new)->content);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*list;
	char			buff[BUFF_SIZE + 1];
	int				n;
	int				k;
	t_fb			*t;

	if (!line)
		return (-1);
	t = get_corresponding_fd(&list, fd);
	while ((n = read(fd, buff, BUFF_SIZE)))
	{
		buff[n] = '\0';
		k = strlen_bfrchr(buff, '\n');
		strncat_mal(line, buff, k);
		return (1);
	}
	return (0);
}
