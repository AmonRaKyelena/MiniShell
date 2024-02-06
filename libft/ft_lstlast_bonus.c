

#include"libft.h"

t_lst	*ft_lstlast(t_lst *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}
