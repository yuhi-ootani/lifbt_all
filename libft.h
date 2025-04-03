/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:08:26 by oyuhi             #+#    #+#             */
/*   Updated: 2025/04/03 15:22:49 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
// printf
# include <stdarg.h>
# include <stdbool.h>

typedef struct s_fprintf_buffer
{
	char			*buffer;
	int				index;
	int				buf_size;
}					t_fprintf_buffer;

//*** libft ***//
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
size_t				ft_strlen(const char *s);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
int					ft_atoi(const char *nptr);

void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *s);

char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, const char *delimiters);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
/*added by kiki*/
int					ft_strcmp(const char *s1, const char *s2);
int					ft_isspace(int c);
int					ft_isnumber(char *str);
void				ft_putendl(char *s);
char				*ft_strndup(const char *s, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
size_t				ft_array_count_str(char **array);
void				*ft_realloc(void *ptr, size_t old_size, size_t new_size);
int					ft_fprintf(int fd, const char *format, ...);
/*minishell yuhi*/
char				*ft_strjoin_three(const char *str1, const char *str2,
						const char *str3);
char				**ft_array_join(char **array1, char **array2);

//*** libft_bonus ***//
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

//*** ft_get_next_line ***//
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char				*ft_get_next_line(int fd);
size_t				ft_strlen_gnl(const char *str);
char				*ft_strchr_gnl(const char *s, int c);
void				ft_strncpy_gnl(char *dest, const char *str, size_t len);
char				*ft_strjoin_gnl(char *mega_buf, char *buf);
char				*ft_substr_gnl(char *s, unsigned int start, size_t len);

//*** ft_printf ***//
size_t				numlen_prt(unsigned long long ull, int base);
char				*itoa_ull_prt(unsigned long long ull, int base, char sign);
int					putnbr_prt(unsigned long long ull, int base, char sign);
int					minus_flag_prt(int n);
int					handle_ptr_prt(unsigned long long ull);

int					ft_putchar_prt(int i);
int					ft_putstr_prt(char *str);
int					identify_type(char c, va_list ap);
int					ft_printf(const char *format, ...);

//*** so_long ***//
char				**ft_array_dup(char **array);
void				ft_array_free(char **array);
int					ft_error(char *message);
int					ft_strlen_newline(char *str);

#endif
