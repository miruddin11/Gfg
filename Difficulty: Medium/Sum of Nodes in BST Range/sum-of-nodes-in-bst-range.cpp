/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    long long totSum;
    void solve(Node *node,int l,int r){
        if(node==nullptr){
            return;
        }
        if(node->data>=l&&node->data<=r){
            totSum+=node->data;
        }
        solve(node->left,l,r);
        solve(node->right,l,r);
    }
    int nodeSum(Node* root, int l, int r) {
        // code here
        totSum=0;
        solve(root,l,r);
        return totSum;
    }
};
