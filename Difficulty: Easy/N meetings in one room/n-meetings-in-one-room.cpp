//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    static bool compare(pair<int,int>&a,pair<int,int>&b){
        if(a.second==b.second)
          return a.first<b.first;
        else
          return a.second<b.second;
    }
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({start[i],end[i]});
        }
        sort(v.begin(),v.end(),compare);
        int LastendTime=v[0].second;
        int cnt=1;
        for(int i=1;i<n;i++)
        {
            if(LastendTime<v[i].first){
                cnt+=1;
                LastendTime=v[i].second;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends