#include <unistd.h>

typedef struct A
{
	int 	age;
	char	*type;
	char	*name;
} 			youness;
#include <stdio.h>

int main()
{
	youness pinger;
	pinger.name = "Youness Bourajli";
	pinger.age = 21;
	pinger.type = "years old";
	youness aloalo;
	aloalo.name = "youness";
//	ft_putstr(aloalo.name);
	printf("the name of the goat is : %s\nhe is : %d %s\nthe syzeof aloalo is : %d\nthe sizeof pinger is %d",aloalo.name, pinger.age, pinger.type, sizeof(aloalo), sizeof(pinger));
}
