

#include"libft.h"

void	ft_lstadd_back(t_lst **lst, t_lst *new)
{
	t_lst	*begin;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	begin = (*lst);
	while (begin->next && new)
		begin = begin->next;
	begin->next = new;
}
