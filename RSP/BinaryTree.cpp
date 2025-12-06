#include <iostream>
#include <stack>

struct Node {
	int val;
	Node* right;
	Node* left;
};


class BinaryTree {
public:
	void InsertNode(int n) {
		if (head == nullptr) {
			Node* new_node = new Node();
			new_node->val = n;
			head = new_node;
			return;
		}
		Node* dummy = head;
		while (true) {
			if (n == dummy->val) {
				return;
			}
			if (n < dummy->val) {
				if (dummy->left == nullptr) {
					Node* new_node = new Node();
					new_node->val = n;
					dummy->left = new_node;
					return;
				}
				dummy = dummy->left;
			}
			else {
				if (dummy->right == nullptr) {
					Node* new_node = new Node();
					new_node->val = n;
					dummy->right = new_node;
					return;
				}
				dummy = dummy->right;
			}
		}
	}

	void DeleteNode(int n) {
		return;
	}

	void InOrderTraversal(Node * node) {
		if (node == nullptr) {
			return;
		}

		InOrderTraversal(node->left);
		std::cout << node->val << " ";
		InOrderTraversal(node->right);
	}

	void PreOrderTraversal(Node * node) {
		std::stack<Node*> stack;
		if (node != nullptr) {
			stack.push(node);
		}
		while (!stack.empty()) {
			Node* current = stack.top();
			stack.pop();

			if (current->right != nullptr) {
				stack.push(current->right);
			}
			std::cout << current->val << " ";
			if (current->left != nullptr) { // FIFO, therefore left gets evaled first.
				stack.push(current->left);
			}

		}
	}

	void PostOrderTraversal(Node* node) { // need a "bubble up"
		if (node == nullptr) {
			return;
		}
		PostOrderTraversal(node->left);
		PostOrderTraversal(node->right);
		std::cout << node->val << " ";
	}

	Node* GetNode(int val) {
		Node* dummy = head;
		while (dummy != nullptr) {
			if (val == dummy -> val) {
				return dummy;
			}
			if (val > dummy->val) {
				dummy = dummy->left;
			}
			else {
				dummy = dummy->right;
			}
		}
		return nullptr;
	}

private:
	Node* head = nullptr;
};


int main() {
	BinaryTree bt;
	bt.InsertNode(5);
	bt.InsertNode(6);
	bt.InsertNode(3);

	bt.PreOrderTraversal(bt.GetNode(5));
	std::cout << "\n";
	bt.InOrderTraversal(bt.GetNode(5));
	std::cout << "\n";
	bt.PostOrderTraversal(bt.GetNode(5));

}