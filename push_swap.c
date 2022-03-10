#include "push_swap.h"

char	*get_arg_line(int argc, char **argv)
{
	int		i;
	char	*nums;
	char	*tmp;

	i = 3;
	if (argc > 2)
	{
		nums = ft_strjoin_space(argv[1], argv[2]);
		argc -= 3;
		while (argc > 0)
		{
			tmp = nums;
			nums = ft_strjoin_space(nums, argv[i]);
			free(tmp);
			i++;
			argc--;
		}
	}	
	else
		return (ft_strdup(argv[1]));
	return (nums);
}

void	print_arr(int *arr, int size)
{
	int	i;

	i = 0;
	printf("\n");
	while (i < size)
	{
		printf("%d\n", arr[i]);
		i++;
	}
	printf("\n");
}

void	print_stack(t_alg *alg)
{
	t_stack	*tmpa;
	t_stack	*tmpb;

	tmpa = alg->a;
	tmpb = alg->b;
	printf("\na: ");
	while (alg->a)
	{
		printf("%d ", alg->a->value);
		alg->a = alg->a->next;
	}
	printf("\nb: ");
	while (alg->b)
	{
		printf("%d ", alg->b->value);
		alg->b = alg->b->next;
	}
	alg->a = tmpa;
	alg->b = tmpb;
}

int	main(int argc, char **argv)
{
	char	*arg_str;
	int		*args;
	int		size;
	t_alg	*alg;

	if (argc < 2)
		return (0);
	arg_str = get_arg_line(argc, argv);
	if (!check_args(arg_str))
	{
		printf("Error\n");
		free(arg_str);
		return (0);
	}
	size = get_arr(arg_str, &args);
	free(arg_str);
	if (size < 2)
		return (0);
	if (!is_sorted(args, size))
	{		
		alg = init_stacks(args, size);
		start_sort(alg, size);
		free_alg(alg);
	}
	return (0);
}