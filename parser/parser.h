/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 07:22:12 by joleksia          #+#    #+#             */
/*   Updated: 2025/04/12 07:23:24 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/*	SECTION:
 *		Macro definitions
 * */

# ifndef PAR_F_EXT
#  define PAR_F_EXT ".cub"
# endif

/*	SECTION:
 *		Include headers
 * */

# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "../libft/libft.h"

/*	SECTION:
 *		Type definitions
 * */

typedef float			t_vec2[2];
typedef int				t_vec2i[2];
typedef float			t_vec3[3];
typedef int				t_vec3i[3];
typedef float			t_vec4[4];
typedef int				t_vec4i[4];

typedef enum e_parse_mode
{
	PARSE_MODE_MISC = 0,
	PARSE_MODE_CELL,
	PARSE_MODE_FIN
}	t_parse_mode;

typedef enum e_face_dir
{
	DIR_NORTH = 'N',
	DIR_SOUTH = 'S',
	DIR_WEST = 'W',
	DIR_EAST = 'E'
}	t_face_dir;

typedef struct s_dat
{
	t_parse_mode	parse_mode;
	/* misc. part */
	int				misc_fill[6];
	char			*wall_no_file;
	char			*wall_so_file;
	char			*wall_we_file;
	char			*wall_ea_file;
	t_vec3i			color_floor;
	t_vec3i			color_ceiling;
	/* cell part */
	char			**cell_data;
	unsigned int	height;
}	t_dat;

typedef struct s_map
{
	char		**cell;
	t_face_dir	dir;
	t_vec2i		map_spawn;
	t_vec2i		map_size;
	t_vec4i		map_col_f;
	t_vec4i		map_col_c;
	char		*map_txt_no;
	char		*map_txt_so;
	char		*map_txt_we;
	char		*map_txt_ea;
}	t_map;

/*	SECTION:
 *		Function declarations
 * */

/* ./par-dat0.c ./par-dat1.c */
int		par_dat_init(t_dat *dat, const char *filepath);
int		par_dat_unload(t_dat *dat);
int		par_dat_ext(const char *filepath);
int		par_dat_inv_char(t_dat *dat);
int		par_dat_spawn_present(t_dat *dat);
int		par_get_neigh(char **t, t_vec2i i, int h, char l[5]);
int		par_strdiff(char *a, char *b);

/* ./par-fgetc.c */
char	par_fgetc(int fd);
char	*par_sgetline(const char *s);

/* ./par-extract-data0.c ./par-extract-data1.c ./par-extract-data2.c */
int		par_extract(t_dat *dat, const char *s);
int		par_process_line(t_dat *dat, char *line);
int		par_getpath(char *s, char **dst);
int		par_getcol(char *s, t_vec3i dst);
int		par_line_empty(char *s);
int		par_parse_misc(t_dat *dat, char *s);
int		par_parse_cell(t_dat *dat, char *s);
void	par_check_current_fill(t_dat *dat, char *s);
int		par_misc_filled(t_dat *dat);

/* ./par-map0.c */
t_map	*par_map_init(const char *file);
int		par_map_unload(t_map *map);

/* ./par-dat-bounds0.c */
int		par_empty_char(t_dat *dat);

/* ./par-utils0.c */
void	*par_realloc(void *ptr, size_t size);
char	*par_readfile(int fd);
int		par_isspace(int c);
int		par_max(int a, int b);
char	**par_mapdup(char **src, size_t cnt);

#endif /* PARSER_H */
