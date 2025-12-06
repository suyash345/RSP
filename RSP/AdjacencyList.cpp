#include <unordered_map>

std::unordered_map<int,int> GetList() {
	std::unordered_map<int, int> mp;
	for (int i = 1; i <= 10; ++i) {
		mp[i] = i + 2;
		mp[i-1] = i;
	}

	return mp;
}