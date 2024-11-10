//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
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
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution {

  public:
    unordered_map<Node*,Node*> mp; // child , parent
    Node *t;
    int x;
    void inorder(Node *root)
    {
        if(!root) return;
        if(root->data==x) t=root;
        if(root->left) mp[root->left]=root;
        inorder(root->left);
        if(root->right) mp[root->right]=root;
        inorder(root->right);
    }
    vector<int> KDistanceNodes(Node* root, int target, int k) {
        // return the sorted vector of all nodes at k dist
        mp.clear();
        x=target;
        t=NULL;
        inorder(root);
        queue<Node*> q;
        q.push(t);
        unordered_set<Node*> vis;
        vis.insert(t);
        int level=0;
        while(!q.empty())
        {
            int size=q.size();
            if(level==k){
                break;
            }
            while(size--)
            {
                Node* node=q.front();
                q.pop();
                if(node->left&&vis.count(node->left)==0){
                    q.push(node->left);
                    vis.insert(node->left);
                }
                if(node->right&&vis.count(node->right)==0){
                    q.push(node->right);
                    vis.insert(node->right);
                }
                if(mp.find(node)!=mp.end()&&vis.count(mp[node])==0){
                    q.push(mp[node]);
                    vis.insert(mp[node]);
                }
            }
            level++;
        }
        vector<int> ans;
        while(!q.empty())
        {
            ans.push_back(q.front()->data);
            q.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    getchar();

    Solution x = Solution();

    while (t--) {
        string s;
        getline(cin, s);
        Node* head = buildTree(s);

        int target, k;
        cin >> target >> k;
        getchar();

        vector<int> res = x.KDistanceNodes(head, target, k);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends