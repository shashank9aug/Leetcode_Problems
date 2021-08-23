/*
    PS : given BT and targetsum  we have to find if their is any path exist in BT or not whose
    sum results into targetsum or not.
        
        -------Path must be from root to leaf----------
    
    Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1]
    targetSum = 22
    Output: true 

8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
19
1

*/

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

//taking input data in which will reflect in tree
node *buildTree()
{
    int d;
    cin >> d;

    if (d == -1)
    {
        return NULL;
    }

    node *root = new node(d);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

bool hasPathSum(node *root, int targetSum)
{
    //Base case :
    if (root == NULL)
    {
        return false;
    }
    if (root->left == NULL and root->right == NULL and targetSum - root->data == 0)
    {
        return true;
    }

    bool left = hasPathSum(root->left, targetSum - root->data);
    bool right = hasPathSum(root->right, targetSum - root->data);

    return left or right;
}

int main()
{
    node *root = buildTree();

    int targetSum;

    cin >> targetSum;
    int sum = 0;
    cout << hasPathSum(root, targetSum) << endl;
}