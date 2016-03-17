/*
** my_memset.c for mymset in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Mar 17 11:35:04 2016 alies_a
** Last update Thu Mar 17 11:35:05 2016 alies_a
*/

#include <stddef.h>

void            my_memset(void *s, char c, size_t n)
{
  size_t        x;

  x = 0;
  while (x < n)
    {
      ((char*)s)[x] = c;
      x += 1;
    }
}
