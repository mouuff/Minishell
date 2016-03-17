/*
** recompose.c for recompose in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Mar 17 10:00:15 2016 alies_a
** Last update Thu Mar 17 10:09:39 2016 alies_a
*/

t_cmd	*new_cmd()
{
  t_cmd	*res;

  if ((res = malloc(sizeof(t_cmd))) == NULL)
    return (NULL);
  res->args = NULL;
  res->input_file = NULL;
  res->output_file = NULL;
  res->prev = NULL;
  res->next = NULL;
}

t_cmd	*recompose(t_token *tok)
{
  t_cmd	*start;

  if ((start = new_cmd()) == NULL)
    return (NULL);
  while (tok != NULL)
    {
      
      tok = tok->next;
    }
}
