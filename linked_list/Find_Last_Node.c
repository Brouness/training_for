#include "struct.h"

node	*ft_last_node(node *a)
{
	if (!a)
		return (NULL);
	node *h;
	h = a;
	while (h->next != NULL)
		h = h->next;
	return (h);
}