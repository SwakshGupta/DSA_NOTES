/*
Number of Ways to Arrive at Destination

You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. 
The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections u
i and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.



Input: n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
Output: 4
Explanation: The shortest amount of time it takes to go from intersection 0 to intersection 6 is 7 minutes.
The four ways to get there in 7 minutes are:
- 0 ➝ 6
- 0 ➝ 4 ➝ 6
- 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
- 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6


*/

#include<iostream>
#include<queue>
using namespace std;


int countPaths(int n,vector<vector<int>>&roads)
{
vector<pair<int,int>>adj[n];
for(auto it:roads)
{
    adj[it[0]].push_back({it[1],it[2]});
    adj[it[1]].push_back({it[0],it[2]});

}

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
vector<int>dis(n,1e9);
vector<int>ways(n,0);

dis[0]=0;
ways[0]=1;

pq.push({0,0});
while(!pq.empty())
{
    int dist=pq.top().first;
    int node=pq.top().second;
    pq.pop();

    for(auto it:adj[node])
    {
        int node2=it.first;
        int dis2=it.second;

        if(dist+dis2<dis[node2]) // if distance is lesser than update the dis vector and ways node
        {
            dis[node2]=dist+dis2;
            pq.push({dist+dis2,node2});
            ways[node2]=ways[node]; 
        }
        else if(dist+dis2==dis[node2]) // if distance is equal then we only  need to increase the number of ways 
        {
            ways[node2]=ways[node2]+ways[node]; 
        }
    }
    return ways[n-1];
}






}


int main()
{



    return 0;
}