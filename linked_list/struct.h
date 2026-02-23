#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct n_list	*next;
}					t_list;

#endif