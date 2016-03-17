/*
** my_strdcpy.c for strdcpy in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Mar 17 10:10:19 2016 alies_a
** Last update Thu Mar 17 10:18:43 2016 alies_a
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdcpy(const char *str1,
		    const char *str2)
{
  char	*res;
  int	len1;
  int	len2;

  len1 = my_strlen(str1);
  len2 = my_strlen(str2);
  if ((res = malloc(sizeof(char) * (len1 + len2 + 1))) == NULL)
    return (NULL);
  if (str1 != NULL)
    my_strcpy(res, str1);
  if (str1 != NULL)
    my_strcpy(res + len1, str2);
  return (res);
}
