#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Description: A NULL pointer is not a perfect tree
 *
 * Return: 1 if tree is perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int perfect = 0;

	if (tree)
	{
		perfect = 1;
		if (tree->left)
			perfect = perfect && binary_tree_is_perfect(tree->left);
		if (tree->right)
			perfect = perfect && binary_tree_is_perfect(tree->right);
		if ((tree->left && !tree->right) || (!tree->left && tree->right))
			perfect = 0;
		if (binary_tree_balance(tree) != 0)
			perfect = 0;
	}
	return (perfect);
}
