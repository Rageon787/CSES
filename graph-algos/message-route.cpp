#include<bits/stdc++.h>
using namespace std; 


int main() {
	int n, m; 
	cin >> n >> m; 
	
	vector<vector<int>> adj(n + 1);

	for (int i = 0; i < m; i++) {
		int u, v; 
		cin >> u >> v;  
		adj[u].push_back(v); 
		adj[v].push_back(u);
	}  

	queue<pair<int,int>> bfs;  
	vector<int> previous(n + 1, -1);	
		
	bfs.push({1, 0}); 


	while (!bfs.empty()) {
		auto [curr, prev] = bfs.front(); 
		bfs.pop(); 
		if (previous[curr] != -1) continue;
		previous[curr] = prev; 
		for (auto neighbour: adj[curr]) {
			if (neighbour == curr) continue;
			bfs.push({neighbour, curr}); 
		} 
	} 

	if (previous[n] == -1) {
		cout << "IMPOSSIBLE" << endl;
	} else { 
		vector<int> ans;
		while (n != 0) { 
		 	ans.push_back(n); 
		 	n = previous[n];
		}

		reverse(ans.begin(), ans.end()); 

		cout << ans.size() << endl; 
		for (auto x: ans) cout << x << ' ';
	}
	
}
