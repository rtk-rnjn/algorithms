#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};

struct tree *build_tree(int arr[], int size, int index)
{
    if (index >= size)
    {
        return NULL;
    }
    struct tree *node = (struct tree *)malloc(sizeof(struct tree));
    node->data = arr[index];
    node->left = build_tree(arr, size, 2 * index + 1);
    node->right = build_tree(arr, size, 2 * index + 2);

    return node;
}

void inorder(struct tree *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct tree *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct tree *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void free_tree(struct tree *root)
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
    int arr[] = {1, 2, 3, 4, 5, 6};
    struct tree *root = build_tree(arr, 6, 0);

    if (root == NULL)
    {
        printf("Tree is empty\n");
        free(root);

        return -1;
    }

    inorder(root);
    printf("\n");

    preorder(root);
    printf("\n");

    postorder(root);
    printf("\n");

    free_tree(root);
    return 0;
}
