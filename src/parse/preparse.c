/*
** syntax.c for syntax in /home/alies/rendu/PSU_2015_minishell1/src
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Tue Jan  5 18:07:49 2016 Arnaud Alies
** Last update Fri Jan 22 14:47:39 2016 alies_a
*/

#include "my.h"

int		check_par(const char *str)
{
  double	c;

  c = my_char_count(str, '\'');
  if (c / 2 != (int)c / 2)
    {
      my_puterr("Unmatched '.\n");
      return (1);
    }
  c = my_char_count(str, '\"');
  if (c / 2 != (int)c / 2)
    {
      my_puterr("Unmatched \".\n");
      return (1);
    }
  return (0);
}

int		pre_check(char *str)
{
  my_purstr(str);
  if (check_par(str))
    return (1);
  return (0);
}
