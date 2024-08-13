
#include "push_swap.h"

void rotate(t_list **stack)
{
	t_list *first;
	t_list *last;

	first = *stack;
	last = ft_last_lst((*stack));
	last->next = first;
	*stack = (*stack)->next;
	first->next = NULL;

}

void ra(t_list **stack_a)
{
	rotate(stack_a);
	write(1,"ra\n",3);
}
