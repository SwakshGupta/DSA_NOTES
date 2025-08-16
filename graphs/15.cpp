/*

 Cheapest Flights Within K Stops

 here we cannot use the  dijkastras algorithm watch striver lecture to understand deeply 


*/

#include<iostream>
#include<queue>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        // Build adjacency list
        vector<vector<pair<int, int>>> adj(n);
        
        for(auto it : flights) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            adj[u].push_back({v, wt});
        }
        
        // Min-heap: { cost so far, current city, stops used so far }
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq; // greater<> tells the queue smallest element should come first 

/*

tuple<int, int, int> → (cost_so_far, current_city, stops_used)

vector<tuple<int, int, int>> // this means it is a vector three things 






*/
        pq.push({0, src, 0}); // cost 0, from src, 0 stops
        
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        
        while(!pq.empty()) {
            auto [cost, u, stops] = pq.top();
            pq.pop();
            
            if(u == dst) return cost;
            
            if(stops > k) continue;
            
            for(auto [v, wt] : adj[u]) {
                if(cost + wt < dist[v] || stops <= k) { // if the dist[v] is greater then update it and also update hte stop 
                    dist[v] = cost + wt;
                    pq.push({cost + wt, v, stops + 1}); // pushing the new object but with incremented stops
                }
            }
        }
        
        return -1;
    }
int main()
{




    return 0;
}