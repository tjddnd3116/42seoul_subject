#include "./includes/philo.h"
#include <stdio.h>

int main(void)
{
	struct timeval mytime;

	gettimeofday(&mytime, NULL);
	printf("%ld, %d\n", mytime.tv_sec, mytime.tv_usec);
}
