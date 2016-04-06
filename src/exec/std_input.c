/*
** std_redirect.c for std in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Tue Mar 29 20:02:08 2016 alies_a
** Last update Wed Apr  6 14:53:37 2016 alies_a
*/

#include <stdlib.h>
#include <unistd.h>
#include "mysh.h"
#include "my.h"

static ssize_t  myprompt(int fd, void *buf, size_t count, int ret)
{
  if (ret)
    my_putstr("? ");
  return (read(fd, buf, count));
}

static int      std_to_fd(const t_cmp *cmp,
			  int *fd)
{
  char          buff[READ_SIZE + 1];
  int           r;
  int           valid;
  int		ret;

  valid = 1;
  ret = 1;
  if (pipe(fd) == -1)
    return (1);
  while (valid && (r = myprompt(STDIN_FILENO, buff, READ_SIZE, ret)) > 0)
    {
      ret = (buff[r - 1] == '\n' ? 1 : 0);
      r -= ret;
      buff[r] = '\0';
      if (my_strcmp(buff, (cmp->rd)[IN].file) == 0)
	valid = 0;
      else
	{
	  write(fd[1], buff, r);
	  if (ret)
	    write(fd[1], "\n", 1);
	}
    }
  return (0);
}

int     std_input(const t_cmp *cmp)
{
  int	fd[2];

  if (std_to_fd(cmp, fd))
    return (-1);
  if (close(fd[1]) == -1)
    return (-1);
  return (fd[0]);
}
