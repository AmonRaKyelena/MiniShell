


#include "../../includes/minishell.h"

int	ft_unset(char **args, t_mini *mini)
{
	int		i;

	if (!(args[1]))
		return (SUCCESS);
	i = 1;
	while (args[i])
	{
		del_var_by_name(mini, args[i]);
		i++;
	}
	return (SUCCESS);
}
