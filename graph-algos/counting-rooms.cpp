#include<bits/stdc++.h>
using namespace std; 

void dfs(int i, int j, vector<vector<bool>> &visited, vector<string> &grid) { 
	if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return; 

	if (visited[i][j] || grid[i][j] == '#') return; 
	visited[i][j] = true;

	vector<pair<int,int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // north, south, east, west

	for (auto dir: directions) {
		dfs(i + dir.first, j + dir.second, visited, grid);	
	}
}

int main() {
	int n, m; 
	cin >> n >> m; 
	
	vector<string> grid(n); 
	
	for (int i = 0; i < n; i++) cin >> grid[i];
	
	int ans = 0;
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && grid[i][j] == '.') {
				dfs(i, j, visited, grid);
				ans++; 
			} 
		}
	} 

	cout << ans << endl;

}
