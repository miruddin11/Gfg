/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> nodes;
    void solve(Node* root){
        if(root==nullptr){
            return;
        }
        solve(root->left);
        nodes.push_back(root->data);
        solve(root->right);
    }
    int findMedian(Node* root) {
        // Code here
        nodes.clear();
        solve(root);
        int n=nodes.size();
        if(n%2==0){
            return nodes[(n/2)-1];
        }
        else{
            return nodes[(n-1)/2];
        }
    }
};