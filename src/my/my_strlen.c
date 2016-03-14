/*
** my_strlen.c for Day 4 Exercice 4 in /home/alies_a/rendu/Piscine_C_J04
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Oct  1 14:06:25 2015 Arnaud Alies
** Last update Mon Jan  4 20:12:33 2016 Arnaud Alies
*/

#include <stdlib.h>

int	my_strlen(const char *str)
{
  int	x;

  if (str == NULL)
    return (0);
  x = 0;
  while (str[x] != '\0')
    x += 1;
  return (x);
}
