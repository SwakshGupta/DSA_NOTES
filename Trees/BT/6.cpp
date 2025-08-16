/*
 Serialize and Deserialize Binary Tree

 Converting a tree into string and  deserialize means convering string into tree 

*/






#include<iostream>
#include<queue>
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

// Converting the tree into string 

string serialize(TreeNode*root)
{

if(!root)
return "";

string s="";
queue<TreeNode*>q;

q.push(root);

while(!q.empty())
{
TreeNode*temp=q.front();
q.pop();

if(temp==NULL)
{
    s.append("#,");
}
else
{
    s.append(to_string(temp->val)+",");
}
if(temp!=NULL)
{
    q.push(temp->left);
    q.push(temp->right);
}

}
}










}; // for code go to striver tree playlist 


int main()
{





    return 0;
}