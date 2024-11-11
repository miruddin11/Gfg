//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    unordered_map<Node*,Node*> par;
    int t;
    Node *start;
    void solve(Node* root)
    {
        if(!root) return;
        if(root->data==t){
            start=root;
        }
        if(root->left) par[root->left]=root;
        solve(root->left);
        if(root->right) par[root->right]=root;
        solve(root->right);
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        t=target;
        start=NULL;
        solve(root);
        queue<Node*> q;
        q.push(start);
        unordered_set<Node*> vis;
        vis.insert(start);
        int level=0;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                Node* curr=q.front();
                q.pop();
                if(curr->left&&vis.count(curr->left)==0){
                    q.push(curr->left);
                    vis.insert(curr->left);
                }
                if(curr->right&&vis.count(curr->right)==0){
                    q.push(curr->right);
                    vis.insert(curr->right);
                }
                if(par.find(curr)!=par.end()&&vis.count(par[curr])==0)
                {
                    q.push(par[curr]);
                    vis.insert(par[curr]);
                }
            }
            level++;
        }
        return level-1;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    
cout << "~" << "\n";
}


    return 0;
}

// } Driver Code Ends