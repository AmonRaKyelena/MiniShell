

#include "../../includes/minishell.h"

void	ft_putstr2_fd(char *s1, char *s2, int fd)
{
	ft_putstr_fd(s1, fd);
	ft_putstr_fd(s2, fd);
}

int	is_type(t_token *token, int type)
{
	if (token && token->type == type)
		return (1);
	else
		return (0);
}

int	is_types(t_token *token, char *types)
{
	if (ft_strchr(types, ' ') && is_type(token, EMPTY))
		return (1);
	else if (ft_strchr(types, 'X') && is_type(token, CMD))
		return (1);
	else if (ft_strchr(types, 'x') && is_type(token, ARG))
		return (1);
	else if (ft_strchr(types, 'T') && is_type(token, TRUNC))
		return (1);
	else if (ft_strchr(types, 'A') && is_type(token, APPEND))
		return (1);
	else if (ft_strchr(types, 'I') && is_type(token, INPUT))
		return (1);
	else if (ft_strchr(types, 'P') && is_type(token, PIPE))
		return (1);
	return (0);
}

int	count_seps(char *s)
{
	int	seps;
	int	i;

	seps = 0;
	i = 0;
	while (s[i])
	{
		if (is_separator(s, i))
			seps++;
		i++;
	}
	return (seps);
}

void	first_token(t_token **token)
{
	while (*token && (*token)->prev)
		(*token) = (*token)->prev;
}
