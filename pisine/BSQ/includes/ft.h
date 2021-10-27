#ifndef FT_H
# define FT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# include "../includes/ft_map.h"

t_map		*ft_map(char *filename);
void		ft_solve(t_map *data, int pos);

int			ft_strlen(char *str);
int			ft_strcheck(t_uc *str, int size);
int			ft_free(void *ptr);
void		ft_putnbr(int nb);
void		ft_putchar(char c);
void		ft_putstr(char *str);
int			ft_puterr(char *str);
void		ft_strccpy(t_uc *dest, t_uc *src, int width);

#endif
