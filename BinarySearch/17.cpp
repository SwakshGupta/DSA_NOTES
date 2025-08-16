/*
1. Find the element in 2d matrix and return 

here our BS mid represents in the column number 



*/

#include<iostream>
using namespace std;

vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        int low = 0;
        int high = n - 1; // we will be doing BS in the colmn number 

        while (low <= high) {
            int midCol = (low + high) / 2;

            // Find the row with the max element in the mid column
            int maxRow = 0;
            for (int i = 0; i < m; ++i) {
                if (mat[i][midCol] > mat[maxRow][midCol]) {
                    maxRow = i;
                }
            }

            int midVal = mat[maxRow][midCol];
            int leftVal = (midCol - 1 >= 0) ? mat[maxRow][midCol - 1] : -1;
            int rightVal = (midCol + 1 < n) ? mat[maxRow][midCol + 1] : -1;

            if (midVal > leftVal && midVal > rightVal) {
                return {maxRow, midCol}; // Peak found
            } else if (rightVal > midVal) {
                low = midCol + 1; // Move right
            } else {
                high = midCol - 1; // Move left
            }
        }

        return {-1, -1}; // Should never reach here
    }

int main()
{




    return 0;
}