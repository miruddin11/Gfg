//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

/* matrix : given input matrix, you are require
 to change it in place without using extra space */
void rotate(vector<vector<int> >& matrix) {
    // Your code goes here
    int i,j,k;
    int n=matrix.size();
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            swap(matrix[i][j],matrix[j][i]);
            
        }
    }
    //swap the columns 
    for(i=0;i<n;i++)
    {
        for(j=0,k=n-1;j<n/2;j++,k--)
        {
            swap(matrix[i][j],matrix[i][k]);
            
        }
    }
}


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > matrix(n);
        for (int i = 0; i < n; i++) {
            matrix[i].resize(n);
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; j++)
                cout << matrix[i][j] << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends