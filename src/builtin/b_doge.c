/*
** b_doge.c for b_doge in /home/alies_a/rendu/PSU_2015_minishell1
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Jan 25 22:45:56 2016 alies_a
** Last update Thu Mar 31 19:41:52 2016 alies_a
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "mysh.h"
#include "my.h"

int	b_doge(t_data *data, int ac, char **av)
{
  char	buff[READ_SIZE];
  int	fd;
  int	r;

  (void)data;
  (void)ac;
  (void)av;
  if ((fd = open("res/doge.txt", O_RDONLY)) == -1)
    {
      my_putstr("no doge :(\n");
      return (0);
    }
  r = 1;
  while (r > 0)
    {
      r = read(fd, buff, READ_SIZE);
      write(1, buff, r);
    }
  close(fd);
  return (0);
}
