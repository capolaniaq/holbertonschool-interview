#include "binary_trees.h"

/**
 * heap_extract - extracts the root of a heap
 * @root: pointer to the root of the heap
 *
 * Return: the value of the root
 */

int heap_extract(heap_t **root)
{
	int data;

	if (!root || !*root)
		return (0);

	data = (*root)->n;
	sort_values(root);

	return (data);
}


/**
 * sort_values - sorts the values of a heap
 *
 * @root: pointer to the root of the heap
 * Return: void
 */

void *sort_values(heap_t **root)
{
	heap_t *tmp;
	int value;

	tmp = *root;
	if (tmp->left == NULL && tmp->right == NULL)
		find_last_leaf(root, tmp);

	if (tmp->left && tmp->right)
	{
		if (tmp->left->n >= tmp->right->n)
		{
			value = tmp->left->n;
			tmp->left->n = tmp->n;
			tmp->n = value;
			sort_values(&tmp->left);
		}
		else
		{
			value = tmp->right->n;
			tmp->right->n = tmp->n;
			tmp->n = value;
			sort_values(&tmp->right);
		}
	}
	else if (tmp->left)
	{
		value = tmp->left->n;
		tmp->left->n = tmp->n;
		tmp->n = value;
		sort_values(&tmp->left);
	}
	else if (tmp->right)
	{
		value = tmp->right->n;
		tmp->right->n = tmp->n;
		tmp->n = value;
		sort_values(&tmp->right);
	}
	return (NULL);
}


/**
 * find_last_leaf - finds the last leaf of a heap
 *@root: pointer to the root of the heap
 *@leaf: pointer to the leaf of the heap
 *
 * Return: void
 */

void *find_last_leaf(heap_t **root, heap_t *leaf)
{
	heap_t *tmp;
	size_t lenght_right, lenght_left;

	tmp = *root;

	if (tmp->left == NULL && tmp->right == NULL)
		del_node(root, tmp, leaf);

	lenght_right = binary_tree_height(&tmp->right);
	lenght_left = binary_tree_height(&tmp->left);
	if (lenght_left > lenght_right)
		find_last_leaf(&tmp->left, leaf);
	else
		find_last_leaf(&tmp->right, leaf);
	return (NULL);
}


/**
 * binary_tree_height - finds the length of a binary tree
 * @root: pointer to the root of the tree
 *
 * Return: the length of the tree
 */

size_t binary_tree_height(heap_t **root)
{
	size_t height_left = 0;
	size_t height_right = 0;
	heap_t *tmp;

	tmp = *root;
	if (tmp->left != NULL)
	{
		height_left = binary_tree_height(&tmp->left) + 1;
	}
	if (tmp->right != NULL)
	{
		height_right = binary_tree_height(&tmp->right) + 1;
	}
	if (height_left >= height_right)
		return (height_left);
	else
		return (height_right);
}


/**
 * del_node - deletes a node from a heap
 * @root: pointer to the root of the heap
 * @leaf: pointer to the leaf of the heap
 *
 * Return: void
 */
void del_node(heap_t **root, heap_t *node, heap_t *leaf)
{
	heap_t *tmp;
	int tmp_data;

	tmp = node;

	printf("leaf-> =  %d\n", leaf->n);
	printf("tmp->n = %d\n", tmp->n);
	if (tmp == leaf)
	{
		printf("tmp->n = %d\n", tmp->n);
		tmp->parent->left = NULL;
		tmp->parent = NULL;
		free(tmp);
		binary_tree_print(*root);
		return;
	}
	else
	{
		tmp_data = leaf->n;
		tmp->n = tmp_data;
		if (leaf->parent->left == leaf)
			leaf->parent->left = NULL;
		else
			leaf->parent->right = NULL;
		free(leaf);
		return;
	}
}