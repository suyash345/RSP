#include "BinaryTree.cpp"
//#include "LinkedList.cpp"
#include "AdjaceyList.cpp"

int main() {
	BinaryTree bt;
	bt.InsertNode(5);
	bt.InsertNode(6);
	bt.InsertNode(3);
	bt.DeleteNode(3);

	bt.PreOrderTraversal(bt.GetNode(5));
	std::cout << "\n";
	bt.InOrderTraversal(bt.GetNode(5));
	
	std::cout << "\n";
	bt.PostOrderTraversal(bt.GetNode(5));


}