/*
** delimiter.c for delimiter in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Mar 16 16:33:07 2016 alies_a
** Last update Wed Mar 16 18:00:02 2016 alies_a
*/

static char delimiters[] =
  {'\t', ' ', '|', '<', '>', '\0'};

int	is_delimiter(char c)
{
  int	x;

  x = 0;
  while (delimiters[x] != '\0')
    {
      if (delimiters[x] == c)
	return (1);
      x += 1;
    }
  return (0);
}
