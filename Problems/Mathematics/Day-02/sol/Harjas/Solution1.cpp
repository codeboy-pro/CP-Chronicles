/*
Problem Statement:
Given size of array and elements. We need to find possible combination (i,j) of elements (i and j are positions in array)
size that the absolute difference is equal to absolute max difference from elements of array

Prefix Sums:
Not applicable since the problem is purely mathematical and does not involve
range queries or cumulative sums.

Time Complexity: O(n)
Space Complexity: O(n)

Submission Link:
https://codeforces.com/contest/1771/submission/355453765
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >>t;
    while(t--){

int n;
cin>>n;
vector <int> a(n);
for(int &x: a) cin>> x;

int smallestNum= INT_MAX;
int largestNum=INT_MIN;
int counts =0;
int countl=0;
for(int i=0;i<n;i++){
    if(a[i]<smallestNum){ 
        smallestNum=a[i];     // scanning through array once to find number of times max and min element appears
        counts=0;
    }
     if(a[i]>largestNum){ 
        largestNum=a[i];
        countl=0;
    }

    if(a[i]==smallestNum) counts++;
    
    if(a[i]==largestNum) countl++;
}
if (smallestNum == largestNum) {
    cout << 1LL* n * (n - 1) << endl; //edge case when all elements are equal
} else {
    cout << 2LL* counts * countl << endl;    // final answer uses long long because n can be large so n^2 crosses max of int
}






    }
    return 0;
}