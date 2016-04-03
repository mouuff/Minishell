/*
** b_exit.c for exit in /home/alies/rendu/PSU_2015_minishell1
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Jan 11 16:49:00 2016 Arnaud Alies
** Last update Sun Apr  3 12:30:44 2016 alies_a
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

static int	str_is_nbr(const char *str)
{
  int		x;

  x = 0;
  while (str[x] != '\0')
    {
      if (!(str[x] >= '0' && str[x] <= '9'))
	return (0);
      x += 1;
    }
  return (1);
}

int     b_exit(t_data *data, int ac, char **av)
{
  (void)data;
  if (ac > 1 && av[1] != NULL)
    {
      if (str_is_nbr(av[1]))
	{
	  my_putstr("exit\n");
	  exit(my_str_to_nbr(av[1]));
	}
      else
	{
	  my_puterr("exit: Expression Syntax.\n");
	  return (0);
	}
    }
  return (2);
}
