#include<bits/stdc++.h>
using namespace std; 

vector<int> parent; 
vector<int> set_size; 
unordered_set<int> disjoint_cities; 

void make_set(int a) {
	parent[a] = a; 
	set_size[a] = 1;
	disjoint_cities.insert(a);  
} 

int find_parent(int a) {
	if (a == parent[a]) return a; 
	return parent[a] = find_parent(parent[a]);
} 


void union_sets(int a, int b) {
	a = find_parent(a); 
	b = find_parent(b);  
	if (a != b) {
		if (set_size[a] < set_size[b]) swap(a, b);
		set_size[a] += set_size[b]; 
		parent[b] = parent[a];    
		disjoint_cities.erase(b); 
	} 

	return;

} 



int main() {
	int n, m; 
	cin >> n >> m;  
	
	parent.resize(n + 1, 0); 
	set_size.resize(n + 1, 0);

	for (int i = 1; i <= n; i++) make_set(i);	
	for (int i = 0; i < m; i++) {

		int u, v; 
		cin >> u >> v; 
		union_sets(u, v);
	} 
	
	int p_city = -1;
	cout << disjoint_cities.size() - 1 << endl;
	for (auto city: disjoint_cities) {
		if (p_city != -1) cout << p_city << ' ' << city << endl;  
		p_city = city;
	}	
}

