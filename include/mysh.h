/*
** mysh.h for mysh in /home/alies/rendu/PSU_2015_minishell1
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Jan  4 14:09:57 2016 Arnaud Alies
** Last update Thu Mar 24 16:01:38 2016 alies_a
*/

#ifndef MYSH_H_
#define MYSH_H_

#define IS_ERR(x) ((x > 0 ? 1 : 0))

#define IN (0)
#define OUT (1)

#define AIN (1)
#define AOUT (2)

typedef struct s_data
{
  char **env;
  char *oldpwd;
} t_data;

typedef struct s_func
{
  int (*func)(t_data *data, int ac, char **av);
  const char *name;
} t_func;

typedef struct t_signal
{
  int signal;
  const char *name;
} t_signal;

typedef enum e_exit_code
  {
    E_SKIP	= -2,
    E_PASS	= -1,
    E_EXIT	= 1,
    E_MALLOC	= 2
  } t_exit_code;

void    clean_str(char **s);
void	clean_array(char ***array);

int     init_data(t_data *data, char **env);
void	free_data(t_data *data);
void    keyboard_interrupt(int sig);
void    do_void(int sig);
int     compute_line(t_data *data, char *line);

/*
** Builtins
*/

int     check_builtin(t_data *data, char **args);
int     b_setenv(t_data *data, int ac, char **av);
int     b_unsetenv(t_data *data, int ac, char **av);
int     b_env(t_data *data, int ac, char **av);
int     b_exit(t_data *data, int ac, char **av);
int     b_cd(t_data *data, int ac, char **av);
int     b_doge(t_data *data, int ac, char **av);

/*
** Environement
*/

const char *get_env(t_data *data, const char *name);
int     find_env(t_data *data, const char *name);
int     my_setenv(t_data *data, char **args);
int     parse_setenv(char **args);
int     my_unsetenv(t_data *data, char **args);

/*
** Execution
*/

char    *get_exec(t_data *data, char **args);
int     my_exec(t_data *data, char **args);

/*
** Parsing
*/

typedef struct s_token
{
  char type;
  char *str;
  struct s_token *next;
  struct s_token *prev;
} t_token;

typedef struct s_rd
{
  char *file;
  char type;
} t_rd;

typedef struct s_cmp
{
  char **args;
  t_rd rd[2];
  int ambiguous;
  struct s_cmp *prev;
  struct s_cmp *next;
} t_cmp;

typedef struct s_parse
{
  int (*detect)(const char *line);
  int (*recomp)(const t_token *tok, t_cmp **cmp);
  int (*clean)(t_token *tok);
  char type;
} t_parse;

/*
** pipes
*/

typedef struct s_rdr
{
  int (*pipe)(const t_cmp *cmp);
  char type;
} t_rdr;

int     out_simple(const t_cmp *cmp);
int     in_simple(const t_cmp *cmp);
int	pipeit(const t_cmp *cmp);

/*
** Rebuilding tokens
*/

int     cmp_left_simple(const t_token *tok, t_cmp **cmp);
int     cmp_right_simple(const t_token *tok, t_cmp **cmp);
int     cmp_str(const t_token *tok, t_cmp **cmp);
int     cmp_default(const t_token *tok, t_cmp **cmp);
int     cmp_pipe(const t_token *tok, t_cmp **cmp);
t_cmp   *new_cmp();
void    cmps_free(t_cmp **start);

int     get_func(t_parse *res, char type);
t_cmp	*recompose(const t_token *tok);
int     launch_cmps(t_data *data, t_cmp *cmp, int in_fd);

/*
** Tokenize
*/

int	is_delimiter(char c);

int	tok_default(const char *line);
int	tok_str(const char *line);
int	tok_right_simple(const char *line);
int	tok_left_simple(const char *line);
int     tok_pipe(const char *line);

t_token	*tokenize(const char *line);
void	tokens_free(t_token **start);

/*
** Clean token
*/

int	cl_tokens(t_token *tok);

int     cl_no(t_token *tok);
int	cl_str(t_token *tok);
int     cl_right(t_token *tok);
int     cl_left(t_token *tok);

/*
** Parse
*/

typedef struct s_cmp_parse
{
  const char *err;
  int (*parse)(t_cmp *cmp);
} t_cmp_parse;

int     cmps_parse(t_cmp *cmp);

int     parse_empty_args(t_cmp *cmp);
int     parse_ambig_out(t_cmp *cmp);
int     parse_ambig_in(t_cmp *cmp);

/*
** Misc
*/

void    set_handlers();
void    unset_handlers();

int	pre_check(char *str);
int     parse(char **args);

int	isdir(const char *path);
int	isfile(const char *path);
int	is_something(const char *path);
int     is_true_path(const char *str);

char    **str_to_arg(const char *str);

#endif
