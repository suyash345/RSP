#include <iostream>

struct LinkedListNode {
	int value;
	LinkedListNode* next;
};

class LinkedList {
public:
	void DeleteNode(int n) {
		LinkedListNode* delete_next_to_me = FindNode(n);
		if (delete_next_to_me == nullptr) {
			return;
		}

		LinkedListNode* next = delete_next_to_me->next->next;
		delete delete_next_to_me->next;
		delete_next_to_me->next = next;		
	}

	void InsertAtNode(int n) {
		if (IsEmpty()) {
			head = new LinkedListNode();
			head->value = n;
			return;
		}

		LinkedListNode* insert_next_to_me = FindNode(n);
		if (insert_next_to_me == nullptr) {
			std::cout << "ERROR INSERTING";
			return;
		}
		LinkedListNode* new_node = new LinkedListNode();
		new_node->value = n;
		new_node->next = insert_next_to_me->next;
		insert_next_to_me->next = new_node;
	}

	void InsertFront(int n) {
		if (IsEmpty()) {
			head = new LinkedListNode();
			head->value = n;
		}
		LinkedListNode* new_node = new LinkedListNode();
		new_node->value = n;
		new_node->next = head;
		head = new_node;
	}

	void PrintList() {
		LinkedListNode* dummy = head;
		while (dummy != nullptr) {
			std::cout << dummy->value << " ";
			dummy = dummy->next;
		}
	}

private:
	LinkedListNode* FindNode(int n) {
		LinkedListNode* dummy = head;
		LinkedListNode* prev = dummy;
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

	LinkedListNode* head = nullptr;
};

