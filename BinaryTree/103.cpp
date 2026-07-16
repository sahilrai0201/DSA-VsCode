//Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. 
//(i.e. from left to right, then right to left for the next level and alternate between).

#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector<int> zigzagLevelOrder(TreeNode* root){
    vector<int> result;
    if(root == NULL) return result;

    queue<TreeNode*> q;
    q.push(root);

    bool leftToRight = true;

    while(!q.empty()){
        int size = q.size();
        vector<int> ans(size);

        //level process
        for(int i=0; i<size; i++){
            TreeNode* frontNode = q.front();
            q.pop();

            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontNode->data;

            if(frontNode->left) q.push(frontNode->left);
            if(frontNode->right) q.push(frontNode->right);
        }
        //direction change
        leftToRight = !leftToRight;

        for(auto i : ans){
            result.push_back(i);
        }
    }
    return result;
}

int main(){
    //creating tree
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> result = zigzagLevelOrder(root);

    cout << "ZigZag Traversal: ";
    for(int i : result){
        cout << i << " ";
    }

    return 0;
}