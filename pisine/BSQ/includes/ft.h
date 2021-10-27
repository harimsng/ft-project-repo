#ifndef FT_H
# define FT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# include "../includes/ft_map.h"

t_map		*ft_map(char *filename);

int			ft_strlen(char *str);
int			ft_putstr(char *str);
int			ft_strcheck(char *str, unsigned int size);
int			ft_free(void *ptr);
void		ft_putnbr(int nb);

#endif
