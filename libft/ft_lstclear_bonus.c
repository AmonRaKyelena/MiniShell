

#include"libft.h"

void	ft_lstclear(t_lst **lst, void (*del)(void *))
{
	t_lst	*begin;
	t_lst	*tmp;

	if (!del)
		return ;
	begin = (*lst);
	while (begin)
	{
		del(begin->content);
		tmp = begin;
		begin = begin->next;
		free(tmp);
	}
	*lst = NULL;
}
