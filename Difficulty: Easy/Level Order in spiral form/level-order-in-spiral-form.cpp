//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    return new Node(val);
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after splitting by space
    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

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
        if (i >= ip.size())
            break;
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

/* A binary tree node has data, pointer to left child
   and a pointer to right child
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */
class Solution {
  public:
    vector<int> findSpiral(Node* root) {
        // code here
        int level=0;
        queue<Node*> q;
        q.push(root);
        vector<int> vec;
        while(!q.empty()){
            int n= q.size();
            for(int i=0; i<n; i++){
                Node* temp= q.front();
                q.pop();
                vec.push_back(temp->data);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(level %2 ==0) reverse(vec.end()-n, vec.end());
            level++;
        }
        return vec;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    Solution sol; // Create Solution object
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        // Call the findSpiral function from Solution class
        vector<int> vec = sol.findSpiral(root);
        for (int x : vec)
            cout << x << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends