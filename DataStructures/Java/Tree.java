public class Tree {
    static class Node {
        int data;
        Node left;
        Node right;

        Node(int d) {
            this.data = d;
            this.left = null;
            this.right = null;
        }
    }

    Node root;

    public void insert(int d) {
        Node newNode = new Node(d);
        if (this.root == null) {
            this.root = newNode;
            return;
        }
        Node temp = this.root;
        while (temp != null) {
            if (d < temp.data) {
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

    private void print(Node root, String prefix, boolean isLeft) {
        if (root == null) {
            return;
        }
        print(root.right, prefix + (isLeft ? "│   " : "    "), false);
        System.out.println(prefix + (isLeft ? "└── " : "┌── ") + root.data);
        print(root.left, prefix + (isLeft ? "    " : "│   "), true);
    }

    public void print(boolean isLeft) {
        print(this.root, "", isLeft);
    }

    public void inorder(Node root) {
        if (root == null) {
            return;
        }
        inorder(root.left);
        System.out.print(root.data + " -> ");
        inorder(root.right);
    }

    public void inorder() {
        inorder(this.root);
        System.out.println("null");
    }

    public void preorder(Node root) {
        if (root == null) {
            return;
        }
        System.out.print(root.data + " -> ");
        preorder(root.left);
        preorder(root.right);
    }

    public void preorder() {
        preorder(this.root);
        System.out.println("null");
    }

    public void postorder(Node root) {
        if (root == null) {
            return;
        }
        postorder(root.left);
        postorder(root.right);
        System.out.print(root.data + " -> ");
    }

    public void postorder() {
        postorder(this.root);
        System.out.println("null");
    }

    public static void main(String[] args) {
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
