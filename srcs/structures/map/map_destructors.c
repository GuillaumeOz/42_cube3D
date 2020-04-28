/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_destructors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 15:13:12 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/28 19:37:07 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void   destroy_map(t_map to_destroy)
{
	int	i;

	i = -1;
	while (++i < to_destroy.size.y)
			free(to_destroy.board[i]);
	free(to_destroy.board);
	free_vector2(&to_destroy.size);//double free here when you change the map || Up check if its ok
}

void   free_map(t_map *to_free)
{
	destroy_map(*to_free);
	free(to_free);
}
