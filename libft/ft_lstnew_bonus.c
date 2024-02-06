

#include"libft.h"

t_lst	*ft_lstnew(void *content)
{
	t_lst	*list;

	list = malloc(sizeof(*list));
	if (list)
	{
		list->content = content;
		list->next = NULL;
	}
	return (list);
}
