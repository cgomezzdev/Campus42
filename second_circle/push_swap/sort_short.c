
#include "push_swap.h"

void ft_sort2(t_list **stack_a)
{
	if(lst_size(*stack_a) == 2)
		sa(stack_a);
	else
		printf("error sort2");
}

int cases_variants(t_list **stack_a)
{
	t_list *middle;
	t_list *last;

	middle = (*stack_a)->next;
	last = ft_last_lst(*stack_a);
	if((*stack_a)->content > middle->content && (*stack_a)->content < last->content)
		return(1);
	if((*stack_a)->content < middle->content && (*stack_a)->content > last->content)
		return(2);
	if((*stack_a)->content < middle->content && middle->content > last->content)
		return(3);
	if(last->content < (*stack_a)->content && last->content > middle->content)
		return(4);
	if(middle->content < (*stack_a)->content && middle->content > last->content)
		return(5);
	return(0);
}

void ft_sort3(t_list **stack_a)
{
	if(lst_size(*stack_a) == 3 && lst_sorted(*stack_a) == 1)
	{
		if(cases_variants(stack_a) == 1)
			sa(stack_a);
		if(cases_variants(stack_a) == 2)
			rra(stack_a);
		if(cases_variants(stack_a) == 3)
		{
			sa(stack_a);
			ra(stack_a);
		}
		if(cases_variants(stack_a) == 4)
			ra(stack_a);
		if(cases_variants(stack_a) == 5)
		{
			sa(stack_a);
			rra(stack_a);
		}
	}
	else
		printf("error sort3\n");
}


void ft_sort4(t_list **stack_a, t_list **stack_b)
{
	t_list *min;

	min = find_min(*stack_a);
	if(lst_size(*stack_a) == 4)
	{	
		if(min->i == 0)
		{
			pb(min,stack_b);
			ft_sort3(stack_a);
			pa(min,stack_b);
		}
	}
	else
		printf("error sort4\n");
}


void ft_sort5(t_list **stack_a)
{
	if(lst_size(*stack_a) == 5)
		sa(stack_a);
	else
		printf("error sort5\n");
}
