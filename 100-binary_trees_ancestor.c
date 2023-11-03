#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Description: The lowest common ancestor is the farthest node from the root
 * where both nodes are in the same level
 *
 * Return: pointer to the lowest common ancestor node of the two given nodes,
 * or NULL if no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
							const binary_tree_t *second)
{
	int depth1 = 0, depth2 = 0;
	const binary_tree_t *temp1 = first, *temp2 = second;

	if (!first || !second)
		return (NULL);

	while (temp1)
	{
		depth1++;
		temp1 = temp1->parent;
	}

	while (temp2)
	{
		depth2++;
		temp2 = temp2->parent;
	}

	temp1 = first;
	temp2 = second;

	while (depth1 > depth2)
	{
		temp1 = temp1->parent;
		depth1--;
	}

	while (depth2 > depth1)
	{
		temp2 = temp2->parent;
		depth2--;
	}

	while (temp1 != temp2)
	{
		temp1 = temp1->parent;
		temp2 = temp2->parent;
	}

	return ((binary_tree_t *)temp1);
}
