
#include "push_swap.h"

void ft_sort2(t_list **stack_a)
{
	if(lst_size(*stack_a) == 2)
		sa(stack_a);
	else
		printf("error sort2");
}


void ft_sort3(t_list **stack_a)
{
	if(lst_size(*stack_a) == 3 && lst_sorted(*stack_a) == 1)
		ra(stack_a);
	else
		printf("error sort3");
}


void ft_sort4(t_list **stack_a)
{
	if(lst_size(*stack_a) == 4)
		sa(stack_a);
	else
		printf("error sort4");
}


void ft_sort5(t_list **stack_a)
{
	if(lst_size(*stack_a) == 5)
		sa(stack_a);
	else
		printf("error sort5");
}
