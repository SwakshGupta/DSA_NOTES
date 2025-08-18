/*

410. Split Array Largest Sum
Solved
Hard
Topics
premium lock icon
Companies
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.
A subarray is a contiguous part of the array.


approach

1. here we have to diviide the subarray into k parts such that the maximum sum should be minimum

2. so our binary search range will  vary from largest element to sum of all the elements 

3. the we have defined the function which will count number of slashes based on the value of mid if  the number of slashes 
are lesser then we have to decrease our number  otherwise we have to increase the number 



*/

#include<iostream>
using namespace std;


int solve(vector<int>& nums, int k, int mid) {
    int count = 1;  // at least one subarray
    long long currSum = 0;

    for (int num : nums) {
        if (currSum + num > mid) {  
            // start new subarray
            count++;
            currSum = num;
        } else {
            currSum += num;
        }
    }
    return count;  // number of subarrays needed
}

int splitArray(vector<int>& nums, int k) {
    int n = nums.size();
    if (k > n) return -1;

    int l = *max_element(nums.begin(), nums.end());
   int r=0;

   for(int i=0; i<n; i++)
   {
    r+=nums[i];
   }
    int ans = r;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        int count = solve(nums, k, mid);

        if (count <= k) {
            ans = mid;
            r = mid - 1;  // try smaller maximum
        } else {
            l = mid + 1;  // need bigger maximum
        }
    }
    return ans;
}









int main()
{




    return 0;
}