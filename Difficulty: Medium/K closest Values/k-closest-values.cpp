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
    void solve(Node* root,int target,vector<pair<int,int>> &a){
        if(root==nullptr){
            return;
        }
        int diff=abs(root->data-target);
        a.push_back({diff,root->data});
        solve(root->left,target,a);
        solve(root->right,target,a);
    }
    vector<int> getKClosest(Node* root, int target, int k) {
        // code here
        vector<pair<int,int>> a;
        solve(root,target,a);
        sort(a.begin(),a.end());
        vector<int> ans;
        int cnt=0;
        for(auto &it:a){
            if(cnt>=k){
                break;
            }
            ans.push_back(it.second);
            cnt+=1;
        }
        return ans;
    }
};