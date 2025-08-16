/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.


*/

#include<iostream>
using namespace std;


void solve(int i, int target, vector<int>& candidates, vector<int>& temp, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (i >= candidates.size() || target < 0) {
            return;
        }

        // Pick the current element
        if (candidates[i] <= target) {  // we will pick the element push into our temp ds and call the reccursion 

            temp.push_back(candidates[i]);
            solve(i, target - candidates[i], candidates, temp, ans); 
            temp.pop_back(); // while coming back we will pop out the element  see in notebook 
        }

        
        solve(i + 1, target, candidates, temp, ans); // if i dont pick up the current elemetn then we have to move to the next index 
    }




    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, target, candidates, temp, ans); // we are starting our recusion with index 0
        return ans;
    }


 

int main()
{





    return 0;
}