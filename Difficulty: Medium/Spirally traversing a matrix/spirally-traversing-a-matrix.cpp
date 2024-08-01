//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        vector<int> ans;
        int n=matrix.size(),m=matrix[0].size();
        int startRow=0,startCol=0,endRow=n-1,endCol=m-1;
        while(startRow<=endRow&&startCol<=endCol)
        {
            for(int j=startCol;j<=endCol;j++){
                ans.push_back(matrix[startRow][j]);
            }
            for(int i=startRow+1;i<=endRow;i++){
                ans.push_back(matrix[i][endCol]);
            }
            if(startRow!=endRow){
                for(int j=endCol-1;j>=startCol;j--){
                    ans.push_back(matrix[endRow][j]);
                }
            }
            if(startCol!=endCol){
                for(int i=endRow-1;i>startRow;i--){
                    ans.push_back(matrix[i][startCol]);
                }
            }
            startRow++;
            endRow--;
            startCol++;
            endCol--;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends