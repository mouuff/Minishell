/*
** cmp_str.c for str in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Mar 17 10:35:27 2016 alies_a
** Last update Thu Mar 17 11:41:42 2016 alies_a
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

int	cmp_str(const t_token *tok, t_cmd **cmd)
{
  char	*buff;

  buff = (*cmd)->args;
  if (((*cmd)->args = my_strdcpy((*cmd)->args, tok->str)) == NULL)
    return (1);
  free(buff);
  return (0);
}
