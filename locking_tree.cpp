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

bool LockingTree::has_locked_descendent(Tree* node) {
    for (Tree* child : node->children) {
        if (child->locked.first || has_locked_descendent(child)) return true;
    }

    return false;
}

bool LockingTree::has_locked_ancestor(Tree* node) {
    while (node->parent) {
        if (node->parent->locked.first) return true;

        node = node->parent;
   }

    return false;
}

bool LockingTree::has_all_descendents_locked_by(Tree* node, int uid, bool& valid_descendents) {
    for (Tree* child : node->children) {
        if (child->locked.first && child->locked.second == uid) valid_descendents = true;
        if ((child->locked.first && child->locked.second != uid) || !has_all_descendents_locked_by(child, uid, valid_descendents)) return false;
    }
    return true;
}

void LockingTree::unlock_descendents(Tree* node) {
    for (Tree* child : node->children) {
        if (child->locked.first) child->locked = { false,-1 };

        unlock_descendents(child);
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

bool LockingTree::lock(std::string value, int uid) {
    Tree* node = nodes[value];

    if (node->locked.first || has_locked_ancestor(node) || has_locked_descendent(node)) return false;

    node->locked = { true,uid };

    return true;
}

bool LockingTree::unlock(std::string value, int uid) {
    Tree* node = nodes[value];

    if (node->locked.first && node->locked.second == uid) {
        node->locked = { false,-1 };
        return true;
    }

    return false;
}

bool LockingTree::upgrade_lock(std::string value, int uid) {
    Tree* node = nodes[value];
    bool valid_descendents = false;
    if (!node->locked.first && has_all_descendents_locked_by(node, uid, valid_descendents) && valid_descendents) {
        unlock_descendents(node);
       
        return lock(value, uid);
    }

    return false;
}