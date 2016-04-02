/*
** pipeit.c for pipeit in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Tue Mar 22 14:39:02 2016 alies_a
** Last update Sat Apr  2 11:37:09 2016 alies_a
*/

#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "mysh.h"
#include "my.h"

t_rdr rdr[] = {
  {&in_simple, '<'},
  {&out_simple, '>'},
  {&out_double, '}'},
  {NULL, 0},
};

int	in_simple(const t_cmp *cmp)
{
  int	fd;

  if ((fd = open((cmp->rd)[IN].file, O_RDONLY)) == -1)
    {
      my_puterr((cmp->rd)[IN].file);
      if (errno == EACCES)
	my_puterr(": Permission denied.\n");
      return (1);
    }
  if (dup2(fd, 0) == -1)
    {
      close(fd);
      return (1);
    }
  close(fd);
  return (0);
}

int	out_simple(const t_cmp *cmp)
{
  int	fd;

  if ((fd = open((cmp->rd)[OUT].file, O_WRONLY | O_CREAT, 0644)) == -1)
    {
      my_puterr((cmp->rd)[OUT].file);
      if (errno == EACCES)
	my_puterr(": Permission denied.\n");
      if (errno == EISDIR)
	my_puterr(": Is a directory.\n");
      return (1);
    }
  if (dup2(fd, 1) == -1)
    {
      close(fd);
      return (1);
    }
  close(fd);
  return (0);
}

int	out_double(const t_cmp *cmp)
{
  int	fd;

  if ((fd = open((cmp->rd)[OUT].file,
		 O_WRONLY | O_CREAT | O_APPEND,
		 0644)) == -1)
    {
      my_puterr((cmp->rd)[OUT].file);
      if (errno == EACCES)
	my_puterr(": Permission denied.\n");
      if (errno == EISDIR)
	my_puterr(": Is a directory.\n");
      return (1);
    }
  if (dup2(fd, 1) == -1)
    {
      close(fd);
      return (1);
    }
  close(fd);
  return (0);
}

int	redirect(const t_cmp *cmp)
{
  int	x;
  int	res;

  res = 0;
  x = 0;
  while (rdr[x].rdr != NULL)
    {
      if (rdr[x].type == cmp->rd[OUT].type ||
	  rdr[x].type == cmp->rd[IN].type)
	res = (rdr[x].rdr(cmp) ? 1 : res);
      x += 1;
    }
  return (res);
}
