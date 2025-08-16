/*
947. Most Stones Removed with Same Row or Column

On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.


ans=totalnumberfoStones-number of components





*/

#include<iostream>
#include<unordered_set>
using namespace std;


int findParent(int node,vector<int>&parent)
{
    if(node==parent[node])
    return node;

    return parent[node]=findParent(parent[node],parent);
}

void unionByRank(int u,int v,vector<int>&parent,vector<int>&rank)
{
int pu=findParent(u,parent);
int pv=findParent(v,parent);

if(rank[pu]>rank[pv])
{
    parent[pv]=pu;
    
}
else if(rank[pu]<rank[pv])
{
    parent[pu]=pv;   
}
else
{
    parent[pu]=pv;
    rank[pv]++;
}
}
// the above are basic functions for dsu

/*
due to {0,0} present in stones  we can't just direcly  u=0 and v=0 dsu will consider that as a single node

instead we will find max rows and max colun and 

total size=maxRows+maxCOlumn+2


for column and rows element not to become equal we will start column counting after rows 

[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]

so 0,1,2 represent the row

and  v=it[1]+maxRow+1; represent the column 

*/ 




    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxRow=0;
        int maxCol=0;

        for (auto &s : stones) {
            maxRow = max(maxRow, s[0]);
            maxCol = max(maxCol, s[1]);
        }

        int TotalSize=maxRow+maxCol+2;

        vector<int>rank(TotalSize,0);
        vector<int>parent(TotalSize);

        for(int i=0; i<TotalSize; i++)
        {
            parent[i]=i;
        }
        
        for(auto it:stones)
        {
            int u=it[0];
            int v=it[1]+maxRow+1;// is done such that the row and column elements does not become equal

            unionByRank(u,v,parent,rank);
        }
        unordered_set<int>uniqueParent;
        int components=0;

        for(auto it:stones)
        {
            uniqueParent.insert(findParent(it[0],parent));
        }
        
        components=uniqueParent.size();


        return n-components;
    }

int main()
{




    return 0;
} 