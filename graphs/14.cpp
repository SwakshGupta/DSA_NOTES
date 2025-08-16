
/*


You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns,
 where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), 
 and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.


Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.



max heap where the parent is always greater than the children 
priority_queue<int> maxHeap;


min heap where parent is always smaller than the children 
priority_queue<int, vector<int>, greater<int>> minHeap;


 





*/




#include<iostream>
#include<queue>
using namespace std;

 int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        // Min-heap priority queue: {effort, {row, col}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq; // this is the min heap where  the parent node is always smaller than its children

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0; // effort to reach (0,0) is 0

        pq.push({0, {0, 0}});

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            int effort = it.first;   // we will be storing the effort in the queue itself 
            int row = it.second.first;
            int col = it.second.second;

            // If we reach bottom-right, return answer
            if(row == n-1 && col == m-1) {
                return effort;
            }

            for(int i = 0; i < 4; i++) {
                int r = row + drow[i];
                int c = col + dcol[i];

                if(r >= 0 && r < n && c >= 0 && c < m) {

                    int currentDiff = abs(heights[r][c] - heights[row][col]); // we are calcualting the previous effort 

                    int newEffort = max(effort, currentDiff); // checking whether the current effort is grester than the previous effort 

                    if(newEffort < dist[r][c]) {  // comparing that with the distance array  if yes then update the distance vector 

                        dist[r][c] = newEffort;  
                        pq.push({newEffort, {r, c}});
                    }

                }
            }
        }

        // We should never reach here
        return 0;
    }


int main()
{





    return 0;
}