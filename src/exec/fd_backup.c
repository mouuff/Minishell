/*
** fd_backup.c for fd backup in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Tue Mar 29 17:59:06 2016 alies_a
** Last update Tue Mar 29 18:06:30 2016 alies_a
*/

#include <unistd.h>

int	fd_backup(int *fds)
{
  if ((fds[0] = dup(0)) == -1)
    return (1);
  if ((fds[1] = dup(1)) == -1)
    return (1);
  return (0);
}

int	fd_rollback(int *fds)
{
  if (dup2(fds[0], 0) == -1)
    return (1);
  if (dup2(fds[1], 1) == -1)
    return (1);
  if (close(fds[0]) == -1)
    return (1);
  if (close(fds[1]) == -1)
    return (1);
  return (0);
}
