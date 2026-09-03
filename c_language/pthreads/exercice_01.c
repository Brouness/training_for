#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int i = 0;

void	*say_hello(void *arg)
{
	printf("THis is thread number %d and execution number %d\n", (int)gettid(), i);
	i++;
	return NULL;
}

int main(void)
{
	pthread_t	one;
	pthread_t	two;

	pthread_create(&one, NULL, say_hello, NULL);
	pthread_create(&two, NULL, say_hello, NULL);
	pthread_join(two, NULL);
	pthread_join(one, NULL);
}
