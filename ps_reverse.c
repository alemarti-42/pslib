#include "pslib.h"

int	exec_rra(t_push_swap *push_swap)
{
	
	if (rev_rotate(push_swap->stack_a) == NULL)
		return (-1);
	add_command(push_swap, "rra\n");
	return (0);
}

int	exec_rrb(t_push_swap *push_swap)
{
	
	if (rev_rotate(push_swap->stack_b) == NULL)
		return (-1);
	add_command(push_swap, "rrb\n");
	return (0);
}

int	exec_rrr(t_push_swap *push_swap)
{
	
	if (exec_rra(push_swap) != 0 || exec_rrb(push_swap) != 0)
		return (-1);
	//push_swap->commands = ft_strjoin(push_swap->commands, "rrr");
	return (0);
}