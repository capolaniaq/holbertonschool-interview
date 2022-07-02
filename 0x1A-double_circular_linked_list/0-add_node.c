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
	List *firts_tmp = *list;
	char *tmp_str = str;
	char *firts_str = NULL;

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
		new_node->next = new_node;
		new_node->prev = new_node;
		return (new_node);
	}
	firts_str = tmp->str;
	if (tmp->next == tmp)
	{
		tmp->next = new_node;
		tmp->prev = new_node;
		new_node->next = tmp;
		new_node->prev = tmp;
		return (new_node);
	}
	while (firts_str != tmp->next->str)
		tmp = tmp->next;
	tmp->next = new_node;
	new_node->next = firts_tmp;
	new_node->prev = tmp;
	firts_tmp->prev = new_node;
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
	List *firts_tmp = *list;
	char *tmp_str = str;
	char *firts_str;

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
		new_node->next = new_node;
		new_node->prev = new_node;
		return (new_node);
	}
	firts_str = tmp->str;
	if (tmp->next == tmp)
	{
		new_node->next = tmp;
		new_node->prev = tmp;
		tmp->next = new_node;
		tmp->prev = new_node;
		*list = new_node;
		return (new_node);
	}
	while (firts_str != tmp->next->str)
		tmp = tmp->next;
	new_node->next = firts_tmp;
	firts_tmp->prev = new_node;
	new_node->prev = tmp;
	tmp->next = new_node;
	*list = new_node;
	return (new_node);
}
