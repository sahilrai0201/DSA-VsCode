//Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where 
//the sum of the node values in the path equals targetSum. Each path should be returned as a list 
//of the node values, not node references.
//A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a 
//node with no children.

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

void solve(Node* root, int targetSum, vector<int> &path, vector<vector<int>> &ans){
    if(root == NULL) return;

    path.push_back(root->data);

    //check at leaf node
    if(root->left == NULL && root->right == NULL){
        int sum = 0;
        for(int x : path){
            sum += x;
        }
        if(sum == targetSum){
            ans.push_back(path);
        }
    }

    solve(root->left, targetSum, path, ans);
    solve(root->right, targetSum, path, ans);

    path.pop_back();    //backtracking
}

vector<vector<int>> pathSum(Node* root, int targetSum){
    vector<vector<int>> ans;
    vector<int> path;

    solve(root, targetSum, path, ans);

    return ans;
}

int main(){
    cout << "Enter elements in preOrder (-1 for null) : " << endl;
    //8 4 3 3 -1 -1 -2 -1 -1 2 -1 1 -1 -1 5 -1 2 -1 -1

    Node* root = buildTree();

    int k;
    cout << "Enter target sum : " <<endl;
    cin >> k;

    vector<vector<int>> result = pathSum(root, k);
    cout << "Root-to-leaf paths where the sum of node values in the path equals k is : " << endl;
    for(auto path : result){
        for(auto x : path){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}