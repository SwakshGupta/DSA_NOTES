/*
239. Sliding Window Maximum

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

*/
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> slidingWindow(vector<int> arr, int k) {
    deque<int> dq; // Store indices of elements
    vector<int> result;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        // Remove indices out of this window
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Remove smaller elements from the back of deque
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }

        // Push current index at the back
        dq.push_back(i);

        // If we have a complete window
        if (i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }

    return result;
}




int main()
{




    return 0;
}

/*


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0;
        int j=k-1;
        int n=nums.size();
        vector<int>ans;

        while(j<n)
        {
            int maxi=INT_MIN;
            for(int m=i; m<j+1; m++)
            {
                maxi=max(maxi,nums[m]);
            }
            ans.push_back(maxi);
            i++;
            j++;
        }

        return ans;
        
    }
};


*/