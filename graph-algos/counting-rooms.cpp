#include<bits/stdc++.h>
using namespace std; 

void solve(int i, int j, vector<string> &building, map<pair<int,int>,int>  visited) {
	if (visited[{i, j}] || building[i][j] == '#') return; 
	visited[{i, j}] = 1;  
	if (i + 1 < building.size()) solve(i + 1, j, building, visited);   
	if (i - 1 < building.size()) solve(i + 1, j, building, visited);   
	if (j + 1 < building[0].size()) solve(i, j + 1, building, visited);   
	if (j - 1 < building[0].size()) solve(i, j - 1, building, visited);   
 
} 

int main() { 

	int n, m; 
	cin >> n >> m; 
	vector<string> building;	 
	unordered_map<pair<int,int>, int> visited; 

	for (int i = 0; i < n; i++) {
		string s; 
		cin >> s;  
		building.push_back(s);
	} 
	
	int ans = 0; 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[{i, j}] == 0) {
				solve(i, j, building, visited);
			}
		}
	} 

	cout << ans << endl;
}
