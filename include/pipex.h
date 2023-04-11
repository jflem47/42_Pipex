#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf.h"
# include "libft.h"

# define SUCCESS 0
# define FAILURE 1

//STRUCTS
typedef struct s_env {
	char	*file1;
	char	*file2;
	char	*cmd1;
	char	*cmd2;
}	t_env;

//UTILS
int	parse_args(t_env *env, int ac, char **av);

//PIPEX
void pipex(int f1, int f2);

#endif