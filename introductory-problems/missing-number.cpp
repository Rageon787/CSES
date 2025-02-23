#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int nsum = (n * (n + 1)) / 2;  // sum of first N natural numbers
    int sum = 0;  // variable to store the sum of the input values
    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        sum += x;
    }

    // the missing value will be the different between nsum and sum
    cout << nsum - sum << endl;
}
