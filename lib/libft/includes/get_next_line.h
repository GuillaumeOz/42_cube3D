/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:52:08 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/19 15:46:18 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define VCT_DEFSIZE	128
# define VCT_DEFQUART	32

typedef struct s_gnl_vector
{
	char				*str;
	size_t				len;
	size_t				size;
	size_t				quart;
}						t_gnl_vector;

typedef struct s_gnl
{
	t_gnl_vector		*vct;
	int					fd;
	struct s_gnl		*next;
	struct s_gnl		*prev;
}						t_gnl;

bool			malloc_root_gnl(t_gnl **rootp);
bool			malloc_next_gnl(t_gnl *head);
int				create_gnl_content(t_gnl *head, char **line, int fd, int *i);
t_gnl_vector	*gnl_vct_new(size_t size);
bool			gnl_vct_appnstr(t_gnl_vector *vct, char *addens,
					size_t n);
bool			gnl_vct_cutnfrom(t_gnl_vector *vct, size_t idx,
					size_t n);
int				gnl_strnchr_idx(char *s, char c, size_t n, int mode);
int				get_next_line(int fd, char **line);

#endif
