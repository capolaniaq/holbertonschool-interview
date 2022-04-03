#include "search.h"

/**
 * linear_skip - Finds a value in a singly linked list
 * @list: Pointer to the head of the list
 * @value: Value to be found
 *
 * Return: Pointer to the node containing the value, or NULL if not found
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *skip_node = NULL;
	skiplist_t *node = NULL;
	size_t size = 0;

	if (list == NULL)
		return (NULL);

	skip_node = list;

	while (skip_node->express != NULL)
	{
		if (skip_node->express->n >= value)
		{
			printf("Value checked at index [%lu] = [%d]\n",
				skip_node->express->index,
				skip_node->express->n);
			printf("Value found between indexes [%lu] and [%lu]\n",
					skip_node->index, skip_node->express->index);
			node = find_node(skip_node, value);
			return (node);
		}
		skip_node = skip_node->express;
		printf("Value checked at index [%lu] = [%d]\n",
				skip_node->index, skip_node->n);
		if (skip_node->express == NULL)
		{
			size = find_final_index(skip_node);
			printf("Value found between indexes [%lu] and [%lu]\n",
					skip_node->index, size);
			node = find_node(skip_node, value);
			return (node);
		}
	}
	return (NULL);
}


/**
 * find_node - Finds a node with the given value
 * @skip_node: Pointer to the node to start searching from
 * @value: Value to be found
 *
 * Return: Pointer to the node containing the value, or NULL if not found
 */
skiplist_t *find_node(skiplist_t *skip_node, int value)
{

	if (skip_node == NULL)
		return (NULL);

	while (skip_node != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		skip_node->index,
		skip_node->n);
		if (skip_node->n == value)
			return (skip_node);
		skip_node = skip_node->next;
	}

	return (NULL);
}


/**
 * find_final_index - Finds the final index of a node
 *
 * @skip_node: Pointer to the node to start searching from
 *
 * Return: The final index of the node
 */
size_t find_final_index(skiplist_t *skip_node)
{

	while (skip_node->next != NULL)
		skip_node = skip_node->next;

	return (skip_node->index);
}

