/*
Q2 Advertising Agency
.*/

#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
 
long long nCr(int n, int r) {
    if (r > n || r < 0) return 0;
    if (r == 0 || r == n) return 1;
    
    vector<vector<long long>> dp(n + 1, vector<long long>(r + 1, 0));
    
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= min(i, r); j++) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD;
        }
    }
    
    return dp[n][r];
}
 
void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end(), greater<int>());
    
    int kth_value = a[k - 1];
    int total_count = 0;
    int selected_count = 0;
    
    for (int i = 0; i < n; i++) {
        if (a[i] == kth_value) {
            total_count++;
            if (i < k) {
                selected_count++;
            }
        }
    }
    
    long long result = nCr(total_count, selected_count);
    cout << result << "\n";
}
 
int main() {
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}


//TC : O(n log n)
//SC : O(n²)
/*
My submission : https://codeforces.com/contest/1475/submission/355466435
*/