#include<bits/stdc++.h>
using namespace std; 


void weird_algo(long long int n) {
	cout << n << ' ';  
	if (n == 1) return; 
	else if (n % 2 == 0) weird_algo(n / 2); 
	else weird_algo(3 * n + 1); 
	return;
}
int main() {
	long long int n; 
	cin >> n; 
	weird_algo(n);
}
