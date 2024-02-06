

#include"libft.h"

void	ft_lstiter(t_lst *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
