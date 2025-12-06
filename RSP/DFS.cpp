#include <iostream>

struct Node {
	int val;
	Node* right;
	Node* left;
};


void DFS(Node* node) {
	if(node==nullptr) {
		return;
	}
	std::cout<<node->val << " ";

	DFS(node->left);
	DFS(node->right);

}	