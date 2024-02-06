// 144. Binary Tree Preorder Traversal

#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int *preorderTraversal(struct TreeNode *root, int *returnSize)
{
    if (root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }

    int *left = NULL;
    int *right = NULL;
    int leftSize = 0;
    int rightSize = 0;

    if (root->left != NULL)
    {
        left = preorderTraversal(root->left, &leftSize);
    }
    if (root->right != NULL)
    {
        right = preorderTraversal(root->right, &rightSize);
    }

    *returnSize = leftSize + rightSize + 1;
    int *result = (int *)malloc(sizeof(int) * (*returnSize));
    result[0] = root->val;

    for (int i = 0; i < leftSize; i++)
    {
        result[i + 1] = left[i];
    }

    for (int i = 0; i < rightSize; i++)
    {
        result[i + leftSize + 1] = right[i];
    }

    free(left);
    free(right);

    return result;
}

void free_tree(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main()
{
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));

    root->val = 1;
    root->left = NULL;
    root->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->right->val = 2;
    root->right->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->right->left->val = 3;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right = NULL;

    /*
     *       1
     *        \
     *         2
     *        /
     *       3
     */

    int returnSize;
    int *result = preorderTraversal(root, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", result[i]);
    }

    free(result);
    free_tree(root);

    return 0;
}