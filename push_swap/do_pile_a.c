#include "push_swap.h"

pile_a	*create_node(char **argv, int i)
{
	pile_a node;

	node = malloc(sizeof(pile_a));
	if(node == NULL)
		return (NULL);
	node->number = argv[i];
	return(node);
}

pile_a	*pile_a(int argc, char** argv)
{
	int i;
	pile_a	node;

	i = 1;
	node = malloc(sizeof(pile_a));
	if (node == NULL)
		return (NULL);
	node->next = create_node(argv, i);
	while(i != argc)
	{
		i++;
		node->next = create_node(argv, i);
	}
	return (node);
}
