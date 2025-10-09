/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> ans;
    void solve(Node* root){
        if(!root){
            return;
        }
        solve(root->left);
        solve(root->right);
        ans.push_back(root->data);
    }
    vector<int> postOrder(Node* root) {
        // code here
        ans.clear();
        solve(root);
        return ans;
    }
};