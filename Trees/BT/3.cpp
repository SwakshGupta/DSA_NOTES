/*

L26. Print Root to Node Path in Binary Tree 



*/
#include<iostream>
using namespace std;

struct node
{
int val;
node*left;
node*right;

node( int data)
{
    val=data;
    left=NULL;
    right=NULL;
}

// get path function 



bool getPath(node*root,vector<int>&arr,int x) // we are using dfs here pushing the value into the vector and then calling left or right function 
{
if(root==NULL)
{
    return false;
}

arr.push_back(root->val);

if(root->val==x)
{
    return true;
}

if(getPath(root->left,arr,x) || getPath(root->right,arr,x))
{
    return true; // if any of the left or right path is returning true then we will return true 
}

arr.pop_back(); // if the element is not found then we will start backtracking 
return false;

}


vector<int>Solution(node*A,int target)
{
vector<int>arr;
if(A==NULL)
{
    return arr;
}
getPath(A,arr,target);
return arr;

}

};


int main()

{


    return 0;
}