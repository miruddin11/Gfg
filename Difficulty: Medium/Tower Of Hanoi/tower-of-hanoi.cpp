//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    long long toh(int n, int from, int to, int aux) {
        // Your code here
        if(n==0) return 0;
        if(n==1){
            cout<<"move disk "<<n<<" from rod "<<from<<" to rod "<<to<<"\n";
            return 1;
        }
        
        long long count=toh(n-1,from,aux,to);
        
        cout<<"move disk "<<n<<" from rod "<<from<<" to rod "<<to<<"\n";
        count+=1;
        
        count+=toh(n-1,aux,to,from);
        
        return count;
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T; // testcases
    while (T--) {

        int N;
        cin >> N; // taking input N

        // calling toh() function
        Solution ob;

        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}

// } Driver Code Ends