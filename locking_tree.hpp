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

    //Helper function to find if any locked descendent
    bool has_locked_descendent(Tree* node);

    //Helper function to find if any locked ancestor
    bool has_locked_ancestor(Tree* node);

    //Helper function to check descendents lock status for lock upgrade
    bool has_all_descendents_locked_by(Tree* node, int uid, bool& valid_descendents);

    //Helper function to unlock descendents 
    void unlock_descendents(Tree* node);

public:
    LockingTree();
    ~LockingTree();

    // Initializes the root of the tree
    void initialize_tree(std::string value);

    // Adds a node to the tree
    void add_node(std::string parent_name, std::string node_name);

    //Lock Operation on Tree Node
    bool lock(std::string value, int uid);

    //Unlock Operation on Tree Node
    bool unlock(std::string value, int uid);

    //Upgrade lock Operation on Tree Node
    bool upgrade_lock(std::string value, int uid);
};

#endif
