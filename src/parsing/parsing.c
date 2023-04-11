#include "pipex.h"

int parse_args(t_env *env, int ac, char **av)
{
    if (ac < 5)
        return (FAILURE);
    env->file1 = av[1];
    env->cmd1 = av[2];
    env->cmd2 = av[3];
    env->file2 = av[4];
    return (SUCCESS);
}
