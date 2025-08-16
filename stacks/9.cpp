/*
 Maximal Rectangle

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

*/


#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// Largest area histogram from the previous code since that will be needed for this code 
int LargestArea(vector<int> nums) {
    stack<int> st;
    int maxArea = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] > nums[i]) // so we  have created a stack and we will find area  of each index while we are popping out the elements (logic is there in the notebook)
        {
            int element = st.top();
            st.pop();
            int nse = i;
            int pse = st.empty() ? -1 : st.top();

            maxArea = max(nums[element] * (nse - pse - 1), maxArea);
        }
        st.push(i);
    }

    // if there are leftover elements even when the array is traversed then we will do this (explanation in the notes )
    while (!st.empty()) {
        int nse = n;
        int element = st.top();
        st.pop();
        int pse = st.empty() ? -1 : st.top();

        maxArea = max(maxArea, (nse - pse - 1) * nums[element]);
    }
    return maxArea;
}


int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;

    int n = matrix.size();    // rows
    int m = matrix[0].size(); // columns
    int maxArea = 0;

    vector<vector<int>> pSum(n, vector<int>(m, 0)); //This is the prefix sum 

    for (int j = 0; j < m; j++) // here we will be computing the prefix sum 
    {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] == '1') {
                sum += 1;
            } else {
                sum = 0;
            }
            pSum[i][j] = sum; // pushing the sum to the prefix sum matrix 
        }
    }

    for (int i = 0; i < n; i++) {
        maxArea = max(maxArea, LargestArea(pSum[i])); // for each prefix sum row we will be calculating the area and  finding the max area out of it 
    }

    return maxArea;
}

int main() {
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    cout << "Max Area: " << maximalRectangle(matrix) << endl;

    return 0;
}




