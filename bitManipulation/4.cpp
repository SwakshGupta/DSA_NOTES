// find the number of subsets generated in an array

#include<iostream>
using namespace std;

vector<vector<int>> generateSubsets(const vector<int>& set) {
    int n = set.size();
    int totalSubsets = 1 << n; // 2^n subsets
    vector<vector<int>> allSubsets;

    for (int mask = 0; mask < totalSubsets; ++mask) { // traversing through all the subsets 
        vector<int> subset;
        for (int j = 0; j < n; ++j) { // now  we are traversing through every element 

            if (mask & (1 << j)) {    // checking whether the ith bit is set  if set then pushing that into the vector 
                subset.push_back(set[j]);
            }
        }
        allSubsets.push_back(subset);
    }

    return allSubsets;
}

// this mask represent one possible subset 





int main()
{





    return 0;
}

/*


vector<vector<int>> generateSubsets(const vector<int>& set) {

int n=set.size();

int totalsubsets= 1<<n; // this is the total number of subsets

vector<vector<int>Subsets;


for(int mask=0; mask<totalsubsets; mask++)
{

for(int j=0; j<n ; i++)

{
    if(mask && (1>>j));  // this function will check whehter the jth bit is set or not
    {
        
    }
}





     
}







    }












*/