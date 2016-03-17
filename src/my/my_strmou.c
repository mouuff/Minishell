/*
** my_strmou.c for ou in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Mar 17 19:31:06 2016 alies_a
** Last update Thu Mar 17 19:31:48 2016 alies_a
*/

#include "my.h"

int     my_strmou(const char *s1, const char *s2)
{
  char  diff;
  int   x;

  diff = 0;
  x = 0;
  while (s1[x] != '\0' && s2[x] != '\0')
    {
      diff = s1[x] - s2[x];
      if (diff != 0)
	return (diff);
      x += 1;
    }
  return (0);
}
