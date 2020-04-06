/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 13:57:39 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/06 20:03:32 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool cross_check(t_list *map, size_t y, size_t x)
{
	char	*line;
	size_t	tmp_x;

	line = (char*)list_at(map, y);
	tmp_x = x;
	if (x == 0 || y == 0)
		return (true);
	while (line[--x] != '1')
		if (x == 0 || line[x] == ' ')
			return (true);
	while (line[++x] != '1')
		if (x == map->size || line[x] == ' ')
			return (true);
	while (line[tmp_x] != '1')
	{
		if (y == 0 || line[tmp_x] == ' ')
			return (true);
		line = (char*)list_at(map, --y);
	}
	line = (char*)list_at(map, ++y);
	while (line[tmp_x] != '1')
	{
		if ( y == map->nb_line || line[tmp_x] == ' ')
			return (true);
		line = (char*)list_at(map, ++y);
	}
	return (false);
}

void flood_fill(t_list *map)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < map->size)
	{
		line = (char*)list_at(map, i);
		PRINTS(line)
		PRINTC(line[j])
		while (line[j] != '\0')
		{
			if (line[j] == '0' || line[j] == 'W' || line[j] == 'E' ||
				line[j] == 'S' || line[j] == 'N')
				if (cross_check(map, j, i) == true)
					catch_error(FLOOD_FILL_1);
			// check forbidden list of char without charset
			j++;
		}
		j = 0;
		i++;
	}
}

bool parse_map_line(t_game_engine *engine, char *line, t_vector2 *map_size)
{
	char *content;

	content = ft_strdup(line);
	if (map_size->x == 0)
		map_size->x = ft_strlen(content);
	if (ft_strlen(content) > map_size->x)
		map_size->x = ft_strlen(content);
	list_push_back(engine->map_content, content);
	map_size->y++;
	return (true);
}

void compute_map(t_game_engine *engine, t_vector2 map_size)
{
	t_list	*new_map;
	char	*line;
	char	*tmp;
	size_t	size;
	size_t	i;

	i = 0;
	new_map = malloc_list(500);
	while (i < engine->map_content->size)
	{
		line = (char*)list_at(engine->map_content, i);
		size = ft_strlen(line);
		tmp = (char*)ft_memalloc(map_size.x);
		ft_strcpy(tmp, line);
		while (size < map_size.x)
			tmp[size++] = ' ';
		list_push_back(new_map, tmp);
		i++;
	}
	free_list(engine->map_content, &free);
	engine->map_content = new_map;
	flood_fill(engine->map_content);
	engine->map = malloc_map(engine, map_size, engine->map_content);
}

void parse_map(t_game_engine *engine, int fd)
{
	t_vector2	map_size;
	bool		found;
	char		*line;

	line = NULL;
	found = false;
	map_size = create_vector2(0, 0);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strlen(line) == 0 && found == false)
			;
		else if (ft_strlen(line) != 0)
		{
			if (parse_map_line(engine, line, &map_size) == true)
				found = true;
			else
				catch_error(PARSE_MAP_1);
		}
		else
			catch_error(PARSE_MAP_2);
		free(line);
	}
	parse_map_line(engine, line, &map_size);
	free(line);
	compute_map(engine, map_size);
}
