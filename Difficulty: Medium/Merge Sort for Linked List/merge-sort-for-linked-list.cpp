/*
class Node {
public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* merge(Node* left,Node* right){
        Node *result=new Node(-1);
        Node *dummy=result;
        while(left!=NULL && right!=NULL)
        {
            if(left->data<=right->data)
            {
                dummy->next=left;
                left=left->next;
            }
            else
            {
                dummy->next=right;
                right=right->next;
            }
            dummy=dummy->next;
        }
        dummy->next=(left==NULL)?right:left;
        return result->next;
    }
    Node* findmid(Node* head)
    {
        Node* slow=head;
        Node* fast=head;
        while(fast->next&&fast->next->next) 
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    Node* mergeSort(Node* head) {
        // code here
         if(head==NULL||head->next==NULL){
            return head;
        }
        Node *mid=findmid(head);
        Node *temp=mid->next;
        mid->next=NULL;
        Node* left=mergeSort(head);
        Node* right=mergeSort(temp);
        return merge(left,right);
    }
};