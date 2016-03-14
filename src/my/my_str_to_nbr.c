/*
** my_str_to_nbr.c for my str in /home/alies_a/rendu/PSU_2015_minishell1
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Sat Jan 23 15:30:36 2016 alies_a
** Last update Sat Jan 23 15:31:10 2016 alies_a
*/

#include "my.h"

int     my_compute(int len, char *str, int *mul, int *result)
{
  int   add;

  add = 0;
  if (str[len] >= '0' && str[len] <= '9')
    {
      add = *mul * (str[len] - '0');
      *result += add;
      *mul *= 10;
    }
  return (0);
}

int     my_str_to_nbr(char *str)
{
  int   result;
  int   len;
  int   mul;

  result = 0;
  mul = 1;
  len = my_strlen(str) - 1;
  while (len + 1 > 0)
    {
      my_compute(len, str, &mul, &result);
      len -= 1;
    }
  if (str[0] == '-')
    result = -result;
  return (result);
}
