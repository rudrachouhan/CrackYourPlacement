//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to find minimum number of pages.
    bool possible(int v[], long long mid, int member, int n){
    int cnt = 0;
    int running = 0;
    for(int i = 0; i < n; i++){
        running += v[i];
        
        if(running > mid){
            cnt++;
            running = v[i];
        }
    }
    return cnt >= member;
}
    long long findPages(int n, int arr[], int m) {
        long long start = INT_MIN, end = 0;
        if(n < m)
            return -1;
        for(int i = 0; i < n; i++){
            long long v = arr[i];
            start = max(start, v);
            end += v;
        }
        while(start <= end){
            long long mid = start + (end - start) / 2;
            if(possible(arr, mid, m, n))
                start = mid + 1;
            else
                end = mid - 1;
        }
        return start;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends