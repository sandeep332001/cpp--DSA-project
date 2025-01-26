#include <tree.h>

int main()
{
    Binary_Tree tree;
    tree.insert_node(50);
    tree.insert_node(30);
    tree.insert_node(70);
    tree.insert_node(20);
    tree.insert_node(40);
    tree.insert_node(60);
    tree.insert_node(80);
    tree.insert_node(90);

    tree.display();
    tree.is_node_present(80);

    std::cout << "Max data is : " << tree.find_max_value_data();
    std::cout << "\nMin data is : " << tree.find_min_value_data();
    std::cout << "\n";
    tree.level_order_traversal();
    std::cout << "\n";
    std::cout << "Height : " << tree.height_of_node();
    std::cout << "\n";

    tree.delete_node(70);
    std::cout << "Height : " << tree.height_of_node();
    std::cout << "\n";
    tree.level_order_traversal();
    std::cout << "\n";

    return 0;
}