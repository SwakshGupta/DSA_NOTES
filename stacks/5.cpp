/*
You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

Return the sum of all subarray ranges of nums.

A subarray is a contiguous non-empty sequence of elements within an array.


# To solve this question we have to find find (sum of subuarray max )- (sum of subarray minimum) which we have already found in 3.cpp 



(sum of subuarray max ) to solve this we have to find  NGE and PGE
*/






#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int MOD = 1e9 + 7;

// ...........from previous code .................
vector<int> prevSmallerIndex(const vector<int>& nums) {
    int n = nums.size();
    vector<int> pse(n, -1);  // -1 if no smaller on the left
    stack<int> s;

    for (int i = 0; i < n; i++) {  // in the pse we are traversing from left to right 
        while (!s.empty() && nums[s.top()] >= nums[i]) {
            s.pop();
        }
        if (!s.empty()) {
            pse[i] = s.top();
        }
        s.push(i);
    }
    return pse;
}


vector<int> nextSmallerIndex(const vector<int>& nums) {
    int n = nums.size();
    vector<int> nse(n, n);  // n if no smaller on the right
    stack<int> s;

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && nums[s.top()] > nums[i]) { 
            s.pop();
        }
        if (!s.empty()) {
            nse[i] = s.top();
        }
        s.push(i); 
    }
    return nse;
}

// .............for the subarray max element we need pge and nge............
vector<int> prevGreaterIndex(const vector<int>& nums) {
    int n = nums.size();
    vector<int> pse(n, -1);  // -1 if no smaller on the left
    stack<int> s;

    for (int i = 0; i < n; i++) {  // in the pse we are traversing from left to right 
        while (!s.empty() && nums[s.top()] <= nums[i]) {
            s.pop();
        }
        if (!s.empty()) {
            pse[i] = s.top();
        }
        s.push(i);
    }
    return pse;
}


vector<int> nextGreaterIndex(const vector<int>& nums) {
    int n = nums.size();
    vector<int> nse(n, n);  // n if no smaller on the right
    stack<int> s;

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && nums[s.top()] < nums[i]) { 
            s.pop();
        }
        if (!s.empty()) {
            nse[i] = s.top();
        }
        s.push(i); 
    }
    return nse;
}





int sumOfSubarrayRanges(vector<int>& nums) {
    int n = nums.size();
    vector<int> prev1 = prevSmallerIndex(nums); 
    vector<int> next1 = nextSmallerIndex(nums);

    vector<int> prev2 = prevGreaterIndex(nums); 
    vector<int> next2 = nextGreaterIndex(nums); // found the arrays of all nge pge pse nse 




    long long total = 0;
    long long contribution1=0;
     long long contribution2=0; 

    for (int i = 0; i < n; i++) {     // sum of subarray minimum
        long long left = i - prev1[i]; 
        long long right = next1[i] - i;
        contribution1+= (nums[i] * left % MOD) * right % MOD;
    }

    for (int i = 0; i < n; i++) {    // sum of subarray maximum
        long long left = i - prev2[i]; 
        long long right = next2[i] - i;
        contribution2+= (nums[i] * left % MOD) * right % MOD;
    }
  total=contribution2-contribution1;

    return total;
}

int main() {
    vector<int> nums = {3, 1, 2, 4};

  
    cout << "Sum of Subarray Minimums: " ;

    return 0;
}
