#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 *
 * Description: A NULL pointer is not a full tree
 *
 * Return: 1 if tree is full, otherwise 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int full = 0;

	if (tree)
	{
		full = 1;
		if (tree->left)
			full = full && binary_tree_is_full(tree->left);
		if (tree->right)
			full = full && binary_tree_is_full(tree->right);
		if ((tree->left && !tree->right) || (!tree->left && tree->right))
			full = 0;
	}
	return (full);
}
