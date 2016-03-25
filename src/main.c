/*
** main.c for main in /home/alies/rendu/PSU_2015_minishell1/src
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Jan  4 14:08:32 2016 Arnaud Alies
** Last update Fri Mar 25 12:51:12 2016 alies_a
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
	return (E_EXIT);
      if (IS_ERR((code = compute_line(data, line))))
	{
	  free(next);
	  free(line);
	  return (code);
	}
      free(line);
      line = NULL;
    }
  free(next);
  return (0);
}

int		main(int ac, char **av, char **env)
{
  t_data	data;
  int		code;

  (void)ac;
  (void)av;
  set_handlers();
  if (init_data(&data, env))
    return (E_MALLOC);
  code = loop(&data);
  if (code == E_EXIT)
    {
      my_putstr("exit\n");
      free_data(&data);
    }
  if (code == E_MALLOC)
    {
      my_puterr("Memory error\n");
    }
  return (0);
}
