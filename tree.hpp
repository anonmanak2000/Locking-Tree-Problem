#ifndef TREE_H
#define TREE_H

#include<string>
#include<vector>

//Define Tree class
class Tree {
public:
	std::string value;
	std::pair<bool, int> locked;
	std::vector<Tree*> children;
	Tree* parent;

	Tree(const std::string& value) : value(value), locked({ false,-1 }), parent(nullptr) {}
};

#endif