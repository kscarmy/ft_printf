/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 08:49:11 by guderram          #+#    #+#             */
/*   Updated: 2019/11/08 09:32:50 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

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


#endif
