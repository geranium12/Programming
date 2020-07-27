package com.tree;

public class Node<T> {
    T value;
    Node left, right;

    public Node() {
        value = null;
        left = right = null;
    }

    public Node(T value) {
        this.value = value;
        left = right = null;
    }

    public Node(Node<T> node) {
        this.value = node.value;
        this.left = node.left;
        this.right = node.right;
    }

    public T getValue() {
        return value;
    }

    public Node getLeft() {
        return left;
    }

    public Node getRight() {
        return right;
    }

    @Override
    public String toString() {
        return "Node{" +
                "value=" + value +
                ", left.value=" + left.value +
                ", right.value=" + right.value +
                '}';
    }
}