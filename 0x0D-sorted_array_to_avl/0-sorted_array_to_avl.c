#include "binary_trees.h"


/**
 * sorted_array_to_avl - Stores recursively each level in
 * an array of strings
 * @array: Pointer to the node to print
 * @size: Size of the array
 *
 * Return: Pointer to the new AVL tree
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree;
	size_t i;

	if (!array || !size)
		return (NULL);

	tree = malloc(sizeof(avl_t));

	for (i = 0; i < size; i++)
	{
		if (i == 0)
		{
			tree->n = array[i];
			tree->parent = NULL;
			tree->left = NULL;
			tree->right = NULL;
		}
		else
			insert_node(&tree, array[i]);
	}

return (tree);
}

/**
 * insert_node - Inserts a node in a binary tree
 * @tree: Pointer to the node to insert
 * @value: Value to insert
 *
 * Return: Pointer to the new node
 */

void insert_node(avl_t **tree, int value)
{
	avl_t *new_node;
	avl_t *current;
	avl_t *parent;

	if (!tree)
		return;

	new_node = malloc(sizeof(avl_t));

	if (!new_node)
		return;
	new_node->n = value;
	current = *tree;

	while (current->left == NULL && current->right == NULL)
	{
		parent = current;
		if (value < current->n)
			current->left = new_node;
		else
			current->right = new_node;
	}
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;
}
