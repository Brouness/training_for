#include "struct.h"

t_list	*ft_lst_last(t_list *last)
{
	t_list	*lastee;
	lastee = last;
	while (lastee)
	{
		if (lastee->next == NULL)
			return (lastee);
		lastee = lastee->next;
	}
}