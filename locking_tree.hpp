#ifndef LOCKING_TREE_HPP
#define LOCKING_TREE_HPP

#include "tree.hpp"
#include <unordered_map>
#include <string>

class LockingTree {
private:
    Tree* root;
    std::unordered_map<std::string, Tree*> nodes;

    // Helper function to delete all nodes in the subtree rooted at `node`
    void deleteSubtree(Tree* node);

public:
    LockingTree();
    ~LockingTree();

    // Initializes the root of the tree
    void initialize_tree(std::string value);

    // Adds a node to the tree
    void add_node(std::string parent_name, std::string node_name);
};

#endif
