/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_load_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 21:37:38 by hseong            #+#    #+#             */
/*   Updated: 2022/05/24 09:42:15 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "c3d.h"
#include "libft.h"
#include <stdio.h>

typedef void	*(*t_img_ext)(void *, char *, int *, int *);

static t_img_ext	which_file(char *path);
static int			get_image_attr(void *img_ptr, t_img_elem *attr_arr);

int c3d_load_texture(const char **path, t_mlx_info *mlx_info)
{
	void		*img_ptr;
	t_resource	*resource;
	int			idx;

	ft_putstr_fd("loading texture files\n", 1);
	idx = 0;
	resource = mlx_info->resource;
	while (path[idx] && idx < MAX_TEXTURE)
	{
		img_ptr = (which_file((char *)path[idx]))(mlx_info->mlx_ptr,
			(char *)path[idx], (int *)&(resource->attr_arr + idx)->hor_px,
			(int *)&(resource->attr_arr + idx)->ver_px);
		if (img_ptr == NULL
			|| get_image_attr(img_ptr, resource->attr_arr + idx) == FAIL)
		{
			resource->size *= -1;
			break ;
		}
		resource->texture_arr[idx] = img_ptr;
		++idx;
		++resource->size;
	}
	if (idx == MAX_TEXTURE)
		ft_putstr_fd("reached maximum textures. adjust MAX_TEXTURE\n", 2);
	return (path == NULL);
}

void	c3d_destroy_texture(t_mlx_info *mlx_info)
{
	int		idx;
	t_resource	*resource;

	ft_putstr_fd("texture loading failed\n", 2);
	idx = 0;
	resource = mlx_info->resource;
	while (idx < resource->size)
	{
		mlx_destroy_image(mlx_info->mlx_ptr, resource->texture_arr[idx]);
		++idx;
	}
}

t_img_ext	which_file(char *path)
{
	char	*point;

	point = NULL;
	while (*path)
	{
		if (*path == '.')
			point = path++;
		while (*path && *path != '.')
			++path;
	}
	if (ft_strncmp(point, ".xpm", ft_strlen(point)) == 0)
		return (mlx_xpm_file_to_image);
//	else if (ft_strncmp(point, ".png", ft_strlen(point)) == 0)
//		return (mlx_png_file_to_image);
	return (NULL);
}

int	get_image_attr(void *img_ptr, t_img_elem *attr_ptr)
{
	attr_ptr->img_buf = (t_pixel *)mlx_get_data_addr(img_ptr,
		&attr_ptr->depth_bits, 
		&attr_ptr->line_bytes, &attr_ptr->endian);
	printf("hor_px = %zu\n", attr_ptr->hor_px);
	return (attr_ptr->img_buf == NULL);
}
