// 94. Binary Tree Inorder Travel

#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorder(struct TreeNode *root, int *res, int *returnSize)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, res, returnSize);
    res[(*returnSize)++] = root->val;
    inorder(root->right, res, returnSize);
}

int *inorderTraversal(struct TreeNode *root, int *returnSize)
{
    *returnSize = 0;
    int *res = (int *)malloc(sizeof(int) * 100);
    inorder(root, res, returnSize);
    return res;
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
    int *res = inorderTraversal(root, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", res[i]);
    }
    printf("\n");

    free(res);
    free_tree(root);

    return 0;
}
