#include <stdio.h>
#include <stdlib.h>
typedef struct salah
{
	char	*data;
	struct salah *next;
} borji;

borji	*ft_hamid(char *content)
{
	borji	*a;
	a->data = content;
	a->next = NULL;
	return (a);
}
int main()
{
	borji	*a;
	char *st = "salah m9aaaawed ki fham dghya\n";
	a = ft_hamid(st);
	printf("%s", a->data);
}	
