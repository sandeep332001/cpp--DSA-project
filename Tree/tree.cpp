#include <tree.h>
#include <vector>
#include <queue>

/*
You define the template outside the class so that the compiler knows you're working with a template and the specific type T.
You need to fully qualify the definition with Node<T>:: to tell the compiler which instantiation of the template you're working with.
Without this, the compiler wouldn't know how to associate the definition with the correct template instance (e.g., Node<int>, Node<double>, etc.).
*/

Node::Node(int data)
{
    this->data = data;
    left = nullptr;
    right = nullptr;
}

Binary_Tree::Binary_Tree()
{
    root_node = nullptr;
}

void Binary_Tree::insert(Node *node, int data)
{

    if (node->data > data)
    {
        if (!node->left)
            node->left = new Node(data);
        else
            insert(node->left, data);
    }
    else
    {
        if (!node->right)
            node->right = new Node(data);
        else
            insert(node->right, data);
    }
}

void Binary_Tree::inorder(Node *node)
{
    if (node)
    {
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }
}

void Binary_Tree::preorder(Node *node)
{
    if (node)
    {
        std::cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

void Binary_Tree::postorder(Node *node)
{
    if (node)
    {
        postorder(node->left);
        postorder(node->right);
        std::cout << node->data << " ";
    }
}

void Binary_Tree::display()
{
    std::cout << "\nIn-order\n";
    inorder(root_node);
    std::cout << "\nPre-order\n";
    preorder(root_node);
    std::cout << "\nPost-order\n";
    postorder(root_node);
    std::cout << "\n";
}

void Binary_Tree::insert_node(int data)
{
    if (!root_node)
        root_node = new Node(data);
    else
        insert(root_node, data);
}

bool Binary_Tree::find_node(Node *node, int data)
{

    bool result = false;
    if (node->data == data)
    {
        result = true;
        std::cout << node->data << " <- ";
    }
    else if (node->data > data)
    {
        result = node->left ? find_node(node->left, data) : false;
        if (result)
            std::cout << node->data << " <- ";
    }
    else
    {
        result = node->right ? find_node(node->right, data) : false;
        if (result)
            std::cout << node->data << " <- ";
    }
    return result;
}

bool Binary_Tree::is_node_present(int data)
{
    bool result;
    if (!root_node)
    {
        result = false;
    }

    result = find_node(root_node, data);
    if (result)
        std::cout << "Yes node is present\n";
    else
        std::cout << "No, not present\n";
    return result;
}

Node *Binary_Tree::find_max_min_data(Node *node, bool is_max)
{
    if (is_max)
    {
        return node->right ? find_max_min_data(node->right, is_max) : node;
    }
    return node->left ? find_max_min_data(node->left, is_max) : node;
}

int Binary_Tree::find_max_value_data()
{
    Node *result;
    if (root_node)
    {
        result = find_max_min_data(root_node, 1);
    }
    else
    {
        std::cout << "No tree\n";
        return 0;
    }
    return result->data;
}

int Binary_Tree::find_min_value_data()
{
    Node *result;
    if (root_node)
    {
        result = find_max_min_data(root_node, 0);
    }
    else
    {
        std::cout << "No tree\n";
        return 0;
    }
    return result->data;
}

void Binary_Tree::level_order_traversal()
{
    if (!root_node)
    {
        std::cout << "No tree";
        return;
    }

    std::queue<Node *> q;

    q.push(root_node);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
        std::cout << temp->data << " ";
    }
}
/*
Node *Binary_Tree::find_parent(Node *node, Node *parent, int data)
{
    if (node->data > data)
    {
        if (node->left)
            return find_parent(node->left, node, data);
        else
            std::cout << "data is not there";
    }
    else if (node->data < data)
    {
        if (node->right)
            return find_parent(node->right, node, data);
        else
            std::cout << "data is not there";
    }
    else
    {
        std::cout << "Found\n";
        std::cout << "Parent is " << parent->data << " ";
        return parent;
    }
    return NULL;
}


int Binary_Tree::check_child_number_to_parent(Node *node)
{
    int child = 0;
    if (node->left)
    {
        child++;
    }
    if (node->right)
    {
        child++;
    }
    return child;
}

void Binary_Tree::delete_node_impl(Node *parent_of_data, int data)
{
    if (((parent_of_data->left == nullptr) && (parent_of_data->right == nullptr)))
        return;

    int left = 0, right = 0;
    Node *child;
    if (parent_of_data->left->data == data)
    {
        child = parent_of_data->left;
        left = 1;
    }
    else
    {
        child = parent_of_data->right;
        right = 1;
    }
    int child_number = check_child_number_to_parent(child);
    std::cout << "\nNumber of childrens is : " << child_number << "\n";

    if (child_number == 0)
    {
        if (left)
            parent_of_data->left = nullptr;
        else
            parent_of_data->right = nullptr;
    }
    else if (child_number == 1)
    {
        if (left)
            parent_of_data->left = (child->left == nullptr ? child->right : child->left);
        else
            parent_of_data->right = (child->left == nullptr ? child->right : child->left);
    }
    else ///////////  issue is here
    {
        Node *left_max = find_max_min_data(child, 1);
        parent_of_data->data = left_max->data;
        delete_node_impl(child, data);
    }
}

void Binary_Tree::delete_node(int data)
{
    Node *parent_of_data = find_parent(root_node, NULL, data);
    if (!parent_of_data)
    {
        std::cout << "Not found";
        return;
    }
    delete_node_impl(parent_of_data, data);
}

*/

Node *Binary_Tree::delete_node_impl(Node *node, int data)
{
    if (node == nullptr)
        return node;
    if (node->data > data)
    {
        node->left = delete_node_impl(node->left, data);
    }
    else if (node->data < data)
    {
        node->right = delete_node_impl(node->right, data);
    }
    else
    {
        if (node->left == nullptr && node->right == nullptr)
        {
            delete node;
            return nullptr;
        }
        else if (node->left == nullptr)
        {
            Node *temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr)
        {
            Node *temp = node->left;
            delete node;
            return temp;
        }
        else
        {
            Node *temp = find_max_min_data(node->right, 0);
            node->data = temp->data;
            node->right = delete_node_impl(node->right, temp->data);
        }
    }
    return node;
}

void Binary_Tree::delete_node(int data)
{
    delete_node_impl(root_node, data);
}

int Binary_Tree::height(Node *node)
{
    if (node == nullptr)
        return 0;
    return std::max(height(node->left), height(node->right)) + 1;
}

int Binary_Tree::height_of_node()
{
    return height(root_node);
}
