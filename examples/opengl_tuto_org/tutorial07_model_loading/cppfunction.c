#include "libft.h"

void				*ft_lst_get(t_list *lst, size_t i)
{
	t_list	*iter;
	size_t	nb_loop;

	if (lst == NULL)
		return (NULL);
	iter = lst;
	nb_loop = 0;
	while (iter != NULL)
	{
		if (nb_loop == i)
			return (iter->content);
		iter = iter->next;
		++nb_loop;
	}
	return (NULL);
}

void	ft_lstaddq(t_list **alst, t_list *newe)
{
	t_list	*end;

	if (alst == NULL || newe == NULL)
		return ;
	if (*alst == NULL)
	{
		*alst = newe;
		return ;
	}
	end = ft_lst_last(*alst);
	end->next = newe;
	newe->prev = end;
}

void		ft_clstaddq(t_list **alst, t_list *newe)
{
	t_list	*buffer;

	if (*alst == NULL)
	{
		*alst = newe;
		newe->next = newe;
		newe->prev = newe;
		return ;
	}
	buffer = (*alst)->prev;
	(*alst)->prev = newe;
	buffer->next = newe;
	newe->prev = buffer;
	newe->next = *alst;
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}


t_list	*ft_lst_last(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_list				*ft_push_back(t_list **dest, void *content, size_t size)
{
	t_list	*newl;

	newl = ft_lstnew(content, size);
	ft_lstaddq(dest, newl);
	return(newl);
}

void		ft_lstdel(t_list **alst, void (*del)(void *))
{
	t_list	*node;
	t_list	*next;

	if (alst == NULL || del == NULL)
		return ;
	node = *alst;
	while (node != NULL)
	{
		next = node->next;
		ft_lstdelone(&node, del);
		node = next;
	}
	*alst = NULL;
}

size_t		ft_lstlen(t_list *lst)
{
	size_t	length;

	if (lst == NULL)
		return (0);
	lst = ft_lst_first(lst);
	length = 0;
	while (lst != NULL)
	{
		++length;
		lst = lst->next;
	}
	return (length);
}

t_list		*ft_lstnew(void *content, size_t content_size)
{
	t_list	*to_return;

	to_return = (t_list*)malloc(sizeof(t_list));
	if (to_return == NULL)
		return (NULL);
	if (content == NULL)
	{
		to_return->content_size = 0;
		to_return->content = NULL;
	}
	else
	{
		to_return->content_size = content_size;
		to_return->content = (unsigned char*)malloc(content_size *
				sizeof(unsigned char));
		ft_memcpy(to_return->content, content, content_size);
	}
	to_return->next = NULL;
	to_return->prev = NULL;
	return (to_return);
}

void	*ft_memset(void *b, int c, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char*)b;
	while (i < len)
	{
		ptr[i] = (char)c;
		++i;
	}
	return (b);
}

t_list		*ft_lst_first(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->prev != NULL)
		lst = lst->prev;
	return (lst);
}

void		ft_lstdelone(t_list **alst, void (*del)(void *))
{
	t_list	*prev;
	t_list	*next;

	if (del == NULL || alst == NULL || *alst == NULL)
		return ;
	prev = (*alst)->prev;
	next = (*alst)->next;
	if (prev != NULL && prev != (*alst))
		prev->next = next;
	if (next != NULL && next != (*alst))
		next->prev = prev;
	del((**alst).content);
	free(*alst);
	*alst = NULL;
}

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char	*ptr1;
	char	*ptr2;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ptr1 = (char*)s1;
	ptr2 = (char*)s2;
	i = 0;
	while (i < n)
	{
		ptr1[i] = ptr2[i];
		i++;
	}
	return (s1);
}
