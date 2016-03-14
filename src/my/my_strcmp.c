/*
** my_strcmp.c for Day 6 Exercice 6 in /home/alies_a/rendu/Piscine_C_J06/ex_06
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Oct  5 16:58:16 2015 Arnaud Alies
** Last update Tue Jan  5 10:33:01 2016 Arnaud Alies
*/

#include "my.h"

int	my_strcmp(const char *s1, const char *s2)
{
  char	diff;
  int	x;

  if (my_strlen(s1) != my_strlen(s2))
    return (1);
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
