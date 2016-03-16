/*
** tok_pipe.c for pipe in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Mar 16 17:00:02 2016 alies_a
** Last update Wed Mar 16 17:07:22 2016 alies_a
*/

int     tok_pipe(const char *line)
{
  if (line[0] == '|')
    return (1);
  return (0);
}
