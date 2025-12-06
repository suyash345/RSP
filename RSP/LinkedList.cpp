#include <iostream>

struct Node {
	int value;
	Node* next;
};

class LinkedList {
public:
	void DeleteNode(int n) {
		Node* delete_next_to_me = FindNode(n);
		if (delete_next_to_me == nullptr) {
			return;
		}

		Node* next = delete_next_to_me->next->next;
		delete delete_next_to_me->next;
		delete_next_to_me->next = next;		
	}

	void InsertAtNode(int n) {
		if (IsEmpty()) {
			head = new Node();
			head->value = n;
			return;
		}

		Node* insert_next_to_me = FindNode(n);
		if (insert_next_to_me == nullptr) {
			std::cout << "ERROR INSERTING";
			return;
		}
		Node* new_node = new Node();
		new_node->value = n;
		new_node->next = insert_next_to_me->next;
		insert_next_to_me->next = new_node;
	}

	void InsertFront(int n) {
		if (IsEmpty()) {
			head = new Node();
			head->value = n;
		}
		Node* new_node = new Node();
		new_node->value = n;
		new_node->next = head;
		head = new_node;
	}

	void PrintList() {
		Node* dummy = head;
		while (dummy != nullptr) {
			std::cout << dummy->value << " ";
			dummy = dummy->next;
		}
	}

private:
	Node* FindNode(int n) {
		Node* dummy = head;
		Node* prev = dummy;
		while (dummy != nullptr) {
			if (dummy->value == n) {
				return prev; // return the previous node.
			}
			prev = dummy;
			dummy = dummy->next;
		}

		return nullptr;
	}

	bool IsEmpty() {
		if (head == nullptr) {
			return true;
		}
		return false;
	}

	Node* head = nullptr;
};

int main() {
	LinkedList ll;
	ll.InsertAtNode(2);
	ll.InsertFront(5);
	ll.PrintList();
	std::cout << "\n";
	ll.DeleteNode(2);
	ll.PrintList();
	std::cout << "\n";
	ll.DeleteNode(5);

}