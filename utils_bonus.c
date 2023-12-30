/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:29:26 by malanglo          #+#    #+#             */
/*   Updated: 2023/12/30 12:29:44 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

int	ft_atoi(const char *nptr)
{
	int	res;
	int	i;

	i = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res);
}
