/*
MOrris traversal of the inorder 




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
vector<int>getInorder(TreeNode*root)
{

vector<int>inorder;
TreeNode*curr=root;

while(curr!=NULL)
{

if(curr->left==NULL) // this was our first case if left is null then push the current value in the vector and move teh curr pointer to the right 
{
    inorder.push_back(curr->val);
    curr=curr->right;
}

else
{
    TreeNode*prev=curr->left; // created a variable prev which is storing hte curr->left
    while(prev->right && prev->right!=curr)
    {
        prev=prev->right; // so for the left subtree we will move the prev pointer to the extreme right  
    }

if(prev->right==NULL) // if the extreme right is equal to NULL then we have to create a thread with curr level 
{
    prev->right=curr; // so we have created a thread here and then we will move the left pointer 
    curr=curr->left;
}
else
{ // if thread if already present then we have to remove that thread 

prev->right=NULL;  // we have removed the thread  pushed the current value to the  vector and then move the curr pointer to the right 
inorder.push_back(curr->val); 
curr=curr->right;
}

}


}


return inorder;



}


vector<int>getPreOrder(TreeNode*root)
{

vector<int>inorder;
TreeNode*curr=root;

while(curr!=NULL)
{

if(curr->left==NULL) // this was our first case if left is null then push the current value in the vector and move teh curr pointer to the right 
{
    inorder.push_back(curr->val);
    curr=curr->right;
}

else
{
    TreeNode*prev=curr->left; // created a variable prev which is storing hte curr->left
    while(prev->right && prev->right!=curr)
    {
        prev=prev->right; // so for the left subtree we will move the prev pointer to the extreme right  
    }

if(prev->right==NULL) 
{
    prev->right=curr; 
 
    inorder.push_back(curr->val);  // in preorder we will be pushing the element while creating a thread not while removing the thread  and this is the only difference 


    curr=curr->left;
}
else
{ // if thread if already present then we have to remove that thread 

prev->right=NULL;  // we have removed the thread  pushed the current value to the  vector and then move the curr pointer to the right 

curr=curr->right;
}

}


}


return inorder;



}





};



int main()
{





    return 0;
}