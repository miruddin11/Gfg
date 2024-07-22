//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

struct child
{
    int size;
    int min;
    int max;
    int isBst;
    int ans;
};
class Solution{
    public:
    child dfs(Node* root)
    {
        if(root == NULL)
        {
            return {0,INT_MAX,INT_MIN,1,0};
        }
        child l = dfs(root->left);
        child r = dfs(root->right);
        
        if(l.isBst && l.max < root->data && r.isBst && r.min > root->data)
        {
            child node;
            node.size = l.size + r.size + 1;
            node.isBst = 1;
            node.min = min({l.min,r.min,root->data});
            node.max = max({l.max,r.max,root->data});
            node.ans = node.size;
            return node;
        }
        child node;
        node.size = l.size + r.size + 1;  
        node.isBst = 0;
        node.min = min({l.min, r.min, root->data});  
        node.max = max({l.max, r.max, root->data});
        node.ans = max(l.ans, r.ans);  
        return node;

    }
    int largestBst(Node *root)
    {
        return dfs(root).ans;
    }
};




//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}

// } Driver Code Ends