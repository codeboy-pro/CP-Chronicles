#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    for(auto &x : a) cin >> x;

    /*
        We need for each i:
            nearest index j < i such that a[j] < a[i]
            if no such j exists → print 0

        Efficient approach:
        ------------------
        Use a MONOTONIC STACK that stores elements in increasing order.
        But instead of storing values, we store INDEXES.

        Why it works:
        - For each element a[i], we pop all elements >= a[i]
          because they cannot be answer for this or any future element.
        - The element remaining on top of stack (if any) is the nearest
          smaller to the LEFT.
        - Then push current index i into stack.

        Total complexity O(n) because every index is pushed and popped at most once.
    */

    vector<int> ans(n);
    stack<int> st;   // stores indices, maintaining increasing values

    for(int i = 0; i < n; i++){

        // remove all elements >= current value
        while(!st.empty() && a[st.top()] >= a[i])
            st.pop();

        // if stack empty → no smaller element to left
        if(st.empty())
            ans[i] = 0;
        else
            ans[i] = st.top() + 1; // +1 for 1-based index output

        // push current index
        st.push(i);
    }

    // print answer
    for(int x : ans)
        cout << x << " ";
}


// Submission Link: https://cses.fi/problemset/result/15787089/