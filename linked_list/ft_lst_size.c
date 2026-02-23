#include "struct.h"

int	ft_lst_size(t_list *head)
{
	int	i;

	if (head == NULL)
		return (0);
	i = 0;
	while (head)
	{
		i++; 
		head = head->next;
	}
	return (i);
}