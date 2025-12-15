#include "BinaryTree.cpp"
#include "LinkedList.cpp"
#include "AdjacencyList.cpp"

int main() {
	Graph* g = new Graph(10);
	g->PrintMap();
	g->InsertEdge(1, 5);
	std::cout << "\n";
	g->PrintMap();

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