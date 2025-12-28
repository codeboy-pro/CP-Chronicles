/*
DAY 1
Q1 Who's Opposite?
.*/

typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
       ll a, b, c;
        cin >> a >> b >> c;

        ll diff = abs(a - b);
        ll n = 2 * diff;

        if (diff==0 || max({a,b,c})> n){
            cout << -1 << endl;
        } else {
            ll d = c + diff;
            if (d > n) d -= n;
            cout << d << endl;
    }
    }
  return 0;
}
/*
My submission : https://codeforces.com/contest/1560/submission/355307599
*/