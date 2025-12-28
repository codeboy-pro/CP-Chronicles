/*
Q1 Hossam and Combinatorics
.*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int minVal = *min_element(a.begin(), a.end());
    int maxVal = *max_element(a.begin(), a.end());
    
    if (minVal == maxVal) {
        long long ans = (long long)n * (n - 1);
        cout << ans << "\n";
        return;
    }
    
    long long minCount = count(a.begin(), a.end(), minVal);
    long long maxCount = count(a.begin(), a.end(), maxVal);
    
    long long ans = 2 * minCount * maxCount;
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}


//Time Complexity: O(n)
//Space Complexity: O(n)
/*
My submission : https://codeforces.com/contest/1771/submission/355468439
*/