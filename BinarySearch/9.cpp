/*
1482. Minimum Number of Days to Make m Bouquets

You are given an integer array bloomDay, an integer m and an integer k.

You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

...........

Similar to previous koko eating banana problem we will find the max value from the array and tehn we will apply BS from (1 to max value in array)

and will write a function to check for the bouquets 

*/

#include<iostream>
using namespace std;

// wrting the function to check for the bouquets 

    bool canMakeBouquets(vector<int>& bloomDay, int day, int m, int k) {
        int bouquets = 0, flowers = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0; // reset if bloomDay[i] > day
            }
        }

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        long long total = 1LL * m * k;

        if (total > bloomDay.size()) return -1; // number of flowers lesser than the total in the array then return -1

        int left = 1, right = *max_element(bloomDay.begin(), bloomDay.end());
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canMakeBouquets(bloomDay, mid, m, k)) {
                result = mid;
                right = mid - 1; // try smaller days
            } else {
                left = mid + 1;
            }
        }

        return result;
    }






int main()
{




    return 0;
}