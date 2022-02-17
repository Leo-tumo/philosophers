#include "../includes/philos.h"

int	main(int argc, char **argv)
{
	t_philos	args;

	if (argc < 5 || argc > 6)
		ft_error("Wrong input");
	arg_init(&args, argv, argc);
	printf("\x1b[31m");
}

void	arg_init(t_philos *args, char **argv, int ac)
{
	args->nb_philo = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	if (args->nb_philo > 200 || args-> time_to_die < 60 || args->time_to_eat < 60 
		|| args->time_to_sleep < 60)
		ft_error("");
	if (ac == 6)
		args->nb_must_eat = ft_atoi(argv[5]);
	else
		args->nb_must_eat = 0;
}
