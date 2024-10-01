#include<bits/stdc++.h>
using namespace std; 


int main() {
	int n, m; 
	cin >> n >> m; 
		
	vector<string> maze(n);
	for (int i = 0; i < n; i++) cin >> maze[i];

	vector<vector<bool>> visited(n, vector<bool>(m, false));  
	vector<vector<char>> dir(n, vector<char>(m, ' '));
	queue<tuple<int,int,char>> bfs;
	
	int ax, ay;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (maze[i][j] == 'A') {
				bfs.push({i, j, ' '}); 
				ax = i;
				ay = j;
			}
		}
	}
	
	bool ok = false; 
	string ans = ""; 
	int bx, by;
	while (!bfs.empty()) { 

		auto [x, y, temp] = bfs.front();
		bfs.pop();	
		
		if (x < 0 || y < 0 || x >= maze.size() || y >= maze[0].size() || maze[x][y] == '#' || visited[x][y]) continue;
		visited[x][y] = true;
		

		dir[x][y] = temp;


		if (maze[x][y] == 'B') {
			ok = true;  
			bx = x; 
			by = y;
			break;
		} 

		vector<pair<int,int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // north, south, east, west
		string side = "RLDU";
		
		for (int i = 0; i < directions.size(); i++) { 
			bfs.push({x + directions[i].first, y + directions[i].second, side[i]});	
		}
	}   
	

		
	if (ok) {
		while (!(ax == bx && ay == by)) { 
	 		ans += dir[bx][by];
	 		if (dir[bx][by] == 'R') by--; 
			else if (dir[bx][by] == 'L') by++;  
			else if (dir[bx][by] == 'U') bx++; 
			else if (dir[bx][by] == 'D') bx--;  
		} 
		reverse(ans.begin(), ans.end());
		cout <<  "YES" << endl;
		cout << ans.size() << endl;
		cout << ans << endl;
	} else {
		cout <<  "NO" << endl;
	}


}

