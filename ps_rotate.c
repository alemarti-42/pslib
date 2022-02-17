#include "pslib.h"

int	exec_ra(t_push_swap *push_swap)
{
	
	if (rotate(push_swap->stack_a) == NULL)
		return (-1);
	add_command(push_swap, "ra\n");
	return (0);
}

int	exec_rb(t_push_swap *push_swap)
{
	
	if (rotate(push_swap->stack_b) == NULL)
		return (-1);
	add_command(push_swap, "rb\n");
	return (0);
}

int	exec_rr(t_push_swap *push_swap)
{
	if (exec_ra(push_swap) != 0 || exec_rb(push_swap) != 0)
		return (-1);
	//push_swap->commands = ft_strjoin(push_swap->commands, "rr");
	return (0);
}