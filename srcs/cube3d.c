/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:25:29 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/06 18:03:04 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void		do_save(t_game_engine *engine)
{
	if (engine->save == true)
	{
		if (save_bmp(engine, engine->map, engine->player) == FAILURE)
			catch_error(DO_SAVE_1);
		ft_putstr("A photo was taken");
		exit(SUCCESS);
	}
}

int main(int argc, char **argv)
{
	t_game_engine	engine;
	t_vector2		resolution;

	size_t i;

	i = 0;

	if (argc < 2 || argc >= 4)
		catch_error(MAIN_1);
	start_application(600, 600, "Cube3D");
	engine = create_game_engine();
	cube3d_parsing(&engine, argc, argv, &resolution);
	resize_application((int)resolution.x, (int)resolution.y);
	do_save(&engine);

	while (i < engine.map_content->size)
	{
		PRINTS((char*)list_at(engine.map_content, i++));
	}
	// printf("(%f,%f)\n", engine.player->pos.x, engine.player->pos.y);

	//	mlx_key_hook(g_app->win_ptr, key_win1, 0);
//	g_app->mlx_ptr;
//	g_app->image;
//	g_app->win_ptr;
//	engine.texture[0];

//	mlx_put_image_to_window(g_app->mlx_ptr, g_app->win_ptr, engine.texture[0],0,0);
//	mlx_loop(g_app->mlx_ptr);
	add_interaction_to_application(&cube3d_key_manager, KEYPRESS, KEYPRESSMASK, &engine);

	// add_interaction_to_application(&, KEYRELEASE, &engine);
	render_funct_application(&draw_map, &engine);

	return (run_application());
}
