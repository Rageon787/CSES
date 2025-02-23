#include<bits/stdc++.h>
using namespace std; 

bool ok = false;  
vector<int> ans;
void cycle(int curr, int prev, vector<bool> &visited, vector<vector<int>> &cities, vector<int> &previous) {
	if (visited[curr]) { 
		int x = prev;  
		cout << curr << ' ';
		while (x != curr) {
			cout << x << ' ';
			x = previous[x];
		} 
		cout << curr << ' ';
		ok = true;	
		return;
	} 
	previous[curr] = prev;	
	visited[curr] = true;
	
	for (auto city: cities[curr]) {
		if (city == prev) continue; 
		cycle(city, curr, visited, cities, previous);
		if (ok) break;
	} 

	return;
} 



int main() {
	int n, m; 
	cin >> n >> m; 
 	
	vector<vector<int>> cities(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v; 
		cin >> u >> v; 

		cities[u].push_back(v); 
		cities[v].push_back(u);
	} 

	vector<int> previous(n + 1, -1);
	vector<bool> visited(n + 1, false);
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue; 
		cycle(i, -1, visited, cities, previous); 
		if (ok) break; 
	} 
	
	if (!ok) {
		cout << "IMPOSSIBLE" << endl;
	} 

} 
