#include<iostream>
#include<vector>
#include<string>
#include "operation.hpp"
#include "locking_tree.hpp"

int main() {

	/*
		n -> No. of nodes
		m -> No. of children per node
		q -> No. of queries/operations to be performed 
	*/
	uint32_t n, m, q;

	std::cin >> n >> m >> q;

	//Take input of n nodes
	std::vector<std::string> nodes(n);
	for (int i = 0; i < n; i++) {
		std::string node;
		std::cin >> node;

		nodes[i] = node;
	}

	//Take input of q queries/operations
	std::vector<Operation> queries(q);
	for (int i = 0; i < q; i++) {
		int op_type, op_uid;
		std::string op_node;

		std::cin >> op_type >> op_node >> op_uid;

		Operation op;
		op.operation_type = op_type;
		op.node_name = op_node;
		op.uid = op_uid;

		queries[i] = op;
	}

	//Prepare m-ary Tree

	/*uint32_t breaker = n / m;*/

	LockingTree tree;

	tree.initialize_tree(nodes[0]);

	for (int i = 1; i < n; i+=m) {
		/*
		child_index = parent_index * m + jth child
		(child_index - jth child) / m = parent_index
		*/

		for (int j = 1; j <= m; j++) {
			/*std::cout << "Parent Name: " << nodes[((i + j - 1) - j) / m] << " child name: " << nodes[(i + j - 1)] << std::endl;*/
			std::string parent_node = nodes[((i + j - 1) - j) / m],
				current_node = nodes[(i + j - 1)];
			tree.add_node(parent_node,current_node);
		}
	}

	return 0;
}