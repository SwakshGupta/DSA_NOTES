/*
447. Number of Boomerangs

// try to understand the intuition for this one 
*/

#include<iostream>
using namespace std;

   int numberOfBoomerangs(vector<vector<int>>& points) {
        int total = 0;
        
        for (int i = 0; i < points.size(); i++) {
            unordered_map<int, int> distanceMap;
            
            for (int j = 0; j < points.size(); j++) {
                if (i == j) continue;
                
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int distSquared = dx * dx + dy * dy;
                
                distanceMap[distSquared]++;
            }
            
            for (auto& entry : distanceMap) {
                int count = entry.second;
                if (count > 1) {
                    total += count * (count - 1);
                }
            }
        }
        
        return total;
    }




int main()
{




    return 0;
}