/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dima <dima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:31:03 by snorcros          #+#    #+#             */
/*   Updated: 2020/08/28 12:51:57 by dima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

# define FD_MAX    10240
# define BUFF_SIZE 1

char				*ft_itoadouble(long double n);
void				free_table(void **arr, int position);
int					**new_table(int n, int m);
int					get_next_line(const int fd, char **line);
void				*ft_memset(void *dest, int ch, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t count);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *src);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack,
								const char *needle, size_t len);
char				*ft_strcat_front(char *dest, const char *src,
										size_t size_buf, size_t len2);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, int (*f)(int));
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strcut(char *dst, size_t len_res);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_stradd_front(char *str, size_t len, char c);
char				*ft_stradd_back(char *str, size_t len, char c);
char				*ft_strreplace(char *str, char a, char b);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_itoabase(unsigned long long n, unsigned int base);
char				*ft_itoahex(unsigned long long n, char tcase);
char				*ft_itoa_signed(long long n, unsigned int base);
int					ft_putchar(char c);
void				ft_putnbr(int n);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

void				ft_swap_int(int *s1, int *s2);
void				ft_swap_char(char *s1, char *s2);
void				ft_qsort(int *arr, size_t *board,
		int(*comp)(const int *, const int *), void(*fswap)(void *, void *));

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void(*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *neww);
void				ft_lstiter(t_list *lst, void(*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int					ft_lstsize(t_list *begin_list);
t_list				*ft_lstlast(t_list *begin_list);
t_list				*ft_lsti(t_list *begin_list, size_t nbr);
void				ft_lstreverse(t_list **begin_list);
t_list				*ft_lstfind(t_list *begin_list, void *data_ref,
								int (*cmp)());
void				ft_lstremove_if(t_list **begin_list, void *data_ref,
									int (*cmp)());
void				ft_lstmerge(t_list **begin_list1, t_list *begin_list2);
void				ft_lstswap(t_list **prev, t_list **l1, t_list **l2);
void				ft_lstadd_back(t_list **alst, t_list *neww);
void				ft_lstqsort(t_list **arr, t_list *first, t_list *last,
								int (*comp)(t_list *, t_list *));
#endif
