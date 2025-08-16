
/*Number of rabbits in the forest problem 


*/


#include<iostream>
using namespace std;


  int numRabbits(vector<int>& answers) {
        unordered_map<int, int> freq;
        for (int ans : answers) {
            freq[ans]++;
        }

        int total = 0;

        for (auto [x, cnt] : freq) {
            int groupSize = x + 1;
            int groups = (cnt + x) / groupSize;    // to get the logic gpt it 
            total += groups * groupSize;
        }

        return total;
    }




int main()
{




    return 0;
}