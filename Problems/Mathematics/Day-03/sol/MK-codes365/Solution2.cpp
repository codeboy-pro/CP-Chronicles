/*
SHORT PROBLEM STATEMENT: 
We need to find the minimum number of 1-ohm resistors to get a resistance of a/b.
Resistors can be connected in series or parallel.

APPROACH USING PREFIX SUMS: 
Not applicable here as it's a math/GCD based problem.
The logic is basiclly like the Euclidean algorithm. If we have to reach a/b, 
we keep taking the floor part (x/y) as series resistors and then 
calculate the remainder and swap to simulate the parallel recipricol logic.

TIME & SPACE COMPLEXITY:
Time: O(log(min(a, b)))
Space: O(1)

SUBMISSION LINK: https://codeforces.com/contest/343/submission/355457508 
*/


#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll x, y;
    if (!(cin >> x >> y)) return 0;

    ll count = 0;

    while (y > 0) {
        count += (x / y);
        x %= y;
        swap(x, y);
    }

    cout << count << "\n";

    return 0;
}
