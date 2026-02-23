#include "struct.h"

int		ft_count(node *head)
{
	int i = 0;
	node *count = head;
	while (count != NULL)
	{
		i++;
		count = count->next;
	}
	return (i);
}
