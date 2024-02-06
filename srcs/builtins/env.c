

#include "../../includes/minishell.h"

int	ft_env(t_var *env, char **args)
{
	if (args[1])
	{
		print_error_no_exit(NULL, NULL, "minishell: env: too many arguments");
		return (ERROR);
	}
	while (env)
	{
		write(1, env->name, ft_strlen(env->name));
		write(1, "=", 1);
		write(1, env->value, ft_strlen(env->value));
		write(1, "\n", 1);
		env = env->next;
	}
	return (SUCCESS);
}
