#include "pslib.h"

int	exec_push(t_list *stack_src, t_list *stack_dst)
{
	t_list_node	*swap;

	swap = pop_node(stack_src);
	if (swap == NULL)
		return (-1);
	push_node(swap, stack_dst);
	return (0);
}

int	exec_pa(t_push_swap *push_swap)
{
	if (exec_push(push_swap->stack_b, push_swap->stack_a) == -1)
		return (-1);
	add_command(push_swap, "pa\n");
	return (0);
}

int	exec_pb(t_push_swap *push_swap)
{
	if (exec_push(push_swap->stack_a, push_swap->stack_b) == -1)
		return (-1);
	add_command(push_swap, "pb\n");
	return (0);
}