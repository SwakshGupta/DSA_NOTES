/*
For a binary array count te number of subarray with sum k

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: 
the number of subarrays are [1,0,1] [1,0,1,0] [0,1,0,1] [1,0,1]




*/

#include<iostream>
using namespace std;




int countSub(vector<int>nums,int k)
{

int l=0;
int r=0;
int sum=0;
int n=nums.size();
int count=0;


if(k<0) // this is the edge case if the goal is less than zero then return zero 
{
    return 0;
}

while(r<n)
{
    sum+=nums[r];
    while(sum>k)
    {
        sum-=nums[l];
        l++;
    }
    count+=(r-l+1); // these are the possible number of subarrays whose sum is less than k 
    r++;
}


// for this function TC-O(2N) because of the two while loop which we have here   and the SC-O(1) 


}

int main()
{
vector<int>nums;
int k;
 int answer=countSub(nums,k)-countSub(nums,k-1);



    return 0;
}


// better approach is by using the prefix sum 

/*
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;
        
        int sum = 0, count = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            // If sum - goal has been seen before
            if(prefixCount.find(sum - goal) != prefixCount.end()) {
                count += prefixCount[sum - goal];
            }
            
            prefixCount[sum]++;
        }
        
        return count;
    }
};












*/