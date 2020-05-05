/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_destructors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 14:47:26 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/05 18:41:56 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_texture(t_texture p_wall)
{
	free(p_wall.path);
}

void	free_texture(t_texture *p_wall)
{
	destroy_texture(*p_wall);
	free(p_wall);
}
