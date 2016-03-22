/*
** cmp_free.c for free in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Mar 17 13:44:51 2016 alies_a
** Last update Tue Mar 22 14:31:06 2016 alies_a
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

static void	cmp_free(t_cmp *cmp)
{
  my_array_del(cmp->args);
  free((cmp->rd)[IN].file);
  free((cmp->rd)[OUT].file);
  free(cmp);
}

void	cmps_free(t_cmp **start)
{
  t_cmp       *tmp;
  t_cmp       *old;

  tmp = *start;
  while (tmp != NULL)
    {
      old = tmp;
      tmp = tmp->next;
      cmp_free(old);
    }
}
