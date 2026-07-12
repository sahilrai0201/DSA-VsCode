// Add Two Numbers

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    
    //constructor
    Node(int d){
        this->data = d;
        this->next = NULL;
    }

    //deconstructor
    // ~Node(){
    //     int val = this->data;
    //     if(this->next != NULL){
    //         delete next;
    //         next = NULL;
    //     }
    //     cout << "Memory is free for node with data " << val << endl;
    // }
};

void printList(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void insertAtTail(Node* &head, Node* &tail, int val){
    Node* temp = new Node(val);

    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
}

Node* addNumbers(Node* head1, Node* head2){
    int carry = 0;
    Node* ansHead = NULL;
    Node* ansTail = NULL;

    while(head1 != NULL || head2 != NULL || carry != 0){
        int val1 = 0;
        if(head1 != NULL) val1 = head1->data;

        int val2 = 0;
        if(head2 != NULL) val2 = head2->data;

        int sum = carry + val1 + val2;
        int digit = sum % 10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;

        if(head1 != NULL) head1 = head1->next;
        if(head2 != NULL) head2 = head2->next;
    }

    return ansHead;
}

int main(){
    //First list
    Node* node1 = new Node(2);
    node1->next = new Node(4);
    node1->next->next = new Node(3);

    cout << "First list : " << endl;
    printList(node1);

    //Second list
    Node* node2 = new Node(5);
    node2->next = new Node(6);
    node2->next->next = new Node(4);

    cout << "Second list : " << endl;
    printList(node2);

    Node* ans = addNumbers(node1, node2);

    cout << "Final list after addition : " << endl;
    printList(ans);

    return 0;
}