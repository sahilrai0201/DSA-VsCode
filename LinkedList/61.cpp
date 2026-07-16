// Rotate a List

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
};

void printList(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* rotateList(Node* head, int k){
    if(head == NULL || head->next == NULL || k == 0) return head;

    // step1 : find length & last node
    Node* temp = head;
    int n = 1;
    while(temp->next != NULL){
        temp = temp->next;
        n++;
    }

    // step2 : reduce k
    k = k % n;
    if(k == 0) return head;    // No rotation required

    // step3 : make circular
    temp->next = head;

    // step4 : find new tail
    int steps = n-k;
    Node* newTail = head;
    for(int i=1; i<steps; i++){
        newTail = newTail->next;
    }

    // step5 : break circle
    Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

int main(){
    Node* node1 = new Node(1);
    node1->next = new Node(2);
    node1->next->next = new Node(3);
    node1->next->next->next = new Node(4);
    node1->next->next->next->next = new Node(5);

    int k;
    cout << "Enter the k that is the number of rotation : " << endl;
    cin >> k;

    cout << "Original List : " << endl;
    printList(node1);

    node1 = rotateList(node1, k);

    cout << "List after rotation : " << endl;
    printList(node1);

    return 0;
}