#ifndef FT_H
# define FT_H

// read()
# include <sys/types.h>
# include <sys/stat.h>

// open()
# include <fcntl.h>

// read(), close(), write()
# include <unistd.h>

// errno
# include <sys/errno.h>

// basename()
# include <libgen.h>

// strerror()
# include <string.h>

void	ft_putstr(char *str);
void	ft_puterr(char *str);

#endif
