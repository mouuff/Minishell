/*
** tok_str.c for str in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Tue Mar 15 20:34:39 2016 alies_a
** Last update Fri Mar 18 14:22:13 2016 alies_a
*/

#include <stdlib.h>
#include "mysh.h"

int	tok_str(const char *line)
{
  int	x;

  if (line[0] != '"')
    return (0);
  x = 1;
  while (line[x] != '\0' && line[x] != '"')
    {
      x += 1;
    }
  return (x + 1);
}
