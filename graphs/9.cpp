/*

Course Schedule 

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.






*/

#include<iostream>
#include<queue>
using namespace std;

bool isPossible(int N,vector<pair<int,int>>&pre)
{
vector<int>adj[N];
for(auto it:pre)
{
    adj[it.first].push_back(it.second); // since we were using pair that is why we were using .first and.second to figure out nodes
}




// now the code is same as the detection of cycle via topological sort 

int count=0;

 vector<int>indegree(N);

 for(int i=0; i<N; i++)
 {
    for(auto nbr:adj[i])
    {
        indegree[nbr]++;
    }
 }
   





// now 0 indegree valo ko queue mai push kar do 
queue<int>q;
for(int i=0; i<N; i++)
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
    count++;
    

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
if(count==N) return false; // if the top.size()== number of courses then return true (means no cycle is formed )

return true; // if not then return false 

}




int main()
{





    return 0;
}