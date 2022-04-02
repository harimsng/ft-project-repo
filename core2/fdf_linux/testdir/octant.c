
/*
 *function to find octant more accurately. not working now.
 *static const int		g_index_table[8] = {
 *	0, 2, 3, 1,
 *	3, 1, 0, 2
 *};
 *
 *int	get_octant(t_map_info *map_info)
 *{
 *	static char	buf[100];
 *	int			idx;
 *	int			minidx;
 *	double		minval;
 *	double		edges[4];
 *
 *	edges[0] = map_info->map_proj[0][0].y;
 *	edges[1] = map_info->map_proj[0][map_info->col - 1].y;
 *	edges[2] = map_info->map_proj[map_info->row - 1][map_info->col - 1].y;
 *	edges[3] = map_info->map_proj[map_info->row - 1][0].y;
 *	minval = 2147483647;
 *	if (edges[1] < minval)
 *	{
 *		minidx = 1;
 *		minval = edges[1];
 *	}
 *	if (edges[2] < minval)
 *	{
 *		minidx = 2;
 *		minval = edges[2];
 *	}
 *	if (edges[3] < minval)
 *	{
 *		minidx = 3;
 *		minval = edges[3];
 *	}
 *	if (edges[0] < minval)
 *	{
 *		minidx = 4;
 *		minval = edges[0];
 *	}
 *	idx = g_index_table[minidx - 1 + 4 * (tan(map_info->ver_angle) < 0)];
 *	if (edges[minidx - 1] < edges[(minidx + 1) % 4])
 *		idx += 4;
 *			snprintf(buf, 99, "oct: %d  y0x0:%6.2lf  y0x1:%6.2lf  y1x1:%6.2lf  y1x0:%6.2lf",
 *			idx, edges[0], edges[1], edges[2], edges[3]);
 *	map_info->carry = buf;
 *	return (idx);
 *}
 */
