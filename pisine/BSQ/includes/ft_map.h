#ifndef FT_MAPDATA_H
# define FT_MAPDATA_H

# define MAX_WIDTH 128

// 1 <= row, col < 1280
typedef struct
{
	unsigned int		lines;
	unsigned int		width;
	char				empty;
	char				obs;
	char				full;
	unsigned long long	(*pos)[MAX_WIDTH >> 6];
}	t_map;

#endif
