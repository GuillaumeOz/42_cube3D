/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_octa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 09:03:19 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/17 20:09:21 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_octa(long long int nbr)
{
	char	*base;
	char	*result;

	base = "01234567";
	result = ft_itoa_base(nbr, base);
	return (result);
}
