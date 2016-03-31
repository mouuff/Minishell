/*
** b_env.c for env in /home/alies/rendu/PSU_2015_minishell1
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Jan 11 16:26:01 2016 Arnaud Alies
** Last update Thu Mar 31 19:42:22 2016 alies_a
*/

#include "my.h"
#include "mysh.h"

int     b_setenv(t_data *data, int ac, char **av)
{
  if (ac <= 1)
    my_array_show(data->env);
  if (my_setenv(data, av))
    return (1);
  return (0);
}

int     b_unsetenv(t_data *data, int ac, char **av)
{
  if (ac <= 1)
    {
      my_puterr("unsetenv: Too few arguments.");
      return (0);
    }
  my_unsetenv(data, av);
  return (0);
}

int     b_env(t_data *data, int ac, char **av)
{
  (void)ac;
  (void)av;
  my_array_show(data->env);
  return (0);
}
