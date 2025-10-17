/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
  public:
    typedef long long ll;
    void solve(Node* root,ll &currSum){
        if(root==nullptr){
            return;
        }
        solve(root->right,currSum);
        ll value=root->data;
        root->data=currSum;
        currSum+=value;
        solve(root->left,currSum);
    }
    void transformTree(Node *root) {
        // code here
        ll currSum=0;
        solve(root,currSum);
    }
};