
#include "push_swap.c"

void find_min(t_lits **stack_a)
{
	t_list *tmp;
	int ref;

	tmp = *stack_a;
	ref = tmp->content;
	while(tmp)
	{
		if(ref > tmp->content)
			ref = tmp->content;
		tmp = tmp->next;
	}
	while(stack_a)
	{
		if (stack_a->content == ref)
			stack_a->i++;
		stack_a = stack_a->next;
	}

}

void push(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp;

	tmp = *stack_a;

}
