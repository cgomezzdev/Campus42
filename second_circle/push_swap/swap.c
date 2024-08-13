
#include "push_swap.h"

void swap(t_list **stack)
{
	t_list *first;
	t_list *second;

	first = *stack;
	second = (*stack)->next;
	(*stack) = second;
	first->next = second->next;
	second->next = first;
}

void sa(t_list **stack_a)
{
	swap(stack_a);
	write(1,"sa\n",3);
}
