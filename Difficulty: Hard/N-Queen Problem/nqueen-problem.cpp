//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>> ans;
    void addBoard(vector<vector<char>> &board)
    {
        vector<int> temp;
        for(int j=0;j<board[0].size();j++)
        {
            for(int i=0;i<board.size();i++)
            {
                if(board[i][j]=='Q'){
                    temp.push_back(i+1);
                    break;
                }
            }
        }
        ans.push_back(temp);
    }
    bool isValid(vector<vector<char>> &board,int row,int col)
    {
        //vertical up
        for(int i=row-1;i>=0;i--)
        {
            if(board[i][col]=='Q')
            return false;
        }
        //diag up left
        for(int i=row-1,j=col-1;j>=0 && i>=0;j--,i--)
        {
            if(board[i][j]=='Q')
            return false;
        }
        //diag up right
        for(int i=row-1,j=col+1;j<board.size() && i>=0;i--,j++)
        {
            if(board[i][j]=='Q')
            return false;
        }
        return true;
    }
    void solve(vector<vector<char>> &board,int i)
    {
        if(i==board.size()){
            addBoard(board);
            return;
        }
        for(int j=0;j<board[0].size();j++)
        {
            if(isValid(board,i,j)){
                board[i][j]='Q';
                solve(board,i+1);
                board[i][j]='X';
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        if(n==1){
            return {{1}};
        }
        vector<vector<char>> board(n,vector<char>(n,'X'));
        ans.clear();
        solve(board,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends