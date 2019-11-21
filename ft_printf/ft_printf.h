#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# define X_MAJ_BASE "0123456789ABCDEF"
# define X_MIN_BASE "0123456789abcdef"


typedef struct informations
{
	char	*str;//to give
	char	cv;//converter on en a besoin
	int		p;
	int		spaces;
}infos;

int			ft_printf(const char *format, ...);
void		ft_init_infos(infos *inf);
int			ft_process(va_list *ap, char *str, infos *inf);
void		ft_convert(va_list *ap, char c, infos *inf);
void		ft_flag_applier(infos *inf);
void		ft_point_flag(infos *inf);
void		ft_space_flags(infos *inf);
int			ft_isinstr(char c, char *str);

int			ft_isconvert(int c);
int			ft_atoi_p(const char *str);
char		*ft_strdup_char(char c);
char		*ft_strjoin_char(char const *s1, char c);
int			int_size_base(long long n, int base_size);
char		*ft_utoa_base(unsigned int n, char *base);


#endif
