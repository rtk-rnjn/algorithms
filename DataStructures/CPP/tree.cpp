#include <iostream>
#include <vector>

class tree
{
public:
    int data;
    tree *left;
    tree *right;

    tree(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }

    ~tree()
    {
        delete left;
        delete right;
    }

    tree(const std::vector<int> &array)
    {
        tree *root = build_tree(array, 0);
        this->data = root->data;
        this->left = root->left;
        this->right = root->right;
        root->left = nullptr;
        root->right = nullptr;
        delete root;
    }

    tree *build_tree(const std::vector<int> &array, int index);
    tree *build_tree(const std::vector<int> &array, int size, int index);

    void inorder(tree *root);
    void preorder(tree *root);
    void postorder(tree *root);
};

tree *tree::build_tree(const std::vector<int> &array, int index)
{
    int size = (int)array.size();
    if (index >= size)
    {
        return nullptr;
    }
    tree *node = new tree(array[index]);
    node->left = build_tree(array, 2 * index + 1);
    node->right = build_tree(array, 2 * index + 2);

    return node;
}

void tree::inorder(tree *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}

void tree::preorder(tree *root)
{
    if (root == nullptr)
    {
        return;
    }
    std::cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void tree::postorder(tree *root)
{
    if (root == nullptr)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    std::cout << root->data << " ";
}

int main()
{
    std::vector<int> array = {1, 2, 3, 4, 5, 6, 7};
    tree t(array);

    std::cout << "Inorder: ";
    t.inorder(&t);
    std::cout << std::endl;

    std::cout << "Preorder: ";
    t.preorder(&t);
    std::cout << std::endl;

    std::cout << "Postorder: ";
    t.postorder(&t);
    std::cout << std::endl;

    return 0;
}
