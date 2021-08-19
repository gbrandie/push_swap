#include "push_swap.h"
t_list *greater_than_pivot(t_list *stack, int pivot)
{
	t_list *greater;
	t_list *start;
	greater = NULL;
	while (stack)
	{
		if (stack->data > pivot)
		{
			greater = stack;
			stack = stack->next;
			greater->next = NULL;
			greater->prev = NULL;
			break;
		}
		else
			stack = stack->next;
	}
	start = greater;
	while (stack)
	{
		if (stack->data > pivot)
		{
			greater->next = stack;
			stack->prev = greater;
			greater = greater->next;
		}
		stack = stack->next;
	}
	if (greater)
		greater->next = NULL;
//	printf("\nFIRST_GREATER PRINT\n");
//	while (start)
//	{
//		printf("%d\n",start->data);
//		start = start->next;
//	}
	return (start);
}



t_list *less_than_pivot(t_list *stack, int pivot)
{
	t_list *less;
	t_list *start;
	less = NULL;
	while (stack)
	{
		if (stack->data <= pivot)
		{
			stack->prev->next = stack->next;
			stack->next->prev = stack->prev;
			less = stack;
			stack = stack->next;
			less->next = NULL;
			less->prev = NULL;
			break;
		}
		else
			stack = stack->next;
	}
	start = less;
	while (stack)
	{
		if (stack->data <= pivot)
		{
			stack->prev->next = stack->next;
			stack->next->prev = stack->prev;
			less->next = stack;
			stack->prev = less;
			less = less->next;
		}
		stack = stack->next;
	}
	if (less)
		less->next = NULL;
//	printf("\nFIRST_LESS PRINT\n");
//	while (start)
//	{
//		printf("%d\n",start->data);
//		start = start->next;
//	}
	return (less);
}

t_list *find_start(t_list *list)
{
	while(list)
	{
		if (!list->prev)
			return (list);
		list = list->prev;
	}
	return (NULL);
}

t_list *quick_sort(t_list *stack)
{
	int		pivot;
	t_list	*greater;
	t_list	*less;
	t_list *less_sorted_end;
	t_list *greater_sorted_start;

	if (list_len(stack) < 2)
		return (stack);
	pivot = stack->data;
	less = less_than_pivot(stack->next, pivot);
	greater = greater_than_pivot(stack->next, pivot);
	less_sorted_end = quick_sort(less);
	less_sorted_end->next = stack;
	stack->prev = less_sorted_end;
	greater_sorted_start = quick_sort(greater);
	stack->next = greater_sorted_start;
	greater_sorted_start->prev = stack;
	return (find_start(stack));
}


#include <stdio.h>
int main(int argc, char **argv)
{
	t_list *A;
	if (!create_stack(&A, --argc, ++argv))
		return (if_bad_stack(A));

	t_list *A_start = A;
	while (A)
	{
		printf("%d\n",A->data);
		A = A->next;
	}
	A = quick_sort(A_start);
	printf("\nSORTED LIST OUTPUT\n");
	while (A)
	{
		printf("%d\n",A->data);
		A = A->next;
	}
	return (0);
}