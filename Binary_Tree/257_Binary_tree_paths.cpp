/*

8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
8 10 1 6 9 7 3 14 13 
8->10->1
8->10->6->9
8->10->6->7
8->3->14->13

*/



#include<iostream>
#include<string>
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

    vector<string>ans;
    void storePath(TreeNode*root,string op){

        if(root->left==NULL and root->right==NULL){
            op+=to_string(root->val);      
            ans.push_back(op);
            return;
        }
        op+=to_string(root->val);      
        op+="->";
        if(root->left){
            storePath(root->left,op);
        }
        if(root->right){
            storePath(root->right,op);
        }
    }
public:    
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL){
            return ans;
        }
        storePath(root,"");
        return ans;            
    }
};

int main(){
    TreeNode* root=buildTree();

    print(root);
    cout<<endl;
    Solution o;
    vector<string>S=o.binaryTreePaths(root);

    for(int i=0;i<S.size();i++){
        cout<<S[i]<<endl;
    }

}