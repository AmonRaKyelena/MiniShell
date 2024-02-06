

#include"libft.h"

int	ft_lstsize(t_lst *lst)
{
	size_t	i;

	i = 0;
	while (lst && ++i)
		lst = lst->next;
	return (i);
}
