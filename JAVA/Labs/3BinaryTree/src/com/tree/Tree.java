package com.tree;

public class Tree<T extends Comparable<T>> {
    private Node<T> root;

    public Tree() {
        root = null;
    }

    public void add(T value) throws NullPointerException {
        if (value == null) {
            throw new NullPointerException("You've tried to add NULL to the tree!");
        }
        if (root == null) {
            root = new Node(value);
        } else {
            Node<T> parent = root;
            Node<T> temp = root;
            while (temp != null) {
                parent = temp;
                if (value.compareTo(temp.value) < 0) {
                    temp = temp.left;
                } else if (value.compareTo(temp.value) > 0) {
                    temp = temp.right;
                } else {
                    temp = null;
                }
            }
            if (value.compareTo(parent.value) < 0) {
                parent.left = new Node(value);
            } else if (value.compareTo(parent.value) > 0) {
                parent.right = new Node(value);
            }
        }
    }

    private Node<T> searchParent(Node<T> curNode) {
        Node<T> temp = root;
        Node<T> prevNode = null;

        while (temp != null && temp != curNode) {
            prevNode = temp;
            if (curNode.value.compareTo(temp.value) < 0) {
                temp = temp.left;
            } else {
                temp = temp.right;
            }
        }
        return prevNode;
    }

    public void delete(T value) throws NullPointerException {
        Node<T> delNode = searchRecursion(root, value);
        if (delNode == null) {
            throw new NullPointerException("You've tried to delete non-existed object in the tree!");
        }

        Node<T> parentDelNode = searchParent(delNode);

        if (delNode.left == null && delNode.right == null) {
            if (parentDelNode == null) {
                root = null;
            } else {
                if (parentDelNode.left == delNode) {
                    parentDelNode.left = null;
                } else {
                    parentDelNode.right = null;
                }
            }
        } else if (delNode.left == null || delNode.right == null) {
            if (parentDelNode == null) {
                if (delNode.left == null) {
                    root = delNode.right;
                } else {
                    root = delNode.left;
                }
            } else if (delNode.left == null) {
                if (parentDelNode.left == delNode) {
                    parentDelNode.left = delNode.right;
                } else {
                    parentDelNode.right = delNode.right;
                }
            } else {
                if (parentDelNode.left == delNode) {
                    parentDelNode.left = delNode.left;
                } else {
                    parentDelNode.right = delNode.left;
                }
            }
        } else {
            Node<T> nextNode = delNode.right;
            while (nextNode.left != null) {
                nextNode = nextNode.left;
            }
            Node<T> parentNextNode = searchParent(nextNode);
            delNode.value = nextNode.value;
            if (parentNextNode != delNode) {
                parentNextNode.left = nextNode.right;
            } else {
                parentNextNode.right = nextNode.right;
            }
        }
    }

    private Node<T> searchRecursion(Node<T> curNode, T value) {
        if (curNode == null || curNode.value == value) {
            return curNode;
        }
        if (value.compareTo(curNode.value) < 0) {
            return searchRecursion(curNode.left, value);
        } else {
            return searchRecursion(curNode.right, value);
        }
    }

    public boolean search(T value) {
        return (searchRecursion(root, value) != null);
    }

    private void inorderTraversalRecursion(Node<T> curNode) {
        if (curNode != null) {
            inorderTraversalRecursion(curNode.left);
            System.out.print(curNode.value + " ");
            inorderTraversalRecursion(curNode.right);
        }
    }

    public void inorderTraversal() {
        inorderTraversalRecursion(root);
        System.out.println();
    }

    private void preorderTraversalRecursion(Node<T> curNode) {
        if (curNode != null) {
            System.out.print(curNode.value + " ");
            preorderTraversalRecursion(curNode.left);
            preorderTraversalRecursion(curNode.right);
        }
    }

    public void preoderTraversal() {
        preorderTraversalRecursion(root);
        System.out.println();
    }

    private void postorderTraversalRecursion(Node<T> curNode) {
        if (curNode != null) {
            postorderTraversalRecursion(curNode.left);
            postorderTraversalRecursion(curNode.right);
            System.out.print(curNode.value + " ");
        }
    }

    public void postorderTraversal() {
        postorderTraversalRecursion(root);
        System.out.println();
    }

    private int numberOfNodesRecursion(Node<T> curNode) {
        if (curNode == null) {
            return 0;
        }
        return numberOfNodesRecursion(curNode.left) + numberOfNodesRecursion(curNode.right) + 1;
    }

    public int numberOfNodes() {
        return numberOfNodesRecursion(root);
    }
}