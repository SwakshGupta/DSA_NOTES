/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array 
[0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.



to solve this problem we are doing two things for every element we are finding two things prefix max and suffix max

1. For every indivial elemenet we will find how much water it can store that will obviously depends upon prefix and suffix max

2.  every contribution =min(prefixMax,suffixMax)-height of that element itself 

3. these are the three things which will store the rainwater 






*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix(vector<int> nums) { // here we are calculating the prefix vector 
    int n = nums.size();
    vector<int> prefixMax(n);
    prefixMax[0] = nums[0];

    for (int i = 1; i < n; i++) {
        prefixMax[i] = max(prefixMax[i - 1], nums[i]);
    }

    return prefixMax; 
}

vector<int> suffix(vector<int> nums) { // here we are calcuating the suffix vector 
    int n = nums.size();
    vector<int> suffixMax(n);
    suffixMax[n - 1] = nums[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        suffixMax[i] = max(suffixMax[i + 1], nums[i]);
    }

    return suffixMax;
}

int rainWater(vector<int> nums) {
    int n = nums.size();
    int total = 0;
    vector<int> prefixMax = prefix(nums);
    vector<int> suffixMax = suffix(nums);

    for (int i = 0; i < n; i++) {
        int leftMax = prefixMax[i]; // logic is written in the notebook
        int rightMax = suffixMax[i];
        total += min(leftMax, rightMax) - nums[i];
    }

    return total;
}

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Trapped Water: " << rainWater(height) << endl;
    return 0;
}
