#include "locking_tree.hpp"

LockingTree::LockingTree() : root(nullptr) {}

LockingTree::~LockingTree() {
    deleteSubtree(root);    // Deallocate all nodes in the tree
    root = nullptr;         // Set root to nullptr for safety
    nodes.clear();          // Clear the map to release references
}

void LockingTree::deleteSubtree(Tree* node) {
    if (node) {
        for (Tree* child : node->children) {
            deleteSubtree(child);
        }
        delete node;
    }
}

void LockingTree::initialize_tree(std::string value) {
    root = new Tree(value);
    nodes[value] = root;
}

void LockingTree::add_node(std::string parent_name, std::string node_name) {
    Tree* parent_node = nodes[parent_name];
    Tree* child_node = new Tree(node_name);
    child_node->parent = parent_node;
    parent_node->children.push_back(child_node);
    nodes[node_name] = child_node;
}
