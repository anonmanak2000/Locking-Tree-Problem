#ifndef OPERATION_H
#define OPERATION_H

#include<string>

//Operation Input structure
struct Operation {
	int operation_type;
	std::string node_name;
	int uid;
};

#endif