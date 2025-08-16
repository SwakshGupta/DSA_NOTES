/*
Inorder sucessor - Element which is ust greater than the given element 


*/



#include<iostream>
using namespace std;

struct TreeNode
{
int val;
TreeNode*left;
TreeNode*right;

TreeNode( int data)
{
    val=data;
    left=NULL;
    right=NULL;
}

TreeNode*inOrderSucc(TreeNode*root,TreeNode*target) // if the targetvalue is greater than we will move to the rigth part of binary tree 
{

TreeNode*succ=NULL;

if(target->val>=root->val)
{
    root=root->right;
}
else // root>target
{
    succ=root; // we will store the value the succ cuz this value could  be the successor
    root=root->left;

}
return succ;

}

};



int main()
{



    return 0;
}