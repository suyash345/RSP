#include <iostream>
#include "Node.cpp"


void DFS(Node* node) {
	if(node==nullptr) {
		return;
	}
	std::cout<<node->val << " ";

	DFS(node->left);
	DFS(node->right);

}	