/*
Find the target in the 2d sorted array 




*/


#include<iostream>
using namespace std;

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int low = 0;
        int high = n * m - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;

            int row = mid / m; // we calculate the row number by diviion 
            int col = mid % m; // we compute the column number by modulo

   // this modulo givs the position within  the row to know where we are in current row we do modulo as this gives us remainder 


            // through this row and column we will find the element and then calculate the number and shorten the limit accordinly 
            
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return false;
    }


int main()
{




    return 0;
}