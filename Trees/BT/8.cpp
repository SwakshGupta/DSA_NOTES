/*
Print all the nodes at distace k from the root node 


we arrdoing three thigns here 

1. Creating a parent child mapping so that we can check the parent 

2. We are doing level order Traversal BFS in short by putting elements in the queue and then using for loop 

3. Then we will create a visited array to check for the left right and parent nodes if they are visited mark true

4. we will create a current level varibale if it is equal to k then we will break the loop

5. At the end we will b having those nodes in the queue which are at the k distance 



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

void mapping(TreeNode*root,unordered_map<TreeNode*,TreeNode*>map) // created parent child mapping 
{
queue<TreeNode*>q;

q.push(root);

while(!q.empty())
{
TreeNode*top=q.front();
q.pop();

if(top->left)
{
    map[top->left]=top;
}

else if(top->right)
{
    map[top->right]=top;
}
}
}

vector<TreeNode*>distance(TreeNode*root,TreeNode*target,int k)
{

    unordered_map<TreeNode*,TreeNode*>map;
    queue<TreeNode*>q;
    unordered_map<TreeNode*,bool>vis;
    vector<TreeNode*>result;

   mapping(root,map);
   int currentLevel=0;
   q.push(target);
   vis[target]=true;


   while(!q.empty())
   {


if(currentLevel==k)
break;


    int n=q.size();

    for(int i=0; i<n; i++)
    {
        TreeNode*top=q.front();
        q.pop();

        if(top->left && !vis[top->left]) // if any of the element are not visited then push it into the queue 
        {
            vis[top->left]=true;
            q.push(top->left);
        }

        if(top->right && !vis[top->right])
        {
            vis[top->right]=true;
            q.push(top->right);
        }

        if(map.find(top)!=map.end() && !vis[top])
        {
            q.push(top);
            vis[top]=true;

        }
    }
   }

while(!q.empty()) // now queue is having those elements which are at k distance 
{
    TreeNode*front=q.front();
    result.push_back(front);
    q.pop();
}


return result;
}

};
int main()
{




    return 0;
}