public class Tree {
    private Node root;

    static class Node {
        // CSOFF: VisibilityModifier
        int data;
        Node left;
        Node right;
        // CSON: VisibilityModifier

        Node(final int newData) {
            this.data = newData;
            this.left = null;
            this.right = null;
        }
    }

    public final void insert(final int data) {
        Node newNode = new Node(data);
        if (this.root == null) {
            this.root = newNode;
            return;
        }
        Node temp = this.root;
        while (temp != null) {
            if (data < temp.data) {
                if (temp.left == null) {
                    temp.left = newNode;
                    return;
                }
                temp = temp.left;
            } else {
                if (temp.right == null) {
                    temp.right = newNode;
                    return;
                }
                temp = temp.right;
            }
        }
    }

    public final void delete(final int data) {
        if (this.root == null) {
            return;
        }
        if (this.root.data == data) {
            this.root = null;
            return;
        }
        Node temp = this.root;
        while (temp != null) {
            if (temp.left != null && temp.left.data == data) {
                temp.left = null;
                return;
            }
            if (temp.right != null && temp.right.data == data) {
                temp.right = null;
                return;
            }
            if (data < temp.data) {
                temp = temp.left;
            } else {
                temp = temp.right;
            }
        }
    }

    private void print(final Node node, final String prefix, final boolean isLeft) {
        if (node == null) {
            return;
        }
        print(node.right, prefix + (isLeft ? "│   " : "    "), false);
        System.out.println(prefix + (isLeft ? "└── " : "┌── ") + node.data);
        print(node.left, prefix + (isLeft ? "    " : "│   "), true);
    }

    public final void print(final boolean isLeft) {
        print(this.root, "", isLeft);
    }

    public final void inorder(final Node node) {
        if (node == null) {
            return;
        }
        inorder(node.left);
        System.out.print(node.data + " -> ");
        inorder(node.right);
    }

    public final void inorder() {
        inorder(this.root);
        System.out.println("null");
    }

    public final void preorder(final Node node) {
        if (node == null) {
            return;
        }
        System.out.print(node.data + " -> ");
        preorder(node.left);
        preorder(node.right);
    }

    public final void preorder() {
        preorder(this.root);
        System.out.println("null");
    }

    public final void postorder(final Node node) {
        if (node == null) {
            return;
        }
        postorder(node.left);
        postorder(node.right);
        System.out.print(node.data + " -> ");
    }

    public final void postorder() {
        postorder(this.root);
        System.out.println("null");
    }

    public final int depth(final Node node) {
        if (node == null) {
            return 0;
        }
        int leftDepth = depth(node.left);
        int rightDepth = depth(node.right);
        return Math.max(leftDepth, rightDepth) + 1;
    }

    public final int depth() {
        return depth(this.root);
    }

    public final int height(final Node node) {
        if (node == null) {
            return -1;
        }
        int leftHeight = height(node.left);
        int rightHeight = height(node.right);
        return Math.max(leftHeight, rightHeight) + 1;
    }

    public final int height() {
        return height(this.root);
    }

    public static void main(final String[] args) {
        Tree tree = new Tree();
        tree.insert(5);
        tree.insert(3);
        tree.insert(7);
        tree.insert(2);
        tree.insert(4);
        tree.insert(6);
        tree.insert(8);

        System.out.println("Inorder Traversal:");
        tree.inorder();

        System.out.println("Preorder Traversal:");
        tree.preorder();

        System.out.println("Postorder Traversal:");
        tree.postorder();

        System.out.println("Tree:");
        tree.print(true);
    }
}
