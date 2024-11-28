#include <iostream>
#include <vector>

using namespace std;

constexpr int Max = 2e5+1;

// create an adjacency list for the tree - what is an adjacency list?
vector<int> adj[Max];
// create an array to store the distance of each node from the tree. 
int dist[Max], maxDist;

void dfs(int node = 0, int p = -1) {
	for (auto child : adj[node]) {
		if (child == p) {
			continue;
		}
		dfs(child, node);
		maxDist = max(dist[child]+dist[node]+1, maxDist);
		dist[node] = max(dist[node], dist[child]+1); 
	} 
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int N;
	cin >> N;
	int A, B;
	
	for (int i = 1; i < N; i++) {
		cin >> A >> B; --A, B--;
		adj[A].push_back(B);
		adj[B].push_back(A);
	}
	dfs();
	cout << maxDist << endl;
}
