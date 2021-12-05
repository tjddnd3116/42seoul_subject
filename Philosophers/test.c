#include "./includes/philo.h"
#include <stdio.h>

int main(void)
{
	struct timeval time;
	long long ms;
	long long last_ms;
	gettimeofday(&time, NULL);
	ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	//printf("sec : %ld usec : %d\n", time.tv_sec, time.tv_usec);
	printf("%lld\n", ms);
	usleep(1000);
	gettimeofday(&time, NULL);
	last_ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	printf("%lld\n", last_ms);
	printf("diff : %lld\n", last_ms - ms);
}
