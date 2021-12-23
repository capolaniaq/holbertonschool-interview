#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node
 * @parent: pointer to parent node, or null in case of root node
 * @value: value to store in node
 *
 * Return: pointer to new node, or null in case failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;


	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;

	if (parent == NULL)
		return (new_node);

	new_node->parent = parent;
	return (new_node);

}
