/*
** cmp_redirect.c for redirect in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Mar 17 11:00:47 2016 alies_a
** Last update Thu Mar 17 14:11:18 2016 alies_a
*/

#include <stdlib.h>
#include "mysh.h"
#include "my.h"

int	cmp_left_simple(const t_token *tok, t_cmp **cmp)
{
  if (((*cmp)->input_file = my_strdup(tok->str)) == NULL)
    return (1);
  (*cmp)->input_type = '<';
  return (0);
}

int	cmp_right_simple(const t_token *tok, t_cmp **cmp)
{
  if (((*cmp)->output_file = my_strdup(tok->str)) == NULL)
    return (1);
  (*cmp)->output_type = '>';
  return (0);
}
