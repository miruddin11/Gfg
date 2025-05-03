//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

// User function Template for C++

/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/

class Solution {
  public:
    bool isPrime(int value){
        if(value <= 1 ){
            return false;
        }
        for(int i = 2; i <= sqrt(value); i++){
            if(value%i == 0){
                return false;
            }
        }
        return true;
    }
    int findPrime(int value){
        int val1 = value;
        int val2 = value;
        while(true){
            if(val1 != 0){
                bool ans = isPrime(val1);
                if(ans == true){
                    return val1;
                }
                val1--;
            }
            if(val2 != 0){
                bool ans = isPrime(val2);
                if(ans == true){
                    return val2;
                }
                val2++;
            }
        }
        return -1;
    }
    Node *primeList(Node *head) {
        // code here
        Node* temp = head;
        while(temp != NULL){
            int value = temp->val;
            int ans = findPrime(value);
            temp->val = ans;
            temp = temp->next;
        }
        return head;
    }
};


//{ Driver Code Starts.

int main() {

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
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.primeList(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends