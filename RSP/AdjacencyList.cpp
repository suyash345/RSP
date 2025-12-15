#include <unordered_map>
#include <unordered_set>
#include <iostream>

class Graph {

private:
	std::unordered_map<int, std::unordered_set<int>> mp;
public:
	Graph(int size) {
		for (int i = 1; i < size - 1; ++i) {
			mp[i].insert(i + 1);
		}
	}

	void PrintMap() {
		for (auto [key, val] : mp) {
			std::cout << " key: " << key << " vals: ";
			for (auto i : val) {
				std::cout << i << " ";
			}
			std::cout << "\n";
		}
	
	}
	void InsertEdge(int node_a, int node_b) {
		mp[node_a].insert(node_b);
	}

};