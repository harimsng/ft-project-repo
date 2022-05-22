/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_load_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 21:37:38 by hseong            #+#    #+#             */
/*   Updated: 2022/05/22 23:11:53 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "c3d.h"
#include "libft.h"
#include <stdio.h>

typedef void	*(*t_mlx_image_func)();

static t_mlx_image_func	which_image(char *path);
static void				remove_texture(t_mlx_info *mlx_info);

int c3d_load_texture(const char **path, t_mlx_info *mlx_info)
{
	void		*img_ptr;
	t_resource	*resource;
	int			width;
	int			height;
	int			idx;

	(void)which_image;
	idx = 0;
	resource = mlx_info->resource;
	while (path[idx] && idx < MAX_TEXTURE)
	{
		img_ptr = /*((which_image((char *)path[idx]))*/mlx_xpm_file_to_image(mlx_info, (char *)path[idx],
			&width, &height);
		if (img_ptr == NULL)
		{
			remove_texture(mlx_info);
			break ;
		}
		printf("%p %d\n", img_ptr, idx);
		resource->texture_arr[idx] = img_ptr;
		resource->texture_info[idx] = (t_ivec2){width, height};
		++idx;
		++resource->size;
	}
	if (idx == MAX_TEXTURE)
		ft_putstr_fd("reached maximum textures. adjust MAX_TEXTURE\n", 2);
	return (path != NULL);
}

void	remove_texture(t_mlx_info *mlx_info)
{
	int		idx;
	t_resource	*resource;

	idx = 0;
	resource = mlx_info->resource;
	while (idx < resource->size - 1)
	{
		mlx_destroy_image(mlx_info->mlx_ptr, resource->texture_arr[idx]);
		++idx;
	}
}

t_mlx_image_func	which_image(char *path)
{
	if (ft_strnstr(path, ".png", 4) == 0)
		return (mlx_png_file_to_image);
	else if (ft_strnstr(path, ".xpm", 4) == 0)
		return (mlx_xpm_file_to_image);
	return (NULL);
}

