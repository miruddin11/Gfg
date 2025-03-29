//{ Driver Code Starts
// Driver code
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


struct Job{
    int dead;
    int profit;
};
class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n = deadline.size();
        vector<Job> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = {deadline[i], profit[i]};
        }
        sort(arr.begin(), arr.end(), [](const Job& a, const Job& b) {
            return a.profit > b.profit;
        });
        int mx = 0;
        for (const auto& job : arr) {
            mx = max(mx, job.dead);
        }
        vector<int> slot(mx + 1, -1);
        int cnt = 0, totalProfit = 0;
        for (int i = 0; i < n; i++) {
            for (int j = arr[i].dead; j > 0; j--) {
                if (slot[j] == -1) {
                    slot[j] = i;
                    cnt++;
                    totalProfit += arr[i].profit;
                    break;
                }
            }
        }
        return {cnt, totalProfit};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> deadlines, profits;
        string temp;
        getline(cin, temp);
        int x;
        istringstream ss1(temp);
        while (ss1 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            profits.push_back(x);

        Solution obj;
        vector<int> ans = obj.jobSequencing(deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends