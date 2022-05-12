#include "binary_trees.h"

/**
 * heap_extract - extracts the root of a heap
 * @root: pointer to the root of the heap
 *
 * Return: the value of the root
 */

int heap_extract(heap_t **root)
{
	heap_t *tmp;
	int data;

	if (!root || !*root)
		return (0);

	tmp = *root;
	data = tmp->n;
	*root = tmp->left;
	if (*root)
		(*root)->parent = NULL;
	free(tmp);
	return (data);
}