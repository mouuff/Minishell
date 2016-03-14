/*
** stat.c for stat in /home/alies_a/rendu/PSU_2015_minishell1
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Sat Jan 23 22:07:44 2016 alies_a
** Last update Sun Jan 24 14:15:18 2016 alies_a
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int	is_true_path(const char *str)
{
  int   x;

  x = 0;
  while (str[x] != '\0')
    {
      if (str[x] == '/')
	return (1);
      x += 1;
    }
  return (0);
}

int		is_something(const char *path)
{
  struct stat   sb;

  if (lstat(path, &sb) == -1)
    return (0);
  return (1);
}

int		isfile(const char *path)
{
  struct stat   sb;

  if (lstat(path, &sb) == -1)
    return (0);
  if (S_ISREG(sb.st_mode) || S_ISLNK(sb.st_mode))
    return (1);
  return (0);
}

int		isdir(const char *path)
{
  struct stat   sb;

  if (lstat(path, &sb) == -1)
    return (0);
  if (S_ISDIR(sb.st_mode))
    return (1);
  return (0);
}
