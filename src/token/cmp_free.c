/*
** cmp_free.c for free in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Mar 17 13:44:51 2016 alies_a
** Last update Thu Mar 17 14:06:34 2016 alies_a
*/

#include <stdlib.h>
#include "mysh.h"

static void	cmp_free(t_cmp *cmp)
{
  free(cmp->args);
  free(cmp->input_file);
  free(cmp->output_file);
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
