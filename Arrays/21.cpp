/*
594. Longest Harmonious Subsequence

We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.

Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.

 

Example 1:

Input: nums = [1,3,2,2,5,2,3,7]

Output: 5

Explanation:

The longest harmonious subsequence is [3,2,2,2,3].


ohk so this question can be solved by two methods 

1. Is by first sorting and then creating two pointers check condition (nums[r]-nums[l]==1) increase the counter otherwise increase the left 

2. Second is by creating hashmap calcualte the frequency of all the number check whether  for every num (num+1) number exist if yes the add the frequecy of both the number 



class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> frequencyMap;

        // Step 1: Count frequencies of each number
        for (int num : nums) {
            frequencyMap[num]++;
        }

        int maxLength = 0;

        // Step 2: Check all possible (num, num+1) pairs
        for (auto& [num, count] : frequencyMap) {
            if (frequencyMap.count(num + 1)) {
                int currentLength = count + frequencyMap[num + 1];
                maxLength = max(maxLength, currentLength);
            }
        }

        return maxLength;
    }
};




*/