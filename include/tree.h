#ifndef TREE_H
#define TREE_H

#include <iostream>

class Node
{
public:
    Node *left;
    Node *right;
    int data;

    Node(int data);
};

class Binary_Tree
{
    Node *root_node;
    void insert(Node *node, int data);
    void inorder(Node *node);
    void preorder(Node *node);
    void postorder(Node *node);
    bool find_node(Node *root_node, int data);
    Node *find_max_min_data(Node *node, bool is_max);
    Node *find_parent(Node *node, Node *parent, int data);
    int check_child_number_to_parent(Node *node);
    Node *delete_node_impl(Node *parent_of_data, int data);
    int height(Node *node);

public:
    Binary_Tree();
    void insert_node(int data);
    void display();
    bool is_node_present(int data);
    int find_max_value_data();
    int find_min_value_data();
    void level_order_traversal();
    void delete_node(int data);
    int height_of_node();
};

/*
template <typename T>
extern template class Binary_Tree<int>;
*/
#endif