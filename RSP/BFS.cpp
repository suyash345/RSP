#include <queue>
#include <iostream>

struct Node {
	int val;
	Node* right;
	Node* left;
};


void BFS(Node* node) {
	std::queue<Node*> queue;
	queue.push(node);
	while (!queue.empty()) {
		Node* current = queue.front();
		queue.pop();
		std::cout << current->val << std::endl;
		if (current->left != nullptr) {
			queue.push(current->left);
		}
		if (current->right!= nullptr) {
			queue.push(current->right);
		}
	}
}