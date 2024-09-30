#include<bits/stdc++.h>
using namespace std; 

vector<int> parent; 
vector<int> set_rank; 
vector<int> set_size; 

int components = 0; 
int max_size = 1; 

void make_set(int v) {
	parent[v] = v; 
	set_size[v] = 1; 
	set_rank[v] = 0; // optional, for union by rank (depth of the tree) 
} 

int find_set(int v) {
	if (v == parent[v]) return v; 
	return parent[v] = find_set(parent[v]);
} 

void union_sets(int a, int b) {
	a = find_set(a); 
	b = find_set(b); 
	if (a != b) {
		set_size[a] += set_size[b]; 
		parent[b] = parent[a];
		max_size = max(set_size[a], max_size); 
		components--;
		/*
		* Union by rank
		* if (rank[a] < rank[b]) swap(a,b); 
		* if(rank[a] == rank[b]) rank[a]++; 
		* parent[b] = a;
		*/
	}
} 




int main() {
	int n, m; 

	cin >> n >> m; 

	set_size.resize(n + 1, 0); 
	parent.resize(n + 1, 0); 
	set_rank.resize(n + 1, 0); 



	for (int i = 1; i <= n; i++) {
		components++; 
		make_set(i);
	}

	vector<pair<int,int>> roads; 


	for (int i = 0; i < m; i++) {
		int u, v; 
		cin >> u >> v;  
		roads.push_back({u, v}); 
		union_sets(u, v); 
		cout << components << ' ' << max_size << endl;
	}  

}
