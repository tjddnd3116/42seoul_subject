#include "./includes/philo.h"
#include <stdio.h>
int main(int argc, char **argv)
{
	t_info *info;

	info = (t_info *)malloc(sizeof(t_info));
	if (argc == 5 || argc == 6)
	{
		init_info(info, argc, argv);
		dinning_philo(info);
	}
	free(info);
}
