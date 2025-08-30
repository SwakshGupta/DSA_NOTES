/*
Insert a node in a binary search tree 

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

TreeNode*InsertElement(TreeNode*root,int val)
{

if(root==NULL)
{
    return new TreeNode(val); // if there is no value in the tree then create a node and return that node 
}

TreeNode*curr=root;

while(true)
{

if(curr->right->val<=val) // current right value is lesser than go to the right sided
{
 
if(curr->right==NULL) // if right side is null then insert a node there 
{
    curr->right=new TreeNode(val);
    break;
}
else
{
curr=curr->right;   
}

}
else
{

if(curr->left==NULL) // similarly do this for the left side 
{
    curr->left=new TreeNode(val);
    break;
}
else
{
    curr=curr->left;
}
}
return root;

}

}

};



int main()
{




    return 0;
}