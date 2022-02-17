#include "pslib.h"

// FOR TESTING
void print_stacks(t_push_swap *push_swap)
{
	push_swap = push_swap;
// 	printf("[A]size:%d:\t", push_swap->stack_a->size);
// 	print_list(push_swap->stack_a);
// 	printf("[B]size:%d:\t", push_swap->stack_b->size);
// 	print_list(push_swap->stack_b);
// 	printf("\n");
}

void print_list(t_list *list)
{
	t_list_node *reader;

	if (list->first == NULL)
	{
		return ;
	}
	
	reader = list->first;
/* 	reader = list->first;
	printf("\t\t%d\n", reader->value); */
	//printf("\nprint_list:\t");
	while (reader->next != list->first)
	{
		ft_putnbr_fd(reader->value, 2);
		ft_putstr_fd("\n", 2);
		reader = reader->next;
	}
	ft_putnbr_fd(reader->value, 2);
	return ;
}

t_list	*string_tolist(char* str)
{
	char	**chopped;
	t_list	*res;
	void	*centinel;

	if (check_only_digits(str) == -1)
	{
		ft_putstr_fd("Caracteres no numéricos\n", 2);
		free (str);
		return (NULL);
	}
	res = new_list();
	chopped = ft_split(str, ' ');
	centinel = chopped;
	//printf("[TEST]STRING: %s\n", str);

	free (str);
	while(*chopped)
	{
		//printf("[TEST]ATOI: %d\n", ft_atoi(*chopped));

		queue_node(new_node(ft_atoi(*chopped)), res);
		free(*chopped);
		chopped++;
	}
	free (centinel);
	
	return (res);
}