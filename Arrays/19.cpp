/*

1498. Number of Subsequences That Satisfy the Given Sum Condition


*/

#include<iostream>
using namespace std;

 int numSubseq(vector<int>& nums, int target) {
        int MOD = 1e9 + 7;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0, right = n - 1; // initiated the left and right pointer with power of 2 
        vector<int> power(n, 1);   

        for (int i = 1; i < n; ++i) 
            power[i] = (power[i - 1] * 2) % MOD; // here we have calculated the whole vector with power of 2 

        int count = 0;

        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                count = (count + power[right - left]) % MOD;  
                left++;
            } else {
                right--;
            }
        }

        return count;
    }

int main()
{




    return 0;
}