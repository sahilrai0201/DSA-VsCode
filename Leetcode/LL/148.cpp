// Given the head of a linked list, return the list after sorting it in ascending order.

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

Node* merge(Node* head1, Node* head2){
    Node* dummy = new Node(0);
    Node* tail = dummy;

    while(head1 && head2){
        if(head1->data <= head2->data){
            tail->next = head1;
            head1 = head1->next;
        }
        else{
            tail->next = head2;
            head2 = head2->next;
        }

        tail = tail->next;
    }

    tail->next = head1 ? head1 : head2;
    return dummy->next;
}

Node* sortList(Node* head){
    if(!head || !(head->next)) return head;

    //Find middle
    Node* slow = head;
    Node* fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    //split
    Node* mid = slow->next;
    slow->next = NULL;

    //sort both halves using recursion
    Node* left = sortList(head);
    Node* right = sortList(mid);

    //merge
    return merge(left, right);
}

int main(){
    //First list
    Node* node1 = new Node(-1);
    node1->next = new Node(5);
    node1->next->next = new Node(3);
    node1->next->next->next = new Node(4);
    node1->next->next->next->next = new Node(0);

    cout << "Original List : " << endl;
    printList(node1);

    Node* ans = sortList(node1);

    cout << "Final list after sorting : " << endl;
    printList(ans);

    return 0;
}