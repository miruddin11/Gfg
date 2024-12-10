//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        // code here
        auto comp=[&](auto &a,auto &b){
            return a[1]<b[1];
        };
        sort(intervals.begin(),intervals.end(),comp);
        int cnt=0;
        int last=0;
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<intervals[last][1]){
                cnt+=1;
            }
            else{
                last=i;
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
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(intervals) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends