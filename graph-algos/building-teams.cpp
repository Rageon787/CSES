#include<bits/stdc++.h>
using namespace std; 


bool bfs(int start, vector<int> &assigned, vector<vector<int>> &friends) {
	
	queue<tuple<int, int, int>> q; 
	
	q.push({start, -1, 1});

	while (!q.empty()) {

		auto [curr, prev, team] = q.front(); 
		q.pop();
		
		if (assigned[curr] > 0)  {
			if (assigned[curr] == assigned[prev]) return false; 
			continue;
		}
		assigned[curr] = team;

		for (auto f: friends[curr]) {
			if (f == prev) continue;
			if (team == 1) q.push({f, curr, 2});
			else q.push({f, curr, 1});
		}
	} 

	return true; 
}

int main() {
	int n, m; 
	cin >> n >> m; 

	vector<vector<int>> friends(n + 1);

	for (int i = 0; i < m; i++) { 
		int a, b; 
		cin >> a >> b; 
		friends[a].push_back(b);
		friends[b].push_back(a);
	} 
	
	bool ok = true; 
	vector<int> assigned(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		if (assigned[i] > 0) continue;
		ok &= bfs(i, assigned, friends);
		if (!ok) break;
	}

	if (!ok) {
		cout << "IMPOSSIBLE" << endl;
	} else {
		for (int i = 1; i <= n; i++) cout << assigned[i] << ' ';
	}
}
