//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        vector<pair<int,int>> endtime;
        int n=finish.size();
        for(int i=0;i<n;i++){
            endtime.push_back({finish[i],start[i]});
        }
        sort(endtime.begin(),endtime.end());
        int lasttime=-1, count=0;
        for(int i=0;i<n;i++){
            if(lasttime==-1 || (i>0 && endtime[i].second>lasttime)){
                count++;
                lasttime=endtime[i].first;
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> start;
        int num;
        while (ss >> num)
            start.push_back(num);
        getline(cin, input);
        ss.clear();
        vector<int> finish;
        ss.str(input);
        while (ss >> num)
            finish.push_back(num);

        Solution obj;
        cout << obj.activitySelection(start, finish) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends