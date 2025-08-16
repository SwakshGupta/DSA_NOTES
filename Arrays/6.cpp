/* Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.


approach

1. First one is the two pointer approach whose solution is give in solve1 Function 


2. Appraoch of prefix sum  with the usage of hashmaps 


Example 1:

Input: nums = [1,1,1], k = 2
Output: 2


*/




#include<iostream>
#include<map>
using namespace std;

  int solve1(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int n = nums.size();
        int sum = 0;
        int count = 0;

        while (r < n) {
            sum += nums[r];

            while (l <= r && sum > k) {
                sum -= nums[l];
                l++;
            }

            if (sum == k) {
                count++;
            }

            r++;
        }

        return count;
    }


// hashmaps and prefix sum soltion 

int solve(vector<int>&arr, int k)
{
unordered_map<int,int>mpp;// first int gives the prefixSum and second gives the count 

mpp[0]=1; // if none of the element is considered then prefix sum is zero 

int preSum=0;
int count=0;

for(int i=0; i<arr.size(); i++)
{

preSum+=arr[i];

int remove=preSum-k;
count+=mpp[remove]; // if the remove element is there in the map then increase the conter  
mpp[preSum]=i;
}
}


int main()
{




    return 0;
}