

#include"libft.h"

static void	*erase(t_lst *begin, void (*del)(void *))
{
	t_lst	*tmp;

	while (begin)
	{
		if (del)
			del(begin->content);
		tmp = begin;
		begin = begin->next;
		free(tmp);
	}
	return (NULL);
}

t_lst	*ft_lstmap(t_lst *lst, void *(*f)(void *), void (*del)(void *))
{
	t_lst	*new;
	t_lst	*begin;
	t_lst	*prev;

	prev = NULL;
	begin = NULL;
	while (lst)
	{
		new = malloc(sizeof(*new));
		if (!begin)
			begin = new;
		if (!new)
			return (erase(begin, del));
		if (f)
			new->content = f(lst->content);
		lst = lst->next;
		if (prev)
			prev->next = new;
		prev = new;
	}
	if (prev)
		prev->next = NULL;
	return (begin);
}
