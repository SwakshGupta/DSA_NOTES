/*
H index 

Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, return the researcher's h-index.

According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.


we will solve this problem by searching and sorting 

1. First sort the array in ascending order and then do binary search 

*/

#include<iostream>
using namespace std;

int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int left = 0, right = n - 1;
        int hIndex = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int papersWithAtLeast = n - mid; // number greater than mid to end 

            if (citations[mid] >= papersWithAtLeast) { // if current citation is greater than equal to the number of papers from mid to end then it is a valid h index 

                // valid h-index found, try for better (move left)
                hIndex = papersWithAtLeast;
                right = mid - 1;
            } else {
                // too few citations, move right
                left = mid + 1;
            }
        }

        return hIndex;
    }



int main()
{




    return 0;
}