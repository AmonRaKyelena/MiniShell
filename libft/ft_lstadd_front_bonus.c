

#include"libft.h"

void	ft_lstadd_front(t_lst **lst, t_lst *new)
{	
	new->next = (*lst);
	*lst = new;
}
