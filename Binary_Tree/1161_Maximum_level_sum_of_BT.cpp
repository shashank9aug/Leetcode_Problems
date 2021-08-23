/*

Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
---------------------------------------------------------------
* return the level with the maximum sum which is level 2 * 
---------------------------------------------------------------

$ ./a.exe
8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
8 10 1 6 9 7 3 14 13 
4

*/

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
    //Iterative approach of Level order Traversal
    void levelOrder(TreeNode *root,vector<vector<int>>&ans)
    {

        if (root == NULL)
            return;

        //queue will store node
        queue<TreeNode *> q;

        q.push(root);
        while (!q.empty())
        {
            int n = q.size();

            vector<int> v(n, 0);
            for (int i = 0; i < n; i++)
            {
                TreeNode *f = q.front();
                v[i] = f->val;

                q.pop();

                //check for left node :
                if (f->left)
                {
                    q.push(f->left);
                }   

                //check for right node :
                if (f->right)
                {
                    q.push(f->right);
                }
            }
            ans.push_back(v);
        }
    }
public:
    int maxLevelSum(TreeNode* root) {
        vector<vector<int>>ans;
        levelOrder(root,ans);
        
        int idx=0;
        int maxSum=INT_MIN;
        for(int i=0;i<ans.size();i++){
            int sum=0;
            for(int j=0;j<ans[i].size();j++){
                sum+=ans[i][j];
            }
            if(maxSum<sum){
                maxSum=sum;
                idx=i+1;
            }
        }
        return idx;
    }
};


int main(){
    TreeNode* root=buildTree();

    print(root);
    cout<<endl;
    Solution s;
    cout<<s.maxLevelSum(root)<<endl;
}