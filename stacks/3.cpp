/*
Sum of subarray is minimum question theory in notebook 

1. So pse and nse will give us the left  and right range for which nums[i] was smallest 

2. after we  have figured out the left and right range we can find for how many subarrays  nums[i] was smallest 

3. ans+=nums[i]*range and range=(i-pse[i])*(nse[i]-1)



so its basically find range where nums[i] was minimum and then multiply the range with nums[i]


*/





#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int MOD = 1e9 + 7; // 10^9+7

// Previous Smaller Element: returns index of previous smaller element or -1
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

// Next Smaller Element: returns index of next smaller element or n
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
        s.push(i); // here instead of pushing elements we are pushing the indices since we will find the subarrays using indices 
    }
    return nse;
}

int sumOfSubarrayMinimums(vector<int>& nums) {
    int n = nums.size();
    vector<int> prev = prevSmallerIndex(nums); // created the arrays for the nsi and psi 
    vector<int> next = nextSmallerIndex(nums);

    long long total = 0;

    for (int i = 0; i < n; i++) {
        long long left = i - prev[i]; 
        long long right = next[i] - i;
        long long contribution = (nums[i] * left % MOD) * right % MOD;
        total = (total + contribution) % MOD;
    }

    return total;
}

int main() {
    vector<int> nums = {3, 1, 2, 4};

    int result = sumOfSubarrayMinimums(nums);
    cout << "Sum of Subarray Minimums: " << result << endl;

    return 0;
}
