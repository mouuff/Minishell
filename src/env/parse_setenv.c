/*
** parse_setenv.c for parse setenv in /home/alies/rendu/PSU_2015_minishell1
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Jan  6 22:34:33 2016 Arnaud Alies
** Last update Thu Jan 14 14:58:13 2016 Arnaud Alies
*/

#include "my.h"

int	parse_setenv(char **args)
{
  int	len;

  len = my_array_len(args);
  if (len > 3)
    {
      my_puterr("setenv: Too many arguments.\n");
      return (1);
    }
  if (len < 2)
    return (1);
  if (!my_char_isalpha(args[1][0]))
    {
      my_puterr("setenv: Variable name must begin with a letter.\n");
      return (1);
    }
  if (!(my_str_isalphanum(args[1])))
    {
      my_puterr("setenv: ");
      my_puterr("Variable name must contain alphanumeric characters.\n");
      return (1);
    }
  return (0);
}
