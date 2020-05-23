#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>

# include <stdio.h> // A SUPPRIMER

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 32

int		ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset (void *s, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char const *s, int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strnstr(const char	*source, const char *objet, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_tolower(int c);
int		ft_toupper(int c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dest, const char *src, size_t destsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
void	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);

int		ft_gnl_strlen(char *str);
char	*ft_gnl_strnew(int *error);
int		ft_gnl_strchr(char *str);
int		ft_gnl_strcount(char *str);
void	ft_gnl_strjoin(char **str, const char *buff, int buff_size, int *error);

int		ft_gnl_exerror(char **str, int error);
void	ft_gnl_strdel(char **as);
char	*ft_gnl_strsub(char const *s, unsigned int start, size_t len, int **error);
void	ft_gnl_read(char **str, char **line, int ret, int *error);
int		get_next_line(int fd, char **line);


typedef	struct	s_point
{
	va_list ap;
	int ret; // valeur retournée
	int i; // valeur du curseur de lecture dans format à %
	int u; // valeur du curseur de lecture dans format de % à type
	int wdh; // un entier décimal ou "*" avec sa valeur dans un argument après
	int pco; // un entier décimal ou "*" avec sa valeur dans un argument après
	int siz; // la taille de str qui sera print après calculs
	char *str; // récupe un arg,
	char *fmt; // *format de base
	char c; // gère et stocke le %c
	char typ; // contient le type
	char fag; // flags : "-" ou "0"  peut etre mettre un int avec des valeurs corres

	char d[64]; // gestions des nombres (itoa)
	int t; // int nombre que je récupère dans va_arg pr les %d
	unsigned long long ull; // ull nombre que je récup ds va_arg pr les %p
	int b; // base utilisé dans les convertions
	int maj; // pour les bases, si on commence à 'A' ou 'a'
	int g; // g prend en compte le signe dans %d pour la sizeof de typ + sig
	unsigned int ui; // ui nombre que je récup ds va_arg pr les %u
}					t_point;


int ft_printf(const char *format, ...);
void ft_init_ptf(t_point	*ptf, char *format);
void	ft_putchar_printf(char c, t_point *ptf);
void	ft_putstr_printf(char *str, t_point *ptf);
void	ft_know_flags(t_point *ptf);
void	ft_know_width(t_point *ptf);
void	ft_know_precision(t_point *ptf);
void	ft_ana_types(t_point *ptf);
int	ft_make_type(char type, t_point *ptf);
int	ft_find_type(t_point *ptf);
void	ft_ana_flags(t_point *ptf);
void	ft_printf_s(t_point *ptf);
void	ft_clear_ptf(t_point *ptf);
int	ft_printf_strlen(char *str);
void	ft_printf_percent(t_point *ptf);
void	ft_printf_c(t_point *ptf);
void	ft_printf_d(t_point *ptf);
void	ft_printf_itoa(t_point *ptf);
void	ft_printf_d_disp(t_point *ptf);
void	ft_printf_itoa_init(t_point *ptf);
void	ft_printf_d_incre(int x, t_point *ptf);
void	ft_printf_d_suite(t_point *ptf);
int	ft_printf_d_disp_suite(int *m, int *a, int *u, t_point *ptf);
void	ft_printf_p(t_point *ptf);
void	ft_printf_p_suite(t_point *ptf);
void	ft_printf_p_incre(int x, t_point *ptf);
void	ft_printf_itoa_ull(t_point *ptf);
void	ft_printf_p_disp(t_point *ptf);
void	ft_printf_p_disp_suite(int *m, int *a, int *u, t_point *ptf);
void	ft_printf_u(t_point *ptf);
void	ft_printf_u_suite(t_point *ptf);
void	ft_printf_itoa_u(t_point *ptf);
int		ft_printf_u_disp_suite(int *m, int *a, int *u, t_point *ptf);
void	ft_printf_u_disp(t_point *ptf);
void	ft_printf_x(t_point *ptf);
void	ft_printf_x_suite(t_point *ptf);
void	ft_printf_itoa_x(t_point *ptf);
void	ft_printf_x_disp(t_point *ptf);
void	ft_printf_x_disp_suite(int *m, int *a, int *u, t_point *ptf);
int		ft_false_type(t_point *ptf);
void	ft_printf_itoa_ll(t_point *ptf);


#endif
