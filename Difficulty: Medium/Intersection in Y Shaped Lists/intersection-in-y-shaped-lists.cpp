/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int getLen(Node* node){
        Node* temp=node;
        int len=0;
        while(temp!=nullptr){
            len+=1;
            temp=temp->next;
        }
        return len;
    }
    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
        int len1=getLen(head1);
        int len2=getLen(head2);
        int diff=abs(len1-len2);
        Node* temp1=head1;
        Node* temp2=head2;
        if(len1>len2){
            for(int i=0;i<diff;i++){
                temp1=temp1->next;
            }
        }
        else{
            for(int i=0;i<diff;i++){
                temp2=temp2->next;
            }
        }
        while(temp1!=nullptr && temp2!=nullptr){
            if(temp1==temp2){
                return temp1;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return nullptr;
    }
};