//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

typedef long long ll;
vector<long long> printFirstNegativeInteger(long long int a[], long long int n, long long int k) {
    vector<ll> ans;
    deque<ll> dq;
    int i=0,j=0;
    while(j<n)
    {
        if(a[j]<0) dq.push_back(a[j]);
        
        if(j-i+1==k){
            if(!dq.empty()) ans.push_back(dq.front());
            else ans.push_back(0);
            
            if(a[i]<0&&!dq.empty()){
                dq.pop_front();
            }
            i++;
        }
        j++;
    }
    return ans;
 }