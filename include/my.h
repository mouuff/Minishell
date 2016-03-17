/*
** my.h for my in /home/alies/rendu/PSU_2015_minishell1/include
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Jan  4 18:29:00 2016 Arnaud Alies
** Last update Thu Mar 17 19:32:32 2016 alies_a
*/

#ifndef MY_H_
#define MY_H_

#ifndef READ_SIZE
#define READ_SIZE (14)
#endif

#include <stddef.h>

int     my_putchar(const char c);
int     my_putstr(const char *str);
int     my_puterr(const char *str);
int     my_strlen(const char *str);
char    *my_strdup(const char *src);
char    *my_strcpy(char *dest, const char *src);
int     my_strcmp(const char *s1, const char *s2);
int     my_char_append(char *str, const char c);
char    *my_char_add(char **s, const char c);
int     my_char_count(const char *str, char c);
char    *my_str_join(const char *dest, const char *from);
int	my_char_isalpha(char c);
int     my_str_isalphanum(const char *str);
void    my_purstr(char *str);
int     my_str_to_nbr(char *str);

int	my_array_show(char **tab);
int     my_array_len(char **array);
int     my_array_append(char **array, char *str);
char    **my_array_add(char ***from, const char *str);
void    my_array_free(char **array);
char	**my_array_dup(char **from);
char    **my_array_cpy(char **dest, char **from);
int     my_array_del(char **array);
char    **my_str_split(const char *str, char c);
void	my_strncpy(char *dest,
		   const char *from,
		   int n);
char    *my_strdcpy(const char *str1,
		    const char *str2);
void	my_memset(void *s, char c, size_t n);
int     my_strmou(const char *s1, const char *s2);

char	*get_next_line(const int fd, char **next, int *size);

#endif
