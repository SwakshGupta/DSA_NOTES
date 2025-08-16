/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.



this solution also uses the hash maps


approach 2-Using two pointer



*/

#include<iostream>
using namespace std;

    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size();

        // Build the hash table
        for (int i = 0; i < n; i++) { // created the mapping for each element 
            numMap[nums[i]] = i;
        }

        // Find the complement
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (numMap.count(complement) && numMap[complement] != i) { // if the complement exist in the hashmap and is not equal to i then we have found the pairs 
                return {i, numMap[complement]}; // This is the returned pair 
            }
        }

        return {}; // No solution found
    }

/*
 ......... optimal approach is the two pointer approach(greedy approach)  
 But  this appraoch only works if the array is sorted 

you know how it works create two pointer point in the beginning and in the end take their sum if sum is lesser or greater then move the pointer accordinly


*/

vector<int>solve2(vector<int>&nums,int target)
{

int n=nums.size();
vector<int>ans;

int p=0;
int q=n-1;

while(p<q)
{

if(p+q>target)
{
    q--;
}

if(p+q<target)
{
    p++;
}

if(p+q==target)
{
    ans.push_back(p);
    ans.push_back(q);
}

}
return ans;

}






int main()
{



    return 0;
}

/*
   int majorityElement(vector<int>& nums) {
        unordered_map<int,int>a;
        int n=nums.size();
        int ans=0;

        for(auto x:nums)
        {
            a[x]++;
        }

        for(auto x:a)
        {
            if(x.second>n/2)
            {
               ans=x.first;
            }
        }
        return ans;
    }






*/