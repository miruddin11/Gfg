//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
        if(k == 1) return head;
        
        Node* curr = head;
        Node* pre = nullptr;
        
        for(int i = 0; i < k && curr != nullptr; i++){
            Node* nxt = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nxt;
        }
        Node *start = head;
        head = pre;
        int cnt = 0;
        if(curr == nullptr) return head;
        pre = nullptr;
        Node* newSt = curr;
        
        while(curr != nullptr){
            if(cnt < k){
                cnt++;
                Node* nxt = curr->next;
                curr->next = pre;
                pre = curr;
                curr = nxt;
            }else{
                start->next = pre;
                start = newSt;
                newSt = curr;
                cnt = 0;
                pre = nullptr;
            }
        }
        
        start->next = pre;
        return head;
    }
};


//{ Driver Code Starts.

/* Driver program to test above function*/
int main(void) {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseKGroup(head, k);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends