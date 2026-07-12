// Add 1 to a Linked List Number

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

    // //deconstructor
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

Node* reverseList(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

Node* addOne(Node* head){
    head = reverseList(head);

    Node* curr = head;
    int carry = 1;

    while(curr != NULL && carry){
        int sum = curr->data + carry;
        curr->data = sum % 10;
        carry = sum / 10;

        if(curr->next == NULL && carry){
            curr->next = new Node(0);
        }

        curr = curr->next;
    }

    head = reverseList(head);

    return head;
}

int main(){
    Node* node1 = new Node(4);
    node1->next = new Node(5);
    node1->next->next = new Node(6);

    cout << "List before addition of 1 : " << endl;
    printList(node1);

    addOne(node1);

    cout << "List after addition of 1 : " << endl;
    printList(node1);

    return 0;
}