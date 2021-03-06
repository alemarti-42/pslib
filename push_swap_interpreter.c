#include "pslib.h"

t_push_swap	*init_push_swap(void)
{
	t_push_swap	*new_push_swap;

	new_push_swap = malloc(sizeof(t_push_swap));
	new_push_swap->commands = malloc (1);
	*new_push_swap->commands = 0;
	//new_push_swap->stack_a = new_list();
	new_push_swap->stack_b = new_list();
	return (new_push_swap);
}

int	exec_phrase(t_push_swap *push_swap, char *phrase)
{
	char	**commands;
	char	*buf;

	buf = ft_strdup("\0\0\0\0\0");
	commands = ft_split(phrase, ' ');
	while (read(0, buf, 3))
	{
		//printf("\tCMD: %d  \t--%s--\n", ++count, buf);
		add_command(push_swap, " ");
		exec_command(push_swap, buf);
		print_stacks(push_swap);
		commands++;
	}

	/* while (*commands)
	{
		printf("\tCMD: %d  \t--%s--\n", ++count, *commands);
		add_command(push_swap, " ");
		exec_command(push_swap, *commands);
			
		 if (exec_command(push_swap, *commands) == -1)
			return (-1); 
		print_stacks(push_swap);
		
		commands++;
	} */

	
	return (0);
}

int	exec_command(t_push_swap *push_swap, char *command)
{
	if (command[0] == 's')
	{
		if (command[1] == 'a')
			return (exec_sa(push_swap));
		if (command[1] == 'b')
			return (exec_sb(push_swap));
		if (command[1] == 's')
			return (exec_ss(push_swap));
		return (-1);
	}
	if (command[0] == 'p')
	{
		if (command[1] == 'a')
			return (exec_pa(push_swap));
		if (command[1] == 'b')
			return (exec_pb(push_swap));
	}
	if (command[0] == 'r')
	{
		if (command[1] == 'a')
			return (exec_ra(push_swap));
		if (command[1] == 'b')
			return (exec_rb(push_swap));
		if (command[1] == 'r')
		{
			if (command[2] == 0)
				return (exec_rr(push_swap));
			if (command[2] == 'a')
				return (exec_rra(push_swap));
			if (command[2] == 'b')
				return (exec_rrb(push_swap));
			if (command[2] == 'r')
				return (exec_rrr(push_swap));
		}
	}
	return (-1);
}

void	add_command(t_push_swap *push_swap, char *cmd)
{
	char	*swap;

	//printf("##Command:\t%s", cmd);
	swap = ft_strjoin(push_swap->commands, cmd);
	free(push_swap->commands);
	push_swap->commands = swap;
	//print_stacks(push_swap);
	return ;
}
