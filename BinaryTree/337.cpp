//The thief has found himself a new place for his thievery again. 
//There is only one entrance to this area, called root.

//Besides the root, each house has one and only one parent house. After a tour, the smart thief 
//realized that all houses in this place form a binary tree. It will automatically contact the 
//police if two directly-linked houses were broken into on the same night.

//Given the root of the binary tree, return the maximum amount of money the thief can rob without 
//alerting the police.

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

Node* buildTree(){
    int data;
    cin >> data;

    if(data == -1) return NULL;

    Node* root = new Node(data);

    root->left = buildTree();
    root->right = buildTree();

    return root;
}

pair<int, int> solve(Node* root){
    if(root == NULL){
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    pair<int, int> result;

    result.first = root->data + left.second + right.second;
    result.second = max(left.first, left.second) + max(right.first, right.second);

    return result;
}

int robber(Node* root){
    pair<int, int> ans = solve(root);
    return max(ans.first, ans.second);
}

int main(){
    cout << "Enter elements in preOrder (-1 for null) : " << endl;
    //3 2 -1 3 -1 -1 3 -1 1 -1 -1
    //3 4 1 -1 -1 3 -1 -1 5 -1 1 -1 -1

    Node* root = buildTree();

    int finalAns = robber(root);
    cout << "the maximum amount of money the thief can rob without alerting the police is : " 
    << finalAns << endl;

    return 0;
}