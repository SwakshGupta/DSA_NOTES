/*
Constructing a binary search  tree using a preorder tranversal 



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
TreeNode*buidFromPreorder(vector<int>&A)
{
    int i=0; // pointer of the preorder index 

    return build(A,i,INT_MAX);
}


TreeNode*build(vector<int>&A,int &i,int bound)
{


if(i==A.size() || A[i]>bound)
return NULL;

TreeNode*root=new TreeNode(A[i++]);
root->left=build(A,i,root->val);  // this is the main part bound for left traversal is root-val

root->right=build(A,i,bound); //  for the right side the bound will remaint the same it changes only for the left part 
return root;

// the bound only changes for the left traversal and for the right traversal it remains the same 



}



};






int main()
{




    return 0;
}