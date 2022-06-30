#include "list.h"

/**
 * add_node_end - add nod to the end of the double linked-list
 * @list: Double pointer to the beginning of the double linked list
 * @str: Pointer to string to save in the node
 *
 * Return: addres of new node
 */
List *add_node_end(List **list, char *str)
{
	List *new_node = NULL;
	List *tmp = NULL;
	char *tmp_str = str;

	if (list == NULL)
		return (NULL);

	new_node = malloc(sizeof(List));

	if (new_node == NULL)
		return (NULL);

	new_node->str = tmp_str;
	tmp = *list;

	if (tmp == NULL)
	{
		*list = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;
		return (new_node);
	}

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	tmp->next = new_node;
	new_node->prev = tmp;
	new_node->next = NULL;

	return (new_node);

}


/**
 * add_node_begin - Add node to the biggining
 * @list: Double pointer to the list to modify
 * @str: string to save in the new node
 *
 * Return: address of the new node
 */
List *add_node_begin(List **list, char *str)
{

	List *new_node = NULL;
	List *tmp = NULL;
	char *tmp_str = str;

	if (list == NULL)
		return (NULL);

	new_node = malloc(sizeof(List));

	if (new_node == NULL)
		return (NULL);

	new_node->str = tmp_str;
	tmp = *list;

	if (tmp == NULL)
	{
		*list = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;
		return (new_node);
	}

	tmp->prev = new_node;
	new_node->prev = NULL;
	new_node->next = tmp;
	*list = new_node;

	return (new_node);

}
