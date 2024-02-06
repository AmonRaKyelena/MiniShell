

#include"libft.h"

void	ft_lstdelone(t_lst *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
