# 0x02. Heap Insert

By Alexa Orrico, Software Engineer at Holberton Schoo

#### Basic Binary Tree

```
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};
```
#### Max Binary Heap

```
typedef struct binary_tree_s heap_t;
```

## Tasks

### 0. New node


Write a function that creates a binary tree node:

-   Prototype:  `binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);`
-   `parent`  is a pointer to the parent node of the node to create
-   `value`  is the value to put in the new node
-   When created, a node does not have any children
-   Your function must return a pointer to the new node, or  `NULL`  on failure
- 

### 1. Heap - Insert

Write a function that inserts a value into a Max Binary Heap:

-   Prototype:  `heap_t *heap_insert(heap_t **root, int value);`
-   `root`  is a double pointer to the root node of the Heap
-   `value`  is the value to store in the node to be inserted
-   Your function must return a pointer to the inserted node, or  `NULL`  on failure
-   If the address stored in  `root`  is  `NULL`, the created node must become the root node.
-   You have to respect a  `Max Heap`  ordering
-   You are allowed to have up to  `6`  functions in your file

Your file  `0-binary_tree_node.c`  will be compiled during the correction


