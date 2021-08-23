#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;


class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int d){
        val=d;
        left=NULL;
        right=NULL;
    }
};

//taking input data in which will reflect in tree
TreeNode* buildTree(){
    int d;
    cin>>d;

    if(d==-1){
        return NULL;
    }

    TreeNode* root=new TreeNode(d);
    root->left=buildTree();
    root->right=buildTree();

    return root;
}


//print the tree : Preorder ( Root -> left -> Right)
void print(TreeNode* root){
    if(root==NULL){
        return;
    }

    //otherwise, print root first followed by subtree.
    cout<<root->val<<" ";
    print(root->left);
    print(root->right);
}

class Solution {
public:
    vector<vector<int>>ans;
    void storePath(TreeNode*root,int targetSum,vector<int>&op){
        //Base case :
        if(root==NULL){
            return;
        }
        op.push_back(root->val);
        if(root->left==NULL and root->right==NULL and targetSum-root->val==0){
            ans.push_back(op);
            // op.clear();
            // return;
        }   
        // op.push_back(root->val);
        storePath(root->left,targetSum-root->val,op);
        storePath(root->right,targetSum-root->val,op);
        //Backtrack;
        op.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>op;
        
        storePath(root,targetSum,op);
        
        return ans;
    }
};


int main(){
    TreeNode* root=buildTree();

    print(root);
    cout<<endl;
    
    int targetSum;
    cout<<"Target Sum : ";
    cin>>targetSum;
    
    Solution s;
    vector<vector<int>>o = s.pathSum(root,targetSum);

    for(int i=0;i<o.size();i++){
        for(int j=0;j<o[i].size();j++){
            cout<<o[j]<<" ";
        }
        cout<<endl;
    }
}