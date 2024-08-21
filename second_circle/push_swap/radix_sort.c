
#include "push_swap.h"

/*Esta funcion es par encontrar el nodo con el valor mas pqueño siempre que el indice sea -1 ya que asi saltara los que ya tienen indice y esto es para que la funcion get index le pongar el indice*/
t_list *get_min_num(t_list **stack_a)
{
	t_list *tmp;
	t_list *min;
	int min_finded;

	min = NULL;
	tmp = *stack_a;
	min_finded = 0;
	while(tmp)
	{
		if(tmp->index == -1 && (!min_finded || tmp->content < min->content))
		{
			min = tmp;
			min_finded = 1;
		}
		tmp = tmp->next;
	}
	return (min);
}

/*Esta funcion llama a get min para cada vez que consiga el valor mmas pequeño de la lista y le da en nuevo valor al indice*/
void get_index_num(t_list **stack_a)
{
	t_list *min_num;
	int new_i;

	min_num = get_min_num(stack_a);
	new_i = 0;
	while(min_num)
	{
		min_num->index = new_i++;
		min_num = get_min_num(stack_a);
	}
}

/*En esta funcion buscaremos el indice del numero mas grade
 Y devolvermos el numero de bits necesarios desplazados a la derecha hasta que llegue a 0*/
int max_i_bits(t_list **stack_a)
{
	t_list *tmp;
	int max;
	int bits;

	tmp = *stack_a;
	max = tmp->index;
	bits = 0;
	while(tmp)
	{
		printf("aA");
		if(tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	while((max >> bits) !=0)
	{
		bits++;
	}
	return(bits);
}

/*En esta funcion usamos el algorimto the Radix sort
 ordena los numeros procesandos sus bits en este caso en los bits de los indices*/

void radix_sort(t_list **stack_a, t_list **stack_b)
{
	printf("a");
	t_list *tmp;
	int highest_i;
	int size;
	int i;
	int j;

	tmp = *stack_a;
	highest_i = max_i_bits(stack_a);//numero max de bits
	size = lst_size(tmp);//tamaño de la lista
	printf("size: %d",size);
	i = 0;
	while(i < highest_i)
	{
		j = 0;
		while (j < size)
		{
			tmp = *stack_a;
			if (((tmp->index >> i) & 1) == 0)
				pb(stack_a,stack_b);
			else
				ra(stack_a);
			j++;
		}
		while(lst_size(*stack_b) != 0)
			pa(stack_a,stack_b);
		i++;
	}
}
