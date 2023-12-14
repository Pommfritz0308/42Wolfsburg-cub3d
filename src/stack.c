#include "cub3d.h"

void	initialize(t_stack *stack)
{
	stack->top = NULL;
}

int	is_empty(t_stack *stack)
{
	return (stack->top == NULL);
}

void	push(t_stack *stack, t_pixel item)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->data = item;
	new_node->next = stack->top;
	stack->top = new_node;
}

t_pixel	pop(t_stack *stack)
{
	t_pixel	default_pixel;
	t_node	*temp;

	if (is_empty(stack))
	{
		default_pixel.x = -42;
		default_pixel.y = -42;
		return (default_pixel);
	}
	temp = stack->top;
	default_pixel = temp->data;
	stack->top = temp->next;
	free(temp);
	return (default_pixel);
}

void	destroy_stack(t_stack *stack)
{
	t_node	*temp;

	while (stack->top != NULL)
	{
		temp = stack->top;
		stack->top = stack->top->next;
		free(temp);
	}
}
