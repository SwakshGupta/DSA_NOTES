/*
Topological sort using kahn algorithm(or using BFS algorithm)

1. Here we will be using the indegree and queue to solve the answer  we will push those nodes into queue whose indegree
is zero and then repeat the process using BFS

explanation is there in the notebook 

*/

#include<iostream>
#include<queue>
#include<unordered_map>
#include<list>
using namespace std;

vector<int>topologicalSort(vector<vector<int>>&edges,int v,int e)
{
    // create the adj list
    unordered_map<int,list<int> >adj;

    for(int i=0; i<e; i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
    }

    // find all the indegrees

    vector<int>indegree(v);
    for(auto i:adj)
    {
        for(auto j:i.second) //  j=i.second (all the nodes adjacent to i)
        {
            indegree[j]++; // increase the indegree ot j
        }
    }
// now 0 indegree valo ko queue mai push kar do 
queue<int>q;
for(int i=0; i<v; i++)
{
    if(indegree[i]==0)
    {
        q.push(i); // pushed the root node into the queue since it has indegree equal to  0
    }
}
// now do BFS
vector<int>ans;
while(!q.empty())
{
    int front=q.front();
    q.pop();
    ans.push_back(front);

// here we update the indegree
for(auto neighbour:adj[front])
{
    indegree[neighbour]--;  // so we will decrease the indegree of the neighbour 
    if(indegree[neighbour]==0) // if the indegree of nbd is equal to zero then we will push the neightbour 
    {
        q.push(neighbour);
    }
}

}
return ans;


}
/*
if the adjoint list is directly given to us then we can directly form the indegree

vector<int>top(vector<int>adj[],int v)
{

for(int i=0; i<V; i++)
{
    for(auto nbr:adj[i])
    {
        indegre[nbr]++;
    }
}




}


*/









int main()
{




    return 0;
}/*

vector<int>topSort(vector<vector<int>>&edges,int v,int e)
{
// here i will write the code for the topological sort

1. Create the inodrder matrix and make a queue
2. node which have zero inorder push them into the queue
3. do the level order traversal now push the node which have zero node into the queue 


}

vector<int<list<int>>>adj;

for(int i=0; i<e; i++)
{
    int u=edge[i][0];
    int v=edge[i][1];

    adj[u].push_back(v);
}

vector<int>indegree(v);

for(auto i:adj)
{
    for(auto j:i.second)
    {
        indegree[j]++;
    }
}

for(int i=0; i<n; i++)
{
    if(indegree[i]==0)
    {
        q.push(i);
    }
}

while(!q.empty())
{
int node=q.front();
ans.push_back(node);
q.pop();

for(auto nbr:adj[node])
{

indegree[nbr]--;
if(indegree[nbr]==0)
{
    q.push(nbr);
}


}
return ans;

}



*/