//Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

// Function to build tree using preorder input
Node* buildTree(){
    int data;
    cin >> data;

    if(data == -1) return NULL;

    Node* root = new Node(data);

    root->left = buildTree();
    root->right = buildTree();

    return root;
}

//LCA function
Node* lca(Node* root, int p, int q){
    //base case
    if(root == NULL) return NULL;

    if(root->data == p || root->data == q){
        return root;
    }

    Node* leftAns = lca(root->left, p, q);
    Node* rightAns = lca(root->right, p, q);

    if(leftAns != NULL && rightAns != NULL){
        return root;
    }
    else if(leftAns != NULL && rightAns == NULL){
        return leftAns;
    }
    else if(leftAns == NULL && rightAns != NULL){
        return rightAns;
    }
    else{
        return NULL;        //leftAns = rightAns = NULL
    }
}

int main(){
    cout << "Enter tree nodes in preOrder (-1 for null) : " << endl;
    //5 4 7 -1 -1 8 -1 9 -1 -1 3 22 -1 -1 27 29 -1 -1 -1

    Node* root = buildTree();

    int p, q;
    cout << "Enter two nodes: ";
    cin >> p >> q;

    Node* result = lca(root, p, q);

    if(result != NULL){
        cout << "Lowest common ancestor : " << result->data << endl;
    }
    else{
        cout << "LCA not found!" << endl;
    }

    return 0;
}

// int main(){
//     Node* root = new Node(5);

//     root->left = new Node(4);
//     root->right = new Node(3);

//     root->left->left = new Node(7);
//     root->left->right = new Node(8);

//     root->left->right->right = new Node(9);

//     root->right->left = new Node(22);
//     root->right->right = new Node(27);

//     root->right->right->left = new Node(29);

//     int p = 8;
//     int q = 27;

//     Node* result = lca(root, p, q);
//     cout << "lowest common ancestor of the given tree is : " << result->data << endl;

//     return 0;
// }