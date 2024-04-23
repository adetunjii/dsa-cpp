#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int gridTraveller(int m, int n) {
	if (n == 1 && m == 1) return 1;
	if (n == 0 || m == 0) return 0;

	unordered_map<string, int> map;

	stringstream st;
	st << m << "," << n;

	string key;
	st >> key;

	if (map.find(key) != map.end()) {
		return map[key];
	}
 	
	auto res = gridTraveller(m-1, n) + gridTraveller(m, n-1);
	map[key] = res;
	return res;
}

int main() {
	int M, N;
	cin >> M >> N;
	cout << gridTraveller(M, N) << "\n";

	return 0;
}