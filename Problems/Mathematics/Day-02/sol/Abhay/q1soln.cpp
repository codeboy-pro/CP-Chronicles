/*
The problem relies permutations between the max and min elements, and a (i,j) and(j,i) being unique.
The special case is when the entire array is the same. then we simply needed to use nC2*2!. 

Time complexity- O(nlogn)
Sorting is not needed, but makes implementaion easier.
Submission link- https://codeforces.com/contest/1771/submission/355301277
*/
    #include <bits/stdc++.h>
    using namespace std;
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
     int t;
        cin >> t;
       
        while (t--) {
            int n;
            cin>>n;
            vector<int>arr(n);
            for(int i=0;i<n;i++)
            {
                cin>>arr[i];
            }
            sort(arr.begin(),arr.end());
            long long  mincount=0;
            long long  maxcount=0;
            for(int i=0;i<n;i++)
            {
                if(arr[i]==arr[0])
                mincount++;
                if(arr[i]==arr[n-1])
                maxcount++;
            }
            long long a;
           a=2LL*mincount*maxcount;
            if(arr[0]==arr[n-1])
            { a=1LL*(n-1)*(n);
                
                
            cout<<a<<endl;
            }
            else
            cout<<a<<endl;
        }
        return 0;
    }
     
