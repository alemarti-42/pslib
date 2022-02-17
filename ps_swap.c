#include "pslib.h"

int	exec_swap(t_list *stack)
{
	t_list_node	*swap;

	swap = pop_node(stack);
	if (swap == NULL)
		return (-1);
	rotate(stack);
	push_node(swap, stack);
	rev_rotate(stack);
	return (0);
}

int	exec_sa(t_push_swap *push_swap)
{
	if (exec_swap(push_swap->stack_a))
		return (-1);
	add_command(push_swap, "sa\n");
	return (0);
}

int	exec_sb(t_push_swap *push_swap)
{
	if (exec_swap(push_swap->stack_b) == -1)
		return (-1);
	add_command(push_swap, "sb\n");
	return (0);
}

int	exec_ss(t_push_swap *push_swap)
{
	
	if (exec_sa(push_swap) == -1 || exec_sb(push_swap) == -1)
		return (-1);
	//push_swap->commands = ft_strjoin(push_swap->commands, "ss");
	return (0);
}
