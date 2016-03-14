/*
** parse.c for parse in /home/alies/rendu/PSU_2015_minishell1/src/parse
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Tue Jan  5 18:38:46 2016 Arnaud Alies
** Last update Wed Jan  6 15:26:00 2016 Arnaud Alies
*/

#include "my.h"

int	parse(char **args)
{
  int	len;

  len = my_array_len(args);
  if (len <= 0)
    return (1);
  return (0);
}
