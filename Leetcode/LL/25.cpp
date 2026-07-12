// Reverse Nodes in k-Group : 

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    
    // constructor
    Node(int d){
        this->data = d;
        this->next = NULL;
    }

    // deconstructor
    ~Node(){
        int val = this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout << "Memory is free for node with data " << val << endl;
    }
};

void printList(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* reverseKGroups(Node* head, int k){
    // step1 : check if size of LL >= k
    Node* temp = head;
    int len = 0;
    while(temp != NULL && len < k){
        temp = temp->next;
        len++;
    }

    // step2 : base case
    if(len < k) return head;

    // step3 : reverse first k nodes
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    int count = 0;
    while(curr != NULL && count < k){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    // step4 : recursive part
    if(forward != NULL){
        head->next = reverseKGroups(forward, k);
    }

    // step5 : answer
    return prev;
}

int main(){
    Node* node1 = new Node(1);
    node1->next = new Node(2);
    node1->next->next = new Node(3);
    node1->next->next->next = new Node(4);
    node1->next->next->next->next = new Node(5);

    int k;
    cout << "Enter the size of groups : " << endl;
    cin >> k;

    cout << "Original List : " << endl;
    printList(node1);

    node1 = reverseKGroups(node1, k);

    cout << "Reversed List : " << endl;
    printList(node1);

    return 0;
}



// Output : 
// Enter the size of groups : 
// 2
// Original List : 
// 1 2 3 4 5 
// Reversed List : 
// 2 1 4 3 5 