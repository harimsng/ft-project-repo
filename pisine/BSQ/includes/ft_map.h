#ifndef FT_MAPDATA_H
# define FT_MAPDATA_H

typedef unsigned char	t_uc;

typedef struct
{
	int					lines;
	int					width;
	char				empty;
	char				obs;
	char				full;
	t_uc				*map;
	int					x;
	int					y;
	int					len;
}	t_map;

#endif
