/*
** main.c for main in /home/alies/rendu/PSU_2015_minishell1/src
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Jan  4 14:08:32 2016 Arnaud Alies
** Last update Sat Apr  2 11:50:32 2016 alies_a
*/

#include <stdlib.h>
#include <signal.h>
#include "mysh.h"
#include "my.h"

int	loop(t_data *data)
{
  char	*next;
  char	*line;
  int	size;
  int   code;

  next = NULL;
  size = 0;
  while (42)
    {
      my_putstr("$>");
      if ((line = get_next_line(0, &next, &size)) == NULL)
	{
	  free(next);
	  return (2);
	}
      if ((code = compute_line(data, line)) != 0)
	{
	  free(next);
	  free(line);
	  return (code);
	}
      free(line);
      line = NULL;
    }
  free(next);
  return (2);
}

int		main(int ac, char **av, char **env)
{
  t_data	data;
  int		code;

  (void)ac;
  (void)av;
  set_handlers();
  if (init_data(&data, env))
    return (1);
  code = loop(&data);
  if (code == 2)
    {
      my_putstr("exit\n");
      free_data(&data);
    }
  else
    {
      my_puterr("Memory error\n");
      return (1);
    }
  return (0);
}
